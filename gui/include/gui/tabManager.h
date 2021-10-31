#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <QObject>
#include <QDebug>

enum tabs{Sonda, Data, Simulation, Plot};

class tabManager: public QObject{
    Q_OBJECT
    public:
        tabManager(QObject *parent=0, int currentTab=0);
        ~tabManager();
        int currentTab();
        //enum tabs currentTab();

    signals:
        void changeTab(int currentTab);
        
    public slots:
        void changedTab(int currentTab);
        void rightTab();
        void leftTab();


    private:
        enum tabs _tab=Sonda;
};

#endif //TABMANAGER_H