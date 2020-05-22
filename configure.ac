AC_INIT([libkahan], [1.0], [InnovAnon-Inc@protonmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 src/libkahan.pc
 src/libneumaier.pc
 src/kahan-test.pc
 src/neumaier-test.pc
])

PKG_PROG_PKG_CONFIG

AC_ARG_ENABLE([use-submodules],
    AS_HELP_STRING([--enable-use-submodules], [Enable use submodules]))
AM_CONDITIONAL([USE_SUBMODULES], [test x"$enable_use_submodules" = "xyes"])

AC_CONFIG_MACRO_DIR([m4])

AC_CHECK_HEADERS([stdlib.h sys/types.h])
AC_CHECK_HEADERS([math.h])
#AC_CHECK_HEADERS([glitter.h])

#AC_CHECK_LIB([stdlib],[])
#AC_CHECK_LIB([math],[fabs])
AC_CHECK_LIB([m],[fabs])

PKG_CHECK_MODULES([GLITTER],[glitter],,)

INNOVANON_WARNINGS([])

AC_OUTPUT

