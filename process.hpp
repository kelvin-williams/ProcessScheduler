#ifndef PROCESS_H_
#define PROCESS_H_

class process{

    public:

        process(int id, int duration, int starttime);

        ~process();

        int id;
        int duration;
        int starttime;
        int returntime;
        int responsetime;
        int waittime;
        int processedtime;
};

#endif /* PROCESS_H_*/
