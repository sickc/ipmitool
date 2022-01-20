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

/** @file */

#ifndef __DCDETYPES_H_INCLUDED__
#define __DCDETYPES_H_INCLUDED__


#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------
/**
 * Macros missing in SDKs or DDKs of other operating systems/compilers
 */
//---------------------------------------------------------------------

//---------------------------------------------------------------------
/** Data type boolean false definition */
//---------------------------------------------------------------------
#ifndef FALSE
#define FALSE								(0)
#endif

//---------------------------------------------------------------------
/** Data type boolean true definition */
//---------------------------------------------------------------------
#ifndef TRUE
#define TRUE								(1)
#endif

//---------------------------------------------------------------------
/** 
 * Set a number by bit position
 * 
 * @param x [in] the bit position
 */
//---------------------------------------------------------------------
#ifndef BIT
#define BIT(x)								(1 << x)
#endif

//---------------------------------------------------------------------
/** 
 * Minimum evaluation:
 * It invokes the passed elements twice depending on the
 * mathematical evaluation; Use on data elements only.
 * 
 * @param x [in] left-hand of evaluation
 * @param y [in] right-hand of evaluation
 */
//---------------------------------------------------------------------
#ifndef MIN
#define MIN(x,y)							((x < y) ? x : y)
#endif

//---------------------------------------------------------------------
/** 
 * Maximum evaluation:
 * It invokes the passed elements twice depending on the
 * mathematical evaluation; Use on data elements only.
 * 
 * @param x [in] left-hand of evaluation
 * @param y [in] right-hand of evaluation
 */
//---------------------------------------------------------------------
#ifndef MAX
#define MAX(x,y)							((x > y) ? x : y)
#endif

//---------------------------------------------------------------------
/** 
 * Get field byte offset:
 * Calculates the byte offset of a field within a structure.
 *
 * @param STRUCT [in] the structure referenced
 * @param FIELD  [in] field name within the structure
 */
//---------------------------------------------------------------------
#ifndef FIELD_OFFSET
#define FIELD_OFFSET(STRUCT, FIELD)			\
		((size_t)&(((STRUCT *)0)->FIELD))
#endif

//---------------------------------------------------------------------
/** 
 * Argument presence test:
 * Determine if an argument is present by testing the value of the 
 * pointer to the argument value
 *
 * @param ARGPTR [in] pointer to the argument referenced
 */
//---------------------------------------------------------------------
#ifndef ARGUMENT_PRESENT
#define ARGUMENT_PRESENT(ARGPTR)			\
		((u8 *)(ARGPTR) != (u8 *)(NULL))
#endif

//---------------------------------------------------------------------
/** 
 * Get base address of a structure:
 * Calculate the address of the base of the structure given its type, 
 * and an address of a field within the structure
 *
 * @param ADDR  [in] pointer to memory referenced
 * @param TYPE  [in] name of the structure referenced
 * @param FIELD [in] field name within TYPE
 */
//---------------------------------------------------------------------
#ifndef CONTAINING_RECORD
#define CONTAINING_RECORD(ADDR, TYPE, FIELD)	\
		((TYPE *)((u8 *)(ADDR) - (u8 *)(&((TYPE *)0)->FIELD)))
#endif

//---------------------------------------------------------------------
/** 
 * Get size of single dimension array:
 * Calculate the number of dimension size of a single dimension array
 *
 * @param ARRNAME [in] pointer to the array referenced
 */
//---------------------------------------------------------------------
#ifndef NUM_1D_ARR_ELEMENTS
#define NUM_1D_ARR_ELEMENTS(ARRNAME)		\
		(sizeof(ARRNAME)/sizeof(ARRNAME[0]))
#endif

//---------------------------------------------------------------------
/** 
 * Convert value specified into a string define
 *
 * @param VALUE [in] the value to convert
 */
//---------------------------------------------------------------------
#ifndef MAKE_STRING_DEFINE_OF_VALUE
#define	MAKE_STRING_DEFINE_OF_VALUE(VALUE)	#VALUE
#endif


//---------------------------------------------------------------------
/** Pseudo-Exception Handling (throw)
 *
 * Sample usage: 
 * ...
 *    _throw _Exception1;
 *    ...
 * _catch(_Exception1):
 * ...
 */
//---------------------------------------------------------------------
#ifndef _throw
#define _throw								goto
#endif

//---------------------------------------------------------------------
/** Pseudo-Exception Handling (catch)
 *
 * Sample usage: 
 * ...
 *    _throw _Exception1;
 *    ...
 * _catch(_Exception1):
 * ...
 *
 * @param LabelName [in] label name indicating point of exception catch
 */
//---------------------------------------------------------------------
#ifndef _catch
#define _catch(LabelName)					LabelName
#endif


//---------------------------------------------------------------------
//
// Timer definitions
//
//---------------------------------------------------------------------

//---------------------------------------------------------------------
/** Timer definition for cancel the timer interval */
//---------------------------------------------------------------------
#define CANCEL_TIMER						(-1) // Cancel the timer interval

//---------------------------------------------------------------------
/** Timer definition for timer interval has expired */
//---------------------------------------------------------------------
#define EXPIRED_TIMER						(0) // Timer interval has expired


//---------------------------------------------------------------------
//
// Network Computing Architecture (NCA) definition
//
//---------------------------------------------------------------------

//---------------------------------------------------------------------
/** NCA Big Endian architecture definition */
//---------------------------------------------------------------------
#ifndef BIG_ENDIAN
#define BIG_ENDIAN							(0)
#endif

//---------------------------------------------------------------------
/** NCA Little Endian architecture definition */
//---------------------------------------------------------------------
#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN						(1)
#endif


//---------------------------------------------------------------------
//
// Native Processor Type definition
//
//---------------------------------------------------------------------

//---------------------------------------------------------------------
/** Native Processor Type IA-32 definition */
//---------------------------------------------------------------------
#define NATIVE_PROCESSOR_TYPE_X86			(1)

//---------------------------------------------------------------------
/** Native Processor Type IA-64 definition */
//---------------------------------------------------------------------
#define NATIVE_PROCESSOR_TYPE_IA64			(2)

//---------------------------------------------------------------------
/** Native Processor Type Intel-EM64T/AMD-64 definition */
//---------------------------------------------------------------------
#define NATIVE_PROCESSOR_TYPE_X86_64		(3)


//--------------------------------------------------------------------
//
// Defines for maximum values
//
//--------------------------------------------------------------------

//--------------------------------------------------------------------
/** Max size in bytes of an IP address string including NULL character terminator */
//--------------------------------------------------------------------
#define MAX_IPADDR_SIZE						(16) 

//--------------------------------------------------------------------
/** Max size in bytes of host name */
//--------------------------------------------------------------------
#define MAX_IPHOSTNAME_SIZE					(64) 

//--------------------------------------------------------------------
/** Max size in bytes for ASCIIZ path including the NULL terminator */
//--------------------------------------------------------------------
#define MAX_PATH_SIZE						(256) 

//--------------------------------------------------------------------
/** Max size in bytes of unicode from string resource including the double NULL terminator */
//--------------------------------------------------------------------
#define MAX_UNIDAT_STRING_SIZE				(2048) 

//--------------------------------------------------------------------
/** Max size in bytes of a section/key name to be stored into an ini file including the NULL terminator */
//--------------------------------------------------------------------
#define MAX_INI_SECKEY_NAME_SIZE			(MAX_PATH_SIZE) 

//--------------------------------------------------------------------
/** Max size in bytes of a value to be stored into an ini file including the NULL terminator */
//--------------------------------------------------------------------
#define MAX_INI_VALUE_SIZE					((MAX_UNIDAT_STRING_SIZE * 4) + 1) 

//--------------------------------------------------------------------
/** Max size in bytes accounting for a NULL, Carriage return and = sign */
//--------------------------------------------------------------------
#define MAX_INI_LINE_SIZE					(MAX_INI_SECKEY_NAME_SIZE + MAX_INI_VALUE_SIZE + 2) 

//--------------------------------------------------------------------
/** Max size in bytes of data buffers provided to event logging functions */
//--------------------------------------------------------------------
#define MAX_SMLOG_DATABUF_SIZE				(32 * 1024) 


//---------------------------------------------------------------------
//
// OS Type Based Macros
//
//---------------------------------------------------------------------

#ifndef SYSTEM_TYPE_WINNT

//--------------------------------------------------------------------
/** 
 * Unused parameter macro to prevent compiler warnings
 *
 * @param P [in] the parameter referenced
 *
 */
//--------------------------------------------------------------------
#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(P)			{ (P) = (P); }
#endif

#endif // SYSTEM_TYPE_WINNT


//---------------------------------------------------------------------
//
// Compiler Type Based Macros
//
//---------------------------------------------------------------------

/** Microsoft compiler */
#ifdef _MSC_VER

// check version
#if (_MSC_VER >= 1000)

// these versions of the the compiler supported 64 bit value
#define COMPILER_SUPPORTS_INT64

#endif

#if (_MSC_VER >= 1400) && defined(__cplusplus)	// 1400 == VS8
#define BUILTIN_WCHAR_T						(1)
#endif

// IA-64 architecture
#if defined (_M_IA64)

#define NATIVE_ENDIAN_TYPE					LITTLE_ENDIAN
#define NATIVE_DATA_WIDTH					(64)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_IA64

// Intel-EM64T/AMD-64 architecture
#elif defined (_M_AMD64)

#define NATIVE_ENDIAN_TYPE					LITTLE_ENDIAN
#define NATIVE_DATA_WIDTH					(64)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_X86_64

// IA-32 architecture
#elif defined (_M_IX86)

#define NATIVE_ENDIAN_TYPE					LITTLE_ENDIAN
#define NATIVE_DATA_WIDTH					(32)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_X86

// IA-16 architecture
#elif defined (_M_I286)

#define NATIVE_ENDIAN_TYPE					LITTLE_ENDIAN
#define NATIVE_DATA_WIDTH					(16)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_X86

#endif // defined (_M_IA64)

#endif // _MSC_VER


/** Watcom compiler */
#ifdef __WATCOMC__

// check version
#if (__WATCOMC__ >= 1100)

// these versions of the the compiler supported 64 bit value
#define COMPILER_SUPPORTS_INT64

#endif

// IA-32 architecture
#if defined (__386__)

#define NATIVE_ENDIAN_TYPE					LITTLE_ENDIAN
#define NATIVE_DATA_WIDTH					(32)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_X86

#endif

#endif // __WATCOMC__


/** Metrowerks compiler */
#ifdef __MWERKS__

// Metrowerks supports 64 bit value
#define COMPILER_SUPPORTS_INT64

// IA-32 architecture
#if defined (__INTEL__)

#define NATIVE_ENDIAN_TYPE					LITTLE_ENDIAN
#define NATIVE_DATA_WIDTH					(32)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_X86

#endif

#endif // __MWERKS__


// If compiler macros not defined as yet
// make assumptions based on OS type specified
#if (!defined (NATIVE_ENDIAN_TYPE)) && \
	(!defined (NATIVE_DATA_WIDTH)) && \
	(!defined (NATIVE_PROCESSOR_TYPE)) && \
	(!defined (COMPILER_SUPPORTS_INT64))

/** GNU compiler */
#ifdef SYSTEM_TYPE_LINUX

// GNU compiler supports 64 bit values
#define COMPILER_SUPPORTS_INT64	

#if (__BYTE_ORDER == __LITTLE_ENDIAN)
#define NATIVE_ENDIAN_TYPE					LITTLE_ENDIAN
#else
#define NATIVE_ENDIAN_TYPE					BIG_ENDIAN
#endif

//
// On IA64 machines, __LP64__ and __ia64__ are defined
// On x86-64 machines, __LP64__ and __x86_64__ are defined
//

// IA-64 architecture
#if defined (__ia64__)

#define NATIVE_DATA_WIDTH					(64)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_IA64

// Intel-EM64T/AMD-64 architecture
#elif defined (__x86_64__)

#define NATIVE_DATA_WIDTH					(64)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_X86_64

// IA-32 architecture
#elif defined (__i386__)

#define NATIVE_DATA_WIDTH					(32)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_X86

#else

#error failed to determine NATIVE_DATA_WIDTH and NATIVE_PROCESSOR_TYPE in Linux

#endif // defined(__ia64__)

#if (NATIVE_DATA_WIDTH == 64)
#define __int64 long int
#else
#define __int64 long long int
#endif

#endif // SYSTEM_TYPE_LINUX


#ifdef SYSTEM_TYPE_DOS

#undef COMPILER_SUPPORTS_INT64
#define NATIVE_ENDIAN_TYPE					LITTLE_ENDIAN
#define NATIVE_DATA_WIDTH					(16)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_X86

#endif // SYSTEM_TYPE_DOS


#ifdef SYSTEM_TYPE_OS2

#undef COMPILER_SUPPORTS_INT64
#define NATIVE_ENDIAN_TYPE					LITTLE_ENDIAN
#define NATIVE_DATA_WIDTH					(32)
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_X86

#endif // SYSTEM_TYPE_OS2

#endif // (!defined (NATIVE_ENDIAN_TYPE)) &&


// If compiler macros not defined as yet
#if (!defined (NATIVE_ENDIAN_TYPE)) && \
	(!defined (NATIVE_DATA_WIDTH)) && \
	(!defined (NATIVE_PROCESSOR_TYPE)) && \
	(!defined (COMPILER_SUPPORTS_INT64))

// Convey that this block is for documentation
#error Compilation entered documenation area

//--------------------------------------------------------------------
/** Indicates if compiler supports native _int64 or equivalent data type. */
//--------------------------------------------------------------------
#define COMPILER_SUPPORTS_INT64

//--------------------------------------------------------------------
/** Native Endian type based on OS and compiler support. */
//--------------------------------------------------------------------
#define NATIVE_ENDIAN_TYPE					LITTLE_ENDIAN

//--------------------------------------------------------------------
/** Native data width definition based on OS and compiler support. */
//--------------------------------------------------------------------
#define NATIVE_DATA_WIDTH					(32)

//--------------------------------------------------------------------
/** Native processor type definition based on OS and compiler support. */
//--------------------------------------------------------------------
#define NATIVE_PROCESSOR_TYPE				NATIVE_PROCESSOR_TYPE_X86

#endif // (!defined (NATIVE_ENDIAN_TYPE)) && 


//---------------------------------------------------------------------
/**
 * Data Direction Markers
 */
//---------------------------------------------------------------------

/**
 * The use of this marker before a parameter to an API method or object 
 * structure data element indicates that the variable following this 
 * marker should considered a required or optional input to the API 
 * method or object structure before invocation or use respectively.
 */
#define _IN

/**
 * The use of this marker before a parameter to an API method or object 
 * structure data element indicates that the variable following this 
 * marker should considered a required or optional output from the API 
 * method or object structure after invocation or use respectively.
 */
#define _OUT

/**
 * The use of this marker before a parameter to an API method or object 
 * structure data element indicates that the variable following this 
 * marker should considered a required or optional input before and 
 * output after the use of API method or object structure
 */
#define _INOUT

/**
 * The use of this marker is to identify a parameter as being for the 
 * exclusive use of the API method or object structure definition and 
 * should be treated by the caller as reserved; These parameters should 
 * not be modified by the caller
 */
#define _PRIV

/**
 * The use of this marker is to identify a parameter as being for the 
 * exclusive use of the caller; Data Engine API method or object 
 * structure definitions will preserve value (not modify) these values
 */
#define _USER



//---------------------------------------------------------------------
//
// Common Data Types
// NOTE:    u = Unsigned Little Endian, U = Unsigned Big Endian
//          s = Signed Little Endian, S = Signed Big Endian
//
//---------------------------------------------------------------------

// Unsigned

#ifdef SYSTEM_TYPE_LINUX

// For Redhat 7.1, there will be conflicts if _LINUX_WAIT_H is defined
// There are conflits if _PCI_LIB_H is defined
#ifndef _LINUX_WAIT_H
#ifndef _PCI_LIB_H

typedef unsigned char u8; // there is no big endian byte form
typedef unsigned short int u16;
typedef unsigned short int U16;
typedef unsigned int u32;

#endif // _PCI_LIB_H
#endif // _LINUX_WAIT_H

typedef unsigned int U32;

#else // SYSTEM_TYPE_LINUX

//---------------------------------------------------------------------
/**
 * Native data type unsigned 8-bit number (little endian) no big endian byte form;
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
typedef unsigned char u8;

//---------------------------------------------------------------------
/**
 * Native data type unsigned 16-bit number (little endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
typedef unsigned short int u16;

//---------------------------------------------------------------------
/**
 * Native data type unsigned 16-bit number (big endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
typedef unsigned short int U16;

//---------------------------------------------------------------------
/**
 * Native data type unsigned 32-bit number (little endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
typedef unsigned long u32;

//---------------------------------------------------------------------
/**
 * Native data type unsigned 32-bit number (big endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
typedef unsigned long U32;

#endif // SYSTEM_TYPE_LINUX


// check if we need to define a 64 bit value
// since the compiler does not support it natively
#ifdef COMPILER_SUPPORTS_INT64

// For Redhat 7.1, there will be conflicts if _LINUX_WAIT_H is defined
#if defined(SYSTEM_TYPE_LINUX)

// if Linux native compiler
#ifndef _LINUX_WAIT_H

typedef unsigned __int64 u64;
typedef unsigned __int64 U64;

#endif // _LINUX_WAIT_H

// Metrowerks compiler
#elif defined(__MWERKS__)

typedef unsigned long long u64;
typedef unsigned long long U64;

// Watcom compiler
#elif defined(__WATCOMC__)

typedef unsigned __int64 u64;
typedef unsigned __int64 U64;

// Microsoft Compilers
#elif defined(_MSC_VER)

typedef unsigned __int64 u64;
typedef unsigned __int64 U64;

// Unspecified
#else // SYSTEM_TYPE_LINUX

// Convey that this block is for documentation
#error Compilation entered documenation area (unsigned 64-bit definitions)

//---------------------------------------------------------------------
/**
 * Native data type unsigned 64-bit number (little endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
#define u64

//---------------------------------------------------------------------
/**
 * Structure to represent unsigned 64-bit number (little endian)
 * for compilers that do not support native 64-bit values;
 * It is assumed that native 32-bit values are supported which is
 * required for ANSI-C compliance. 
 */
//---------------------------------------------------------------------
typedef struct _u64
{
	/**
	 * 64 bit value consists of 2-32 bit values
	 * accessed as 32 bit values
	 */
	struct
	{
		/** The lower 32-bit value (little endian) */
		u32 lo;
		/** The higher 32-bit value (little endian) */
		u32 hi;
	} as32;
} u64;

//---------------------------------------------------------------------
/**
 * Native data type unsigned 64-bit number (big endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
#define U64

//---------------------------------------------------------------------
/**
 * Structure to represent unsigned 64-bit number (big endian)
 * for compilers that do not support native 64-bit values;
 * It is assumed that native 32-bit values are supported which is
 * required for ANSI-C compliance. 
 */
//---------------------------------------------------------------------
typedef struct _U64
{
	/**
	 * 64 bit value consists of 2-32 bit values
	 * accessed as 32 bit values
	 */
	struct
	{
		/** The lower 32-bit value (big endian) */
		U32 lo;
		/** The higher 32-bit value (big endian) */
		U32 hi;
	} as32;
} U64;

#endif // SYSTEM_TYPE_LINUX

//---------------------------------------------------------------------
/** 
 * Get the lower 32-bit value of an unsigned 64-bit number (little endian) 
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo)
 *
 * @param X [in] the 64-bit number
 */
//---------------------------------------------------------------------
#define GETu64LO32(X)		((u32)X)

//---------------------------------------------------------------------
/** 
 * Get the higher 32-bit value of an unsigned 64-bit number (little endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.hi)
 *
 * @param X [in] the 64-bit number
 */
//---------------------------------------------------------------------
#define GETu64HI32(X)		((u32)(X >> 32))

//---------------------------------------------------------------------
/**
 * Get the lower 32-bit value of an unsigned 64-bit number (big endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo)
 *
 * @param X [in] the 64-bit number
 */
//---------------------------------------------------------------------
#define GETU64LO32(X)		((U32)X)

//---------------------------------------------------------------------
/**
 * Get the higher 32-bit value of an unsigned 64-bit number (big endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.hi)
 *
 * @param X [in] the 64-bit number
 */
//---------------------------------------------------------------------
#define GETU64HI32(X)		((U32)(X >> 32))

//---------------------------------------------------------------------
/**
 * Set the lower 32-bit value of an unsigned 64-bit number (little endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo = lo)
 *
 * @param X [inout] the 64-bit number
 * @param lo [in] the lower value to set
 */
//---------------------------------------------------------------------
#define SETu64LO32(X, lo)	(X = ((X & 0xffffffff00000000) | lo))

//---------------------------------------------------------------------
/**
 * Set the higher 32-bit value of an unsigned 64-bit number (little endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.hi = hi)
 *
 * @param X [inout] the 64-bit number
 * @param hi [in] the higher value to set
 */
//---------------------------------------------------------------------
#define SETu64HI32(X, hi)	(X = ((X & 0x00000000ffffffff) | (hi << 32)))

//---------------------------------------------------------------------
/**
 * Set the lower 32-bit value of an unsigned 64-bit number (big endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo = lo)
 *
 * @param X [inout] the 64-bit number
 * @param lo [in] the lower value to set
 */
//---------------------------------------------------------------------
#define SETU64LO32(X, lo)	(X = ((X & 0xffffffff00000000) | lo))

//---------------------------------------------------------------------
/**
 * Set the higher 32-bit value of an unsigned 64-bit number (big endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.hi = hi)
 *
 * @param X [inout] the 64-bit number
 * @param hi [in] the higher value to set
 */
//---------------------------------------------------------------------
#define SETU64HI32(X, hi)	(X = ((X & 0x00000000ffffffff) | (hi << 32)))

//---------------------------------------------------------------------
/**
 * Set to zero value of an unsigned 64-bit number (little endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo = X.as32.hi = 0)
 *
 * @param X [inout] the 64-bit number
 */
//---------------------------------------------------------------------
#define ZEROu64(X)			(X = 0)

//---------------------------------------------------------------------
/**
 * Set to zero value of an unsigned 64-bit number (big endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo = X.as32.hi = 0)
 *
 * @param X [inout] the 64-bit number
 */
//---------------------------------------------------------------------
#define ZEROU64(X)			(X = 0)

#else //  COMPILER_SUPPORTS_INT64

// for compilers that do not support
// native 64 bit values we assume they
// at least support native 32 bit values
// which is required for ANSI-C compliance
typedef struct _u64
{
	// 64 bit value consists of 2-32 bit values
	// accessed as 32 bit values
	struct
	{
		u32 lo; // lo 32-bits
		u32 hi; // hi 32-bits
	} as32;
} u64;

typedef struct _U64
{
	// 64 bit value consists of 2-32 bit values
	// accessed as 32 bit values
	struct
	{
		U32 lo; // lo 32-bits
		U32 hi; // hi 32-bits
	} as32;
} U64;

// macros to get hi and low values
#define GETu64LO32(X)		(X.as32.lo)
#define GETu64HI32(X)		(X.as32.hi)

#define GETU64LO32(X)		(X.as32.lo)
#define GETU64HI32(X)		(X.as32.hi)

// macros to set hi and low values
#define SETu64LO32(X, lo)	(X.as32.lo = lo)
#define SETu64HI32(X, hi)	(X.as32.hi = hi)

#define SETU64LO32(X, lo)	(X.as32.lo = lo)
#define SETU64HI32(X, hi)	(X.as32.hi = hi)

// other helper macros
#define ZEROu64(X)			(X.as32.lo = X.as32.hi = 0)

#define ZEROU64(X)			(X.as32.lo = X.as32.hi = 0)

#endif //  COMPILER_SUPPORTS_INT64


// Signed

// For Redhat 7.1, there will be conflicts if _LINUX_WAIT_H is defined
#ifdef SYSTEM_TYPE_LINUX

#ifndef _LINUX_WAIT_H

typedef signed char s8; // there is no big endian byte
typedef signed short int s16;
typedef signed short int S16;
typedef signed int s32;
typedef signed int S32;
#endif // _LINUX_WAIT_H

#else // SYSTEM_TYPE_LINUX

//---------------------------------------------------------------------
/**
 * Native data type signed 8-bit number (little endian) no big endian byte form;
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
typedef signed char s8; // there is no big endian byte

//---------------------------------------------------------------------
/**
 * Native data type signed 16-bit number (little endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
typedef signed short int s16;

//---------------------------------------------------------------------
/**
 * Native data type signed 16-bit number (big endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
typedef signed short int S16;

//---------------------------------------------------------------------
/**
 * Native data type signed 32-bit number (little endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
typedef signed long s32;

//---------------------------------------------------------------------
/**
 * Native data type signed 32-bit number (big endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
typedef signed long S32;

#endif // SYSTEM_TYPE_LINUX


// check if we need to define a 64 bit value
// since the compiler does not support it natively
#ifdef COMPILER_SUPPORTS_INT64

// For Redhat 7.1, there will be conflicts if _LINUX_WAIT_H is defined
#if defined(SYSTEM_TYPE_LINUX)

#ifndef _LINUX_WAIT_H

typedef __int64 s64;
typedef __int64 S64;

#endif // _LINUX_WAIT_H

#elif defined(__MWERKS__)

typedef long long s64;
typedef long long S64;

// Watcom compiler
#elif defined(__WATCOMC__)

typedef __int64 s64;
typedef __int64 S64;

// Microsoft Compilers
#elif defined(_MSC_VER)

typedef __int64 s64;
typedef __int64 S64;

// Unspecified
#else // SYSTEM_TYPE_LINUX

// Convey that this block is for documentation
#error Compilation entered documenation area (signed 64-bit definitions)

//---------------------------------------------------------------------
/**
 * Native data type signed 64-bit number (little endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
#define s64

//---------------------------------------------------------------------
/**
 * Structure to represent signed 64-bit number (little endian)
 * for compilers that do not support native 64-bit values;
 * It is assumed that native 32-bit values are supported which is
 * required for ANSI-C compliance. 
 */
//---------------------------------------------------------------------
typedef struct _s64
{
	/**
	 * 64 bit value consists of 2-32 bit values
	 * accessed as 32 bit values
	 */
	struct
	{
		/** The lower "unsigned" 32-bit value (little endian) */
		u32 lo;
		/** The higher 32-bit value (little endian) */
		s32 hi;
	} as32;
} s64;

//---------------------------------------------------------------------
/**
 * Native data type signed 64-bit number (big endian);
 * Definition is OS dependent.
 */
//---------------------------------------------------------------------
#define S64

//---------------------------------------------------------------------
/**
 * Structure to represent signed 64-bit number (big endian)
 * for compilers that do not support native 64-bit values;
 * It is assumed that native 32-bit values are supported which is
 * required for ANSI-C compliance. 
 */
//---------------------------------------------------------------------
typedef struct _S64
{
	/**
	 * 64 bit value consists of 2-32 bit values
	 * accessed as 32 bit values
	 */
	struct
	{
		/** The lower "unsigned" 32-bit value (big endian) */
		U32 lo;
		/** The higher 32-bit value (big endian) */
		S32 hi;
	} as32;
} S64;

#endif // SYSTEM_TYPE_LINUX

//---------------------------------------------------------------------
/**
 * Get the lower 32-bit value of an signed 64-bit number (little endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo)
 *
 * @param X [in] the 64-bit number
 */
//---------------------------------------------------------------------
#define GETs64LO32(X)		((s32)X)

//---------------------------------------------------------------------
/**
 * Get the higher 32-bit value of an signed 64-bit number (little endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.hi)
 *
 * @param X [in] the 64-bit number
 */
//---------------------------------------------------------------------
#define GETs64HI32(X)		((s32)(X >> 32))

//---------------------------------------------------------------------
/**
 * Get the lower 32-bit value of an signed 64-bit number (big endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo)
 *
 * @param X [in] the 64-bit number
 */
//---------------------------------------------------------------------
#define GETS64LO32(X)		((S32)X)

//---------------------------------------------------------------------
/**
 * Get the higher 32-bit value of an signed 64-bit number (big endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.hi)
 *
 * @param X [in] the 64-bit number
 */
//---------------------------------------------------------------------
#define GETS64HI32(X)		((S32)(X >> 32))

//---------------------------------------------------------------------
/**
 * Set the lower 32-bit value of an signed 64-bit number (little endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo = Y)
 *
 * @param X [inout] the 64-bit number
 * @param Y [in] the lower value to set
 */
//---------------------------------------------------------------------
#define SETs64LO32(X, Y)	(X = Y)

//---------------------------------------------------------------------
/**
 * Set the higher 32-bit value of an signed 64-bit number (little endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.hi = Y)
 *
 * @param X [inout] the 64-bit number
 * @param Y [in] the higher value to set
 */
//---------------------------------------------------------------------
#define SETs64HI32(X, Y)	(X = (Y << 32))

//---------------------------------------------------------------------
/**
 * Set the lower 32-bit value of an signed 64-bit number (big endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo = Y)
 *
 * @param X [inout] the 64-bit number
 * @param Y [in] the lower value to set
 */
//---------------------------------------------------------------------
#define SETS64LO32(X, Y)	(X = Y)

//---------------------------------------------------------------------
/**
 * Set the higher 32-bit value of an signed 64-bit number (big endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.hi = Y)
 *
 * @param X [inout] the 64-bit number
 * @param Y [in] the higher value to set
 */
//---------------------------------------------------------------------
#define SETS64HI32(X, Y)	(X = (Y << 32))

//---------------------------------------------------------------------
/**
 * Set to zero value of an signed 64-bit number (little endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo = X.as32.hi = 0)
 *
 * @param X [inout] the 64-bit number
 */
//---------------------------------------------------------------------
#define ZEROs64(X)			(X = 0)

//---------------------------------------------------------------------
/**
 * Set to zero value of an signed 64-bit number (big endian)
 * For compilers that do not support native 64-bit values:
 * (X.as32.lo = X.as32.hi = 0)
 *
 * @param X [inout] the 64-bit number
 */
//---------------------------------------------------------------------
#define ZEROS64(X)			(X = 0)

#else //  COMPILER_SUPPORTS_INT64

// for compilers that do not support
// native 64 bit values we assume they
// at least support native 32 bit values
// which is required for ANSI-C compliance
typedef struct _s64
{
	// 64 bit value consists of 2-32 bit values
	// accessed as 32 bit values
	struct
	{
		u32 lo; // lo 32-bits NOTE: lower portion is unsigned
		s32 hi; // hi 32-bits
	} as32;
} s64;

typedef struct _S64
{
	// 64 bit value consists of 2-32 bit values
	// accessed as 32 bit values
	struct
	{
		U32 lo; // lo 32-bits NOTE: lower portion is unsigned
		S32 hi; // hi 32-bits
	} as32;
} S64;

// macros to get hi and low values
#define GETs64LO32(X)		(X.as32.lo)
#define GETs64HI32(X)		(X.as32.hi)

#define GETS64LO32(X)		(X.as32.lo)
#define GETS64HI32(X)		(X.as32.hi)

// macros to set hi and low values
#define SETs64LO32(X, Y)	(X.as32.lo = Y)
#define SETs64HI32(X, Y)	(X.as32.hi = Y)

#define SETS64LO32(X, Y)	(X.as32.lo = Y)
#define SETS64HI32(X, Y)	(X.as32.hi = Y)

// other helper macros
#define ZEROs64(X)			(X.as32.lo = X.as32.hi = 0)

#define ZEROS64(X)			(X.as32.lo = X.as32.hi = 0)

#endif //  COMPILER_SUPPORTS_INT64


//---------------------------------------------------------------------
/** Data type Boolean definition */
//---------------------------------------------------------------------
typedef short int booln; // NOTE: DO NO CHANGE. HAPI will not work

//---------------------------------------------------------------------
/**
 * Data type 64-bit double (little endian) definition
 * The floating point precision is 15 digits and always signed
 */
//---------------------------------------------------------------------
typedef double d64; // the floating point precision is 15 digits and always signed

//---------------------------------------------------------------------
/**
 * Data type 64-bit double (big endian) definition
 * The floating point precision is 15 digits and always signed
 */
//---------------------------------------------------------------------
typedef double D64; // the floating point precision is 15 digits and always signed

//---------------------------------------------------------------------
/** Data type UTF-8 (ASCIIZ) string definition */
//---------------------------------------------------------------------
typedef char astring; // the data type for ASCIIZ string

//---------------------------------------------------------------------
/** Data type UCS-2 (Unicode) string definition */
//---------------------------------------------------------------------
#if defined (BUILTIN_WCHAR_T)
typedef wchar_t ustring;			// the C++ data type for unicode string
#else
typedef unsigned short int ustring; // the C data type for unicode string
#endif
//---------------------------------------------------------------------
/**
 * Structure to represent the string form of IP Addresses
 */
//---------------------------------------------------------------------
typedef struct _IPAddrStr
{
	/** The string representation of an IP address */
	astring az[MAX_IPADDR_SIZE];
} IPAddrStr;


//---------------------------------------------------------------------
/** 
 * String constant for native data width; Value depends on NATIVE_DATA_WIDTH.
 */
//---------------------------------------------------------------------
#if (NATIVE_DATA_WIDTH == 64)
#define NATIVE_DATA_WIDTH_STR			"64"
#elif (NATIVE_DATA_WIDTH == 32)
#define NATIVE_DATA_WIDTH_STR			"32"
#elif (NATIVE_DATA_WIDTH == 16)
#define NATIVE_DATA_WIDTH_STR			"16"
#endif // (NATIVE_DATA_WIDTH == 64)


//---------------------------------------------------------------------
//
// Standard library naming templates
//
//---------------------------------------------------------------------

#if defined(SYSTEM_TYPE_LINUX)

#define LIBNAME_PREFIX		"lib"
#define LIBNAME_EXT			".so"
#define LIBNAME_SUFFIX		NATIVE_DATA_WIDTH_STR LIBNAME_EXT

#elif defined(SYSTEM_TYPE_NETWARE)

#define LIBNAME_PREFIX		""
#define LIBNAME_EXT			".nlm"
#define LIBNAME_SUFFIX		NATIVE_DATA_WIDTH_STR LIBNAME_EXT

#elif defined(SYSTEM_TYPE_WINNT)

#define LIBNAME_PREFIX		""
#define LIBNAME_EXT			".dll"
#define LIBNAME_SUFFIX		NATIVE_DATA_WIDTH_STR LIBNAME_EXT

#elif defined(SYSTEM_TYPE_OS2)

#elif defined(SYSTEM_TYPE_DOS)

#else // unspecified system type

// Convey that this block is for documentation
#error Compilation entered documenation area (libname definitions)

/** String constant for Library Name Prefix; Value depends on system type. */
#define LIBNAME_PREFIX
/** String constant for Library Name Extension; Value depends on system type. */
#define LIBNAME_EXT
/** String constant for Library Name Suffix; Value depends on system type. */
#define LIBNAME_SUFFIX

#endif // system type


#ifdef __cplusplus
}
#endif

#endif  // __DCDETYPES_H_INCLUDED__



//---------------------------------------------------------------------
// Systems Management API interface definitions
//---------------------------------------------------------------------
#ifndef SMINTF

#ifdef __cplusplus
extern "C" {
#endif

// detect if exporting or importing APIs
#ifdef __EXPORTING

// means it is exporting
// detect if compile for static or dynamic lib
#ifdef SM_LIB_STATIC

// use as normal statically linked function
#define SMINTF

#else // SM_LIB_STATIC

#ifdef SYSTEM_TYPE_WINNT

// use as dynamically linked function with this module exporting
#define SMINTF __declspec(dllexport)

#endif // SYSTEM_TYPE_WINNT

#ifdef SYSTEM_TYPE_NETWARE

// use as dynamically linked function with this module exporting NOTE: exported by .imp/.exp files
#define SMINTF

#endif // SYSTEM_TYPE_NETWARE

#ifdef SYSTEM_TYPE_LINUX

// use as dynamically linked function with this module exporting
#define SMINTF

#endif // SYSTEM_TYPE_LINUX

#ifdef SYSTEM_TYPE_OS2

// use as dynamically linked function with this module exporting
#define SMINTF

#endif // SYSTEM_TYPE_OS2

#ifdef SYSTEM_TYPE_DOS

// use as dynamically linked function with this module exporting
#define SMINTF

#endif // SYSTEM_TYPE_DOS

#endif // SM_LIB_STATIC

#else // __EXPORTING

// means it is importing
// detect if compile for static or dynamic lib
#ifdef SM_LIB_STATIC

// use as normal statically linked function
#define SMINTF

#else // SM_LIB_STATIC

#if defined(SYSTEM_TYPE_WINNT)

// use as dynamically linked function with this module importing
#define SMINTF __declspec(dllimport)

#elif defined(SYSTEM_TYPE_NETWARE)

// use as dynamically linked function with this module importing NOTE: imported by .imp/.exp files
#define SMINTF

#elif defined(SYSTEM_TYPE_LINUX)

// use as dynamically linked function with this module importing
#define SMINTF

#elif defined(SYSTEM_TYPE_OS2)

// use as dynamically linked function with this module importing
#define SMINTF

#elif defined(SYSTEM_TYPE_DOS)

// use as dynamically linked function with this module importing
#define SMINTF

#else  // unspecified system type

// Convey that this block is for documentation
#error Compilation entered documenation area (SMINTF definition)

//---------------------------------------------------------------------
/**
 * SMINTF is the export/import wrapper and macro definition;
 * This is outside this header's enclosing definition to allow for
 * multiple include within a single source file depending on the 
 * export or import encapsulation need; Define __EXPORTING to indicate
 * export mode; Define SM_LIB_STATIC to indicate target definitions
 * originate from a library that will be statically linked.
 */
//---------------------------------------------------------------------
#define SMINTF

#endif // system type

#endif // SM_LIB_STATIC

#endif // __EXPORTING

#ifdef __cplusplus
}
#endif

#endif // SMINTF



//---------------------------------------------------------------------
// End
//---------------------------------------------------------------------

