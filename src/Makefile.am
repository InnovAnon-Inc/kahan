AM_CPPFLAGS = -D__STDC_INT64__

#if USE_SUBMODULES
#SUBDIRS = ../glitter
#AM_CPPFLAGS += -I $(top_srcdir)/glitter/src
#endif

lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

#include Makefile-LIBADD.inc
dist_bin_SCRIPTS = libkahan_config libneumaier_config kahan_test_config neumaier_test_config

lib_LTLIBRARIES += libkahan.la
#libkahan_la_LIBADD = $(LIBKAHAN_LIBADD)
libkahan_la_LIBADD = @LIBKAHAN_LIBADD@
include_HEADERS += kahan.h
bin_PROGRAMS += kahan-test
#kahan_test_LDADD = libkahan.la $(LIBKAHAN_LIBADD)
#kahan_test_LDADD = $(KAHAN_TEST_LIBADD)
kahan_test_LDADD = @KAHAN_TEST_LIBADD@
EXTRA_kahan_test_DEPENDENCIES = libkahan.la

lib_LTLIBRARIES += libneumaier.la
#libneumaier_la_LIBADD = $(LIBNEUMAIER_LIBADD)
libneumaier_la_LIBADD = @LIBNEUMAIER_LIBADD@
include_HEADERS += neumaier.h
bin_PROGRAMS += neumaier-test
#neumaier_test_LDADD = libneumaier.la $(LIBNEUMAIER_LIBADD)
#neumaier_test_LDADD = $(NEUMAIER_TEST_LIBADD)
neumaier_test_LDADD = @NEUMAIER_TEST_LIBADD@
EXTRA_neumaier_test_DEPENDENCIES = libneumaier.la

# TODO parallel pairwise summation with FFT and neumaier
