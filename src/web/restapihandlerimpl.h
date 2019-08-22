#pragma once

class RestApiHandlerImpl : public RestApiHandler
{
public:
    RestApiHandlerImpl();

    static bool checkRequest(HttpRequest *_req);
};
