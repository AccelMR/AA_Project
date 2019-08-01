#pragma once


/************************************************************************/
/**
 * Initial platform/compiler-related stuff to set.
*/
/************************************************************************/
#define SW_PLATFORM_WIN32   1                  //Windows Platform
#define SW_PLATFORM_LINUX   2                  //Linux Platform
#define SW_PLATFORM_OSX     3


#define SW_COMPILER_MSVC    1                  //Visual Studio Compiler
#define SW_COMPILER_GNUC    2                  //GCC Compiler
#define SW_COMPILER_INTEL   3                  //Intel Compiler
#define SW_COMPILER_CLANG   4                  //Clang Compiler

#define SW_ARCHITECTURE_X86_32 1               //Intel x86 32 bits
#define SW_ARCHITECTURE_X86_64 2               //Intel x86 64 bits

#define SW_ENDIAN_LITTLE  1
#define SW_ENDIAN_BIG     2

//Define the actual endian type (little endian for Windows, Linux, Apple and PS4)
#define SW_ENDIAN SW_ENDIAN_LITTLE

#define SW_VERSION_MAJOR    0                 //Engine verion major
#define SW_VERSION_MINIOR   1
#define SW_VERSION_PATCH    0
#define SW_VERSION_BUILD    1

//Define if on crach a we want to report warnings on unknown symbols
#define SW_DEBUG_DETAILED_SYMBOLS   1

/************************************************************************/
/**
 * Compiler type and version
 */
 /************************************************************************/

#if defined(__clang__)
#   define SW_COMPILER SW_COMPILER_CLANG
#   define SW_COMP_VER __cland_version__
#   define SW_THREADLOCAL __thread
#   define SW_STDCALL __attribute__((stdcall))
#   define SW_CDECL __attribute__((cdecl))
#   define SW_FALLTHROUHG [[clang::fallthrough]];
#elif defined (__GNUC__) //Check after Cland, as Clang defines this too
#   define SW_COMPILER SW_COMPILER_GNUC
#   define SW_COMP_VER (((__GNUC__)*100)+(__GNUC_MINOR__*10)+__GNUC_PATCHLEVEL__)
#   define SW_THREADLOCAL __thread
#   define SW_STDCALL __attribute__((stdcall))
#   define SW_CDECL __attribute__((cdecl))
#   define SW_FALLTHROUHG __attribute__((fallthrough));
#elif defined (__INTEL_COMPILER)
#   define SW_COMPILER SW_COMPILER_INTEL
#   define SW_COMP_VER __INTEL_COMPILER
#   define SW_STDCALL __stdcall
#   define SW_CDECL __cdecl
#   define SW_FALLTHROUHG 

/**
 * SW_THREADLOCAL define is down below because Intel compiler defines it
 * differently based on platform
 */

 //Check after Clang end Intel, we could be building with either with Vs
#elif defined (_MSC_VER)
#   define SW_COMPILER SW_COMPILER_MSVC
#   define SW_COMP_VER _MSC_VER
#   define SW_THREADLOCAL __declspec
#   define SW_STDCALL __stdcall
#   define SW_CDECL __cdecl
#   define SW_FALLTHROUHG
#   undef __PRETTY_FUNCTION__
#   define __PRETTY_FUNCTION__ __FUNCSIG__
#else
//No know compiler found, send the error to the ourput (if any)
#   pragma error "No known compuler. "
#endif

/************************************************************************/
/**
 * See if we can use __forceinline or if we need to use __inline insted
 */
 /************************************************************************/
#if SW_COMPILER == SW_COMPILER_MSVC
# if SW_COMP_VER >= 1200
#   define FORCEINLINE __forceinline
#   ifndef RESTRICT 
#     define RESTRICT __restrict
#   endif
# endif
#elif defined (__MINGW32__)
# if !defined (FORCEINLINE)
#   define FORCEINLINE __inline
#   ifndef RESTRICT
#     define RESTRICT
#   endif
# endif
#else
# define FORCEINLINE __inline
# ifndef RESTRICT
#   define RESTRICT __restrict
# endif
#endif

/************************************************************************/
/**
 * Finds the current platform
 */
 /************************************************************************/
#if defined (__WIN32__) || defined (_WIN32)
# define SW_PLATFORM SW_PLATFORM_WIN32
#elif defined (__APPLE_CC__ )
# define SW_PLATFORM SW_PLATFORM_OSX
#elif defined (__ORBIS__)
# define SW_PLATFORM SW_PLATFORM_LINUX
#endif

/************************************************************************/
/**
 * Find the architecture type
 */
 /************************************************************************/
#if defined (__x86_x64__) || defined(_M_X64)    //If this is a x64 compile
# define SW_ARCH_TYPE SW_ARCHITECTURE_X86_64
#else
#  define SW_ARCH_TYPE SW_ARCHITECTURE_X86_32
#endif

/************************************************************************/
/**
 * Memory Alignment macros
 */
 /************************************************************************/
#if SW_COMPILER == SW_COMPILER_MSVC
# define MS_ALIGN(n) __declspec(align(n))
# ifndef GCC_PACK
#   define GCC_PACK(n)
# endif
# ifndef GCC_ALIGN
#   define GCC_ALIGN(n)
# endif
#elif (SW_COMPILER == SW_COMPILER_GNUC)
# define MS_ALIGN(n)
# define GCC_PACK(n)
# define GCC_ALIGN(n) __attribute__( (__aligned__(n)) )
#else
# define MS_ALIGN(n)
# define GCC_PACK(n) __attribute__((packed, aligned(n)))
# define GCC_ALIGN(n) __attribute__( (__aligned__(n)) )
#endif

/************************************************************************/
/**
 * For throw override (deprecated on c++11 but VS does not have handle )
 */
 /************************************************************************/
#if SW_COMPILER == SW_COMPILER_MSVC
# define _NOEXCEPT noexcept
#elif SW_COMPILER == SW_COMPILER_INTEL
# define _NOEXCEPT noexcept
#elif SW_COMPILER == SW_COMPILER_GNUC
# define _NOEXCEPT noexcept
#else
# define _NOEXCEPT
#endif

/************************************************************************/
/**
 * Library export specifics
 */
 /************************************************************************/
#if SW_PLATFORM == SW_PLATFORM_WIN32
# if SW_COMPILER == SW_COMPILER_MSVC
#   if defined( SW_STATIC_lib )
#     define SW_UTILITY_EXPORT
#   else
#     if defined ( SW_UTILITY_EXPORTS )
#       define SW_UTILITY_EXPORT __declspec( dllexport )
#     else
#       define SW_UTILITY_EXPORT __declspec( dllimport )
#     endif
#   endif
# else //Any other compiler
#   if defined( SW_STATIC_LIB )
#     define SW_UTILITY_EXPORT
#   else
#     if defined( SW_UTILITY_EXPORTS )
#       define SW_UTILITY_EXPORT __attribute__ ((dllexport))
#     else
#       define SW_UTILITY_EXPORT __attribute__ ((dllimport))
#     endif
#   endif
# endif
# define SW_UTILITY_HIDDEN
#else
# define SW_UTILITY_EXPORT __attribute__ ((visibility ("default")))
# define SW_UTILITY_HIDDEN __attribute__ ((visibility ("hidden")))
#endif

 //DLL export plugins
#if SW_PLATFORM == SW_PLATFORM_WIN32
# if SW_COMPILER == SW_COMPILER_MSVC
#   define SW_PLUGIN_EXPORT __declspec(dllexport)
# else
#   define SW_PLUGIN_EXPORT __attribute__ ((dllexport))
# endif
#else
#  define SW_PLUGIN_EXPORT __attribute__((visibility("default")))
#endif

/************************************************************************/
/**
 * Window specific Settings
 */
 /************************************************************************/
 //Win32
#if SW_PLATFORM == SW_PLATFORM_WIN32
# if defined(_DEBUG) || defined(DEBUG)
#   define SW_DEBUG_MODE 1
# else
#   define SW_DEBUG_MODE 0
# endif
# if SW_COMPILER == SW_COMPILER_INTEL
#   define SW_THREADLOCAL __declspec(thread)
# endif
#endif //SW_PLATFORM

/************************************************************************/
/**
 * LINUX-Apple specific Settings
 */
 /************************************************************************/

 //
#if SW_PLATFORM == SW_PLATFORM_LINUX || SW_PLATFORM == SW_PLATFORM_OSX

//if we're on debug mode
# if defined(_DEBUG) || defined(DEBUG)
#   define SW_DEBUG_MODE 1
# else
#   define SW_DEBUG_MODE 0
# endif
# if SW_COMPILER == SW_COMPILER_INTEL
#   define SW_THREADLOCAL thread
# endif
#endif //SW_PLATFORM

/************************************************************************/
/**
 * DEfinition of DEbug macros
 */
 /************************************************************************/
#if SW_DEBUG_MODE
# define SW_DEBUG_ONLY(x) x
# define SW_ASSERT(x) assert(x)
#else
# define SW_DEBUG_ONLY(x)
# define SW_ASSERT(x)
#endif

/************************************************************************/
/**
 * Disable some compiler warnings
 */
 /************************************************************************/

 //If we are compiling with VS
#if SW_COMPILER == SW_COMPILER_MSVC

# define _CRT_SECURE_NO_WARNINGS

# pragma warning(disable : 4201)

# pragma warning(disable : 4996)

# pragma warning(disable : 4251)

# pragma warning(disable : 4503)

#endif