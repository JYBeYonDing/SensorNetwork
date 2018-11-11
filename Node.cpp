#include "Node.h"

Node::Node()
{

}
int Node::GetNodeId()
{
    return this->nodeId;
}
void Node::SetNodeId(int id)
{
    this->nodeId = id;
}
int Node::GetClusterId()
{
    return this->clusterId;
}
void Node::SetClusterId(int cId)
{
    this->clusterId = cId;
}
bool Node::GetIsClusterHead()
{
    return this->isClusterHead;
}
/*int* node::GetLocation()
{
    return this->location;
}
void node::SetLocation()*/
