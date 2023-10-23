/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_unnamed_0 l_unnamed_0;

/* Structure contents */
struct l_unnamed_0 {
  float field0;
  float field1;
};


/* External Global Variable Declarations */
extern float W_real[512];
extern float W_imag[512];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void init_arr(l_unnamed_0 *llvm_cbe_inr);
void FFTipfn_gold(l_unnamed_0 *llvm_cbe_FFT_input, l_unnamed_0 *llvm_cbe_FFT_output);
signed int main(void);
void FFTipfn(l_unnamed_0 *, l_unnamed_0 *);


/* Global Variable Definitions and Initialization */
float W_real[512] = { 0x1p0, 0x1.fffd88p-1, 0x1.fff622p-1, 0x1.ffe9ccp-1, 0x1.ffd886p-1, 0x1.ffc252p-1, 0x1.ffa72ep-1, 0x1.ff871ep-1, 0x1.ff621ep-1, 0x1.ff383p-1, 0x1.ff0956p-1, 0x1.fed58ep-1, 0x1.fe9cdap-1, 0x1.fe5f3ap-1, 0x1.fe1cbp-1, 0x1.fdd53ap-1, 0x1.fd88dap-1, 0x1.fd3792p-1, 0x1.fce16p-1, 0x1.fc8646p-1, 0x1.fc2648p-1, 0x1.fbc162p-1, 0x1.fb5798p-1, 0x1.fae8e8p-1, 0x1.fa7558p-1, 0x1.f9fce6p-1, 0x1.f97f92p-1, 0x1.f8fd6p-1, 0x1.f8765p-1, 0x1.f7ea62p-1, 0x1.f7599ap-1, 0x1.f6c3f8p-1, 0x1.f6297cp-1, 0x1.f58a2cp-1, 0x1.f4e604p-1, 0x1.f43d08p-1, 0x1.f38f3ap-1, 0x1.f2dc9cp-1, 0x1.f2253p-1, 0x1.f168f6p-1, 0x1.f0a7fp-1, 0x1.efe22p-1, 0x1.ef178ap-1, 0x1.ee482ep-1, 0x1.ed740ep-1, 0x1.ec9b2ep-1, 0x1.ebbd8cp-1, 0x1.eadb2ep-1, 0x1.e9f416p-1, 0x1.e90844p-1, 0x1.e817bap-1, 0x1.e7227ep-1, 0x1.e6288ep-1, 0x1.e529fp-1, 0x1.e426a4p-1, 0x1.e31eaep-1, 0x1.e2121p-1, 0x1.e100ccp-1, 0x1.dfeae6p-1, 0x1.ded06p-1, 0x1.ddb13cp-1, 0x1.dc8d7cp-1, 0x1.db6526p-1, 0x1.da383ap-1, 0x1.d906bcp-1, 0x1.d7d0bp-1, 0x1.d69618p-1, 0x1.d556f6p-1, 0x1.d4134ep-1, 0x1.d2cb22p-1, 0x1.d17e78p-1, 0x1.d02d5p-1, 0x1.ced7bp-1, 0x1.cd7d98p-1, 0x1.cc1f1p-1, 0x1.cabc16p-1, 0x1.c954b2p-1, 0x1.c7e8e6p-1, 0x1.c678b4p-1, 0x1.c5042p-1, 0x1.c38b3p-1, 0x1.c20de4p-1, 0x1.c08c42p-1, 0x1.bf064ep-1, 0x1.bd7c0ap-1, 0x1.bbed7cp-1, 0x1.ba5aa6p-1, 0x1.b8c38ep-1, 0x1.b72834p-1, 0x1.b588ap-1, 0x1.b3e4d4p-1, 0x1.b23cd4p-1, 0x1.b090a6p-1, 0x1.aee04cp-1, 0x1.ad2bcap-1, 0x1.ab7326p-1, 0x1.a9b662p-1, 0x1.a7f586p-1, 0x1.a63092p-1, 0x1.a4678cp-1, 0x1.a29a7ap-1, 0x1.a0c95ep-1, 0x1.9ef43ep-1, 0x1.9d1b2p-1, 0x1.9b3e04p-1, 0x1.995cf2p-1, 0x1.9777fp-1, 0x1.958efep-1, 0x1.93a224p-1, 0x1.91b166p-1, 0x1.8fbccap-1, 0x1.8dc454p-1, 0x1.8bc806p-1, 0x1.89c7eap-1, 0x1.87c4p-1, 0x1.85bc52p-1, 0x1.83b0ep-1, 0x1.81a1b4p-1, 0x1.7f8ecep-1, 0x1.7d7836p-1, 0x1.7b5df2p-1, 0x1.794006p-1, 0x1.771e76p-1, 0x1.74f948p-1, 0x1.72d084p-1, 0x1.70a42cp-1, 0x1.6e7446p-1, 0x1.6c40d8p-1, 0x1.6a09e6p-1, 0x1.67cf78p-1, 0x1.659192p-1, 0x1.63503ap-1, 0x1.610b76p-1, 0x1.5ec34ap-1, 0x1.5c77bcp-1, 0x1.5a28d2p-1, 0x1.57d694p-1, 0x1.558104p-1, 0x1.53282ap-1, 0x1.50cc0ap-1, 0x1.4e6cacp-1, 0x1.4c0a14p-1, 0x1.49a44ap-1, 0x1.473b52p-1, 0x1.44cf32p-1, 0x1.425ff2p-1, 0x1.3fed96p-1, 0x1.3d7824p-1, 0x1.3affa2p-1, 0x1.388418p-1, 0x1.36058cp-1, 0x1.3384p-1, 0x1.30ff8p-1, 0x1.2e780ep-1, 0x1.2bedb2p-1, 0x1.296072p-1, 0x1.26d054p-1, 0x1.243d6p-1, 0x1.21a79ap-1, 0x1.1f0f08p-1, 0x1.1c73b4p-1, 0x1.19d5ap-1, 0x1.1734d6p-1, 0x1.14915ap-1, 0x1.11eb36p-1, 0x1.0f426cp-1, 0x1.0c9704p-1, 0x1.09e908p-1, 0x1.07387ap-1, 0x1.048562p-1, 0x1.01cfc8p-1, 0x1.fe2f64p-2, 0x1.f8ba4ep-2, 0x1.f3405ap-2, 0x1.edc196p-2, 0x1.e83e0ep-2, 0x1.e2b5d4p-2, 0x1.dd28f2p-2, 0x1.d79776p-2, 0x1.d2016ep-2, 0x1.cc66eap-2, 0x1.c6c7f4p-2, 0x1.c1249ep-2, 0x1.bb7cf2p-2, 0x1.b5d1p-2, 0x1.b020d6p-2, 0x1.aa6c82p-2, 0x1.a4b412p-2, 0x1.9ef794p-2, 0x1.993716p-2, 0x1.9372a6p-2, 0x1.8daa52p-2, 0x1.87de2ap-2, 0x1.820e3cp-2, 0x1.7c3a94p-2, 0x1.76634p-2, 0x1.708854p-2, 0x1.6aa9d8p-2, 0x1.64c7dep-2, 0x1.5ee274p-2, 0x1.58f9a8p-2, 0x1.530d88p-2, 0x1.4d1e24p-2, 0x1.472b8ap-2, 0x1.4135cap-2, 0x1.3b3cfp-2, 0x1.35410cp-2, 0x1.2f422ep-2, 0x1.294062p-2, 0x1.233bbap-2, 0x1.1d3444p-2, 0x1.172a0ep-2, 0x1.111d26p-2, 0x1.0b0d9cp-2, 0x1.04fb8p-2, 0x1.fdcdc2p-3, 0x1.f19f98p-3, 0x1.e56ca2p-3, 0x1.d934fep-3, 0x1.ccf8ccp-3, 0x1.c0b826p-3, 0x1.b4732ep-3, 0x1.a82a02p-3, 0x1.9bdccp-3, 0x1.8f8b84p-3, 0x1.83366ep-3, 0x1.76dd9ep-3, 0x1.6a813p-3, 0x1.5e2144p-3, 0x1.51bdf8p-3, 0x1.45576cp-3, 0x1.38edbcp-3, 0x1.2c8106p-3, 0x1.20116ep-3, 0x1.139f0cp-3, 0x1.072a04p-3, 0x1.f564e6p-4, 0x1.dc70ecp-4, 0x1.c3785cp-4, 0x1.aa7b72p-4, 0x1.917a6cp-4, 0x1.787586p-4, 0x1.5f6dp-4, 0x1.466118p-4, 0x1.2d520ap-4, 0x1.144014p-4, 0x1.f656e8p-5, 0x1.c428d2p-5, 0x1.91f66p-5, 0x1.5fc00ep-5, 0x1.2d8658p-5, 0x1.f69374p-6, 0x1.92156p-6, 0x1.2d936cp-6, 0x1.921d2p-7, 0x1.921f1p-8, 0x1.1a6264p-54, -0x1.921f1p-8, -0x1.921d2p-7, -0x1.2d936cp-6, -0x1.92156p-6, -0x1.f69374p-6, -0x1.2d8658p-5, -0x1.5fc00ep-5, -0x1.91f66p-5, -0x1.c428d2p-5, -0x1.f656e8p-5, -0x1.144014p-4, -0x1.2d520ap-4, -0x1.466118p-4, -0x1.5f6dp-4, -0x1.787586p-4, -0x1.917a6cp-4, -0x1.aa7b72p-4, -0x1.c3785cp-4, -0x1.dc70ecp-4, -0x1.f564e6p-4, -0x1.072a04p-3, -0x1.139f0cp-3, -0x1.20116ep-3, -0x1.2c8106p-3, -0x1.38edbcp-3, -0x1.45576cp-3, -0x1.51bdf8p-3, -0x1.5e2144p-3, -0x1.6a813p-3, -0x1.76dd9ep-3, -0x1.83366ep-3, -0x1.8f8b84p-3, -0x1.9bdccp-3, -0x1.a82a02p-3, -0x1.b4732ep-3, -0x1.c0b826p-3, -0x1.ccf8ccp-3, -0x1.d934fep-3, -0x1.e56ca2p-3, -0x1.f19f98p-3, -0x1.fdcdc2p-3, -0x1.04fb8p-2, -0x1.0b0d9cp-2, -0x1.111d26p-2, -0x1.172a0ep-2, -0x1.1d3444p-2, -0x1.233bbap-2, -0x1.294062p-2, -0x1.2f422ep-2, -0x1.35410cp-2, -0x1.3b3cfp-2, -0x1.4135cap-2, -0x1.472b8ap-2, -0x1.4d1e24p-2, -0x1.530d88p-2, -0x1.58f9a8p-2, -0x1.5ee274p-2, -0x1.64c7dep-2, -0x1.6aa9d8p-2, -0x1.708854p-2, -0x1.76634p-2, -0x1.7c3a94p-2, -0x1.820e3cp-2, -0x1.87de2ap-2, -0x1.8daa52p-2, -0x1.9372a6p-2, -0x1.993716p-2, -0x1.9ef794p-2, -0x1.a4b412p-2, -0x1.aa6c82p-2, -0x1.b020d6p-2, -0x1.b5d1p-2, -0x1.bb7cf2p-2, -0x1.c1249ep-2, -0x1.c6c7f4p-2, -0x1.cc66eap-2, -0x1.d2016ep-2, -0x1.d79776p-2, -0x1.dd28f2p-2, -0x1.e2b5d4p-2, -0x1.e83e0ep-2, -0x1.edc196p-2, -0x1.f3405ap-2, -0x1.f8ba4ep-2, -0x1.fe2f64p-2, -0x1.01cfc8p-1, -0x1.048562p-1, -0x1.07387ap-1, -0x1.09e908p-1, -0x1.0c9704p-1, -0x1.0f426cp-1, -0x1.11eb36p-1, -0x1.14915ap-1, -0x1.1734d6p-1, -0x1.19d5ap-1, -0x1.1c73b4p-1, -0x1.1f0f08p-1, -0x1.21a79ap-1, -0x1.243d6p-1, -0x1.26d054p-1, -0x1.296072p-1, -0x1.2bedb2p-1, -0x1.2e780ep-1, -0x1.30ff8p-1, -0x1.3384p-1, -0x1.36058cp-1, -0x1.388418p-1, -0x1.3affa2p-1, -0x1.3d7824p-1, -0x1.3fed96p-1, -0x1.425ff2p-1, -0x1.44cf32p-1, -0x1.473b52p-1, -0x1.49a44ap-1, -0x1.4c0a14p-1, -0x1.4e6cacp-1, -0x1.50cc0ap-1, -0x1.53282ap-1, -0x1.558104p-1, -0x1.57d694p-1, -0x1.5a28d2p-1, -0x1.5c77bcp-1, -0x1.5ec34ap-1, -0x1.610b76p-1, -0x1.63503ap-1, -0x1.659192p-1, -0x1.67cf78p-1, -0x1.6a09e6p-1, -0x1.6c40d8p-1, -0x1.6e7446p-1, -0x1.70a42cp-1, -0x1.72d084p-1, -0x1.74f948p-1, -0x1.771e76p-1, -0x1.794006p-1, -0x1.7b5df2p-1, -0x1.7d7836p-1, -0x1.7f8ecep-1, -0x1.81a1b4p-1, -0x1.83b0ep-1, -0x1.85bc52p-1, -0x1.87c4p-1, -0x1.89c7eap-1, -0x1.8bc806p-1, -0x1.8dc454p-1, -0x1.8fbccap-1, -0x1.91b166p-1, -0x1.93a224p-1, -0x1.958efep-1, -0x1.9777fp-1, -0x1.995cf2p-1, -0x1.9b3e04p-1, -0x1.9d1b2p-1, -0x1.9ef43ep-1, -0x1.a0c95ep-1, -0x1.a29a7ap-1, -0x1.a4678cp-1, -0x1.a63092p-1, -0x1.a7f586p-1, -0x1.a9b662p-1, -0x1.ab7326p-1, -0x1.ad2bcap-1, -0x1.aee04cp-1, -0x1.b090a6p-1, -0x1.b23cd4p-1, -0x1.b3e4d4p-1, -0x1.b588ap-1, -0x1.b72834p-1, -0x1.b8c38ep-1, -0x1.ba5aa6p-1, -0x1.bbed7cp-1, -0x1.bd7c0ap-1, -0x1.bf064ep-1, -0x1.c08c42p-1, -0x1.c20de4p-1, -0x1.c38b3p-1, -0x1.c5042p-1, -0x1.c678b4p-1, -0x1.c7e8e6p-1, -0x1.c954b2p-1, -0x1.cabc16p-1, -0x1.cc1f1p-1, -0x1.cd7d98p-1, -0x1.ced7bp-1, -0x1.d02d5p-1, -0x1.d17e78p-1, -0x1.d2cb22p-1, -0x1.d4134ep-1, -0x1.d556f6p-1, -0x1.d69618p-1, -0x1.d7d0bp-1, -0x1.d906bcp-1, -0x1.da383ap-1, -0x1.db6526p-1, -0x1.dc8d7cp-1, -0x1.ddb13cp-1, -0x1.ded06p-1, -0x1.dfeae6p-1, -0x1.e100ccp-1, -0x1.e2121p-1, -0x1.e31eaep-1, -0x1.e426a4p-1, -0x1.e529fp-1, -0x1.e6288ep-1, -0x1.e7227ep-1, -0x1.e817bap-1, -0x1.e90844p-1, -0x1.e9f416p-1, -0x1.eadb2ep-1, -0x1.ebbd8cp-1, -0x1.ec9b2ep-1, -0x1.ed740ep-1, -0x1.ee482ep-1, -0x1.ef178ap-1, -0x1.efe22p-1, -0x1.f0a7fp-1, -0x1.f168f6p-1, -0x1.f2253p-1, -0x1.f2dc9cp-1, -0x1.f38f3ap-1, -0x1.f43d08p-1, -0x1.f4e604p-1, -0x1.f58a2cp-1, -0x1.f6297cp-1, -0x1.f6c3f8p-1, -0x1.f7599ap-1, -0x1.f7ea62p-1, -0x1.f8765p-1, -0x1.f8fd6p-1, -0x1.f97f92p-1, -0x1.f9fce6p-1, -0x1.fa7558p-1, -0x1.fae8e8p-1, -0x1.fb5798p-1, -0x1.fbc162p-1, -0x1.fc2648p-1, -0x1.fc8646p-1, -0x1.fce16p-1, -0x1.fd3792p-1, -0x1.fd88dap-1, -0x1.fdd53ap-1, -0x1.fe1cbp-1, -0x1.fe5f3ap-1, -0x1.fe9cdap-1, -0x1.fed58ep-1, -0x1.ff0956p-1, -0x1.ff383p-1, -0x1.ff621ep-1, -0x1.ff871ep-1, -0x1.ffa72ep-1, -0x1.ffc252p-1, -0x1.ffd886p-1, -0x1.ffe9ccp-1, -0x1.fff622p-1, -0x1.fffd88p-1 };
float W_imag[512] = { -0x0p0, -0x1.921f1p-8, -0x1.921d2p-7, -0x1.2d936cp-6, -0x1.92156p-6, -0x1.f69374p-6, -0x1.2d8658p-5, -0x1.5fc00ep-5, -0x1.91f66p-5, -0x1.c428d2p-5, -0x1.f656e8p-5, -0x1.144014p-4, -0x1.2d520ap-4, -0x1.466118p-4, -0x1.5f6dp-4, -0x1.787586p-4, -0x1.917a6cp-4, -0x1.aa7b72p-4, -0x1.c3785cp-4, -0x1.dc70ecp-4, -0x1.f564e6p-4, -0x1.072a04p-3, -0x1.139f0cp-3, -0x1.20116ep-3, -0x1.2c8106p-3, -0x1.38edbcp-3, -0x1.45576cp-3, -0x1.51bdf8p-3, -0x1.5e2144p-3, -0x1.6a813p-3, -0x1.76dd9ep-3, -0x1.83366ep-3, -0x1.8f8b84p-3, -0x1.9bdccp-3, -0x1.a82a02p-3, -0x1.b4732ep-3, -0x1.c0b826p-3, -0x1.ccf8ccp-3, -0x1.d934fep-3, -0x1.e56ca2p-3, -0x1.f19f98p-3, -0x1.fdcdc2p-3, -0x1.04fb8p-2, -0x1.0b0d9cp-2, -0x1.111d26p-2, -0x1.172a0ep-2, -0x1.1d3444p-2, -0x1.233bbap-2, -0x1.294062p-2, -0x1.2f422ep-2, -0x1.35410cp-2, -0x1.3b3cfp-2, -0x1.4135cap-2, -0x1.472b8ap-2, -0x1.4d1e24p-2, -0x1.530d88p-2, -0x1.58f9a8p-2, -0x1.5ee274p-2, -0x1.64c7dep-2, -0x1.6aa9d8p-2, -0x1.708854p-2, -0x1.76634p-2, -0x1.7c3a94p-2, -0x1.820e3cp-2, -0x1.87de2ap-2, -0x1.8daa52p-2, -0x1.9372a6p-2, -0x1.993716p-2, -0x1.9ef794p-2, -0x1.a4b412p-2, -0x1.aa6c82p-2, -0x1.b020d6p-2, -0x1.b5d1p-2, -0x1.bb7cf2p-2, -0x1.c1249ep-2, -0x1.c6c7f4p-2, -0x1.cc66eap-2, -0x1.d2016ep-2, -0x1.d79776p-2, -0x1.dd28f2p-2, -0x1.e2b5d4p-2, -0x1.e83e0ep-2, -0x1.edc196p-2, -0x1.f3405ap-2, -0x1.f8ba4ep-2, -0x1.fe2f64p-2, -0x1.01cfc8p-1, -0x1.048562p-1, -0x1.07387ap-1, -0x1.09e908p-1, -0x1.0c9704p-1, -0x1.0f426cp-1, -0x1.11eb36p-1, -0x1.14915ap-1, -0x1.1734d6p-1, -0x1.19d5ap-1, -0x1.1c73b4p-1, -0x1.1f0f08p-1, -0x1.21a79ap-1, -0x1.243d6p-1, -0x1.26d054p-1, -0x1.296072p-1, -0x1.2bedb2p-1, -0x1.2e780ep-1, -0x1.30ff8p-1, -0x1.3384p-1, -0x1.36058cp-1, -0x1.388418p-1, -0x1.3affa2p-1, -0x1.3d7824p-1, -0x1.3fed96p-1, -0x1.425ff2p-1, -0x1.44cf32p-1, -0x1.473b52p-1, -0x1.49a44ap-1, -0x1.4c0a14p-1, -0x1.4e6cacp-1, -0x1.50cc0ap-1, -0x1.53282ap-1, -0x1.558104p-1, -0x1.57d694p-1, -0x1.5a28d2p-1, -0x1.5c77bcp-1, -0x1.5ec34ap-1, -0x1.610b76p-1, -0x1.63503ap-1, -0x1.659192p-1, -0x1.67cf78p-1, -0x1.6a09e6p-1, -0x1.6c40d8p-1, -0x1.6e7446p-1, -0x1.70a42cp-1, -0x1.72d084p-1, -0x1.74f948p-1, -0x1.771e76p-1, -0x1.794006p-1, -0x1.7b5df2p-1, -0x1.7d7836p-1, -0x1.7f8ecep-1, -0x1.81a1b4p-1, -0x1.83b0ep-1, -0x1.85bc52p-1, -0x1.87c4p-1, -0x1.89c7eap-1, -0x1.8bc806p-1, -0x1.8dc454p-1, -0x1.8fbccap-1, -0x1.91b166p-1, -0x1.93a224p-1, -0x1.958efep-1, -0x1.9777fp-1, -0x1.995cf2p-1, -0x1.9b3e04p-1, -0x1.9d1b2p-1, -0x1.9ef43ep-1, -0x1.a0c95ep-1, -0x1.a29a7ap-1, -0x1.a4678cp-1, -0x1.a63092p-1, -0x1.a7f586p-1, -0x1.a9b662p-1, -0x1.ab7326p-1, -0x1.ad2bcap-1, -0x1.aee04cp-1, -0x1.b090a6p-1, -0x1.b23cd4p-1, -0x1.b3e4d4p-1, -0x1.b588ap-1, -0x1.b72834p-1, -0x1.b8c38ep-1, -0x1.ba5aa6p-1, -0x1.bbed7cp-1, -0x1.bd7c0ap-1, -0x1.bf064ep-1, -0x1.c08c42p-1, -0x1.c20de4p-1, -0x1.c38b3p-1, -0x1.c5042p-1, -0x1.c678b4p-1, -0x1.c7e8e6p-1, -0x1.c954b2p-1, -0x1.cabc16p-1, -0x1.cc1f1p-1, -0x1.cd7d98p-1, -0x1.ced7bp-1, -0x1.d02d5p-1, -0x1.d17e78p-1, -0x1.d2cb22p-1, -0x1.d4134ep-1, -0x1.d556f6p-1, -0x1.d69618p-1, -0x1.d7d0bp-1, -0x1.d906bcp-1, -0x1.da383ap-1, -0x1.db6526p-1, -0x1.dc8d7cp-1, -0x1.ddb13cp-1, -0x1.ded06p-1, -0x1.dfeae6p-1, -0x1.e100ccp-1, -0x1.e2121p-1, -0x1.e31eaep-1, -0x1.e426a4p-1, -0x1.e529fp-1, -0x1.e6288ep-1, -0x1.e7227ep-1, -0x1.e817bap-1, -0x1.e90844p-1, -0x1.e9f416p-1, -0x1.eadb2ep-1, -0x1.ebbd8cp-1, -0x1.ec9b2ep-1, -0x1.ed740ep-1, -0x1.ee482ep-1, -0x1.ef178ap-1, -0x1.efe22p-1, -0x1.f0a7fp-1, -0x1.f168f6p-1, -0x1.f2253p-1, -0x1.f2dc9cp-1, -0x1.f38f3ap-1, -0x1.f43d08p-1, -0x1.f4e604p-1, -0x1.f58a2cp-1, -0x1.f6297cp-1, -0x1.f6c3f8p-1, -0x1.f7599ap-1, -0x1.f7ea62p-1, -0x1.f8765p-1, -0x1.f8fd6p-1, -0x1.f97f92p-1, -0x1.f9fce6p-1, -0x1.fa7558p-1, -0x1.fae8e8p-1, -0x1.fb5798p-1, -0x1.fbc162p-1, -0x1.fc2648p-1, -0x1.fc8646p-1, -0x1.fce16p-1, -0x1.fd3792p-1, -0x1.fd88dap-1, -0x1.fdd53ap-1, -0x1.fe1cbp-1, -0x1.fe5f3ap-1, -0x1.fe9cdap-1, -0x1.fed58ep-1, -0x1.ff0956p-1, -0x1.ff383p-1, -0x1.ff621ep-1, -0x1.ff871ep-1, -0x1.ffa72ep-1, -0x1.ffc252p-1, -0x1.ffd886p-1, -0x1.ffe9ccp-1, -0x1.fff622p-1, -0x1.fffd88p-1, -0x1p0, -0x1.fffd88p-1, -0x1.fff622p-1, -0x1.ffe9ccp-1, -0x1.ffd886p-1, -0x1.ffc252p-1, -0x1.ffa72ep-1, -0x1.ff871ep-1, -0x1.ff621ep-1, -0x1.ff383p-1, -0x1.ff0956p-1, -0x1.fed58ep-1, -0x1.fe9cdap-1, -0x1.fe5f3ap-1, -0x1.fe1cbp-1, -0x1.fdd53ap-1, -0x1.fd88dap-1, -0x1.fd3792p-1, -0x1.fce16p-1, -0x1.fc8646p-1, -0x1.fc2648p-1, -0x1.fbc162p-1, -0x1.fb5798p-1, -0x1.fae8e8p-1, -0x1.fa7558p-1, -0x1.f9fce6p-1, -0x1.f97f92p-1, -0x1.f8fd6p-1, -0x1.f8765p-1, -0x1.f7ea62p-1, -0x1.f7599ap-1, -0x1.f6c3f8p-1, -0x1.f6297cp-1, -0x1.f58a2cp-1, -0x1.f4e604p-1, -0x1.f43d08p-1, -0x1.f38f3ap-1, -0x1.f2dc9cp-1, -0x1.f2253p-1, -0x1.f168f6p-1, -0x1.f0a7fp-1, -0x1.efe22p-1, -0x1.ef178ap-1, -0x1.ee482ep-1, -0x1.ed740ep-1, -0x1.ec9b2ep-1, -0x1.ebbd8cp-1, -0x1.eadb2ep-1, -0x1.e9f416p-1, -0x1.e90844p-1, -0x1.e817bap-1, -0x1.e7227ep-1, -0x1.e6288ep-1, -0x1.e529fp-1, -0x1.e426a4p-1, -0x1.e31eaep-1, -0x1.e2121p-1, -0x1.e100ccp-1, -0x1.dfeae6p-1, -0x1.ded06p-1, -0x1.ddb13cp-1, -0x1.dc8d7cp-1, -0x1.db6526p-1, -0x1.da383ap-1, -0x1.d906bcp-1, -0x1.d7d0bp-1, -0x1.d69618p-1, -0x1.d556f6p-1, -0x1.d4134ep-1, -0x1.d2cb22p-1, -0x1.d17e78p-1, -0x1.d02d5p-1, -0x1.ced7bp-1, -0x1.cd7d98p-1, -0x1.cc1f1p-1, -0x1.cabc16p-1, -0x1.c954b2p-1, -0x1.c7e8e6p-1, -0x1.c678b4p-1, -0x1.c5042p-1, -0x1.c38b3p-1, -0x1.c20de4p-1, -0x1.c08c42p-1, -0x1.bf064ep-1, -0x1.bd7c0ap-1, -0x1.bbed7cp-1, -0x1.ba5aa6p-1, -0x1.b8c38ep-1, -0x1.b72834p-1, -0x1.b588ap-1, -0x1.b3e4d4p-1, -0x1.b23cd4p-1, -0x1.b090a6p-1, -0x1.aee04cp-1, -0x1.ad2bcap-1, -0x1.ab7326p-1, -0x1.a9b662p-1, -0x1.a7f586p-1, -0x1.a63092p-1, -0x1.a4678cp-1, -0x1.a29a7ap-1, -0x1.a0c95ep-1, -0x1.9ef43ep-1, -0x1.9d1b2p-1, -0x1.9b3e04p-1, -0x1.995cf2p-1, -0x1.9777fp-1, -0x1.958efep-1, -0x1.93a224p-1, -0x1.91b166p-1, -0x1.8fbccap-1, -0x1.8dc454p-1, -0x1.8bc806p-1, -0x1.89c7eap-1, -0x1.87c4p-1, -0x1.85bc52p-1, -0x1.83b0ep-1, -0x1.81a1b4p-1, -0x1.7f8ecep-1, -0x1.7d7836p-1, -0x1.7b5df2p-1, -0x1.794006p-1, -0x1.771e76p-1, -0x1.74f948p-1, -0x1.72d084p-1, -0x1.70a42cp-1, -0x1.6e7446p-1, -0x1.6c40d8p-1, -0x1.6a09e6p-1, -0x1.67cf78p-1, -0x1.659192p-1, -0x1.63503ap-1, -0x1.610b76p-1, -0x1.5ec34ap-1, -0x1.5c77bcp-1, -0x1.5a28d2p-1, -0x1.57d694p-1, -0x1.558104p-1, -0x1.53282ap-1, -0x1.50cc0ap-1, -0x1.4e6cacp-1, -0x1.4c0a14p-1, -0x1.49a44ap-1, -0x1.473b52p-1, -0x1.44cf32p-1, -0x1.425ff2p-1, -0x1.3fed96p-1, -0x1.3d7824p-1, -0x1.3affa2p-1, -0x1.388418p-1, -0x1.36058cp-1, -0x1.3384p-1, -0x1.30ff8p-1, -0x1.2e780ep-1, -0x1.2bedb2p-1, -0x1.296072p-1, -0x1.26d054p-1, -0x1.243d6p-1, -0x1.21a79ap-1, -0x1.1f0f08p-1, -0x1.1c73b4p-1, -0x1.19d5ap-1, -0x1.1734d6p-1, -0x1.14915ap-1, -0x1.11eb36p-1, -0x1.0f426cp-1, -0x1.0c9704p-1, -0x1.09e908p-1, -0x1.07387ap-1, -0x1.048562p-1, -0x1.01cfc8p-1, -0x1.fe2f64p-2, -0x1.f8ba4ep-2, -0x1.f3405ap-2, -0x1.edc196p-2, -0x1.e83e0ep-2, -0x1.e2b5d4p-2, -0x1.dd28f2p-2, -0x1.d79776p-2, -0x1.d2016ep-2, -0x1.cc66eap-2, -0x1.c6c7f4p-2, -0x1.c1249ep-2, -0x1.bb7cf2p-2, -0x1.b5d1p-2, -0x1.b020d6p-2, -0x1.aa6c82p-2, -0x1.a4b412p-2, -0x1.9ef794p-2, -0x1.993716p-2, -0x1.9372a6p-2, -0x1.8daa52p-2, -0x1.87de2ap-2, -0x1.820e3cp-2, -0x1.7c3a94p-2, -0x1.76634p-2, -0x1.708854p-2, -0x1.6aa9d8p-2, -0x1.64c7dep-2, -0x1.5ee274p-2, -0x1.58f9a8p-2, -0x1.530d88p-2, -0x1.4d1e24p-2, -0x1.472b8ap-2, -0x1.4135cap-2, -0x1.3b3cfp-2, -0x1.35410cp-2, -0x1.2f422ep-2, -0x1.294062p-2, -0x1.233bbap-2, -0x1.1d3444p-2, -0x1.172a0ep-2, -0x1.111d26p-2, -0x1.0b0d9cp-2, -0x1.04fb8p-2, -0x1.fdcdc2p-3, -0x1.f19f98p-3, -0x1.e56ca2p-3, -0x1.d934fep-3, -0x1.ccf8ccp-3, -0x1.c0b826p-3, -0x1.b4732ep-3, -0x1.a82a02p-3, -0x1.9bdccp-3, -0x1.8f8b84p-3, -0x1.83366ep-3, -0x1.76dd9ep-3, -0x1.6a813p-3, -0x1.5e2144p-3, -0x1.51bdf8p-3, -0x1.45576cp-3, -0x1.38edbcp-3, -0x1.2c8106p-3, -0x1.20116ep-3, -0x1.139f0cp-3, -0x1.072a04p-3, -0x1.f564e6p-4, -0x1.dc70ecp-4, -0x1.c3785cp-4, -0x1.aa7b72p-4, -0x1.917a6cp-4, -0x1.787586p-4, -0x1.5f6dp-4, -0x1.466118p-4, -0x1.2d520ap-4, -0x1.144014p-4, -0x1.f656e8p-5, -0x1.c428d2p-5, -0x1.91f66p-5, -0x1.5fc00ep-5, -0x1.2d8658p-5, -0x1.f69374p-6, -0x1.92156p-6, -0x1.2d936cp-6, -0x1.921d2p-7, -0x1.921f1p-8 };
static  char aesl_internal_str[7] = "FAILED";
static  char aesl_internal_str1[7] = "PASSED";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void init_arr(l_unnamed_0 *llvm_cbe_inr) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  float llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  float *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  float *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @init_arr\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__6;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%6, %%1  for 0x%I64xth hint within @init_arr  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sitofp i32 %%storemerge1 to float, !dbg !5 for 0x%I64xth hint within @init_arr  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__1 = (float )((float )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__1, *(int*)(&llvm_cbe_tmp__1));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%storemerge1 to i64, !dbg !5 for 0x%I64xth hint within @init_arr  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__2 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds { float, float }* %%inr, i64 %%3, i32 0, !dbg !5 for 0x%I64xth hint within @init_arr  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__3 = (float *)(&llvm_cbe_inr[(((signed long long )llvm_cbe_tmp__2))].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds { float, float }* %%inr, i64 %%3, i32 1, !dbg !5 for 0x%I64xth hint within @init_arr  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__4 = (float *)(&llvm_cbe_inr[(((signed long long )llvm_cbe_tmp__2))].field1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%2, float* %%4, align 4, !dbg !5 for 0x%I64xth hint within @init_arr  --> \n", ++aesl_llvm_cbe_13_count);
  *llvm_cbe_tmp__3 = llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  store float 0.000000e+00, float* %%5, align 4, !dbg !5 for 0x%I64xth hint within @init_arr  --> \n", ++aesl_llvm_cbe_14_count);
  *llvm_cbe_tmp__4 = 0x0p0;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", 0x0p0);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge1, 1, !dbg !5 for 0x%I64xth hint within @init_arr  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__5 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__5&4294967295ull)));
  if (((llvm_cbe_tmp__5&4294967295U) == (1024u&4294967295U))) {
    goto llvm_cbe_tmp__7;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__5;   /* for PHI node */
    goto llvm_cbe_tmp__6;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__7:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @init_arr}\n");
  return;
}


void FFTipfn_gold(l_unnamed_0 *llvm_cbe_FFT_input, l_unnamed_0 *llvm_cbe_FFT_output) {
  static  unsigned long long aesl_llvm_cbe_FFTIn_R_count = 0;
  float llvm_cbe_FFTIn_R[1024];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_FFTIn_I_count = 0;
  float llvm_cbe_FFTIn_I[1024];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_FFTOut_R_count = 0;
  float llvm_cbe_FFTOut_R[1024];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_FFTOut_I_count = 0;
  float llvm_cbe_FFTOut_I[1024];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge18_count = 0;
  unsigned int llvm_cbe_storemerge18;
  unsigned int llvm_cbe_storemerge18__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  float *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  float llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  float *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  float llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  float llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  float *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  float llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  float *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond22_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge117_count = 0;
  unsigned int llvm_cbe_storemerge117;
  unsigned int llvm_cbe_storemerge117__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  float *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  float llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  unsigned long long llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  float *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  float *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  float llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  float *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond21_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge215_count = 0;
  unsigned int llvm_cbe_storemerge215;
  unsigned int llvm_cbe_storemerge215__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge410_count = 0;
  unsigned int llvm_cbe_storemerge410;
  unsigned int llvm_cbe_storemerge410__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  float *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  float llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  float *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  float llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge59_count = 0;
  unsigned int llvm_cbe_storemerge59;
  unsigned int llvm_cbe_storemerge59__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  unsigned long long llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  float *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  float llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  float llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  float *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  float llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  float llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  float llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  float llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  float llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  float llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  unsigned long long llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  float *llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  float llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  float llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  float *llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  float llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  float llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  float llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  float llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  float llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  float llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  unsigned int llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_exitcond19_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond20_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge38_count = 0;
  unsigned int llvm_cbe_storemerge38;
  unsigned int llvm_cbe_storemerge38__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  float *llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  float llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  float *llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  float llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  float llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  float llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  float llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  float *llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  float *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @FFTipfn_gold\n");
  llvm_cbe_storemerge18__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__102;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__102:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge18 = phi i32 [ 0, %%0 ], [ %%11, %%1  for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_storemerge18_count);
  llvm_cbe_storemerge18 = (unsigned int )llvm_cbe_storemerge18__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge18 = 0x%X",llvm_cbe_storemerge18);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__17);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge18 to i64, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__8 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge18);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds { float, float }* %%FFT_input, i64 %%2, i32 0, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__9 = (float *)(&llvm_cbe_FFT_input[(((signed long long )llvm_cbe_tmp__8))].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load float* %%3, align 4, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__10 = (float )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__10, *(int*)(&llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds { float, float }* %%FFT_input, i64 %%2, i32 1, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__11 = (float *)(&llvm_cbe_FFT_input[(((signed long long )llvm_cbe_tmp__8))].field1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load float* %%5, align 4, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__12 = (float )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call float @crealf(float %%4, float %%6) nounwind readnone, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__13 = (float )crealf(llvm_cbe_tmp__10, llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__10, *(int*)(&llvm_cbe_tmp__10));
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
printf("\nReturn  = %f",llvm_cbe_tmp__13);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [1024 x float]* %%FFTIn_R, i64 0, i64 %%2, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__14 = (float *)(&llvm_cbe_FFTIn_R[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__8) < 1024 && "Write access out of array 'FFTIn_R' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%7, float* %%8, align 4, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_85_count);
  *llvm_cbe_tmp__14 = llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call float @cimagf(float %%4, float %%6) nounwind readnone, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__15 = (float )cimagf(llvm_cbe_tmp__10, llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__10, *(int*)(&llvm_cbe_tmp__10));
printf("\nArgument  = %f,  0x%x",llvm_cbe_tmp__12, *(int*)(&llvm_cbe_tmp__12));
printf("\nReturn  = %f",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [1024 x float]* %%FFTIn_I, i64 0, i64 %%2, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__16 = (float *)(&llvm_cbe_FFTIn_I[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__8) < 1024 && "Write access out of array 'FFTIn_I' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%9, float* %%10, align 4, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_88_count);
  *llvm_cbe_tmp__16 = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add nsw i32 %%storemerge18, 1, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_storemerge18&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
  if (((llvm_cbe_tmp__17&4294967295U) == (1024u&4294967295U))) {
    llvm_cbe_storemerge117__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader16;
  } else {
    llvm_cbe_storemerge18__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__17;   /* for PHI node */
    goto llvm_cbe_tmp__102;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader16' to make GCC happy */
llvm_cbe__2e_preheader16:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge117 = phi i32 [ %%49, %%.preheader16 ], [ 0, %%1  for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_storemerge117_count);
  llvm_cbe_storemerge117 = (unsigned int )llvm_cbe_storemerge117__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge117 = 0x%X",llvm_cbe_storemerge117);
printf("\n = 0x%X",llvm_cbe_tmp__55);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%storemerge117 to i64, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__18 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge117);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [1024 x float]* %%FFTIn_R, i64 0, i64 %%12, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__19 = (float *)(&llvm_cbe_FFTIn_R[(((signed long long )llvm_cbe_tmp__18))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__18) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'FFTIn_R' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load float* %%13, align 4, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__20 = (float )*llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__20, *(int*)(&llvm_cbe_tmp__20));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = shl i32 %%storemerge117, 9, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__21 = (unsigned int )llvm_cbe_storemerge117 << 9u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = and i32 %%15, 512, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__22 = (unsigned int )llvm_cbe_tmp__21 & 512u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = shl i32 %%storemerge117, 7, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__23 = (unsigned int )llvm_cbe_storemerge117 << 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = and i32 %%17, 256, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__24 = (unsigned int )llvm_cbe_tmp__23 & 256u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = shl i32 %%storemerge117, 5, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__25 = (unsigned int )llvm_cbe_storemerge117 << 5u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = and i32 %%19, 128, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__26 = (unsigned int )llvm_cbe_tmp__25 & 128u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = shl i32 %%storemerge117, 3, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__27 = (unsigned int )llvm_cbe_storemerge117 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = and i32 %%21, 64, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__28 = (unsigned int )llvm_cbe_tmp__27 & 64u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = shl i32 %%storemerge117, 1, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__29 = (unsigned int )llvm_cbe_storemerge117 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = and i32 %%23, 32, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__30 = (unsigned int )llvm_cbe_tmp__29 & 32u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = lshr i32 %%storemerge117, 1, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge117&4294967295ull)) >> ((unsigned int )(1u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = and i32 %%25, 16, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__32 = (unsigned int )llvm_cbe_tmp__31 & 16u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = lshr i32 %%storemerge117, 3, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__33 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge117&4294967295ull)) >> ((unsigned int )(3u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__33&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = and i32 %%27, 8, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__34 = (unsigned int )llvm_cbe_tmp__33 & 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = lshr i32 %%storemerge117, 5, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge117&4294967295ull)) >> ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = and i32 %%29, 4, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__36 = (unsigned int )llvm_cbe_tmp__35 & 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = lshr i32 %%storemerge117, 7, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__37 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge117&4294967295ull)) >> ((unsigned int )(7u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__37&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = and i32 %%31, 2, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__38 = (unsigned int )llvm_cbe_tmp__37 & 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = lshr i32 %%storemerge117, 9, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__39 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge117&4294967295ull)) >> ((unsigned int )(9u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__39&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = and i32 %%33, 1, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__40 = (unsigned int )llvm_cbe_tmp__39 & 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = or i32 %%32, %%34, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__41 = (unsigned int )llvm_cbe_tmp__38 | llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = or i32 %%35, %%30, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_160_count);
  llvm_cbe_tmp__42 = (unsigned int )llvm_cbe_tmp__41 | llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = or i32 %%36, %%28, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__43 = (unsigned int )llvm_cbe_tmp__42 | llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = or i32 %%37, %%26, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__44 = (unsigned int )llvm_cbe_tmp__43 | llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = or i32 %%38, %%24, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__45 = (unsigned int )llvm_cbe_tmp__44 | llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = or i32 %%39, %%22, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__46 = (unsigned int )llvm_cbe_tmp__45 | llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = or i32 %%40, %%20, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__47 = (unsigned int )llvm_cbe_tmp__46 | llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = or i32 %%41, %%18, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__48 = (unsigned int )llvm_cbe_tmp__47 | llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = or i32 %%42, %%16, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__49 = (unsigned int )llvm_cbe_tmp__48 | llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = sext i32 %%43 to i64, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__50 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds [1024 x float]* %%FFTOut_R, i64 0, i64 %%44, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__51 = (float *)(&llvm_cbe_FFTOut_R[(((signed long long )llvm_cbe_tmp__50))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__50));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__50) < 1024 && "Write access out of array 'FFTOut_R' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%14, float* %%45, align 4, !dbg !7 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_170_count);
  *llvm_cbe_tmp__51 = llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds [1024 x float]* %%FFTIn_I, i64 0, i64 %%12, !dbg !8 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__52 = (float *)(&llvm_cbe_FFTIn_I[(((signed long long )llvm_cbe_tmp__18))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__18) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'FFTIn_I' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load float* %%46, align 4, !dbg !8 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__53 = (float )*llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__53, *(int*)(&llvm_cbe_tmp__53));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [1024 x float]* %%FFTOut_I, i64 0, i64 %%44, !dbg !8 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__54 = (float *)(&llvm_cbe_FFTOut_I[(((signed long long )llvm_cbe_tmp__50))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__50));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__50) < 1024 && "Write access out of array 'FFTOut_I' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%47, float* %%48, align 4, !dbg !8 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_174_count);
  *llvm_cbe_tmp__54 = llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add nsw i32 %%storemerge117, 1, !dbg !8 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__55 = (unsigned int )((unsigned int )(llvm_cbe_storemerge117&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__55&4294967295ull)));
  if (((llvm_cbe_tmp__55&4294967295U) == (1024u&4294967295U))) {
    llvm_cbe_storemerge215__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_preheader14;
  } else {
    llvm_cbe_storemerge117__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__55;   /* for PHI node */
    goto llvm_cbe__2e_preheader16;
  }

  } while (1); /* end of syntactic loop '.preheader16' */
  do {     /* Syntactic loop '.preheader14' to make GCC happy */
llvm_cbe__2e_preheader14:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge215 = phi i32 [ %%88, %%._crit_edge13 ], [ 1, %%.preheader16  for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_storemerge215_count);
  llvm_cbe_storemerge215 = (unsigned int )llvm_cbe_storemerge215__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge215 = 0x%X",llvm_cbe_storemerge215);
printf("\n = 0x%X",llvm_cbe_tmp__90);
printf("\n = 0x%X",1u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = shl i32 1, %%storemerge215, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_222_count);
  llvm_cbe_tmp__56 = (unsigned int )1u << llvm_cbe_storemerge215;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = ashr i32 %%50, 1, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__57 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__56) >> ((signed int )1u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__57));
  if ((((signed int )llvm_cbe_tmp__57) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph12;
  } else {
    goto llvm_cbe__2e__crit_edge13;
  }

llvm_cbe__2e__crit_edge13:
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = add nsw i32 %%storemerge215, 1, !dbg !11 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_344_count);
  llvm_cbe_tmp__90 = (unsigned int )((unsigned int )(llvm_cbe_storemerge215&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__90&4294967295ull)));
  if (((llvm_cbe_tmp__90&4294967295U) == (11u&4294967295U))) {
    llvm_cbe_storemerge38__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge215__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__90;   /* for PHI node */
    goto llvm_cbe__2e_preheader14;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__103:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge410 = phi i32 [ 0, %%.lr.ph12 ], [ %%87, %%._crit_edge  for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_storemerge410_count);
  llvm_cbe_storemerge410 = (unsigned int )llvm_cbe_storemerge410__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge410 = 0x%X",llvm_cbe_storemerge410);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__89);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = mul nsw i32 %%storemerge410, %%53, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(llvm_cbe_storemerge410&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__58&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = sext i32 %%55 to i64, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__60 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds [512 x float]* @W_real, i64 0, i64 %%56, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__61 = (float *)(&W_real[(((signed long long )llvm_cbe_tmp__60))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__60));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__60) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W_real' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load float* %%57, align 4, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__62 = (float )*llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__62, *(int*)(&llvm_cbe_tmp__62));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = getelementptr inbounds [512 x float]* @W_imag, i64 0, i64 %%56, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__63 = (float *)(&W_imag[(((signed long long )llvm_cbe_tmp__60))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__60));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__60) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'W_imag' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load float* %%59, align 4, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__64 = (float )*llvm_cbe_tmp__63;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__64, *(int*)(&llvm_cbe_tmp__64));
  if ((((signed int )llvm_cbe_storemerge410) < ((signed int )1024u))) {
    llvm_cbe_storemerge59__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge410;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = add nsw i32 %%storemerge410, 1, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_342_count);
  llvm_cbe_tmp__89 = (unsigned int )((unsigned int )(llvm_cbe_storemerge410&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__89&4294967295ull)));
  if (((llvm_cbe_tmp__89&4294967295U) == (llvm_cbe_tmp__57&4294967295U))) {
    goto llvm_cbe__2e__crit_edge13;
  } else {
    llvm_cbe_storemerge410__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__89;   /* for PHI node */
    goto llvm_cbe_tmp__103;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge59 = phi i32 [ %%85, %%.lr.ph ], [ %%storemerge410, %%54  for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_storemerge59_count);
  llvm_cbe_storemerge59 = (unsigned int )llvm_cbe_storemerge59__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge59 = 0x%X",llvm_cbe_storemerge59);
printf("\n = 0x%X",llvm_cbe_tmp__88);
printf("\nstoremerge410 = 0x%X",llvm_cbe_storemerge410);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = add nsw i32 %%storemerge59, %%51, !dbg !8 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__65 = (unsigned int )((unsigned int )(llvm_cbe_storemerge59&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__57&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__65&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = sext i32 %%62 to i64, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__66 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds [1024 x float]* %%FFTOut_R, i64 0, i64 %%63, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__67 = (float *)(&llvm_cbe_FFTOut_R[(((signed long long )llvm_cbe_tmp__66))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__66) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'FFTOut_R' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load float* %%64, align 4, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__68 = (float )*llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__68, *(int*)(&llvm_cbe_tmp__68));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = fmul float %%65, %%58, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__69 = (float )((float )(llvm_cbe_tmp__68 * llvm_cbe_tmp__62));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__69, *(int*)(&llvm_cbe_tmp__69));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = getelementptr inbounds [1024 x float]* %%FFTOut_I, i64 0, i64 %%63, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_266_count);
  llvm_cbe_tmp__70 = (float *)(&llvm_cbe_FFTOut_I[(((signed long long )llvm_cbe_tmp__66))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__66) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'FFTOut_I' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = load float* %%67, align 4, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_267_count);
  llvm_cbe_tmp__71 = (float )*llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__71, *(int*)(&llvm_cbe_tmp__71));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = fmul float %%68, %%60, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_268_count);
  llvm_cbe_tmp__72 = (float )((float )(llvm_cbe_tmp__71 * llvm_cbe_tmp__64));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__72, *(int*)(&llvm_cbe_tmp__72));
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = fsub float %%66, %%69, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_269_count);
  llvm_cbe_tmp__73 = (float )((float )(llvm_cbe_tmp__69 - llvm_cbe_tmp__72));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__73, *(int*)(&llvm_cbe_tmp__73));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = fmul float %%68, %%58, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_273_count);
  llvm_cbe_tmp__74 = (float )((float )(llvm_cbe_tmp__71 * llvm_cbe_tmp__62));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__74, *(int*)(&llvm_cbe_tmp__74));
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = fmul float %%65, %%60, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__75 = (float )((float )(llvm_cbe_tmp__68 * llvm_cbe_tmp__64));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__75, *(int*)(&llvm_cbe_tmp__75));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = fadd float %%71, %%72, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__76 = (float )((float )(llvm_cbe_tmp__74 + llvm_cbe_tmp__75));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__76, *(int*)(&llvm_cbe_tmp__76));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = sext i32 %%storemerge59 to i64, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_279_count);
  llvm_cbe_tmp__77 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge59);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds [1024 x float]* %%FFTOut_R, i64 0, i64 %%74, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_280_count);
  llvm_cbe_tmp__78 = (float *)(&llvm_cbe_FFTOut_R[(((signed long long )llvm_cbe_tmp__77))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__77));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__77) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'FFTOut_R' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = load float* %%75, align 4, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__79 = (float )*llvm_cbe_tmp__78;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__79, *(int*)(&llvm_cbe_tmp__79));
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = fsub float %%76, %%70, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__80 = (float )((float )(llvm_cbe_tmp__79 - llvm_cbe_tmp__73));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__80, *(int*)(&llvm_cbe_tmp__80));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__66) < 1024 && "Write access out of array 'FFTOut_R' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%77, float* %%64, align 4, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_283_count);
  *llvm_cbe_tmp__67 = llvm_cbe_tmp__80;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = getelementptr inbounds [1024 x float]* %%FFTOut_I, i64 0, i64 %%74, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__81 = (float *)(&llvm_cbe_FFTOut_I[(((signed long long )llvm_cbe_tmp__77))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__77));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__77) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'FFTOut_I' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = load float* %%78, align 4, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__82 = (float )*llvm_cbe_tmp__81;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__82, *(int*)(&llvm_cbe_tmp__82));
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = fsub float %%79, %%73, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_286_count);
  llvm_cbe_tmp__83 = (float )((float )(llvm_cbe_tmp__82 - llvm_cbe_tmp__76));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__83, *(int*)(&llvm_cbe_tmp__83));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__66) < 1024 && "Write access out of array 'FFTOut_I' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%80, float* %%67, align 4, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_287_count);
  *llvm_cbe_tmp__70 = llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__83);

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__77) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'FFTOut_R' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = load float* %%75, align 4, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__84 = (float )*llvm_cbe_tmp__78;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__84, *(int*)(&llvm_cbe_tmp__84));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = fadd float %%81, %%70, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_289_count);
  llvm_cbe_tmp__85 = (float )((float )(llvm_cbe_tmp__84 + llvm_cbe_tmp__73));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__85, *(int*)(&llvm_cbe_tmp__85));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__77) < 1024 && "Write access out of array 'FFTOut_R' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%82, float* %%75, align 4, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_290_count);
  *llvm_cbe_tmp__78 = llvm_cbe_tmp__85;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__85);

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__77) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'FFTOut_I' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = load float* %%78, align 4, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__86 = (float )*llvm_cbe_tmp__81;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__86, *(int*)(&llvm_cbe_tmp__86));
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = fadd float %%83, %%73, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_292_count);
  llvm_cbe_tmp__87 = (float )((float )(llvm_cbe_tmp__86 + llvm_cbe_tmp__76));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__87, *(int*)(&llvm_cbe_tmp__87));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__77) < 1024 && "Write access out of array 'FFTOut_I' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store float %%84, float* %%78, align 4, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_293_count);
  *llvm_cbe_tmp__81 = llvm_cbe_tmp__87;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = add nsw i32 %%storemerge59, %%50, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_294_count);
  llvm_cbe_tmp__88 = (unsigned int )((unsigned int )(llvm_cbe_storemerge59&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__56&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__88&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__88) < ((signed int )1024u))) {
    llvm_cbe_storemerge59__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__88;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph12:
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = lshr i32 1024, %%storemerge215, !dbg !10 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__58 = (unsigned int )((unsigned int )(((unsigned int )(1024u&4294967295ull)) >> ((unsigned int )(llvm_cbe_storemerge215&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__58&4294967295ull)));
  llvm_cbe_storemerge410__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__103;

  } while (1); /* end of syntactic loop '.preheader14' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge38 = phi i32 [ %%99, %%.preheader ], [ 0, %%._crit_edge13  for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_storemerge38_count);
  llvm_cbe_storemerge38 = (unsigned int )llvm_cbe_storemerge38__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge38 = 0x%X",llvm_cbe_storemerge38);
printf("\n = 0x%X",llvm_cbe_tmp__101);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = sext i32 %%storemerge38 to i64, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__91 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge38);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = getelementptr inbounds [1024 x float]* %%FFTOut_R, i64 0, i64 %%89, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__92 = (float *)(&llvm_cbe_FFTOut_R[(((signed long long )llvm_cbe_tmp__91))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__91));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__91) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'FFTOut_R' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = load float* %%90, align 4, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__93 = (float )*llvm_cbe_tmp__92;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__93, *(int*)(&llvm_cbe_tmp__93));
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = getelementptr inbounds [1024 x float]* %%FFTOut_I, i64 0, i64 %%89, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__94 = (float *)(&llvm_cbe_FFTOut_I[(((signed long long )llvm_cbe_tmp__91))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__91));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__91) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'FFTOut_I' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = load float* %%92, align 4, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_356_count);
  llvm_cbe_tmp__95 = (float )*llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__95, *(int*)(&llvm_cbe_tmp__95));
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = fmul float %%93, 0.000000e+00, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__96 = (float )((float )(llvm_cbe_tmp__95 * 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__96, *(int*)(&llvm_cbe_tmp__96));
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = fadd float %%93, 0.000000e+00, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__97 = (float )((float )(llvm_cbe_tmp__95 + 0x0p0));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__97, *(int*)(&llvm_cbe_tmp__97));
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = fadd float %%91, %%94, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__98 = (float )((float )(llvm_cbe_tmp__93 + llvm_cbe_tmp__96));
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__98, *(int*)(&llvm_cbe_tmp__98));
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = getelementptr inbounds { float, float }* %%FFT_output, i64 %%89, i32 0, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__99 = (float *)(&llvm_cbe_FFT_output[(((signed long long )llvm_cbe_tmp__91))].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__91));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = getelementptr inbounds { float, float }* %%FFT_output, i64 %%89, i32 1, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__100 = (float *)(&llvm_cbe_FFT_output[(((signed long long )llvm_cbe_tmp__91))].field1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__91));
}
if (AESL_DEBUG_TRACE)
printf("\n  store float %%96, float* %%97, align 4, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_362_count);
  *llvm_cbe_tmp__99 = llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  store float %%95, float* %%98, align 4, !dbg !5 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_363_count);
  *llvm_cbe_tmp__100 = llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = add nsw i32 %%storemerge38, 1, !dbg !9 for 0x%I64xth hint within @FFTipfn_gold  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__101 = (unsigned int )((unsigned int )(llvm_cbe_storemerge38&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__101&4294967295ull)));
  if (((llvm_cbe_tmp__101&4294967295U) == (1024u&4294967295U))) {
    goto llvm_cbe_tmp__104;
  } else {
    llvm_cbe_storemerge38__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__101;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__104:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @FFTipfn_gold}\n");
  return;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_fftin_count = 0;
  l_unnamed_0 llvm_cbe_fftin[1024];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_fftouth_count = 0;
  l_unnamed_0 llvm_cbe_fftouth[1024];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_fftouts_count = 0;
  l_unnamed_0 llvm_cbe_fftouts[1024];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  l_unnamed_0 *llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  l_unnamed_0 *llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  l_unnamed_0 *llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  unsigned int llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  unsigned int llvm_cbe_tmp__108;
  unsigned int llvm_cbe_tmp__108__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  float *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  float llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  float *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  float llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  float *llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  float llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  float *llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  float llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  bool llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  unsigned int llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts1_count = 0;
  unsigned int llvm_cbe_puts1;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [1024 x { float, float }]* %%fftin, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_418_count);
  llvm_cbe_tmp__105 = (l_unnamed_0 *)(&llvm_cbe_fftin[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @init_arr({ float, float }* %%1), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_419_count);
  init_arr((l_unnamed_0 *)llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [1024 x { float, float }]* %%fftouts, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_420_count);
  llvm_cbe_tmp__106 = (l_unnamed_0 *)(&llvm_cbe_fftouts[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @FFTipfn_gold({ float, float }* %%1, { float, float }* %%2), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_421_count);
  FFTipfn_gold((l_unnamed_0 *)llvm_cbe_tmp__105, (l_unnamed_0 *)llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [1024 x { float, float }]* %%fftouth, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_422_count);
  llvm_cbe_tmp__107 = (l_unnamed_0 *)(&llvm_cbe_fftouth[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1024
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @FFTipfn({ float, float }* %%1, { float, float }* %%3) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_423_count);
  FFTipfn((l_unnamed_0 *)llvm_cbe_tmp__105, (l_unnamed_0 *)llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__108__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__120;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__120:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i32 [ 0, %%0 ], [ %%18, %%4  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__119);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = phi i32 [ 0, %%0 ], [ %%., %%4  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_430_count);
  llvm_cbe_tmp__108 = (unsigned int )llvm_cbe_tmp__108__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__108);
printf("\n = 0x%X",0u);
printf("\n. = 0x%X",llvm_cbe__2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%storemerge2 to i64, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_431_count);
  llvm_cbe_tmp__109 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [1024 x { float, float }]* %%fftouth, i64 0, i64 %%6, i32 0, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_432_count);
  llvm_cbe_tmp__110 = (float *)(&llvm_cbe_fftouth[(((signed long long )llvm_cbe_tmp__109))
#ifdef AESL_BC_SIM
 % 1024
#endif
].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__109));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__109) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'fftouth' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load float* %%7, align 8, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_433_count);
  llvm_cbe_tmp__111 = (float )*llvm_cbe_tmp__110;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__111, *(int*)(&llvm_cbe_tmp__111));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [1024 x { float, float }]* %%fftouth, i64 0, i64 %%6, i32 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__112 = (float *)(&llvm_cbe_fftouth[(((signed long long )llvm_cbe_tmp__109))
#ifdef AESL_BC_SIM
 % 1024
#endif
].field1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__109));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__109) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'fftouth' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load float* %%9, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_435_count);
  llvm_cbe_tmp__113 = (float )*llvm_cbe_tmp__112;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__113, *(int*)(&llvm_cbe_tmp__113));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [1024 x { float, float }]* %%fftouts, i64 0, i64 %%6, i32 0, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__114 = (float *)(&llvm_cbe_fftouts[(((signed long long )llvm_cbe_tmp__109))
#ifdef AESL_BC_SIM
 % 1024
#endif
].field0);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__109));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__109) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'fftouts' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load float* %%11, align 8, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_437_count);
  llvm_cbe_tmp__115 = (float )*llvm_cbe_tmp__114;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__115, *(int*)(&llvm_cbe_tmp__115));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [1024 x { float, float }]* %%fftouts, i64 0, i64 %%6, i32 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_438_count);
  llvm_cbe_tmp__116 = (float *)(&llvm_cbe_fftouts[(((signed long long )llvm_cbe_tmp__109))
#ifdef AESL_BC_SIM
 % 1024
#endif
].field1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__109));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__109) < 1024)) fprintf(stderr, "%s:%d: warning: Read access out of array 'fftouts' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load float* %%13, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_439_count);
  llvm_cbe_tmp__117 = (float )*llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = %f,  0x%x\n", llvm_cbe_tmp__117, *(int*)(&llvm_cbe_tmp__117));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = or i1 %%15, %%16, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_442_count);
  llvm_cbe_tmp__118 = (bool )(((llvm_fcmp_une(llvm_cbe_tmp__111, llvm_cbe_tmp__115)) | (llvm_fcmp_une(llvm_cbe_tmp__113, llvm_cbe_tmp__117)))&1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__118);
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%17, i32 1, i32 %%5, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((llvm_cbe_tmp__118) ? ((unsigned int )1u) : ((unsigned int )llvm_cbe_tmp__108));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge2, 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_443_count);
  llvm_cbe_tmp__119 = (unsigned int )((unsigned int )(llvm_cbe_storemerge2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__119&4294967295ull)));
  if (((llvm_cbe_tmp__119&4294967295U) == (1024u&4294967295U))) {
    goto llvm_cbe_tmp__121;
  } else {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__119;   /* for PHI node */
    llvm_cbe_tmp__108__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_;   /* for PHI node */
    goto llvm_cbe_tmp__120;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__121:
  if (((llvm_cbe__2e_&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__122;
  } else {
    goto llvm_cbe_tmp__123;
  }

llvm_cbe_tmp__123:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([7 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__124;

llvm_cbe_tmp__122:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts1 = call i32 @puts(i8* getelementptr inbounds ([7 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts1_count);
  puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts1 = 0x%X",llvm_cbe_puts1);
}
  goto llvm_cbe_tmp__124;

llvm_cbe_tmp__124:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe__2e_;
}

