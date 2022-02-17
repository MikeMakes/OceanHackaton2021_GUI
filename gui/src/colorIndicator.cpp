#include <gui/colorIndicator.h>

colorIndicator::colorIndicator(QObject *parent, int currentState):
    QObject(parent),
    _state(static_cast<colors>(currentState))   
{
    QLabel *label = new QLabel(this);
}

colorIndicator::~colorIndicator(){
    
}

void colorIndicator::changedState(int currentState){
    switch (currentState){
        case state::red:
            _state = colors::red;
            break;
        case state::yellow:
            _state = colors::yellow;
            break;
        case state::green:
            _state = colors::green;
            break;
        default:
            break;
    }
    updateState();
}

void colorIndicator::updateState(){
    switch (_state){
        case state::red:
            ui->label->setPixmap(red);
            break;
        case state::yellow:
            ui->label->setPixmap(yellow);
            break;
        case state::green:
            ui->label->setPixmap(green);
            break;
        default:
            break;
    }
}

int colorIndicator::currentState(){
    return (int)_state;
}