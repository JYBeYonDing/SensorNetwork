#ifndef BIGSCENE_H
#define BIGSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "Centeritem.h"
#include <QPaintEvent>
#include <QWidget>


class BigScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit BigScene(QObject *parent = nullptr);

signals:

public slots:
private:
    centerItem * cenItem;
    int count = 0;
};

#endif // BIGSCENE_H
