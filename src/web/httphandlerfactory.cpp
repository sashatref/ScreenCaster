#include "httphandlerfactory.h"
#include "../settingsinfo.h"
#include "restapihandlerimpl.h"


HttpRequestHandler *HttpHandlerFactory::handleRequest(HttpRequest *_req, HttpResponse *_res)
{
    Q_UNUSED(_res);

    SettingsInfo *s = sgSettings::instance();


    const QString path = _req->getUrl().path();

    if(RestApiHandlerImpl::checkRequest(_req))
    {
        RestApiHandlerImpl *rest = new RestApiHandlerImpl();

        return rest;
    }

    Q_UNUSED(path);

    QString wwwPath = ":/www_scr" /*s->m_wwwPath */;

    return new FileSystemRequestHandler(wwwPath);
}
