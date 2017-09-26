#ifndef _KAHAN_H_
#define _KAHAN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

typedef struct {
   double sum;
   double c;
} kahan_t;

void init_kahan (kahan_t *restrict kahan)
__attribute__ ((nonnull (1), nothrow)) ;

void init_kahan2 (kahan_t *restrict kahan, double initial)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void update_kahan (kahan_t *restrict kahan, double input)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

double ez_kahan (
   double const vals[], size_t nval)
__attribute__ ((const, nonnull (1), nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _KAHAN_H_ */