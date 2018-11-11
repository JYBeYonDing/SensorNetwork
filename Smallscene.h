#ifndef SMALLSCENE_H
#define SMALLSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QPaintEvent>
#include <QWidget>

class SmallScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SmallScene(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SMALLSCENE_H
