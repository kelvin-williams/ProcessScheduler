#include <iostream>
#include <fstream>
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

    int a = 245;
    int b = a + 1000;

    std::vector <process> processes = GetProcessesFromFile("input.txt");

    for(int i = 0; i < processes.size(); i++)
    std::cout << processes[i].starttime << " " << processes[i].duration<< "\n";


    scheduler sc;

    sc.FCFS(processes);

    std::cout << "FCFS: " << sc.meanreturntime <<" "<< sc.meanresponsetime <<" "<< sc.meanwaittime<<"\n";
    return b + 1;
}