#include "restapihandlerimpl.h"
#include "../utils.h"
#include "getimagecommand.h"

RestApiHandlerImpl::RestApiHandlerImpl()
{
    m_commandFact.add<GetImageCommand>("getImage");
}


bool RestApiHandlerImpl::checkRequest(HttpRequest *_req)
{
    static QStringList api = {
        "/api",
    };

    QString path = _req->getUrl().path();

    for(auto &item : api)
    {
        if(path.startsWith(item))
        {
            return true;
        }
    }

    return false;
}
