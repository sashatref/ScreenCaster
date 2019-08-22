#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include "httphandlerfactory.h"
#include "websockethandler.h"

class ServerController : public QObject
{
    Q_OBJECT
public:
    ServerController(QObject *_parent = nullptr);

public slots:
    void start();
    void stop();

    void updateConfig();

private:
    void sendDataValueChanged(const QString &_controlName, const QVariant &_v, const QString &_protocol);

    HttpServer *m_httpServer;
    HttpHandlerFactory *m_handlerFactory;
    WebSocketServer *m_wsServer;

    WebSocketHandler *m_wsHandler = new WebSocketHandler();
};

#endif // SERVERCONTROLLER_H
