

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

 /**********************************************************************************************************************
  *  GLOBAL CONSTANT MACROS
  *********************************************************************************************************************/

  /* ##V_CFG_MANAGEMENT ##CQProject : CommonAsr_Tricore CQComponent : Impl_PlatformTypes */
#define COMMONASR_TRICORE_IMPL_PLATFORMTYPES_VERSION 0x0203
#define COMMONASR_TRICORE_IMPL_PLATFORMTYPES_RELEASE_VERSION 0x01


#define PLATFORM_VENDOR_ID    30u    /* SREQ00015439, SREQ00015413 */
#define PLATFORM_MODULE_ID    199u   /* SREQ00015439, SREQ00015413 */


/* AUTOSAR Software Specification Document Version Information */

/* AUTOSAR release 4.0 R3 */
#   define PLATFORM_AR_RELEASE_MAJOR_VERSION      (4u)
#   define PLATFORM_AR_RELEASE_MINOR_VERSION      (0u)
#   define PLATFORM_AR_RELEASE_REVISION_VERSION   (3u)

/* Component Version Information */
#define PLATFORM_SW_MAJOR_VERSION       (2u)
#define PLATFORM_SW_MINOR_VERSION       (2u)
#define PLATFORM_SW_PATCH_VERSION       (0u) 


#define CPU_TYPE_8       8u
#define CPU_TYPE_16      16u
#define CPU_TYPE_32      32u

#define MSB_FIRST        0u    /* big endian bit ordering */
#define LSB_FIRST        1u    /* little endian bit ordering */

#define HIGH_BYTE_FIRST  0u    /* big endian byte ordering */
#define LOW_BYTE_FIRST   1u    /* little endian byte ordering */

#ifndef TRUE
#define TRUE   1u
#endif

#ifndef FALSE
#define FALSE  0u
#endif

#define CPU_TYPE         CPU_TYPE_32

#define CPU_BIT_ORDER    LSB_FIRST        /*little endian bit ordering*/

#define CPU_BYTE_ORDER   LOW_BYTE_FIRST   /*little endian byte ordering*/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/



 /**********************************************************************************************************************
  *  GLOBAL DATA TYPES AND STRUCTURES
  *********************************************************************************************************************/

typedef unsigned char         boolean;       /*        TRUE .. FALSE           */

typedef signed char           sint8;         /*        -128 .. +127            */
typedef unsigned char         uint8;         /*           0 .. 255             */
typedef signed short          sint16;        /*      -32768 .. +32767          */
typedef unsigned short        uint16;        /*           0 .. 65535           */
typedef signed long           sint32;        /* -2147483648 .. +2147483647     */
typedef unsigned long         uint32;        /*           0 .. 4294967295      */

typedef signed char           sint8_least;   /* At least 7 bit + 1 bit sign    */
typedef unsigned char         uint8_least;   /* At least 8 bit                 */
typedef signed short          sint16_least;  /* At least 15 bit + 1 bit sign   */
typedef unsigned short        uint16_least;  /* At least 16 bit                */
typedef signed long           sint32_least;  /* At least 31 bit + 1 bit sign   */
typedef unsigned long         uint32_least;  /* At least 32 bit                */


#if defined(__TASKING__)  /* valid for Tasking */
# if (__STDC_VERSION__ >= 199901L) /* ISO-C version is C99 or higher*/
#define PLATFORM_SUPPORT_SINT64_UINT64
typedef signed    long long  sint64;   /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long  uint64;   /*                    0 .. 18446744073709551615     */
# endif
#else /* valid for GNU and Diab*/
#define PLATFORM_SUPPORT_SINT64_UINT64
typedef signed    long long  sint64;   /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long  uint64;   /*                    0 .. 18446744073709551615     */
#endif

typedef float                 float32;
typedef double                float64;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


 /**********************************************************************************************************************
  *  GLOBAL FUNCTION PROTOTYPES
  *********************************************************************************************************************/


#endif  /* PLATFORM_TYPES_H */

  /**********************************************************************************************************************
   *  END OF FILE: Platform_Types.h
   *********************************************************************************************************************/
