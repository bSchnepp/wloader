#include <wefi/efitypes.h>
#include <wefi/efimem.h>

#ifndef EFI_COMMON_H_
#define EFI_COMMON_H_

#define EVT_TIMER (0x80000000)
#define EVT_RUNTIME (0x40000000)
#define EVT_NOTIFY_WAIT (0x00000100)
#define EVT_NOTIFY_SIGNAL (0x00000200)
#define EVT_SIGNAL_EXIT_BOOT_SERVICES (0x00000201)
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE (0x60000202)

#define TPL_APPLICATION 0x04
#define TPL_CALLBACK 0x08
#define TPL_NOTIFY 0x10
#define TPL_HIGH_LEVEL 0x1F

typedef enum
{
	TimerCancel,
	TimerPeriodic,
	TimerRelative
} EFI_TIMER_DELAY;

typedef struct
{
	UINT64 Signature;
	UINT32 Revision;
	UINT32 HeaderSize;
	UINT32 CRC32;
	UINT32 Reserved;
} EFI_TABLE_HEADER;

typedef struct
{
	UINT16 ScanCode;
	CHAR16 UnicodeChar;
} EFI_INPUT_KEY;


typedef enum
{
	EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;


#endif
