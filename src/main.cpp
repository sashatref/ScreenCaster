#include "mainwindow.h"
#include "project_pch.h"
#include "buildNumber.h"
#include "settingsinfo.h"

#ifdef STATIC
    #include <QtPlugin>
#endif

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    ExtendApp a(argc, argv);
    a.setApplicationVersion(FULL_VER);

#ifdef STATIC
    Q_IMPORT_PLUGIN(CustomStylePlugin);
    Q_INIT_RESOURCE(CustomStylePlugin);
    Q_INIT_RESOURCE(Propertybrowser3_images);
    Q_INIT_RESOURCE(CustomWidgets_images);
    Q_INIT_RESOURCE(loggertemplate);
#endif

    a.parseCommandLine();

    SettingsInfo *s = sgSettings::instance();
    a.loadSettings(s);

    MainWindow w;
    w.setObjectName("MainWindow");

    a.loadLayout();
    w.loadWidgetState(a.getLayoutSaver()->value(w.objectName()));
    w.show();

    QObject::connect(&a, &ExtendApp::onExceptionMsg, &w, &MainWindow::appExceptionSlot);
    QObject::connect(&a, &ExtendApp::aboutToQuit, [&]{ a.saveSettings(s); });

    w.setOnSaveCallback([&](const QVariant &_val)
    {
        a.getLayoutSaver()->insert(w.objectName(), _val);
    });

    return a.exec();
}
