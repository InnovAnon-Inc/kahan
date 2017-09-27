lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

lib_LTLIBRARIES += libkahan.la
libkahan_la_SOURCES = kahan.c
#libkahan_la_LIBADD = -lm
include_HEADERS += kahan.h
bin_PROGRAMS += kahan
kahan_SOURCES = kahan-test.c
#kahan_LDADD = libkahan.la -lm
kahan_LDADD = libkahan.la

lib_LTLIBRARIES += libneumaier.la
libneumaier_la_SOURCES = neumaier.c
libneumaier_la_LIBADD = -lm
include_HEADERS += neumaier.h
bin_PROGRAMS += neumaier
neumaier_SOURCES = neumaier-test.c
neumaier_LDADD = libneumaier.la -lm

# TODO parallel pairwise summation with FFT and neumaier

AM_CPPFLAGS = -D__STDC_INT64__
AM_CPPFLAGS += -I $(srcdir)/../glitter/src
