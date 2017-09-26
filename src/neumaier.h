#ifndef _NEUMAIER_H_
#define _NEUMAIER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

typedef struct {
   double sum;
   double c; /* A running compensation for lost low-order bits. */
} neumaier_t;

void init_neumaier (neumaier_t *restrict neumaier)
__attribute__ ((nonnull (1), nothrow)) ;

void init_neumaier2 (neumaier_t *restrict neumaier, double initial)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void update_neumaier (neumaier_t *restrict neumaier, double input)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void finish_neumaier (neumaier_t *restrict neumaier)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

double ez_neumaier (
   double const vals[], size_t nval)
__attribute__ ((const, nonnull (1), nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _NEUMAIER_H_ */