#include <gui/mainwindow.h>
#include "ui_mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    MainWindow _mainWindow;
    _mainWindow.show();

    return app.exec();
}