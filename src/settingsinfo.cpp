#include "project_pch.h"
#include "settingsinfo.h"

REGISTER_ONCE(SettingsInfo)

SettingsInfo::SettingsInfo():
    m_port              (80),
    m_autoStart         (false),
    m_wwwPath           ("www"),
    m_imageQuality      (-1),
    m_grabRect          ()
{

}

void SettingsInfo::propertyInfoMap(PropertyInfoMapType &m) const
{
    m["port"] = PropertyInfo(tr("Порт HTTP-сервера"));
    m["port"].m_properties[IntProperty::SpinBoxMaximum] = 60000;

    m["wwwPath"] = PropertyInfo(tr("Каталог с файлами WWW"));
    m["wwwPath"].m_properties[StringProperty::EditorType] = StringProperty::OpenDir;

    m["imageQuality"].m_isHidden = true;
    m["imageQuality"].m_properties[IntProperty::SpinBoxMinimum] = -1;
    m["imageQuality"].m_properties[IntProperty::SpinBoxMaximum] = 100;

    m["autoStart"] = PropertyInfo(tr("Автозапуск сервера"));
    m["grabRect"] = PropertyInfo(tr("Область захвата"));

    m["lastStyle"].m_isHidden = true;
}

void SettingsInfo::registerType()
{
    GadgetHelper::registerToIGadgetConverter<SettingsInfo>();
}

const QMetaObject *SettingsInfo::getMetaObject() const
{
    return &staticMetaObject;
}


