#ifndef NETWORK_H
#define NETWORK_H

#include <Node.h>

class network
{
public:
    network();
private:
    int nodeNum = 2000;
    int runTime = 10000;
    int cycle = 10000;
    int length = 40;
    int broad = 40;
    int distance = 20;
public:

    void SetNodeNum(int);
    int GetNodeNum();
    void SetRunTime(int);
    int GetRunTime();
    void SetCycle(int);
    int GetCycle();
    void SetLength(int);
    int GetLength();
    void SetBroad(int);
    int GetBroad();
    void SetDistance(int);
    int GetDistance();
};

#endif // NETWORK_H
