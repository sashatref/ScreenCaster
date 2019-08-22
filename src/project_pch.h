#pragma once

#include <QDebug>
#include <QPixmap>
#include <QDesktopWidget>
#include <QScreen>
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonObject>
#include <QThreadPool>
#include <QHostAddress>
#include <QTimer>
#include <QPainter>
#include <QMainWindow>
#include <QCommandLineParser>


#include <PropertyBrowser3/settingsform.h>
#include <PropertyBrowser3/Editors/editorproperties.h>
#include <PropertyBrowser3/ipropertyinfomap.h>
#include <PropertyBrowser3/propertybrowser3.h>

#include <HelperLibrary/functions.h>
#include <HelperLibrary/Widgets/infowindow.h>
#include <HelperLibrary/Widgets/widgethelper.h>
#include <HelperLibrary/setgetMacro.h>
#include <HelperLibrary/igadget.h>
#include <HelperLibrary/singleton.hpp>
#include <HelperLibrary/Exceptions/userexception.h>
#include <HelperLibrary/Widgets/extendedmainwindow.h>
#include <HelperLibrary/ExtendApp/extendapp.h>
#include <HelperLibrary/Widgets/singlewidget.h>
#include <HelperLibrary/Widgets/aboutdialog.h>
#include <HelperLibrary/Win/processinfomonitor.h>

#include <CustomWidgets/ClipRectangle/ClipRectangle.h>
#include <CustomWidgets/ClipRectangle/rectgrabber.h>
#include <CustomWidgets/TrayMenu/traymenu.h>

#include <HttpServer2/httpserver.h>
#include <HttpServer2/httprequest.h>
#include <HttpServer2/httprequesthandler.h>
#include <HttpServer2/httprequesthandlerfactory.h>
#include <HttpServer2/httpresponse.h>
#include <HttpServer2/Handlers/filesystemrequesthandler.h>
#include <HttpServer2/api/icommandhandler.h>
#include <HttpServer2/Handlers/restapihandler.h>
#include <HttpServer2/WebSocketApi/websocketapi.h>
#include <HttpServer2/WebSocketApi/websocketserver.h>
#include <HttpServer2/WebSocketApi/basewshandler.h>
#include <HttpServer2/Handlers/datacommandhandler.h>
#include <HttpServer2/Handlers/commoncommandhandler.h>


using namespace HttpServer2Qt;
using namespace WebSocketApiQt;

using namespace HelperLibraryNS;

using Text::format;
