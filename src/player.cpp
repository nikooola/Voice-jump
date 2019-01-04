#include "player.h"

Player::Player(QGraphicsView *view, QGraphicsScene *scene = nullptr)
    : m_view(view), m_scene(scene)
{
    qDebug() << "igrac";

    this->setRect(0, 0, 50, 50);
    this->setBrush(QBrush(Qt::red));

    //  igrac se stavlja u fokus
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(!recorder->get_is_recording())
            setPos(x()-10, y());

    }

    else if(event->key() == Qt::Key_Right){
        if(!recorder->get_is_recording())
            setPos(x()+10, y());
        if( ((int)x()) % VIEW_WIDTH > 0 && ((int)x()) % VIEW_WIDTH < 11){
            qDebug() << "nove prepreke";
            drawObsticles(((int)x())/VIEW_WIDTH + 1);
        }

    }

    else if(event->key() == Qt::Key_Space){
        qDebug() << "space";
        recorder->startRecording(x(), y());
    }

    else if(event->key() == Qt::Key_S){
        qDebug() << "stop";
        recorder->stopRecording();
    }

    // popraviti da view prati igraca
    //m_view->centerOn(this);
}

void Player::drawObsticles(int count){
    //width = 1000;
    int num_of_obsticles = 3;
    for (int i=1; i<=num_of_obsticles; i++){
        Obstacle *o = new Obstacle(count*VIEW_WIDTH + i*100 + i*400/(num_of_obsticles-1), 0);
        m_scene->addItem(o);
    }

    m_scene->addLine(count*VIEW_WIDTH-100, 0, (count+1)*VIEW_WIDTH, 0, QPen(Qt::black, 1));

}



