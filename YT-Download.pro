TEMPLATE = app
TARGET = YTDownload

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x050F00

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h

SOURCES += \
    main.cpp \
    mainwindow.cpp

DISTFILES += \
    LICENSE \
    setup.sh \
    uninstall.sh
