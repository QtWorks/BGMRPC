#ifndef JSPLUGIN_GLOBAL_H
#define JSPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(JSPLUGIN_LIBRARY)
#  define JSPLUGINSHARED_EXPORT Q_DECL_EXPORT
#else
#  define JSPLUGINSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // JSPLUGIN_GLOBAL_H