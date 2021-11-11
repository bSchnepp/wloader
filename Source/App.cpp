
extern "C"
{

/* This library is actually C code, so we need to respect that. */
#include <wefi/efi.h>

}


EFI_STATUS EFIAPI uefi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SysTable)
{
	UINTN MapKey = 0;
	SysTable->ConOut->OutputString(SysTable->ConOut, u"Hello, world!\r\n");

	UINTN MapSize = 0;
	UINTN DescriptorSize = 0;
	EFI_MEMORY_DESCRIPTOR *MemoryMap = nullptr;

	SysTable->BootServices->GetMemoryMap(
		&MapSize, MemoryMap, NULL, &DescriptorSize, NULL);

	SysTable->BootServices->ExitBootServices(ImageHandle, MapKey);
	return EFI_SUCCESS;
}