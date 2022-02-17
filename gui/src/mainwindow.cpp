#include <gui/mainwindow.h>
#include "ui_mainwindow.h"
#include <QProcess> 
#include <QObject> 
#include <QString>
#include <QStringList> 
#include <QDebug>
#include <QAbstractButton>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QFile>
#include <QtCharts>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
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
    //SetStyle();

    // Tabs
    _tabManager = new tabManager(this,ui->tabWidget->currentIndex());
    connect(ui->tabWidget, &QTabWidget::currentChanged, _tabManager, &tabManager::changedTab);
    connect(_tabManager, SIGNAL(changeTab(int)), ui->horizontalSlider, SLOT(setValue(int)));
    //connect(_tabManager, SIGNAL(changeTab(int)), ui->tabWidget, SLOT(setCurrentIndex(int)));
    connect(_tabManager, &tabManager::changeTab, ui->tabWidget, &QTabWidget::setCurrentIndex);
    connect(ui->rightButton, &QPushButton::clicked, _tabManager, &tabManager::rightTab); //&QSignalMapper::map() & ::mapped() not std::
    connect(ui->leftButton, &QPushButton::clicked, _tabManager, &tabManager::leftTab);
    
    // Validators
    ui->lineEditInt->setValidator(new QIntValidator(0,20,this));
    ui->lineEditDouble->setValidator(new QDoubleValidator(-5.0,2.0,5,this));
    ui->lineEditString->setValidator(new QDoubleValidator(-10.4,40.6,1,this));

    // Cmd button
    connect(ui->commandLinkButton, SIGNAL(clicked()), this, SLOT(startProcess()));

    // Charts
    QLineSeries* series = new QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("line chart");
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //another
    QLineSeries* series1 = new QLineSeries();
    series1->append(2, 4);
    series1->append(0, 6);
    QChart *chart1 = new QChart();
    chart1->legend()->hide();
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setTitle("line chart");
    QChartView *chartView1 = new QChartView(chart1);
    chartView1->setRenderHint(QPainter::Antialiasing);
    // create layout
    //QGridLayout layout;
    //layout.addWidget(chartView);
    //this->ui->tabPlot->setLayout(&layout);
    this->ui->tabPlot->layout()->addWidget(chartView);
    this->ui->tabPlot->layout()->addWidget(chartView1);
    // position view to chartview
    //this->ui->stackedWidget->setCurrentIndex(8);
    this->ui->tabWidget->setCurrentIndex(this->ui->tabWidget->indexOf(this->ui->tabPlot));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetStyle(){
      QFile file(_stylesheet_file);
      file.open(QFile::ReadOnly);
      QString _stylesheet = QLatin1String(file.readAll());
      qApp->setStyleSheet(_stylesheet);
      file.close();
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
