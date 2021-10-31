#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QAbstractButton>
//#include <QSignalMapper>

#include <gui/extprocess.h>
#include <gui/test.h>
#include <gui/tabManager.h>

using namespace gui;

namespace Ui {
class MainWindow;
}

//enum tabs{Sonda, Data, Simulation, Plot};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    //void changeTab(int tabindex);

private slots:
    //void slotTest(int n);
    void startProcess();

private:
    Ui::MainWindow *ui;

    tabManager *_tabManager;
    
    enum tabs _tab=Sonda;

    Extprocess _extprocess;
    QProcess myprocess;
    bool started=false;
};

#endif // MAINWINDOW_H
