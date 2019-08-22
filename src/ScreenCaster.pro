#/********************************************************************
#	created:
#	filename: 	HttpServer.pro
#	file ext:	qmake project
#	author:		Aleksandr Neborak

#	Copyright (C) Avia Ltd. Ukraine. Kremenchug 2016
#	All Rights Reserved

#	Project:

#*********************************************************************/
QT              += network widgets gui xml

TEMPLATE = app
PRECOMPILED_HEADER = project_pch.h
TARGET = ScreenCaster
DEFINES += AVIA
CONFIG += mpc_comp

LIBS += -lOle32 -lUser32 -lPsapi

INCLUDE_LIBS +=         \
    HelperLibrary       \
    CustomWidgets       \
    PropertyBrowser3    \
    HttpServer2         \
    CustomStylePlugin


include($$(PROJECTS_DIR)/LibraryBuilds/include.pri)

contains(DEFINES, STATIC) {
    QT += websockets
}

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsinfo.cpp \
    utils.cpp \
    web/getimagecommand.cpp \
    web/httphandlerfactory.cpp \
    web/restapihandlerimpl.cpp \
    web/servercontroller.cpp \
    web/websockethandler.cpp

HEADERS += \
    mainwindow.h \
    settingsinfo.h \
    project_pch.h \
    utils.h \
    web/getimagecommand.h \
    web/httphandlerfactory.h \
    web/restapihandlerimpl.h \
    web/servercontroller.h \
    web/websockethandler.h


FORMS += \
    mainwindow.ui

RESOURCES += \
    images.qrc \
    www.qrc


