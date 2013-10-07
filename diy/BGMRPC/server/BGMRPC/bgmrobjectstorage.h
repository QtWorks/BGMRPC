#ifndef BGMROBJECTSTORAGE_H
#define BGMROBJECTSTORAGE_H

#include <QLibrary>
#include "bgmrpc_global.h"

namespace BGMircroRPCServer {

class BGMRObjectInterface;
class BGMRPC;
typedef QMap < QString, BGMRObjectInterface* > objectMap;
typedef BGMRObjectInterface* (*objCreator_T)();
typedef QMap < QString, objCreator_T > objCreatorMap;

class BGMRPCSHARED_EXPORT BGMRObjectStorage
{
public:
    BGMRObjectStorage(BGMRPC* r);
    ~BGMRObjectStorage ();

    bool installObject (const QString& objName,
                        BGMRObjectInterface* obj);
    bool installObject (const QString& objName, const QString& creator);
    bool installPlugin (const QString& pluginFileName);
    BGMRObjectInterface* object (const QString& obj) const;
    QList<BGMRObjectInterface*> objects() const;
    QStringList types () const;

private:
    BGMRPC* RPC;
    objectMap ObjectStorage;
    objCreatorMap ObjCreators;
    //QString BasePluginDir;
};

}

#endif // BGMROBJECTSTORAGE_H