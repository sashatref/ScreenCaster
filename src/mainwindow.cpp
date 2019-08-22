#include "project_pch.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"



MainWindow::MainWindow(QWidget *parent) :
    ExtendedMainWindow  (parent),
    ui                  (new Ui::MainWindow)
{
    ui->setupUi(this);

    m_trayMenu = new TrayMenu(this, QIcon(":/images/31314.png"));

#ifdef STATIC
    Q_INIT_RESOURCE(Propertybrowser3_images);
    Q_INIT_RESOURCE(CustomWidgets_images);
#endif

    s = sgSettings::instance();

    setCentralWidget(nullptr);

    initAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appExceptionSlot(const QString &_text)
{
    InfoWindow(_text).exec();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsForm form(this);
    form.setValue(QVariant::fromValue(*s));
    if(form.exec() == QDialog::Accepted)
    {
        *s = form.getValue().value<SettingsInfo>();
        qApp->emitSettingChangeEvent();
    }
}

void MainWindow::registerCustomTypes()
{
    PropertyBrowser3::registerBaseTypes();
    SettingsInfo::registerType();
}


void MainWindow::initConnections()
{

}

void MainWindow::on_actionStartServer_triggered()
{
    try
    {
        m_serverController->start();
    }
    catch(std::exception &e)
    {
        onMessage(e.what(), QtCriticalMsg);
        on_actionStopServer_triggered();
    }

    ui->actionStartServer->setEnabled(false);
    ui->actionStopServer->setEnabled(true);
}

void MainWindow::on_actionStopServer_triggered()
{
    m_serverController->stop();

    ui->actionStartServer->setEnabled(true);
    ui->actionStopServer->setEnabled(false);


    onMessage("HTTP | Сервер остановлен", QtInfoMsg);
}

void MainWindow::onMessage(const QString &_text, QtMsgType _type)
{
    ui->logWindow->addMessageInQueue(Text::textWithDateTimeStamp(_text), _type);
}

void MainWindow::on_actionClipRectangle_triggered()
{
    RectGrabber *grabber = new RectGrabber();
    connect(grabber, &RectGrabber::rectSelected, this, [this](const QRect &_rect)
    {
        onMessage(QString("Rect: %1 %2 %3 %4")
                  .arg(_rect.x())
                  .arg(_rect.y())
                  .arg(_rect.width())
                  .arg(_rect.height()), QtInfoMsg);

        s->m_grabRect = _rect;
    });
    connect(grabber, &RectGrabber::rectSelected, grabber, &RectGrabber::deleteLater);
    grabber->show();
}


void MainWindow::loadState(const LayoutSaver &_saver)
{
    _saver.loadMainWindow(this, "mw");
    _saver.load(m_processInfoMonitorState, "processInfoMonitorState");
}

void MainWindow::saveState(LayoutSaver &_saver) const
{
    _saver.saveMainWindow(this, "mw");
    _saver.save(m_processInfoMonitorState, "processInfoMonitorState");
}

void MainWindow::updateLanguage()
{
    ui->retranslateUi(this);
}

void MainWindow::updateStyle()
{
}

void MainWindow::initUiComponets()
{
    WidgetHelper::createStyleActions(ui->menuStyle, &s->m_lastStyle);
}

void MainWindow::settingsChanged()
{
    m_serverController->updateConfig();
}

void MainWindow::on_actionAboutProgramm_triggered()
{
    static SingleWidget<AboutDialog> form;
    if(form.createIfNoExist())
    {
        form.w()->setWindowFlag(Qt::WindowStaysOnTopHint, windowFlags().testFlag(Qt::WindowStaysOnTopHint));
        form.w()->setInfo("ScreenCaster", qApp->applicationVersion(), Utils::getCompileDateTime());
        registerIndependentWindow(form.w());
    }

    form.show();
}

void MainWindow::on_actionAboutProcess_triggered()
{
    static SingleWidget<ProcessInfoMonitor> form;
    if(form.createIfNoExist())
    {
        form.w()->setWindowFlag(Qt::WindowStaysOnTopHint, windowFlags().testFlag(Qt::WindowStaysOnTopHint));
        form.w()->setObjectName("ProcessInfoMonitor");
        form.w()->loadWidgetState(m_processInfoMonitorState);
        form.w()->setOnSaveCallback([&](const QVariant &_var)
        {
            m_processInfoMonitorState = _var;
        });

        registerIndependentWindow(form.w());
    }
    form.show();
}
