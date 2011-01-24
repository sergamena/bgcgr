#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# Init
AC_PREREQ([2.64])
AC_INIT([bgcgr], [0.1], [gor1024@mail.ru])
AC_CONFIG_SRCDIR([src/main.cc])
AC_CONFIG_HEADERS([src/config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
IT_PROG_INTLTOOL([0.40.4])

# For intltool
LOCALEDIR=${localedir}
GETTEXT_PACKAGE=$PACKAGE
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE],["$GETTEXT_PACKAGE"],
	[The domain to use with gettext])
AC_SUBST(GETTEXT_PACKAGE)
AC_SUBST(LOCALEDIR)

# backgrounddir
BACKGROUNDDIR=${datadir}/backgrounds
AC_SUBST(BACKGROUNDDIR)

# Checks for gtkmm
PKG_CHECK_MODULES([GTKMM],[gtkmm-2.4 >= 2.8.0])

# Output
AC_CONFIG_FILES([Makefile src/Makefile po/Makefile.in])
AC_OUTPUT
