#include "utils.h"
#include "buildNumber.h"
#include "settingsinfo.h"

QString Utils::getCompileDateTime()
{
    return COMPILE_DATE " " COMPILE_TIME;
}

QByteArray Utils::grabImage()
{
    QScreen *primaryScreen = QGuiApplication::primaryScreen();

    if(!primaryScreen)
    {
        return QByteArray();
    }

    SettingsInfo *s = sgSettings::instance();

    QPixmap pix = primaryScreen->grabWindow(0,
                                            s->m_grabRect.x(),
                                            s->m_grabRect.y(),
                                            s->m_grabRect.width(),
                                            s->m_grabRect.height());

    return ImageUtils::imageToByteArray(pix, "PNG", s->m_imageQuality);
}
