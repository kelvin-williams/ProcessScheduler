#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "process.hpp"
#include <iostream>

//using namespace std

class scheduler{

    public:

        scheduler();

        ~scheduler(){};

        void FCFS(std::vector <process> processes);

        void SJF(std::vector <process> processes);

    //    void RR(std::vector <process> processes);


        float meanwaittime;
        float meanreturntime;
        float meanresponsetime;
};

#endif /* SCHEDULER_HPP */