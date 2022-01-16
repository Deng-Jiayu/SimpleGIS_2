#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FIRSTPLUGIN_LIB)
#  define FIRSTPLUGIN_EXPORT Q_DECL_EXPORT
# else
#  define FIRSTPLUGIN_EXPORT Q_DECL_IMPORT
# endif
#else
# define FIRSTPLUGIN_EXPORT
#endif
