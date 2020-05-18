# Install the pkg-config file.
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = src/libkahan.pc src/libneumaier.pc src/kahan-test.pc src/neumaier-test.pc

DISTCLEANFILES = $(pkgconfig_DATA)
EXTRA_DIST = src/libkahan.pc.in src/libneumaier.pc.in src/kahan-test.pc.in src/neumaier-test.pc.in

SUBDIRS = src
dist_doc_DATA = README.md
ACLOCAL_AMFLAGS = -I m4

