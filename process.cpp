#include "process.hpp"

process::process(int id, int duration, int starttime){

    this->id = id;
    this->duration = duration;
    this->starttime = starttime;
    
    this->returntime = 0;
    this->responsetime = 0;
    this->waittime = 0;
    this->processedtime = 0;

}

process::~process(){;}