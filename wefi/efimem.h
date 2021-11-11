#include <wefi/efitypes.h>

#ifndef EFIMEM_H_
#define EFIMEM_H_

typedef UINTN EFI_PHYSICAL_ADDRESS;
typedef UINTN EFI_VIRTUAL_ADDRESS;

typedef enum
{
	EfiReservedMemoryType,
	EfiLoaderCode,
	EfiLoaderData,
	EfiBootServicesCode,
	EfiBootServicesData,
	EfiRuntimeServicesCode,
	EfiRuntimeServicesData,
	EfiConventionalMemory,
	EfiUnusableMemory,
	EfiACPIReclaimMemory,
	EfiACPIMemoryNVS,
	EfiMemoryMappedIO,
	EfiMemoryMappedIOPortSpace,
	EfiPalCode,
	EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef enum EFI_ALLOCATE_TYPE
{
	AllocateAnyPages,
	AllocateMaxAddress,
	AllocateAddress,
	MaxAllocateType,
} EFI_ALLOCATE_TYPE;

typedef struct
{
	UINT32 Type;
	EFI_PHYSICAL_ADDRESS PhysicalStart;
	EFI_VIRTUAL_ADDRESS VirtualStart;
	UINT64 NumberOfPages;
	UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

#define EFI_MEMORY_UC (0x0000000000000001)
#define EFI_MEMORY_WC (0x0000000000000002)
#define EFI_MEMORY_WT (0x0000000000000004)
#define EFI_MEMORY_WB (0x0000000000000008)
#define EFI_MEMORY_UCE (0x0000000000000010)
#define EFI_MEMORY_WP (0x0000000000001000)
#define EFI_MEMORY_RP (0x0000000000002000)
#define EFI_MEMORY_XP (0x0000000000004000)
#define EFI_MEMORY_RUNTIME (0x8000000000000000)

#endif