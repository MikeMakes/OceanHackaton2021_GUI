#pragma once
//#ifndef EXTPROCESS_H
//#define EXTPROCESS_H

#include <iostream>
#include <string>

namespace gui{

class Extprocess{
    public:
        Extprocess();
        ~Extprocess();
        std::string processname();
        std::string arguments();
    private:
        std::string _process;
        std::string _args;
        //enum processState{NotStarted, Started, Running, Succesful, Error};
        //enum processState state=NotStarted; 
};

} //namespace gui

//#endif