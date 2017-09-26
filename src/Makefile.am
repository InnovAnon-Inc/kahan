lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

lib_LTLIBRARIES += libkahan.la
libkahan_la_SOURCES = kahan.c
#libkahan_la_LIBADD = -lm
include_HEADERS += kahan.h
bin_PROGRAMS += kahan
kahan_SOURCES = main.c
#kahan_LDADD = libkahan.la -lm
kahan_LDADD = libkahan.la

AM_CPPFLAGS = -D__STDC_INT64__
