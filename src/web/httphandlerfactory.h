#pragma once

class HttpHandlerFactory : public HttpRequestHandlerFactory
{
public:
    virtual HttpRequestHandler *handleRequest(HttpRequest *_req, HttpResponse *_res) override;
};

