#include <stdint.h>

#ifndef EFIDATATYPES_H_
#define EFIDATATYPES_H_

#define EFIAPI __attribute__((ms_abi))

#define CONST const
#define INLINE inline
#define VOID void

typedef uint8_t BOOLEAN;
typedef char CHAR8;
typedef char16_t CHAR16;

typedef int8_t INT8;
typedef int16_t INT16;
typedef int32_t INT32;
typedef int64_t INT64;
typedef struct { int64_t A; uint64_t B; } INT128;

typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef struct { uint64_t A; uint64_t B; } UINT128;

#if defined(__x86_64__) || defined(__aarch64__)
	typedef uint64_t UINTN;
	typedef int64_t INTN;
#elif defined(__i386__)
	typedef uint32_t UINTN;
	typedef int32_t INTN;
#endif

typedef struct EFI_TIME
{
	UINT16 Year;
	UINT8 Month;
	UINT8 Day;
	UINT8 Hour;
	UINT8 Minute;
	UINT8 Second;
	UINT8 RESERVED;
	UINT32 Nanosecond;
	UINT16 TimeZone;
	UINT8 Daylight;
	UINT8 RESERVED2;
}EFI_TIME;

typedef struct EFI_GUID
{
	UINT32 Data1;
	UINT16 Data2;
	UINT16 Data3;
	UINT8 Data4;
	UINT8 Data5;
	UINT8 Data6;
	UINT8 Data7;
	UINT8 Data8;
	UINT8 Data9;
	UINT8 Data11;
	UINT8 Data12;
} EFI_GUID;


#ifndef NULL
#define NULL ((void*)0)
#endif

#ifndef NULLPTR
#define NULLPTR NULL
#endif

#define EFI_FALSE (1)
#define EFI_TRUE (0)

typedef UINTN EFI_STATUS;
typedef VOID *EFI_HANDLE;
typedef VOID *EFI_EVENT;
typedef UINT64 EFI_LBA;
typedef UINTN EFI_TPL;

/* Decorators: some functions get annotated with these for readability */
#define IN
#define OUT
#define INOUT
#define INOPT
#define OPT
#define OUTOPT
#define INOUTOPT
#define OPTIONAL

#endif