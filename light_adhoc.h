#ifndef	 _Light_AdHoc_
#define  _Light_AdHoc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<random>
#include<ctime>
#include<queue>
#include<string>
#include<fstream>
#include<vector>

#define PI 3.141592653
#define MAX 1000000

enum Node_State { off, on, beacon, nodelisten, sending, receive, wait, backoff, close };
enum Event_Type { sendbeacon, senddata, listening, compete, receivedata, add, leave, changeroute, start, broadcast};
enum Event_Step { C2C, D2C, set_up, route, search_net, search_node };
enum Packet_Type { route_broast, node_search, route_requer, route_req, cluster_apply, cluster_reply, change_apply, change_ack, in_beacon, ack, data_pack };
class parameter
{
public:
    parameter()
    {
        SEND_RATE = 2.5e5;//信息发送速率
        PACK_SIZE = 1000;//帧长
        NODE_NUMBER = 2000;//节点数
        INTER_FRAME = 0;//随机数，信息到达偏差
        Run_time = 300000;//运行时间
        Bussiness_Cycle = 10000;//业务周期
        Backoff_Threshold = 12;//最大退避次数
        length = 40;//场景长度
        broad = 40;//场景宽度
        send_distance = 10;//发送/监听距离
        Tbeacon = 10000;//Beacon帧发送周期
        Set_Up_Tbeacon = 100;//建簇期间Beacon时间
        randtosendbeacon = 100; //开机启动时间
        Power_Cluster_Threshold = 4; //簇头轮换门限
        become_cluster_listen_time = 500; //监听时间
        not_receive_turns = 2;//判断信息未接收的发送轮次
        cluster_max = 100; //簇内最大节点数，自变量
        send_sum = 0;		//总发包数
        send_fail = 0;		//总收包数
        start_route_time = 601; //开始路由的时间
        coeff = 1;//TDMA时间与CSMA时间的关系
        Routing_Broadcast_Cycle = 60000;//路由广播时间
        Search_Cycle = 360000; //查询时间
    }
    ~parameter() {}
    double SEND_RATE;
    double PACK_SIZE;
    double NODE_NUMBER;
    double INTER_FRAME;
    int Run_time;
    int Node_Start_Time;
    double Bussiness_Cycle;
    void SetParameter() {}
    int Backoff_Threshold;

    //以上为TDMA和CSMA所需属性
    double length;
    double broad;
    int randtosendbeacon;
    double route_over_control;
    int cluster_number;
    int Tbeacon;
    int start_tdma;
    double Power_Cluster_Threshold;
    double become_cluster_listen_time;
    int not_receive_turns;
    int cluster_max;
    double send_distance;
    double send_sum;
    double send_fail;
    double start_route_time;
    double coeff;
    double Set_Up_Tbeacon;
    int Routing_Broadcast_Cycle;
    int Search_Cycle;
};

class Packet
{
public:
    Packet_Type pack_type;
    int number = 0;
    int size;
    void Set_size()
    {
        switch (this->pack_type)
        {
        case route_broast:
            this->size = 66;
        case node_search:
            this->size = 66;
        case route_requer:
            this->size = 210;
        case cluster_apply:
            this->size = 120;
        case cluster_reply:
            this->size = 128;
        case change_apply:
            this->size = 120;
        case change_ack:
            this->size = 120;
        case in_beacon:
            this->size = 168;
        case ack:
            this->size = 88;
        case data_pack:
            this->size = 1000;
        case route_req:
            this->size = 138;
        default:
            break;
        }
    }
};

class Cluster
{
public:
    Cluster() {
        Node_Number = 1;
        TDMA_time = (1000 / 2.5e5) * 1000;
        CSMA_time =  TDMA_time;
    }

    Cluster(int num) {
        inter_node = new int[num];
        TDMA_time = (1000 / 2.5e5) * 1000 * num;
        CSMA_time =  TDMA_time;
    }

    ~Cluster() { }//delete[] inter_node;

                  //Node_State cluster_state;
    double Node_Number; //簇数量
                        //double Node_time;
                        //double power_consume;
    double x_axis;
    double y_axis;
    int cluster_center_id; //簇头节点
    int *inter_node; //储存簇内节点号
    int TDMA_time; //该簇TDMA时间
    int CSMA_time; //该簇CSMA时间
    int start_tdma;
};

class Node
{
public:
    Node() {
        node_state = off; //节点状态
        If_Center = 0; //节点是否为簇头
        Node_time = 0; //开机时间
        //sleep_count = 0; //睡眠次数
        //wake_up_count = 0; //唤醒次数
        power_consume = 0; //节点能耗
        wait_time = 0;//等待时间
        Backoff_count = 4; //初始退避次数
        send_pack_count = 0;//发送次数
        sleep_time = 0;//睡眠时间
        if_belong_cluster = 0;//是否已加入簇
        if_route_center = 0;//是否路由节点
        if_have_send_cluster = 0;//是否包含待发送簇
        send_target_id = MAX;//发送目标节点
        if_route_work = 0;//路由是否正常工作
        lock_count = 0;//锁定计数
        receive_pack = 0;//接收次数
                         //receive_frame = 0;
        Not_receive_beacon = 0;//判断有无正常接收
        send_dis = 10;//节点发送距离
        send_time = 0;
        receive_time = 0;
        delay = 0;
        send_beacon = 0;
        Start_Time = 0; //启动时间
    }

    ~Node() {}
    int If_Center;
    Node_State node_state;
    int Node_time;
    int listen_begin_time;//监听开始时间
    int listen_last_time;//监听持续时间
    int wait_time;
    int sleep_time;
    //int sleep_count;
    //int wake_up_count;
    double power_consume;
    int Backoff_count;
    int send_pack_count;
    int collision_time;
    Cluster lead_cluster;//本簇信息
    Cluster send_cluster;//待发送的簇信息
    bool if_have_send_cluster;
    int Start_Time;
    double Set_Rank; //节点排序

    friend bool operator < (const Node&a, const Node &b) {
        return a.Set_Rank > b.Set_Rank;
    }

    //以上为TDMA所需属性
    double x_axis; //节点坐标
    double y_axis;//节点坐标
    int random_decision;//随机分配节点是否为路由
    int cluster_id;
    bool if_belong_cluster;
    bool if_route_center;
    double send_dis;
    int id;
    int route_next_id;  //下一跳地址
    int send_target_id;
    bool if_route_work;
    Event_Step work_step;
    int lock_count;
    int receive_pack;
    //int receive_frame;
    int inter_cluster_num; //本簇内节点数量
    int Not_receive_beacon;
    int last_center_id;  //轮换前簇头
    int receive_route_id;
    double send_time;
    double receive_time;
    double delay;
    bool send_beacon;
    int cluster_index;
    //Packet pack[11]; //统计各种帧
    int node_power = 10;
};

class Event
{
public:
    Event() {
        timing = 0;
        maintain = 0;
    }
    ~Event() {}
    double Event_time; //事件发生时间
    int node_id; //事件关联节点
    Event_Type event_type; //事件类型
    Event_Step step;  //事件步骤
    int search_id;	//查询事件查询的节点id
    bool timing;	//是否是周期发生事件
    bool maintain;	//维护
    int target_id;	//发送目标节点
    friend bool operator < (const Event&a, const Event &b) {
        return a.Event_time > b.Event_time;
    }
};

#endif
