#include <gui/mainwindow.h>
#include "ui_mainwindow.h"
#include <QProcess> 
#include <QObject> 
#include <QString>
#include <QStringList> 
#include <QDebug>
#include <QSignalMapper>
//#include <QWidget>

#include <gui/extprocess.h>
#include <gui/test.h>

using namespace gui;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myprocess(parent)
{
    ui->setupUi(this);

    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(changedTab(int)));
    connect(this, SIGNAL(changeTab(int)), ui->tabWidget, SLOT(setCurrentIndex(int)));
    connect(ui->rightButton, SIGNAL(clicked()), this, SLOT(rightTab())); //&QSignalMapper::map() & ::mapped() not std::
    connect(ui->leftButton, SIGNAL(clicked()), this, SLOT(leftTab()));
    
    connect(ui->commandLinkButton, SIGNAL(clicked()), this, SLOT(startProcess()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rightTab(){
    if(_tab==tabs::Plot) _tab=tabs::Sonda;
    else _tab=static_cast<tabs>((int)_tab+1);
    emit changeTab((int)_tab);
    qDebug() << "Right";
}

void MainWindow::leftTab(){
    if(_tab==tabs::Sonda) _tab=tabs::Plot;
    else _tab=static_cast<tabs>((int)_tab-1);
    emit changeTab((int)_tab);
    qDebug() << "Left";
}

void MainWindow::changedTab(int tab){
    switch (tab){
        case tabs::Sonda:
            _tab = tabs::Sonda;
            qDebug() << "Sonda";
            break;
        case tabs::Data:
            _tab = tabs::Data;
            qDebug() << "Data";
            break;
        case tabs::Simulation:
            _tab = tabs::Simulation;
            qDebug() << "Simulation";
            break;
        case tabs::Plot:
            _tab = tabs::Plot;
            qDebug() << "Plot";
            break;
        default:
            break;
    }
}

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
