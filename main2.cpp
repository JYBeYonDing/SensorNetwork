#pragma warning
#include"Light_AdHoc.h"
using namespace std;
double * Event_Manage(parameter para, string suffix);
string getCurrentTime();
void main()
{
    parameter para;
    parameter Result_data;
    string suffix;  //文件后缀名，区分场景文件名
    int run_node_number[11] = { 100,500,1000,2000,4000,6000,8000,10000,50000,100000,1000000 };
    int cluster_max[8] = { 50,100,200,500,800,1000,1500,2000 };
    //int Tbeacon[10] = { 100,200,500,1000,1500,2000,2500,3000,3500,4000 };
    //int length[8] = { 30,40,50,60,70,80,90,100 };

    ofstream result;
    double *result_number;
    double *result_size;
    //double temp[16];
    result.open("Result_6k.txt", ios::app);
    result << "中心节点数 "<< "中心节点平均功率 "<< "中心节点发送数 "<< "中心节点接收数 "<< "纯路由节点数 "<< "纯路由节点平均功率 "<< "纯路由节点发送数 "<< "纯路由节点接收数 " << "普通节点数 "<< "普通节点平均功率 "<< "普通节点发送数 "<< "普通节点接收数 "<< "投递率 "<<"时延 "<<"总能量 "<<"平均每个分组消耗能量 "<< endl;
    for (int i = 6; i < 7; i++)    //以节点数为自变量的有10种场景
    {
        double temp[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        para.NODE_NUMBER = run_node_number[i];
        //if (i < 8)
            para.cluster_max = 100;
        //else
            //para.cluster_max = para.NODE_NUMBER / 100;
        para.Tbeacon = 10000;
        suffix =  "_Number_" + to_string(int(para.NODE_NUMBER)) + "_Beacon_" + to_string(int(para.Tbeacon)); //"_Max Cluster_" + to_string(int(para.cluster_max)) +
        result << suffix << endl;
        for (int i = 0; i < 1; i++)   //每种场景统计1次
        {
            result << "开始时间：" << getCurrentTime() << endl;
            result_number = Event_Manage(para, suffix);
            for (int j = 0; j < 16; j++)
            {
                temp[j] += result_number[j];
            }
            result << "结束时间：  " << getCurrentTime() << endl;
            //system("pause");
        }
        for (int k = 0; k < 16; k++)
        {
            temp[k] = temp[k]/1;
            result_number[k] = temp[k];
            result << result_number[k] << '\t';
        }
        result << endl;
    }

    //for (int i = 0; i < 8; i++)  //以簇容量为自变量的有8种场景
    //{
    //	double temp[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    //	para.NODE_NUMBER = 2000;
    //	para.cluster_max = cluster_max[i];
    //	para.Tbeacon = 10000;
    //	suffix = "_Max Cluster_" + to_string(int(para.cluster_max)) + "_Number_" + to_string(int(para.NODE_NUMBER));
    //	result << suffix << endl;
    //	for (int i = 0; i < 20; i++) //统计20次
    //	{
    //		result_number = Event_Manage(para, suffix);
    //		for (int j = 0; j < 16; j++)
    //		{
    //			temp[j] += result_number[j];
    //		}
    //	}
    //	for (int k = 0; k < 16; k++)
    //	{
    //		temp[k] /= 1;
    //		result_number[k] = temp[k];
    //		result << result_number[k] << '\t';
    //	}
    //	result << endl;
    //}

    /*
    for (int i = 0; i < 10; i++)    //以Beacon周期为自变量的有10种场景
    {
        para.NODE_NUMBER = 2000;
        para.cluster_max = 40;
        para.Tbeacon = Tbeacon[i];
        suffix = "_Max Cluster_" + to_string(int(para.cluster_max)) + "_Number_" + to_string(int(para.NODE_NUMBER)) + "_Beacon_" + to_string(int(para.Tbeacon));
        result << suffix << endl;
        for (int i = 0; i < 10; i++)   //每种场景统计10次
        {
            result_number = Event_Manage(para, suffix);
            for (int j = 0; j < 13; j++)
            {
                temp[j] += result_number[j];
            }
        }
        for (int k = 0; k < 13; k++)
        {
            temp[k] /= 10;
            result_number[k] = temp[k];
            result << result_number[k] << '\t';
        }
        result << endl;
    }
    */
    result.close();
    cout << "--------------END---------------" << endl;
}
