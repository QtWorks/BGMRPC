#ifndef CHATPLUGIN_GLOBAL_H
#define CHATPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CHATPLUGIN_LIBRARY)
#  define CHATPLUGINSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CHATPLUGINSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CHATPLUGIN_GLOBAL_H