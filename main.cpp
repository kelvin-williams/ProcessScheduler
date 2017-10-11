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


void WriteOutFile(scheduler fcfs, scheduler sjf, scheduler rr){

    std::ofstream file;
    file.open("output.txt", std::ios::out | std::ios::trunc);

    file << std::fixed << std::setprecision(1);

    file << "FCFS: " << fcfs.meanreturntime <<" "<< fcfs.meanresponsetime <<" "<< fcfs.meanwaittime<<"\n";
    file << "SJF: " << sjf.meanreturntime <<" "<< sjf.meanresponsetime <<" "<< sjf.meanwaittime<<"\n";
    file << "RR: " << rr.meanreturntime <<" "<< rr.meanresponsetime <<" "<< rr.meanwaittime;

    file.close();

}



int main(){

    std::cout << std::fixed << std::setprecision(1);

    std::vector <process> processes = GetProcessesFromFile("input2.txt");

   // for(int i = 0; i < processes.size(); i++)
   // std::cout << processes[i].starttime << " " << processes[i].duration<< "\n";


    scheduler fcfs, sjf, rr;

    fcfs.FCFS(processes);
    sjf.SJF(processes);
    rr.RR(processes);

    std::cout << "\nFCFS: " << fcfs.meanreturntime <<" "<< fcfs.meanresponsetime <<" "<< fcfs.meanwaittime<<"\n";
    std::cout << "SJF: " << sjf.meanreturntime <<" "<< sjf.meanresponsetime <<" "<< sjf.meanwaittime<<"\n";
    std::cout << "RR: " << rr.meanreturntime <<" "<< rr.meanresponsetime <<" "<< rr.meanwaittime<<"\n";

    WriteOutFile(fcfs,sjf,rr);
    return 0;
}