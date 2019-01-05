#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>
#include "recorder.h"
#include "obstacle.h"

#define VIEW_WIDTH 1000

extern Recorder *recorder;
//extern QGraphicsScene scene;

class Player : public QGraphicsEllipseItem
{
public:
    Player(QGraphicsView *view, QGraphicsScene *scene);
    void keyPressEvent(QKeyEvent *event);
    void drawObsticles(int count);
    //void keyReleaseEvent(QKeyEvent *event);
    QGraphicsView *m_view;
    QGraphicsScene *m_scene;
};

#endif // PLAYER_H