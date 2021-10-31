#include <gui/mainwindow.h>
#include "ui_mainwindow.h"
#include <QProcess> 
#include <QObject> 
#include <QString>
#include <QStringList> 
#include <QDebug>
#include <QAbstractButton>
//#include <QSignalMapper>
//#include <QWidget>

#include <gui/extprocess.h>
#include <gui/test.h>
#include <gui/tabManager.h>


using namespace gui;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myprocess(parent)
{
    ui->setupUi(this);

    
    _tabManager = new tabManager(this,ui->tabWidget->currentIndex());
    connect(ui->tabWidget, &QTabWidget::currentChanged, _tabManager, &tabManager::changedTab);
    connect(_tabManager, SIGNAL(changeTab(int)), ui->horizontalSlider, SLOT(setValue(int)));
    //connect(_tabManager, SIGNAL(changeTab(int)), ui->tabWidget, SLOT(setCurrentIndex(int)));
    connect(_tabManager, &tabManager::changeTab, ui->tabWidget, &QTabWidget::setCurrentIndex);
    connect(ui->rightButton, &QPushButton::clicked, _tabManager, &tabManager::rightTab); //&QSignalMapper::map() & ::mapped() not std::
    connect(ui->leftButton, &QPushButton::clicked, _tabManager, &tabManager::leftTab);
    
    connect(ui->commandLinkButton, SIGNAL(clicked()), this, SLOT(startProcess()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::slotTest(int n){
    qDebug() << n;
}
*/

void MainWindow::startProcess(){
    enum QProcess::ProcessState state;
    if(!started){
        state = myprocess.state();
        switch (state)
        {
        case QProcess::NotRunning:
            qDebug() << "Not running";
            break;
        case QProcess::Starting:
            qDebug() << "Starting";
            break;
        case QProcess::Running:
            qDebug() << "running";
            break;
        default:
            break;
        }

        QString processname = QString::fromStdString(_extprocess.processname());
        QStringList args;
        args << QString::fromStdString(_extprocess.arguments());
        qDebug() << processname;
        qDebug() << args;
        myprocess.start(processname, args);

        state = myprocess.state();
        switch (state)
        {
        case QProcess::NotRunning:
            qDebug() << "Not running";
            break;
        case QProcess::Starting:
            qDebug() << "Starting";
            started=true;
            break;
        case QProcess::Running:
            qDebug() << "running";
            started=true;
            break;
        default:
            break;
        }
    }else{
        state = myprocess.state();
        switch (state)
        {
        case QProcess::NotRunning:
            qDebug() << "Not running";
            break;
        case QProcess::Starting:
            qDebug() << "Starting";
            break;
        case QProcess::Running:
            qDebug() << "running";
            break;
        default:
            break;
        }

        qDebug()<< "err" << myprocess.error();

    }
}
