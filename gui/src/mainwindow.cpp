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
    _signal_mapper = new QSignalMapper(this);
    _signal_mapper->setMapping(ui->rightButton_Sonda, (int)tabs::Right);
    _signal_mapper->setMapping(ui->leftButton_Sonda, (int)tabs::Left);
    _signal_mapper->setMapping(ui->rightButton_Data, (int)tabs::Right);
    _signal_mapper->setMapping(ui->leftButton_Data, (int)tabs::Left);
    _signal_mapper->setMapping(ui->rightButton_Simulation, (int)tabs::Right);
    _signal_mapper->setMapping(ui->leftButton_Simulation, (int)tabs::Left);
    _signal_mapper->setMapping(ui->rightButton_Plot, (int)tabs::Right);
    _signal_mapper->setMapping(ui->leftButton_Plot, (int)tabs::Left);
    _signal_mapper->setMapping(ui->rightButton, (int)tabs::Right);
    _signal_mapper->setMapping(ui->leftButton, (int)tabs::Left);
    connect(ui->rightButton_Sonda, SIGNAL(clicked()), _signal_mapper, SLOT(map())); //&QSignalMapper::map() & ::mapped() not std::
    connect(ui->leftButton_Sonda, SIGNAL(clicked()), _signal_mapper, SLOT(map()));
    connect(ui->rightButton_Data, SIGNAL(clicked()), _signal_mapper, SLOT(map())); //&QSignalMapper::map() & ::mapped() not std::
    connect(ui->leftButton_Data, SIGNAL(clicked()), _signal_mapper, SLOT(map()));
    connect(ui->rightButton_Simulation, SIGNAL(clicked()), _signal_mapper, SLOT(map())); //&QSignalMapper::map() & ::mapped() not std::
    connect(ui->leftButton_Simulation, SIGNAL(clicked()), _signal_mapper, SLOT(map()));
    connect(ui->rightButton_Plot, SIGNAL(clicked()), _signal_mapper, SLOT(map())); //&QSignalMapper::map() & ::mapped() not std::
    connect(ui->leftButton_Plot, SIGNAL(clicked()), _signal_mapper, SLOT(map()));
    connect(ui->rightButton, SIGNAL(clicked()), _signal_mapper, SLOT(map())); //&QSignalMapper::map() & ::mapped() not std::
    connect(ui->leftButton, SIGNAL(clicked()), _signal_mapper, SLOT(map()));
    
    connect(_signal_mapper, SIGNAL(mapped(int)), this, SLOT(changedTab(int)));

    connect(ui->commandLinkButton, SIGNAL(clicked()), this, SLOT(startProcess()));

}

MainWindow::~MainWindow()
{
    delete ui;
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
        case tabs::Right:
            if(_tab==tabs::Plot) _tab=tabs::Sonda;
            else _tab=static_cast<tabs>((int)_tab+1);
            emit changeTab((int)_tab);
            qDebug() << "Right";
            break;
        case tabs::Left:
            if(_tab==tabs::Sonda) _tab=tabs::Plot;
            else _tab=static_cast<tabs>((int)_tab-1);
            emit changeTab((int)_tab);
            qDebug() << "Left";
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
