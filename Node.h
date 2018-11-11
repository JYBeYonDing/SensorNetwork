#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node();
private:
    int nodeId;
    int clusterId;
    bool isClusterHead;
    int clusterHeadId;

public:
    int location[2] = {0};
    int GetNodeId ();
    void SetNodeId (int);
    int GetClusterId();
    void SetClusterId(int);
    bool GetIsClusterHead();

};

#endif // NODE_H
