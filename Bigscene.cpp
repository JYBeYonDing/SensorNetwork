#include "Bigscene.h"


BigScene::BigScene(QObject *parent) : QGraphicsScene(parent)
{
    this->cenItem = new centerItem;
    this->addItem(this->cenItem);
}
