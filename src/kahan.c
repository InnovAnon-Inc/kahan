#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

/*#define NDEBUG 1*/

#ifndef NDEBUG
#include <stdio.h>
#endif

/*#include <math.h>*/

#include <kahan.h>

__attribute__ ((nonnull (1), nothrow))
void init_kahan (kahan_t *restrict kahan) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
   init_kahan2 (kahan, 0.0);
	#pragma GCC diagnostic pop
}

__attribute__ ((nonnull (1), nothrow))
void init_kahan2 (kahan_t *restrict kahan, double initial) {
   kahan->sum = initial;
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
   kahan->c   = 0.0;
	#pragma GCC diagnostic pop
}

__attribute__ ((leaf, nonnull (1), nothrow))
void update_kahan (kahan_t *restrict kahan, double input) {
   double y = input - kahan->c; /* So far, so good: c is zero. */
   double t = kahan->sum + y; /* Alas, sum is big, y small, so low-order
                                * digits of y are lost. */
#ifndef NDEBUG
   printf ("input:%g\n", input);      fflush (stdout);
   printf ("sum  :%g\n", kahan->sum); fflush (stdout);
   printf ("c    :%g\n", kahan->c);   fflush (stdout);
#endif
   kahan->c = (t - kahan->sum) - y; /* (t - sum) cancels the high-order part
                                     * of y; subtracting y recovers negative
                                     * (low part of y) */
   kahan->sum = t; /* Algebraically, c should always be zero. Beware
                    * overly-aggressive optimizing compilers! */
   /* Next time around, the lost low part will be added to y in a fresh
    * attempt. */
#ifndef NDEBUG
   printf ("sum  :%g\n", kahan->sum); fflush (stdout);
   printf ("c    :%g\n", kahan->c);   fflush (stdout);
   puts (""); fflush (stdout);
#endif
}

__attribute__ ((const, nonnull (1), nothrow, warn_unused_result))
double ez_kahan (
   double const vals[], size_t nval) {
   kahan_t k;
   size_t i;
   if (nval == 0)
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
      return 0.0;
	#pragma GCC diagnostic pop
   init_kahan2 (&k, vals[0]);
   for (i = 1; i != nval; i++)
      update_kahan (&k, vals[i]);
   return k.sum;
}
