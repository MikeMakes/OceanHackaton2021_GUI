#ifndef COLORINDICATOR_H
#define COLORINDICATOR_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

enum colors{red,yellow,green}

class colorIndicator: public QWidget{
    Q_OBJECT
    public:
        colorIndicator(QObject *parent=0, int currentState=0);
        ~colorIndicator();
        int currentState();
        //enum tabs currentState();

    signals:
        void changeState(int currentState);
        
    public slots:
        void changedState(int currentState);

    private:
        enum colors _state=red;
        QLabel *label;
        QPixmap red("/home/user/Documents/hackathon/gui/resources/red.png");
        QPixmap yellow("/home/user/Documents/hackathon/gui/resources/yellow.png");
        QPixmap green("/home/user/Documents/hackathon/gui/resources/green.png");
        void updateState();
};

#endif //COLORINDICATOR_H