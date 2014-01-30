#-------------------------------------------------
#
# Project created by QtCreator 2013-11-26T19:12:17
#
#-------------------------------------------------

QT       += core gui network xmlpatterns webkit

TARGET = HTMLDataExtract
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    graph.cpp \
    lib/qcustomplot/qcustomplot.cpp \
    symbollistdialog.cpp \
    lib/nightcharts/nightcharts.cpp \
    statschart.cpp

HEADERS  += dialog.h \
    graph.h \
    lib/qcustomplot/qcustomplot.h \
    symbollistdialog.h \
    lib/nightcharts/nightcharts.h \
    statschart.h

FORMS    += dialog.ui \
    graph.ui \
    symbollistdialog.ui

RESOURCES += \
    res.qrc \

OTHER_FILES += \
    ico.rc \

RC_FILE = ico.rc
