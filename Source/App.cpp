/* This library is actually C code, so we need to respect that. */

extern "C"
{
#include <wefi/efi.h>
}

/* We'll use a config file, located somewhere statically. */
static const CHAR16 *ConfigLocation = u"\\EFI\\MONKEY\\BOOT.INI";


/* Some GUIDs we'll need. */
static EFI_GUID GuidEfiLoadedImageProtocol = EFI_LOADED_IMAGE_PROTOCOL_GUID;
static EFI_GUID GuidEfiSimpleFilesystemProtocol = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;

/* Alias this function call to make things easier... */
static EFI_OPEN_PROTOCOL OpenProtocol;

EFI_STATUS EFIAPI ObtainRootPath(IN EFI_HANDLE &Handle, OUT EFI_SIMPLE_FILESYSTEM_PROTOCOL **FS)
{
	EFI_STATUS Result;
	EFI_LOADED_IMAGE_PROTOCOL *LoadedImageProtocol;
	Result = OpenProtocol(Handle, &GuidEfiLoadedImageProtocol, 
		(void**)(&LoadedImageProtocol), Handle, NULL, 
		EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL);

	if (Result != EFI_SUCCESS)
	{
		return Result;
	}

	EFI_SIMPLE_FILESYSTEM_PROTOCOL *FSProtocol;
	Result = OpenProtocol(LoadedImageProtocol->DeviceHandle, 
		&GuidEfiSimpleFilesystemProtocol, (void**)(&FSProtocol), Handle, 
		NULL, EFI_OPEN_PROTOCOL_GET_PROTOCOL);

	if (Result != EFI_SUCCESS)
	{
		return Result;
	}

	*FS = FSProtocol;
	return Result;
}



EFI_STATUS EFIAPI uefi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SysTable)
{
	UINTN MapKey = 0;

	/* Wipe whatever is on the screen. */
	SysTable->ConOut->ClearScreen(SysTable->ConOut);

	/* Print hello world! */
	SysTable->ConOut->OutputString(SysTable->ConOut, u"Hello, world!\r\n");

	/* And now for a little bit of setup... */
	EFI_SIMPLE_FILESYSTEM_PROTOCOL *RootFSProtocol;
	EFI_STATUS Res = ObtainRootPath(ImageHandle, &RootFSProtocol);

	if (Res != EFI_SUCCESS)
	{
		return Res;
	}

	EFI_FILE_PROTOCOL *ESPRoot = NULLPTR;
	Res = RootFSProtocol->OpenVolume(RootFSProtocol, &ESPRoot);

	if (Res != EFI_SUCCESS)
	{
		return Res;
	}

	/* Look for the config file... */
	EFI_FILE_PROTOCOL *ConfigFile = NULLPTR;
	Res = ESPRoot->Open(ESPRoot, &ConfigFile, ConfigLocation, 
		EFI_FILE_MODE_READ, EFI_FILE_READ_ONLY);

	if (Res != EFI_SUCCESS)
	{
		return Res;
	}

	UINTN MapSize = 0;
	UINTN DescriptorSize = 0;
	EFI_MEMORY_DESCRIPTOR *MemoryMap = nullptr;

	SysTable->BootServices->GetMemoryMap(
		&MapSize, MemoryMap, NULL, &DescriptorSize, NULL);

	/* Silence the watchdog. We don't need it anymore. */
	SysTable->BootServices->SetWatchdogTimer(0, 0, 0, NULL);

	/* Terminate boot services: we don't need these anymore. */
	SysTable->BootServices->ExitBootServices(ImageHandle, MapKey);
	return EFI_SUCCESS;
}