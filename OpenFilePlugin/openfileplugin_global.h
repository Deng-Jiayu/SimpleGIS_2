#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(OPENFILEPLUGIN_LIB)
#  define OPENFILEPLUGIN_EXPORT Q_DECL_EXPORT
# else
#  define OPENFILEPLUGIN_EXPORT Q_DECL_IMPORT
# endif
#else
# define OPENFILEPLUGIN_EXPORT
#endif
