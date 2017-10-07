#include "scheduler.hpp"

scheduler::scheduler(){

    this->meanwaittime = 0;
    this->meanresponsetime = 0;
    this->meanreturntime = 0;
}


//Local Function
bool compstart(process a, process b){

    return (a.starttime < b.starttime);
}
//Local Function


void scheduler::FCFS(std::vector <process> processes){

    int sumresponsetime = 0;
    int sumwaittime = 0;
    int sumreturntime = 0;
    int executiontime = 0;
    const int vecsize = processes.size();

    std::vector <process> activeprocesses = processes;
    std::vector <process> finishedprocesses;

    std::sort(activeprocesses.begin(), activeprocesses.end(), compstart);

    //for(int i = 0; i < activeprocesses.size(); i++)
    //std::cout << activeprocesses[i].starttime << " " << activeprocesses[i].duration<< "\n";
    
    while(activeprocesses.size() != 0){
           
        process p = activeprocesses[0];
        activeprocesses.erase(activeprocesses.begin());

        if(p.starttime > executiontime){
            executiontime = p.starttime;
        }

        sumresponsetime += (executiontime - p.starttime);

        sumwaittime +=(executiontime - p.starttime);

        sumreturntime += (executiontime + p.duration - p.starttime);

        executiontime += p.duration;
       
    }

    this->meanresponsetime =((float)sumresponsetime) / ((float)vecsize);
    this->meanreturntime = ((float)sumreturntime) / ((float)vecsize);
    this->meanwaittime = ((float)sumwaittime) / ((float)vecsize);
}

void scheduler::SJF(std::vector <process> processes){


}