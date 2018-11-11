#include "Mainwindow.h"
#include "ui_mainwindow.h"
#include "Network.h"
#include <QString>
#include <QDebug>
#include <QtGlobal>
#include <QTime>
#include <Node.h>
#include <vector>

int MainWindow::count = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * 画图界面的一些初始化
     */
    this->bScene = new BigScene;
    this->sScene = new SmallScene;
    this->ui->bigView->setScene(bScene);
    this->qtimer = new QTimer;
    this->pen = new QPen(Qt::black, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    this->brush = new QBrush(Qt::white, Qt::SolidPattern);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bScene;
    delete sScene;
    delete qtimer;
    delete pen;
    delete brush;

}

/**
 * @brief MainWindow::on_runButton_clicked
 *
 * 点击运行按钮
 */
void MainWindow::on_runButton_clicked()
{
    // 读取参数
    QString nNum = MainWindow::ui->nodeInput->text();
    QString rTime = MainWindow::ui->runTimeInput->text();
    QString cTime = MainWindow::ui->cycleInput->text();
    QString len = MainWindow::ui->lengthInput->text();
    QString brd = MainWindow::ui->broadInput->text();
    QString dis = MainWindow::ui->distanceInput->text();
    net.SetNodeNum(nNum.toInt());
    net.SetRunTime(rTime.toInt());
    net.SetCycle(cTime.toInt());
    net.SetLength(len.toInt());
    net.SetBroad(brd.toInt());
    net.SetDistance(dis.toInt());

    //初始化节点
    int nodeNum = net.GetNodeNum();
    initNodes(nodeNum);

    //改变颜色
    changeColor();
}

/**
 * @brief MainWindow::initNodes
 * @param nodeNum
 * 根据节点数进行随机初始化操作
 */
void MainWindow::initNodes(int nodeNum)
{
    this->nodes = new Node[nodeNum];
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i = 0; i < nodeNum; i++)
    {
        int x  = qrand()%423;
        int y = qrand()%283;
        if (qrand()%2)
        {
            x = -x;
        }
        if (qrand()%2)
        {
            y = -y;
        }
        nodes[i].location[0] = x;
        nodes[i].location[1] = y;

        bScene->addEllipse(x,y,2,2,*pen, *brush);
    }
}




void MainWindow::changeColor()
{
    for(count = 0 ;count < net.GetNodeNum();count++)
    {
        count ++;
        if (count < net.GetNodeNum())
        {
           if(nodes[count].location[0] < 0 && nodes[count].location[1] < 0)
           {
               pen->setColor(Qt::red);
               brush->setColor(Qt::red);
               ui->bigView->viewport()->update(nodes[count].location[0],nodes[count].location[1],2,2);
               bScene->addEllipse(nodes[count].location[0],nodes[count].location[1],2,2,*pen,*brush);
               this->ui->bigView->setScene(bScene);
           }
           else if(nodes[count].location[0] >= 0 && nodes[count].location[1] < 0)
           {
//               QPen pen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
//               QBrush brush(Qt::green, Qt::SolidPattern);
               pen->setColor(Qt::green);
               brush->setColor(Qt::green);
               ui->bigView->viewport()->update(nodes[count].location[0],nodes[count].location[1],2,2);
               bScene->addEllipse(nodes[count].location[0],nodes[count].location[1],2,2,*pen,*brush);
               this->ui->bigView->setScene(bScene);
           }
            else if(nodes[count].location[0] < 0 && nodes[count].location[1] >= 0)
           {
//                   QPen pen(Qt::blue, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
//                   QBrush brush(Qt::blue, Qt::SolidPattern);
               pen->setColor(Qt::blue);
               brush->setColor(Qt::blue);
               ui->bigView->viewport()->update(nodes[count].location[0],nodes[count].location[1],2,2);
               bScene->addEllipse(nodes[count].location[0],nodes[count].location[1],2,2,*pen,*brush);
               this->ui->bigView->setScene(bScene);
            }
           else if(nodes[count].location[0] >= 0 && nodes[count].location[1] >= 0)
           {
//               QPen pen(Qt::yellow, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
//               QBrush brush(Qt::yellow, Qt::SolidPattern);
               pen->setColor(Qt::yellow);
               brush->setColor(Qt::yellow);
               ui->bigView->viewport()->update(nodes[count].location[0],nodes[count].location[1],2,2);
               bScene->addEllipse(nodes[count].location[0],nodes[count].location[1],2,2,*pen,*brush);
               this->ui->bigView->setScene(bScene);
           }
        }

    }

}
