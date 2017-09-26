#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#define NDEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <kahan.h>

__attribute__ ((nothrow, warn_unused_result))
int main (void) {
   kahan_t kahan;
   double vals[10];
   double sum;
   size_t k;

   srand (time (NULL));
   for (k = 0; k != ARRSZ (vals); k++) {
      int num, dem;
      num = rand ();
      do dem = rand ();
      /*while_check (dem == 0);*/
      while (dem == 0); /* let the PGO tune this */
      vals[k] = (double) num / (double) dem;
   }
   sum = ez_kahan (vals, ARRSZ (vals);

   (void) printf ("sum:%g\n", sum);

   return EXIT_SUCCESS;
}
