#ifndef EFI_STATUS_H_
#define EFI_STATUS_H_

#define EFI_SUCCESS (0)
#define WEFI_WARN(x) (0x0000000000000000 | x)
#define WEFI_ERROR(x) (0x8000000000000000 | x)


#define EFI_LOAD_ERROR WEFI_ERROR(1)
#define EFI_INVALID_PARAMETER WEFI_ERROR(2)
#define EFI_UNSUPPORTED WEFI_ERROR(3)
#define EFI_BAD_BUFFER_SIZE WEFI_ERROR(4)
#define EFI_BUFFER_TOO_SMALL WEFI_ERROR(5)
#define EFI_NOT_READY WEFI_ERROR(6)
#define EFI_DEVICE_ERROR WEFI_ERROR(7)
#define EFI_WRITE_PROTECTED WEFI_ERROR(8)
#define EFI_OUT_OF_RESOURCES WEFI_ERROR(9)
#define EFI_VOLUME_CORRUPTED WEFI_ERROR(10)
#define EFI_VOLUME_FULL WEFI_ERROR(11)
#define EFI_NO_MEDIA WEFI_ERROR(12)
#define EFI_MEDIA_CHANGED WEFI_ERROR(13)
#define EFI_NOT_FOUND WEFI_ERROR(14)
#define EFI_ACCESS_DENIED WEFI_ERROR(15)
#define EFI_NO_RESPONSE WEFI_ERROR(16)
#define EFI_NO_MAPPING WEFI_ERROR(17)
#define EFI_TIMEOUT WEFI_ERROR(18)
#define EFI_NOT_STARTED WEFI_ERROR(19)
#define EFI_ALREADY_STARTED WEFI_ERROR(20)
#define EFI_ABORTED WEFI_ERROR(21)
#define EFI_ICMP_ERROR WEFI_ERROR(22)
#define EFI_TFTP_ERROR WEFI_ERROR(23)
#define EFI_PROTOCOL_ERROR WEFI_ERROR(24)
#define EFI_INCOMPATIBLE_VERSION WEFI_ERROR(25)
#define EFI_SECURITY_VIOLATION WEFI_ERROR(26)
#define EFI_CRC_ERROR WEFI_ERROR(27)
#define EFI_END_OF_MEDIA WEFI_ERROR(28)
#define EFI_END_OF_FILE WEFI_ERROR(31)
#define EFI_INVALID_LANGUAGE WEFI_ERROR(32)
#define EFI_COMPROMISED_DATA WEFI_ERROR(33)
#define EFI_IP_ADDRESS_CONFLICT WEFI_ERROR(34)
#define EFI_HTTP_ERROR WEFI_ERROR(35)

#define EFI_WARN_UNKNOWN_GLYPH WEFI_WARN(1)
#define EFI_WARN_DELETE_FAILURE WEFI_WARN(2)
#define EFI_WARN_WRITE_FAILURE WEFI_WARN(3)
#define EFI_WARN_BUFFER_TOO_SMALL WEFI_WARN(4)
#define EFI_WARN_STALE_DATA WEFI_WARN(5)
#define EFI_WARN_FILE_SYSTEM WEFI_WARN(6)
#define EFI_WARN_RESET_REQUIRED WEFI_WARN(7)

#endif
