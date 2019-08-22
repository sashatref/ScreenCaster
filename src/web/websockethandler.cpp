#include "websockethandler.h"



WebSocketHandler::WebSocketHandler()
{
    registerCommand("getImage", this, &WebSocketHandler::getImage);
}

CommandResult WebSocketHandler::getImage(const CommandRequest &_res, QWebSocket *_sock)
{
    return CommandResult();
}
