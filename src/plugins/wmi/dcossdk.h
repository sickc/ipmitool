/******************************************************************
  Copyright (c) 2008, Dell Inc
  All rights reserved.
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
																		    
  - Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution. 
  - Neither the name of Dell Inc nor the names of its contributors
    may be used to endorse or promote products derived from this software 
    without specific prior written permission. 
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. 
 
//
//  Environment:
//    Linux, NetWare, Windows NT/2000/2003
//
******************************************************************/

#ifndef __DCOSSDK_H_INCLUDED__
#define __DCOSSDK_H_INCLUDED__


//--------------------------------------------------------------------
// NOTE: DO NOT CHANGE THIS FILE UNLESS YOU UNDERSTAND IT
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// NOTE: Shut off any prior packing or compiler option pragmas
// performed by calling headers or compiler 
// Example: someinc.h -> performs pack(1) then #includes <dcossdk.h>
//--------------------------------------------------------------------
#ifdef SYSTEM_TYPE_WINNT
#pragma pack(push, __DCOSSDK_H_PACKSAVE__)
#pragma pack() // restore compiler defaults
#endif

#ifdef SYSTEM_TYPE_NETWARE
#pragma pack(push)
#pragma pack() // restore compiler defaults
#endif

#ifdef SYSTEM_TYPE_LINUX
#pragma pack(push, __DCOSSDK_H_PACKSAVE__, 1)
#pragma pack() // restore compiler defaults
#endif

#ifdef SYSTEM_TYPE_OS2
#pragma pack(push, __DCOSSDK_H_PACKSAVE__, 1)
#pragma pack() // restore compiler defaults
#endif

#ifdef SYSTEM_TYPE_DOS
#pragma pack() // restore compiler defaults
#endif


//--------------------------------------------------------------------
// SDK include files
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// SYSTEM_TYPE_WINNT
//--------------------------------------------------------------------

#ifdef SYSTEM_TYPE_WINNT

#include <windows.h>
#include <winioctl.h>
#include <winnls.h>
#include <aclapi.h>
#include <tchar.h>
#include <lm.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <errno.h>
#include <fcntl.h>
#include <conio.h>
#include <time.h>
#include <signal.h>
#include <dbt.h>

#ifdef _DEBUG

// setup marcos as needed
#if defined(_DEBUG) && defined(SYSTEM_DEBUG_MEM_USAGE)

// need this defined before any other symbol
#define _CRTDBG_MAP_ALLOC

#endif // defined(_DEBUG) && defined(SYSTEM_DEBUG_MEM_USAGE)

#include <stdlib.h>
#include <crtdbg.h>

#endif // _DEBUG

#ifndef FD_SET_STRUCTURE
#define FD_SET_STRUCTURE struct fd_set
#endif

#ifndef MAX_FD
#define MAX_FD(x)	(x)
#endif

#endif // SYSTEM_TYPE_WINNT


//--------------------------------------------------------------------
// SYSTEM_TYPE_NETWARE
//--------------------------------------------------------------------

#ifdef SYSTEM_TYPE_NETWARE

// NOTE: DO NOT USE Watcom header files
// USE ONLY Novell NDK header files
#ifndef N_PLAT_NLM
#define N_PLAT_NLM
#endif

#ifdef __MWERKS__
#define __cdecl
#define _cdecl
#endif // __MWERKS__	in NETWARE

// we need to do this so that exports get define without the
// standard C _FuncName problem
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __WATCOMC__

#if __WATCOMC__ < 900
#pragma aux cdecl "*" parm caller []\
         modify [eax ecx edx fs gs 8087];
#else
#pragma aux cdecl "*" parm caller []\
         modify [eax ecx edx 8087];
#endif

#endif // __WATCOMC__	in NETWARE

#ifdef __cplusplus
};
#endif

// For building using LIBC headers
#ifdef USING_LIBC

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <netdb.h>
#include <library.h>
#include <dlfcn.h>
#include <fenv.h>
#include <nksapi.h>
#include <wchar.h>
#include <wctype.h>
#include <unilib.h>
#include <utf8.h>
#include <utsname.h>
#include <nks\synch.h>
#include <arpa\inet.h>
#include <sys\stat.h>

typedef unsigned long HANDLE;

#define INVALID_HANDLE_VALUE                (-1)

#ifndef Sleep
#define Sleep(x)        delay(x)
#endif

#else // For Building using CLIB headers

#include <nwtypes.h>
#include <ntypes.h>
#include <nwerror.h>
//#include <nwerrno.h> // conflitcs with nwerror.h
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
//#include <nit\niterror.h> // Conflicts with nwserver.h
#include <nit\nwenvrn.h>
#include <nwconio.h>
#include <nunicode.h>
#include <nwclxcon.h>
#include <nwcalls.h>
#include <nit\nwmsg.h>
#include <nwadv.h>
#include <nwthread.h>
#include <nwsemaph.h>
#include <nwsignal.h>
#include <nwlocale.h>
#include <nwdebug.h>
#include <nwmalloc.h>
#include <time.h>
#include <nwtime.h>
#include <nwndscon.h>
#include <unistd.h>
#include <netdb.h>
#include <sys\timeval.h>
#include <sys\stat.h>
#include <sys\socket.h>
#include <sys\bsdskt.h>
#include <netinet\in.h>
#include <arpa\inet.h>

// NOTE: DO NOT USE Watcom header files
// USE ONLY Novell NDK header files
#ifndef BYTE
typedef unsigned char   BYTE;
#endif
#ifndef WORD
typedef unsigned short  WORD;
#endif
#ifndef LONG
typedef unsigned long   LONG;
#endif

// set up equivalences for NT and Netware data types
typedef void VOID;
typedef unsigned char   UCHAR;
typedef unsigned char   BOOL;
typedef unsigned short  USHORT;
typedef unsigned int    UINT;

#ifndef DWORD
typedef unsigned long   DWORD;
#endif	// DWORD

typedef unsigned long   ULONG;
typedef void * PVOID;
typedef unsigned char * PUCHAR;
typedef unsigned short * PUSHORT;
typedef unsigned long * PULONG;
typedef void * LPVOID;
typedef unsigned char * LPBYTE;
typedef unsigned long * LPDWORD;
typedef char * LPSTR;
typedef const char * LPCSTR;

typedef LONG HANDLE;
typedef BOOL BOOLEAN;
typedef LONG NTSTATUS;

#define INVALID_HANDLE_VALUE                (-1)

#ifndef FAR
#define FAR
#endif

#ifndef LOBYTE
#define LOBYTE(w)       ((BYTE)(w))
#endif

#ifndef LOWORD
#define LOWORD(w)       ((WORD)(w))
#endif

#ifndef HIBYTE
#define HIBYTE(w)       ((BYTE)(((WORD)(w) >> 8) & 0xFF))
#endif

#ifndef Sleep
#define Sleep(x)        delay(x)
#endif

#ifndef MAX_PATH
#define MAX_PATH		(256)
#endif

#ifndef ESUCCESS
#define ESUCCESS		(0)
#endif

#ifndef EFAILURE
#define EFAILURE		(-1)
#endif

#ifndef ERR_TIMEOUT_FAILURE
#define ERR_TIMEOUT_FAILURE			(0xFE)  /* 254 */
#endif

#ifndef FD_SET_STRUCTURE
#define FD_SET_STRUCTURE struct fd_set
#endif

#ifndef MAX_FD
#define MAX_FD(x)	(x)
#endif

// missing definitions in Netware headers
typedef LONG							SOCKET;
typedef struct sockaddr_in				SOCKADDR_IN;
typedef struct sockaddr *				LPSOCKADDR;

#define INVALID_SOCKET					(SOCKET)(~0)
#define SOCKET_ERROR					(-1)
#define INADDR_NONE						(0xffffffff)

#define closesocket(X)					close(X)
#define send(s,buf,len,flags)			write(s,buf,len)
#define WSAGetLastError()				(errno)
#define WSAEISCONN						(EISCONN)

#endif // USING_LIBC

#endif // SYSTEM_TYPE_NETWARE


//--------------------------------------------------------------------
// SYSTEM_TYPE_LINUX
//--------------------------------------------------------------------

#ifdef SYSTEM_TYPE_LINUX

#include <ctype.h>
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <pthread.h>
#include <signal.h>
#include <stdarg.h>
#include <stdint.h>
#include <syslog.h>
#include <math.h>				// required for "pow" function
#include <time.h>
#include <unistd.h>
#ifndef SYSTEM_TYPE_CYGWIN
#include <wait.h>
#endif
#include <wchar.h>
#include <arpa/inet.h>
#ifndef SYSTEM_TYPE_CYGWIN
#include <net/ethernet.h>
#endif
#include <net/if.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/ipc.h>
#ifndef SYSTEM_TYPE_CYGWIN
#include <sys/prctl.h>
#endif
#include <sys/select.h>
#include <sys/sem.h>
#include <sys/socket.h>
#include <sys/stat.h>
#ifndef SYSTEM_TYPE_CYGWIN
#include <sys/sysinfo.h>
#endif
#include <sys/time.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/utsname.h>

#ifndef BYTE
typedef unsigned char   BYTE;
#endif

#ifndef WORD
typedef unsigned short  WORD;
#endif

#ifndef LONG
//typedef unsigned long   LONG;
#endif

// set up equivalences for Linux data types
typedef signed char     SBYTE;
typedef unsigned char   UBYTE;
typedef signed short    SWORD;
typedef unsigned short  UWORD;
typedef signed long     SLONG;
#ifndef SYSTEM_TYPE_CYGWIN
#define __cdecl
#define _cdecl
#endif
#define SMINTF
#define _PRIV

typedef void VOID;
typedef unsigned char UCHAR;
typedef unsigned char BOOL;
typedef unsigned short USHORT;
typedef unsigned int UINT;
typedef unsigned int DWORD;
typedef long HANDLE;
typedef unsigned long ULONG;
typedef void *PVOID;
typedef unsigned char *PUCHAR;
typedef unsigned short *PUSHORT;
typedef unsigned long *PULONG;
typedef void *LPVOID;
typedef unsigned char *LPBYTE;
typedef unsigned int *LPDWORD;
typedef char *LPSTR;
typedef const char *LPCSTR;

typedef long NTSTATUS;
typedef short           BOOLEAN;

#define FAR

#define LOBYTE(w)       ((BYTE)(w))
#define HIBYTE(w)       ((BYTE)(((WORD)(w) >> 8) & 0xFF))
#ifndef LOWORD
#define LOWORD(w)       ((WORD)(w))
#endif

#ifndef Sleep
// convert x from milliseconds to microseconds for usleep
#define Sleep(x)        usleep(x * 1000)
#endif


#define INVALID_HANDLE_VALUE		(HANDLE)(-1)


#ifndef MAX_PATH
#define MAX_PATH                (256)
#endif

#ifndef _inp
#define _inp inp
#endif

#ifndef _outp
#define _outp outp
#endif

#ifndef FD_SET_STRUCTURE
#define FD_SET_STRUCTURE fd_set
#endif

#ifndef MAX_FD
#define MAX_FD(x)	FD_SETSIZE
#endif

// missing definitions in Linux headers
#ifndef EFAILURE
#define EFAILURE        (-1)
#endif

#define   SOCKET                        int
typedef struct sockaddr *				LPSOCKADDR;
typedef struct sockaddr_in              SOCKADDR_IN;

#define INVALID_SOCKET					(SOCKET)(-1)
#define SOCKET_ERROR					(-1)

#define closesocket(X)	\
{\
shutdown(X, SHUT_RDWR);\
close(X);\
}
#define WSAGetLastError()				(errno)
#define WSAEISCONN						(EISCONN)

#define stricmp(X,Y)					strcasecmp(X,Y)
#define strnicmp(X,Y,Z)					strncasecmp(X,Y,Z)

#endif // SYSTEM_TYPE_LINUX


//--------------------------------------------------------------------
// SYSTEM_TYPE_OS2
//--------------------------------------------------------------------

#ifdef SYSTEM_TYPE_OS2

// turn on/off features in header files
#define INCL_NOBASEAPI			// for os2.h
#define INCL_NOPMAPI			// for os2.h
#define INCL_NO_SCB			// for abios.h
#define INCL_DOSERRORS			// for bseerr.h
#define INCL_DOSMISC			// bsedos16.h needs this to include prototypes for DosXXX type functions called at init time.
#define INCL_NOXLATE_DOS16		// makes sure DosPutMessage is not munged to
					// Dos16PutMessage by besdos16.h
// define INCL_INITRP_ONLY		// for reqpkt.h. This will select only definitions for init packet.
					// no other packet will be defined
#define INCL_DOSFILEMGR
#define INCL_DOSPROCESS
#define INCL_DOSDEVICES


#include <os2.h>			// top level include for writing os2 apps
#include <bseerr.h>                     // base error codes for OS/2
#include <bsedos16.h>			// DosXXX function protoypes


#ifndef WORD
typedef unsigned short  WORD;
#endif
#ifndef LONG
typedef unsigned long   LONG;
#endif

#ifndef FD_SET_STRUCTURE
#define FD_SET_STRUCTURE struct fd_set
#endif

/* set up equivalences for NT and Netware data types */
#define VOID void
typedef unsigned long   DWORD;
typedef unsigned long   HANDLE;
typedef void * LPVOID;
typedef unsigned char * LPBYTE;
typedef unsigned long * LPDWORD;
typedef char * LPSTR;
typedef const char * LPCSTR;

typedef LONG NTSTATUS;
typedef BOOL BOOLEAN;

#define Sleep(x)				DosSleep(x)

#include <time.h>

#endif // SYSTEM_TYPE_OS2


//--------------------------------------------------------------------
// SYSTEM_TYPE_DOS
//--------------------------------------------------------------------

#ifdef SYSTEM_TYPE_DOS

#include <dos.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>

#ifndef BYTE
typedef unsigned char   BYTE;
#endif

#ifndef WORD
typedef unsigned short  WORD;
#endif

#ifndef LONG
typedef unsigned long   LONG;
#endif

// set up equivalences for NT and Netware data types
typedef void VOID;
typedef unsigned char UCHAR;
typedef unsigned char BOOL;
typedef unsigned short USHORT;
typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef unsigned long HANDLE;
typedef unsigned long ULONG;
typedef void *PVOID;
typedef unsigned char *PUCHAR;
typedef unsigned short *PUSHORT;
typedef unsigned long *PULONG;
typedef void *LPVOID;
typedef unsigned char *LPBYTE;
typedef unsigned long *LPDWORD;
typedef char *LPSTR;
typedef const char *LPCSTR;

typedef LONG NTSTATUS;
typedef BOOL BOOLEAN;

#define FAR

#define LOBYTE(w)       ((BYTE)(w))
#define HIBYTE(w)       ((BYTE)(((WORD)(w) >> 8) & 0xFF))

#define Sleep(x)										\
{														\
	clock_t goal;										\
	if (x != 0)											\
	{													\
	   goal = (clock_t)(80 + x) + clock();				\
	   while (goal > clock());							\
	}													\
}

#define INVALID_HANDLE_VALUE			(HANDLE)(-1)


#ifndef _inp
#define _inp inp
#endif

#ifndef _outp
#define _outp outp
#endif

#ifndef FD_SET_STRUCTURE
#define FD_SET_STRUCTURE struct fd_set
#endif

#endif // SYSTEM_TYPE_DOS


//--------------------------------------------------------------------
// Standard C include files
//--------------------------------------------------------------------
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


//--------------------------------------------------------------------
// NOTE: Restore any prior packing
//--------------------------------------------------------------------
#ifdef SYSTEM_TYPE_WINNT
#pragma pack(pop, __DCOSSDK_H_PACKSAVE__)
#endif

#ifdef SYSTEM_TYPE_NETWARE
#pragma pack(pop)
#endif

#ifdef SYSTEM_TYPE_LINUX
#pragma pack(pop, __DCOSSDK_H_PACKSAVE__)
#endif

#ifdef SYSTEM_TYPE_OS2
#pragma pack(pop, __DCOSSDK_H_PACKSAVE__)
#endif

#ifdef SYSTEM_TYPE_DOS
#pragma pack() // restore compiler defaults
#endif


#endif // __DCOSSDK_H_INCLUDED__

