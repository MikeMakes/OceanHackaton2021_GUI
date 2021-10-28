#ifndef TABMANAGER_H
#define TABMANAGER_H

enum tabs{Sonda, Data, Simulation, Plot};

class tabManager{
    public:
        tabManager(int currentTab);
        ~tabManager();
        int currentTab();
        //enum tabs currentTab();

    public slots:
        void changedTab(int currentTab);
        void rightTab();
        void leftTab();

    signals:
        void changeTab(int currentTab);

    private:
        enum tabs _tab=Sonda;

};

#endif //TABMANAGER_H