AM_CPPFLAGS = -D__STDC_INT64__

SUBDIRS = ../glitter
AM_CPPFLAGS += -I $(top_srcdir)/glitter/src

lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

LIBKAHAN_LIBADD =

lib_LTLIBRARIES += libkahan.la
libkahan_la_LIBADD = $(LIBKAHAN_LIBADD)
include_HEADERS += kahan.h
bin_PROGRAMS += kahan-test
kahan_test_LDADD = libkahan.la $(LIBKAHAN_LIBADD)

LIBNEUMAIER_LIBADD = -lm

lib_LTLIBRARIES += libneumaier.la
libneumaier_la_SOURCES = neumaier.c
libneumaier_la_LIBADD = $(LIBNEUMAIER_LIBADD)
include_HEADERS += neumaier.h
bin_PROGRAMS += neumaier-test
neumaier_test_LDADD = libneumaier.la $(LIBNEUMAIER_LIBADD)

# TODO parallel pairwise summation with FFT and neumaier
