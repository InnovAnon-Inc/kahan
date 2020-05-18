AM_CPPFLAGS = -D__STDC_INT64__

lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

lib_LTLIBRARIES += libkahan.la
libkahan_la_CPPFLAGS = $(GLITTER_CFLAGS)
libkahan_la_LIBADD   = $(GLITTER_LIBS)
include_HEADERS += kahan.h

bin_PROGRAMS += kahan-test
kahan_test_CPPFLAGS =         $(GLITTER_CFLAGS)
kahan_test_LDADD    = -lkahan $(GLITTER_LIBS)
EXTRA_kahan_test_DEPENDENCIES = libkahan.la

lib_LTLIBRARIES += libneumaier.la
libneumaier_la_CPPFLAGS = $(GLITTER_CFLAGS)
#libneumaier_la_LIBADD   = $(GLITTER_LIBS) -lm
libneumaier_la_LIBADD   = $(GLITTER_LIBS)
include_HEADERS += neumaier.h

bin_PROGRAMS += neumaier-test
neumaier_test_CPPFLAGS =            $(GLITTER_CFLAGS)
#neumaier_test_LDADD    = -lneumaier $(GLITTER_LIBS) -lm
neumaier_test_LDADD    = -lneumaier $(GLITTER_LIBS)
EXTRA_neumaier_test_DEPENDENCIES = libneumaier.la

# TODO parallel pairwise summation with FFT and neumaier
