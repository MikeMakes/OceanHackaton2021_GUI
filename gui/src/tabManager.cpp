#include <gui/tabManager.h>

tabManager::tabManager(QObject *parent, int currentTab):
    QObject(parent),
    _tab(static_cast<tabs>(currentTab))   
{
    //_tab = static_cast<tabs>(currentTab);
}

tabManager::~tabManager(){
    
}

void tabManager::changedTab(int currentTab){
    switch (currentTab){
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

void tabManager::rightTab(){
    if(_tab==tabs::Plot) _tab=tabs::Sonda;
    else _tab=static_cast<tabs>((int)_tab+1);
    Q_EMIT changeTab((int)_tab);
    qDebug() << "Right";
}

void tabManager::leftTab(){
    if(_tab==tabs::Sonda) _tab=tabs::Plot;
    else _tab=static_cast<tabs>((int)_tab-1);
    Q_EMIT changeTab((int)_tab);
    qDebug() << "Left";
}

int tabManager::currentTab(){
    return (int)_tab;
}