#ifndef WEBSOCKETHANDLER_H
#define WEBSOCKETHANDLER_H


class WebSocketHandler : public QObject, public BaseWSHandler
{
    Q_OBJECT
public:
    WebSocketHandler();

private:
    CommandResult getImage(const CommandRequest &_res, QWebSocket *_sock);
};

#endif // WEBSOCKETHANDLER_H
