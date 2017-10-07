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

bool compduration(process a, process b){

    return (a.duration < b.duration);
}
//Local Function


void scheduler::FCFS(std::vector <process> processes){

    int sumresponsetime = 0;
    int sumwaittime = 0;
    int sumreturntime = 0;
    int executiontime = 0;
    const int vecsize = processes.size();

    std::vector <process> activeprocesses = processes;

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

    int sumresponsetime = 0;
    int sumwaittime = 0;
    int sumreturntime = 0;
    int executiontime = 0;
    const int vecsize = processes.size();
    std::vector <process> activeprocesses;

    for(int i = 0; i < processes.size(); i++){
        if(processes[i].starttime == 0){
            activeprocesses.push_back(processes[i]);
            processes.erase(processes.begin()+i);
        }
    }

    while(activeprocesses.size() > 0 || processes.size() > 0){

        if(activeprocesses.size() == 0 && processes.size() > 0){//Se não tem nenhum ativo (espaço ocioso)
                                                                // mas ainda tem processos restantes
            int minstarttime = INT_MAX;

            for(int j = 0; j < processes.size(); j++){//Procura o menor tempo de início dos processos ainda não inseridos

                if(processes[j].starttime < minstarttime)
                    minstarttime = processes[j].starttime;
            }

            if(minstarttime > executiontime)//E avança o "tempo" para o mesmo
                executiontime = minstarttime;
        }
        
        
        for(int i = 0; i < processes.size(); i++){
            if(processes[i].starttime <= executiontime){
                activeprocesses.push_back(processes[i]);
                processes.erase(processes.begin()+i);
                i--;
            }
        }
        
        std::sort(activeprocesses.begin(), activeprocesses.end(), compduration);

        process p = activeprocesses[0]; 
        activeprocesses.erase(activeprocesses.begin());

        sumresponsetime += (executiontime - p.starttime);

        sumwaittime +=(executiontime - p.starttime);

        sumreturntime += (executiontime + p.duration - p.starttime);

        executiontime += p.duration;

    }

    this->meanresponsetime =((float)sumresponsetime) / ((float)vecsize);
    this->meanreturntime = ((float)sumreturntime) / ((float)vecsize);
    this->meanwaittime = ((float)sumwaittime) / ((float)vecsize);
}