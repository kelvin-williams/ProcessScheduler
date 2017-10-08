#include <iostream>
#include <fstream>
#include <iomanip>
#include "process.hpp"
#include "scheduler.hpp"

std::vector <process> GetProcessesFromFile(const char * str){

    std::ifstream file;
    file.open(str, std::ios::in);
    int id = 0;
    std::vector <process> aux; 

    while(file.good()){

        int pstart, pduration;
        file >> pstart;
        file >> pduration;

        process p(id, pduration, pstart);

        id++;

        aux.push_back(p);
    }

    file.close();

    return aux;
}



int main(){

    std::cout << std::fixed << std::setprecision(1);

    std::vector <process> processes = GetProcessesFromFile("input.txt");

    for(int i = 0; i < processes.size(); i++)
    std::cout << processes[i].starttime << " " << processes[i].duration<< "\n";


    scheduler fcfs, sjf, rr;

    fcfs.FCFS(processes);
    sjf.SJF(processes);
    rr.RR(processes);

    std::cout << "FCFS: " << fcfs.meanreturntime <<" "<< fcfs.meanresponsetime <<" "<< fcfs.meanwaittime<<"\n";
    std::cout << "SJF: " << sjf.meanreturntime <<" "<< sjf.meanresponsetime <<" "<< sjf.meanwaittime<<"\n";
    std::cout << "RR: " << rr.meanreturntime <<" "<< rr.meanresponsetime <<" "<< rr.meanwaittime<<"\n";
    return 0;
}