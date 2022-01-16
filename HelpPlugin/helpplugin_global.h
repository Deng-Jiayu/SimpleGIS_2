#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(HELPPLUGIN_LIB)
#  define HELPPLUGIN_EXPORT Q_DECL_EXPORT
# else
#  define HELPPLUGIN_EXPORT Q_DECL_IMPORT
# endif
#else
# define HELPPLUGIN_EXPORT
#endif
