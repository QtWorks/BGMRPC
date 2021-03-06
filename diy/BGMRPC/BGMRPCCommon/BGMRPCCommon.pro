#-------------------------------------------------
#
# Project created by QtCreator 2013-12-04T18:53:52
#
#-------------------------------------------------

QT       += network websockets

QT       -= gui

TARGET = BGMRPCCommon
TEMPLATE = lib

DEFINES += BGMRPCCOMMON_LIBRARY

SOURCES += \
    bgmrpcsocketbuffer.cpp \
    parsejson.cpp

HEADERS +=\
        bgmrpccommon_global.h \
    socket.h \
    bgmrpcsocketbuffer.h \
    parsejson.h

unix {
    target.path = $${PREFIX}/lib
    INSTALLS += target
}

