#include <gui/test.h>
#include <gui/patata.h>
int b;
patata _patata;
std::string message(){    
    //meh = "print";
    b=0;
    std::cout << b << std::endl;
    std::cout << _patata.rn() << std::endl;
    std::string meh = "snn";
    return meh;
}
tortilla::tortilla(){
    number=2;
}
tortilla::~tortilla(){}
int tortilla::rn(){
    return number;
}
