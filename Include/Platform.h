#pragma once

namespace Ratchet
{

#if defined(_MSC_VER)

	typedef signed char int8;
	typedef short int16;
	typedef int int32;
	typedef __int64 int64;
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned __int64 uint64;

#if defined(_M_X64) || defined(_M_ARM64)

	typedef __int64 machine;
	typedef unsigned __int64 umachine;
	typedef unsigned __int64 machine_address;

#else

	typedef int machine;
	typedef unsigned int umachine;
	typedef unsigned int machine_address;

#endif

#define RESTRICT __restrict

#pragma warning(disable : 4100) // unreferenced formal parameter
#pragma warning(disable : 4244) // conversion, possible loss of data
#pragma warning(disable : 4324) // structure was padded due to alignment specifier
#pragma warning(disable : 4458) // declaration hides class member
#pragma warning(disable : 4522) // multiple assignment operators specified

#elif defined(__ORBIS__) || defined(__PROSPERO__)

	typedef signed char int8;
	typedef short int16;
	typedef int int32;
	typedef long int64;
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned long uint64;
	typedef long machine;
	typedef unsigned long umachine;
	typedef unsigned long machine_address;

#elif defined(__GNUC__)

	typedef signed char int8;
	typedef short int16;
	typedef int int32;
	typedef long long int64;
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned long long uint64;

#if defined(__LP64__) || defined(_WIN64)

	typedef long long machine;
	typedef unsigned long long umachine;
	typedef unsigned long long machine_address;

#else

	typedef int machine;
	typedef unsigned int umachine;
	typedef unsigned int machine_address;

#endif

#if !defined(restrict)

#define RESTRICT __restrict__

#endif

#elif defined(__SWITCH__)

	typedef signed char int8;
	typedef short int16;
	typedef int int32;
	typedef long long int64;
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned long long uint64;
	typedef long long machine;
	typedef unsigned long long umachine;
	typedef unsigned long long machine_address;

#elif defined(__clang__)

	typedef signed char int8;
	typedef short int16;
	typedef int int32;
	typedef long long int64;
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned long long uint64;

#if defined(__LP64__) || defined(_WIN64)

	typedef long long machine;
	typedef unsigned long long umachine;
	typedef unsigned long long machine_address;

#else

	typedef int machine;
	typedef unsigned int umachine;
	typedef unsigned int machine_address;

#endif

#if !defined(restrict)

#define RESTRICT __restrict__

#endif

#else

#error "Unsupported compiler"

#endif
}