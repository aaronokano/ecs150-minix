# Generated by h2py from /usr/include/netinet/in.h

# Included from stdint.h

# Included from sys/types.h

# Included from ansi.h
_ANSI = 31459
_ANSI = 31459
def _ARGS(params): return params

def _ARGS(params): return ()

_SIZET = int
_POSIX_SOURCE = 1

# Included from minix/sys_config.h
_MINIX_SYS_CONFIG_H = 1
_MACHINE_IBM_PC = 1
_MACHINE_SUN_4 = 40
_MACHINE_SUN_4_60 = 40
_MACHINE_ATARI = 60
_MACHINE_MACINTOSH = 62
_NR_PROCS = 64
_NR_SYS_PROCS = 32
_CHIP_INTEL = 1
_CHIP_M68000 = 2
_CHIP_SPARC = 3
_FP_NONE = 0
_FP_IEEE = 1
_MINIX_CHIP = _CHIP_INTEL
_MINIX_CHIP = _CHIP_M68000
_MINIX_CHIP = _CHIP_SPARC
_MINIX_FP_FORMAT = _FP_IEEE
_ASKDEV = 1
_FASTLOAD = 1
_MINIX_FP_FORMAT = _FP_NONE

# Included from limits.h
CHAR_BIT = 8
CHAR_MIN = -128
CHAR_MAX = 127
SCHAR_MIN = -128
SCHAR_MAX = 127
UCHAR_MAX = 255
MB_LEN_MAX = 1
SHRT_MIN = (-32767-1)
SHRT_MAX = 32767
USHRT_MAX = 0xFFFF
INT_MIN = (-32767-1)
INT_MAX = 32767
UINT_MAX = 0xFFFF
INT_MIN = (-2147483647-1)
INT_MAX = 2147483647
UINT_MAX = 0xFFFFFFFF
LONG_MIN = (-2147483647L-1)
LONG_MAX = 2147483647L
ULONG_MAX = 0xFFFFFFFFL

# Included from sys/dir.h
DIRBLKSIZ = 512
DIRSIZ = 60
_POSIX_ARG_MAX = 4096
_POSIX_CHILD_MAX = 6
_POSIX_LINK_MAX = 8
_POSIX_MAX_CANON = 255
_POSIX_MAX_INPUT = 255
_POSIX_NAME_MAX = DIRSIZ
_POSIX_NGROUPS_MAX = 0
_POSIX_OPEN_MAX = 16
_POSIX_PATH_MAX = 255
_POSIX_PIPE_BUF = 512
_POSIX_STREAM_MAX = 8
_POSIX_TZNAME_MAX = 3
_POSIX_SSIZE_MAX = 32767
_NO_LIMIT = 100
NGROUPS_MAX = 0
ARG_MAX = 16384
ARG_MAX = 4096
CHILD_MAX = _NO_LIMIT
OPEN_MAX = 20
LINK_MAX = CHAR_MAX
LINK_MAX = SHRT_MAX
MAX_CANON = 255
MAX_INPUT = 255
NAME_MAX = DIRSIZ
PATH_MAX = 255
PIPE_BUF = 7168
STREAM_MAX = 20
TZNAME_MAX = 3
SSIZE_MAX = 32767
INT8_MAX = 127
INT16_MAX = 32767
INT32_MAX = 2147483647
UINT8_MAX = 255
UINT16_MAX = 65535
INT_LEAST8_MAX = INT8_MAX
INT_LEAST16_MAX = INT16_MAX
INT_LEAST32_MAX = INT32_MAX
UINT_LEAST8_MAX = UINT8_MAX
UINT_LEAST16_MAX = UINT16_MAX
INT_FAST8_MAX = INT16_MAX
INT_FAST16_MAX = INT16_MAX
INT_FAST8_MAX = INT32_MAX
INT_FAST16_MAX = INT32_MAX
INT_FAST32_MAX = INT32_MAX
UINT_FAST8_MAX = UINT16_MAX
UINT_FAST16_MAX = UINT16_MAX
INTPTR_MIN = INT_MIN
INTPTR_MAX = INT_MAX
UINTPTR_MAX = UINT_MAX
INTPTR_MIN = LONG_MIN
INTPTR_MAX = LONG_MAX
UINTPTR_MAX = ULONG_MAX
INTMAX_MIN = LONG_MIN
INTMAX_MAX = LONG_MAX
UINTMAX_MAX = ULONG_MAX
def INT8_C(c): return c

def INT16_C(c): return c

def INT32_C(c): return __CONCAT(c,l)

def INT32_C(c): return c

def INT64_C(c): return __CONCAT(c,l)

def UINT8_C(c): return __CONCAT(c,u)

def UINT16_C(c): return __CONCAT(c,u)

def UINT32_C(c): return __CONCAT(c,lu)

def UINT32_C(c): return __CONCAT(c,u)

def UINT64_C(c): return __CONCAT(c,lu)

def INTMAX_C(c): return INT32_C(c)

def UINTMAX_C(c): return UINT32_C(c)

def INTMAX_C(c): return INT64_C(c)

def UINTMAX_C(c): return UINT64_C(c)

IPPROTO_IP = 0
IPPROTO_TCP = 6
IPPROTO_UDP = 17
IP_ADD_MEMBERSHIP = 12
IP_DROP_MEMBERSHIP = 13
