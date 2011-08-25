#-------------------------------------------------
#
# Project created by QtCreator 2011-06-21T21:15:54
#
#-------------------------------------------------

QT       += core gui network

TARGET = CodeSearchDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    searchframe.cpp

HEADERS  += mainwindow.h \
    searchframe.h

FORMS    += mainwindow.ui \
    searchframe.ui

RESOURCES += \
    resources.qrc

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib -lqtgdata
