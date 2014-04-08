#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([httplog], [0.1], [tadas@chartbeat.com])
AM_SILENT_RULES([no])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR(config)
AM_INIT_AUTOMAKE(-Wall -Werror tar-ustar foreign subdir-objects)

# This lets us use PACKAGE_VERSION in Makefiles
AC_SUBST(PACKAGE_VERSION)

# Checks for programs.
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_11
AC_PROG_CC

CFLAGS="$CFLAGS -Werror -Wall -g -ggdb"
CXXFLAGS="$CXXFLAGS -Werror -Wall -fno-exceptions -g -ggdb"

# Checks for libraries.
AC_CHECK_LIB([event], [evhttp_new], [], AC_MSG_ERROR(["libevent is required"]))

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
