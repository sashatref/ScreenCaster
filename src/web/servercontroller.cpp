#include "servercontroller.h"

#include "httphandlerfactory.h"


ServerController::ServerController(QObject *_parent):
    QObject(_parent)
{
    m_httpServer = new HttpServer(new HttpHandlerFactory(), this);

    ServerOptions opt = m_httpServer->getServerOptions();
    opt.addToIndexRedirect();
    m_httpServer->setServerOptions(opt);

    m_wsServer = new WebSocketServer("ScreenCasterServser", 9000, this);
    m_wsServer->setWebSocketApi(m_wsHandler);
}

void ServerController::start()
{
    m_httpServer->start();
    m_wsServer->start();
}

void ServerController::stop()
{
    m_httpServer->stop();
    m_wsServer->stop();
}

void ServerController::updateConfig()
{

}
