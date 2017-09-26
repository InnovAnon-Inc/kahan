#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#define NDEBUG 1

#ifndef NDEBUG
#include <stdio.h>
#endif

#include <math.h>

#include <neumaier.h>

__attribute__ ((nonnull (1), nothrow))
void init_neumaier (neumaier_t *restrict neumaier) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
   init_neumaier2 (neumaier, 0.0);
	#pragma GCC diagnostic pop
}

__attribute__ ((nonnull (1), nothrow))
void init_neumaier2 (neumaier_t *restrict neumaier, double initial) {
   neumaier->sum = initial;
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
   neumaier->c   = 0.0;
	#pragma GCC diagnostic pop
}

__attribute__ ((leaf, nonnull (1), nothrow))
void update_neumaier (neumaier_t *restrict neumaier, double input) {
   double t = neumaier->sum + input;
   if (fabs (neumaier->sum) >= fabs (input)) {
      neumaier->c += (neumaier->sum - t) + input; /* If sum is bigger,
                                                   * low-order digits of
                                                   * input[i] are lost. */
   } else {
      neumaier->c += (input - t) + neumaier->sum; /* Else low-order digits of
                                                   * sum are lost */
   }
   neumaier->sum = t;
}

__attribute__ ((leaf, nonnull (1), nothrow))
void finish_neumaier (neumaier_t *restrict neumaier) {
   neumaier->sum += neumaier->c; /* Correction only applied once in the very
                                  * end */
}

__attribute__ ((const, nonnull (1), nothrow, warn_unused_result))
double ez_neumaier (
   double const vals[], size_t nval) {
   neumaier_t n;
   size_t i;
#ifndef NDEBUG
      printf ("nval:%d\n", (int) nval); fflush (stdout);
#endif
   if (nval == 0) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
      return 0.0;
	#pragma GCC diagnostic pop
   }
   init_neumaier2 (&n, vals[0]);
#ifndef NDEBUG
      printf ("sum[0]:%g\n", vals[0]); fflush (stdout);
#endif
   for (i = 1; i != nval; i++) {
      update_neumaier (&n, vals[i]);
#ifndef NDEBUG
      printf ("sum[%d]:%g\n", (int) i, vals[i]); fflush (stdout);
#endif
   }
   finish_neumaier (&n);
   return k.sum;
}
