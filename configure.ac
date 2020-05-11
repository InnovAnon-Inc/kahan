AC_INIT([libkahan], [0.0], [laurence.a.maddox@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])

AC_ARG_ENABLE([use-submodules],
    AS_HELP_STRING([--enable-use-submodules], [Enable use submodules]))
AM_CONDITIONAL([USE_SUBMODULES], [test x"$enable_use_submodules" = "xyes"])

AC_CONFIG_MACRO_DIR([m4])
#AC_CONFIG_SUBDIRS([glitter])

AC_CHECK_HEADERS([stdlib.h sys/types.h])
AC_CHECK_HEADERS([math.h])
AC_CHECK_HEADERS([glitter.h])

#AC_CHECK_LIB([stdlib],[])
AC_CHECK_LIB([math],[fabs])

LIBKAHAN_LIBADD="`PATH=src:$PATH libkahan_config --libs`"
AC_SUBST(LIBKAHAN_LIBADD)

LIBNEUMAIER_LIBADD="`PATH=src:$PATH libneumaier_config --libs`"
AC_SUBST(LIBNEUMAIER_LIBADD)

KAHAN_TEST_LIBADD="libkahan.la `PATH=src:$PATH kahan_test_config --libs`"
AC_SUBST(KAHAN_TEST_LIBADD)

NEUMAIER_TEST_LIBADD="libneumaier.la `PATH=src:$PATH neumaier_test_config --libs`"
AC_SUBST(NEUMAIER_TEST_LIBADD)

INNOVANON_WARNINGS([])

AC_OUTPUT
