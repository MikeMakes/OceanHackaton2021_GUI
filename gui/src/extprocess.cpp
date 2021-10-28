#include <iostream>
#include <string>
#include <gui/extprocess.h>

namespace gui{

Extprocess::Extprocess(){
    _process="python3"; //"/home/user/Documents/hackathon/gui/build/cursor_segmenter.py";
    _args="/home/user/motion_tracker/vel_extractor/cursor_segmenter.py";
}
Extprocess::~Extprocess(){
}
std::string Extprocess::processname(){
    return _process;
}
std::string Extprocess::arguments(){
    return _args;
}

}//namespace gui