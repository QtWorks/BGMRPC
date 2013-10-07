#ifndef JSPLUGIN_H
#define JSPLUGIN_H

#include <QtScript>
#include <bgmrobject.h>
#include <bgmradaptor.h>
#include <relatedproc.h>
#include "jsplugin_global.h"
#include "jsmetatype.h"
#include "jsobjectprototype.h"

using namespace BGMircroRPCServer;

class jsObj;
class jsAdaptor;

class jsObj : public BGMRObject < jsAdaptor >
{
public:
//    jsObj (BGMRPC* rpc);
    jsObj ();

    QString objectType () const;
    bool procIdentify (BGMRProcedure* p, const QJsonObject& call);
    QJsonArray loadJsScript (BGMRProcedure*, const QJsonArray& args);
    bool loadJsScriptFile (const QString& jsFileName, QString& error);
    QJsonArray js (BGMRProcedure*p, const QJsonArray& args);
    relatedProcs* relProcs ();
    void setRPC (BGMRPC* rpc);

private:
    QScriptEngine JsEngine;
    QScriptValue v;
    relatedProcs RelProcs;
    jsRPC JSRPC;
    jsProcClass* JsProcClass;
    jsJsObjClass* JsJsObjClass;
    jsRPCObjectClass* JsRPCObjectClass;
    jsSqlQueryClass* JsSqlClass;
    jsDB JsDB;

    void initial ();
    bool loadJsScriptContent (const QString& jsContent, QString& error,
                              const QString& jsFileName = QString ());
    static QScriptValue jsDebug (QScriptContext *context, QScriptEngine *);
};

Q_DECLARE_METATYPE (const jsObj*)
Q_DECLARE_METATYPE (jsObj*)


class jsAdaptor : public BGMRAdaptor < jsObj >
{
public:
    jsAdaptor () { registerMethods (); }
    void registerMethods ();
};

extern "C" {
BGMRObjectInterface* objCreator ();
QString objType ();
bool initial (BGMRObjectStorage* storage, BGMRPC*rpc);
}

#endif // JSPLUGIN_H