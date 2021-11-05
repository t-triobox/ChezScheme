/* scheme.h for Chez Scheme Version 9.5.7 (a6le) */

/* Do not edit this file.  It is automatically generated and */
/* specifically tailored to the version of Chez Scheme named */
/* above.  Always be certain that you have the correct scheme.h */
/* for the version of Chez Scheme you are using. */

/* Warning: Some macros may evaluate arguments more than once. */

/* Enable function prototypes by default. */
#ifndef PROTO
#define PROTO(x) x
#endif

/* Specify declaration of exports. */
#ifdef _WIN32
#  if __cplusplus
#    ifdef SCHEME_IMPORT
#      define EXPORT extern "C" __declspec (dllimport)
#    elif SCHEME_STATIC
#      define EXPORT extern "C"
#    else
#      define EXPORT extern "C" __declspec (dllexport)
#    endif
#  else
#    ifdef SCHEME_IMPORT
#      define EXPORT extern __declspec (dllimport)
#    elif SCHEME_STATIC
#      define EXPORT extern
#    else
#      define EXPORT extern __declspec (dllexport)
#    endif
#  endif
#else
#  if __cplusplus
#    define EXPORT extern "C"
#  else
#    define EXPORT extern
#  endif
#endif

/* Chez Scheme Version and machine type */
#define VERSION "9.5.7"
#define MACHINE_TYPE "a6le"

/* All Scheme objects are of type ptr.  Type iptr and */
/* uptr are signed and unsigned ints of the same size */
/* as a ptr */
typedef void * ptr;
typedef long int iptr;
typedef unsigned long int uptr;

/* String elements are 32-bit tagged char objects */
typedef unsigned int string_char;

/* Bytevector elements are 8-bit unsigned "octets" */
typedef unsigned char octet;

/* Type predicates */
#define Sfixnump(x) (((uptr)(x)&0x7)==0x0)
#define Scharp(x) (((uptr)(x)&0xFF)==0x16)
#define Snullp(x) ((uptr)(x)==0x26)
#define Seof_objectp(x) ((uptr)(x)==0x36)
#define Sbwp_objectp(x) ((uptr)(x)==0x4E)
#define Sbooleanp(x) (((uptr)(x)&0xF7)==0x6)
#define Spairp(x) (((uptr)(x)&0x7)==0x1)
#define Ssymbolp(x) (((uptr)(x)&0x7)==0x3)
#define Sprocedurep(x) (((uptr)(x)&0x7)==0x5)
#define Sflonump(x) (((uptr)(x)&0x7)==0x2)
#define Svectorp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)((uptr)(x)+1))))&0x7)==0x0))
#define Sfxvectorp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)((uptr)(x)+1))))&0x7)==0x3))
#define Sbytevectorp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)((uptr)(x)+1))))&0x3)==0x1))
#define Sstringp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)((uptr)(x)+1))))&0x7)==0x2))
#define Sbignump(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)((uptr)(x)+1))))&0x1F)==0x6))
#define Sboxp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)((uptr)(x)+1))))&0x7F)==0xE))
#define Sinexactnump(x) ((((uptr)(x)&0x7)==0x7) &&\
    ((uptr)((*((ptr *)((uptr)(x)+1))))==0x36))
#define Sexactnump(x) ((((uptr)(x)&0x7)==0x7) &&\
    ((uptr)((*((ptr *)((uptr)(x)+1))))==0x56))
#define Sratnump(x) ((((uptr)(x)&0x7)==0x7) &&\
    ((uptr)((*((ptr *)((uptr)(x)+1))))==0x16))
#define Sinputportp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)((uptr)(x)+1))))&0x1FF)==0x11E))
#define Soutputportp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)((uptr)(x)+1))))&0x2FF)==0x21E))
#define Srecordp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)((uptr)(x)+1))))&0x7)==0x7))

/* Accessors */
#define Sfixnum_value(x) ((iptr)(x)/8)
#define Schar_value(x) ((string_char)((uptr)(x)>>8))
#define Sboolean_value(x) ((x) != Sfalse)
#define Scar(x) (*((ptr *)((uptr)(x)+7)))
#define Scdr(x) (*((ptr *)((uptr)(x)+15)))
#define Sflonum_value(x) (*((double *)((uptr)(x)+6)))
#define Svector_length(x) ((iptr)((uptr)(*((iptr *)((uptr)(x)+1)))>>4))
#define Svector_ref(x,i) (((ptr *)((uptr)(x)+9))[i])
#define Sfxvector_length(x) ((iptr)((uptr)(*((iptr *)((uptr)(x)+1)))>>4))
#define Sfxvector_ref(x,i) (((ptr *)((uptr)(x)+9))[i])
#define Sbytevector_length(x) ((iptr)((uptr)(*((iptr *)((uptr)(x)+1)))>>3))
#define Sbytevector_u8_ref(x,i) (((octet *)((uptr)(x)+9))[i])
/* Warning: Sbytevector_data(x) returns a pointer into x. */
#define Sbytevector_data(x) &Sbytevector_u8_ref(x,0)
#define Sstring_length(x) ((iptr)((uptr)(*((iptr *)((uptr)(x)+1)))>>4))
#define Sstring_ref(x,i) Schar_value(((string_char *)((uptr)(x)+9))[i])
#define Sunbox(x) (*((ptr *)((uptr)(x)+9)))
EXPORT iptr Sinteger_value PROTO((ptr));
#define Sunsigned_value(x) (uptr)Sinteger_value(x)
EXPORT int Sinteger32_value PROTO((ptr));
#define Sunsigned32_value(x) (unsigned int)Sinteger32_value(x)
EXPORT long Sinteger64_value PROTO((ptr));
#define Sunsigned64_value(x) (unsigned long)Sinteger64_value(x)

/* Mutators */
EXPORT void Sset_box PROTO((ptr, ptr));
EXPORT void Sset_car PROTO((ptr, ptr));
EXPORT void Sset_cdr PROTO((ptr, ptr));
#define Sstring_set(x,i,c) ((void)((((string_char *)((uptr)(x)+9))[i]) = (string_char)(uptr)Schar(c)))
#define Sfxvector_set(x,i,n) ((void)(Sfxvector_ref(x,i) = (n)))
#define Sbytevector_u8_set(x,i,n) ((void)(Sbytevector_u8_ref(x,i) = (n)))
EXPORT void Svector_set PROTO((ptr, iptr, ptr));

/* Constructors */
#define Sfixnum(x) ((ptr)(uptr)((x)*8))
#define Schar(x) ((ptr)(uptr)((x)<<8|0x16))
#define Snil ((ptr)0x26)
#define Strue ((ptr)0xE)
#define Sfalse ((ptr)0x6)
#define Sboolean(x) ((x)?Strue:Sfalse)
#define Sbwp_object ((ptr)0x4E)
#define Seof_object ((ptr)0x36)
#define Svoid ((ptr)0x3E)
EXPORT ptr Scons PROTO((ptr, ptr));
EXPORT ptr Sstring_to_symbol PROTO((const char *));
EXPORT ptr Ssymbol_to_string PROTO((ptr));
EXPORT ptr Sflonum PROTO((double));
EXPORT ptr Smake_vector PROTO((iptr, ptr));
EXPORT ptr Smake_fxvector PROTO((iptr, ptr));
EXPORT ptr Smake_bytevector PROTO((iptr, int));
EXPORT ptr Smake_string PROTO((iptr, int));
EXPORT ptr Smake_uninitialized_string PROTO((iptr));
EXPORT ptr Sstring PROTO((const char *));
EXPORT ptr Sstring_of_length PROTO((const char *, iptr));
EXPORT ptr Sstring_utf8 PROTO((const char*, iptr));
EXPORT ptr Sbox PROTO((ptr));
EXPORT ptr Sinteger PROTO((iptr));
EXPORT ptr Sunsigned PROTO((uptr));
EXPORT ptr Sinteger32 PROTO((int));
EXPORT ptr Sunsigned32 PROTO((unsigned int));
EXPORT ptr Sinteger64 PROTO((long));
EXPORT ptr Sunsigned64 PROTO((unsigned long));

/* Miscellaneous */
EXPORT ptr Stop_level_value PROTO((ptr));
EXPORT void Sset_top_level_value PROTO((ptr, ptr));
EXPORT void Slock_object PROTO((ptr));
EXPORT void Sunlock_object PROTO((ptr));
EXPORT int Slocked_objectp PROTO((ptr));
EXPORT void Sforeign_symbol PROTO((const char *, void *));
EXPORT void Sregister_symbol PROTO((const char *, void *));

/* Support for calls into Scheme */
EXPORT ptr Scall0 PROTO((ptr));
EXPORT ptr Scall1 PROTO((ptr, ptr));
EXPORT ptr Scall2 PROTO((ptr, ptr, ptr));
EXPORT ptr Scall3 PROTO((ptr, ptr, ptr, ptr));
EXPORT void Sinitframe PROTO((iptr));
EXPORT void Sput_arg PROTO((iptr, ptr));
EXPORT ptr Scall PROTO((ptr, iptr));
/* Warning: Sforeign_callable_entry_point(x) returns a pointer into x. */
#define Sforeign_callable_entry_point(x) ((void (*) PROTO((void)))((uptr)(x)+65))
#define Sforeign_callable_code_object(x) ((ptr)((uptr)(x)-65))

/* Customization support. */
EXPORT const char * Skernel_version PROTO((void));
EXPORT void Sretain_static_relocation PROTO((void));
EXPORT void Sset_verbose PROTO((int));
EXPORT void Sscheme_init PROTO((void (*)(void)));
EXPORT void Sregister_boot_file PROTO((const char *));
EXPORT void Sregister_boot_file_fd PROTO((const char *, int fd));
EXPORT void Sregister_heap_file PROTO((const char *));
EXPORT void Scompact_heap PROTO((void));
EXPORT void Ssave_heap PROTO((const char *, int));
EXPORT void Sbuild_heap PROTO((const char *, void (*)(void)));
EXPORT void Senable_expeditor PROTO((const char *));
EXPORT int Sscheme_start PROTO((int, const char *[]));
EXPORT int Sscheme_script PROTO((const char *, int, const char *[]));
EXPORT int Sscheme_program PROTO((const char *, int, const char *[]));
EXPORT void Sscheme_deinit PROTO((void));

/* Features. */
#define FEATURE_ICONV
#define FEATURE_EXPEDITOR

/* Locking macros. */
#define INITLOCK(addr)     \
  __asm__ __volatile__ ("movq $0, (%0)"\
                        :             \
                        : "r" (addr)  \
                        : "memory")

#define SPINLOCK(addr)      \
  __asm__ __volatile__ ("0:\n\t"\
                        "movq $1, %%rax\n\t"\
                        "xchgq (%0), %%rax\n\t"\
                        "cmpq $0, %%rax\n\t"\
                        "je 2f\n\t"\
                        "1:\n\t"\
                        "pause\n\t"\
                        "cmpq $0, (%0)\n\t"\
                        "je 0b\n\t"\
                        "jmp 1b\n\t"\
                        "2:"\
                        :                \
                        : "r" (addr)     \
                        : "rax", "flags", "memory")

#define UNLOCK(addr)     \
  __asm__ __volatile__ ("movq $0, (%0)"\
                        :             \
                        : "r" (addr)  \
                        :"memory")

#define LOCKED_INCR(addr, ret) \
  __asm__ __volatile__ ("lock; incq (%1)\n\t"\
                        "sete %b0\n\t"\
                        "movzx %b0, %0\n\t"\
                        : "=q" (ret)   \
                        : "r" (addr)   \
                        : "flags", "memory")

#define LOCKED_DECR(addr, ret) \
  __asm__ __volatile__ ("lock; decq (%1)\n\t"\
                        "sete %b0\n\t"\
                        "movzx %b0, %0\n\t"\
                        : "=q" (ret)   \
                        : "r" (addr)   \
                        : "flags", "memory")
