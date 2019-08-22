#pragma once

#include "project_pch.h"

using namespace PropertyBrowser3Qt;

class SettingsInfo : public IGadget, public IPropertyBrowserBase
{
    Q_GADGET
public:
    buildPropertyP(QString, lastStyle)
    buildPropertyP(int, port)
    buildPropertyP(bool, autoStart)
    buildPropertyP(QString, wwwPath)
    buildPropertyP(int, imageQuality)
    buildPropertyP(QRect, grabRect)

    Q_INVOKABLE SettingsInfo();

    virtual void propertyInfoMap(PropertyInfoMapType &m) const override;
    virtual const QMetaObject *getMetaObject() const Q_DECL_OVERRIDE;

    static void registerType();
};

typedef Singleton<SettingsInfo> sgSettings;

Q_DECLARE_METATYPE(SettingsInfo)
