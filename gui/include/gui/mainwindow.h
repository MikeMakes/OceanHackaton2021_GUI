#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QSignalMapper>

#include <gui/extprocess.h>
#include <gui/test.h>

using namespace gui;

namespace Ui {
class MainWindow;
}

enum tabs{Sonda, Data, Simulation, Plot, Left, Right};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void changeTab(int tabindex);

private slots:
    void changedTab(int tab);
    void startProcess();

private:
    Ui::MainWindow *ui;
    QSignalMapper *_signal_mapper;
    
    enum tabs _tab=Sonda;

    Extprocess _extprocess;
    QProcess myprocess;
    bool started=false;
};

#endif // MAINWINDOW_H
