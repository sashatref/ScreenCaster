#include "getimagecommand.h"
#include "utils.h"



void GetImageCommand::execute(QByteArray &_data, QByteArray &_contentType)
{
    _contentType = "image/png";
    _data = Utils::grabImage();
}

QStringList GetImageCommand::allowedMethod() const
{
    return {"GET", "POST"};
}
