#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Network.h"

#include <QMainWindow>
#include <Bigscene.h>
#include <QPainter>
#include <Smallscene.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    network net;
    Node * nodes;

    QPen * pen;
    QBrush * brush;

    static int count ;
private slots:
    void on_runButton_clicked();


private:
    QTimer * qtimer;
    Ui::MainWindow *ui;
    BigScene * bScene;
    SmallScene * sScene;

    void changeColor();
    void initNodes(int nodeNum);
};

#endif // MAINWINDOW_H
