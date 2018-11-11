#include "Network.h"

network::network()
{

}
void network::SetNodeNum(int nNum)
{
    this->nodeNum = nNum;
}
int network::GetNodeNum()
{
    return this->nodeNum;
}
void network::SetRunTime(int rTime)
{
    this->runTime = rTime;
}
int network::GetRunTime()
{
    return this->runTime;
}
void network::SetCycle(int cTime)
{
    this->cycle = cTime;
}
int network::GetCycle()
{
    return this->cycle;
}
void network::SetLength(int len)
{
    this->length = len;
}
int network::GetLength()
{
    return this->length;
}
void network::SetBroad(int brd)
{
    this->broad = brd;
}
int network::GetBroad()
{
    return this->broad;
}
void network::SetDistance(int dis)
{
    this->distance = dis;
}
int network::GetDistance()
{
    return this->distance;
}
