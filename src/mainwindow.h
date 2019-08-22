#pragma once

#include "settingsinfo.h"
#include "web/servercontroller.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public ExtendedMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void appExceptionSlot(const QString &_text);

private slots:

    void on_actionExit_triggered();
    void on_actionSettings_triggered();
    void on_actionStartServer_triggered();
    void on_actionStopServer_triggered();

    void onMessage(const QString &_text, QtMsgType _type);

    void on_actionClipRectangle_triggered();
    void on_actionAboutProgramm_triggered();
    void on_actionAboutProcess_triggered();

private:
    virtual void registerCustomTypes() override;
    virtual void initConnections() override;

    Ui::MainWindow *ui;
    TrayMenu *m_trayMenu;

    QVariant m_processInfoMonitorState;

    ServerController *m_serverController = new ServerController(this);

    SettingsInfo *s;

    // ISaveWidget interface
public:
    virtual void loadState(const LayoutSaver &_saver) override;
    virtual void saveState(LayoutSaver &_saver) const override;

    // ExtendedMainWindow interface
public:
    virtual void updateLanguage() override;
    virtual void updateStyle() override;

protected:
    virtual void initUiComponets() override;
    virtual void settingsChanged() override;
};

