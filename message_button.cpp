#include "message_button.h"

MESSAGE_BUTTON::MESSAGE_BUTTON(QGraphicsItem *parent):QGraphicsObject(parent)
{
    icon.load(":/message_button/icon");
    bg.load(":/message_button/bg");

    anim_init();
    anim_show();
}

void MESSAGE_BUTTON::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->drawPixmap(0, 0, bg);
    painter->drawPixmap(this->boundingRect().width()/2 - icon.width()/2, this->boundingRect().height()/2 - icon.height()/2, icon);

    painter->restore();
}

QRectF MESSAGE_BUTTON::boundingRect() const
{
    return QRectF(0, 0, this->bg.width(), this->bg.height());
}

void MESSAGE_BUTTON::anim_init()
{
    anim = new QGraphicsItemAnimation();
    anim->setItem(this);
    anim->setTimeLine(new QTimeLine(1000));
    anim->setPosAt(0, QPointF(450, 450));
    anim->setPosAt(1, anim->posAt(0) - QPointF(this->boundingRect().width(), this->boundingRect().height()));

}

void MESSAGE_BUTTON::anim_show()
{
    anim->timeLine()->setDirection(QTimeLine::Forward);
    anim->timeLine()->start();
}

void MESSAGE_BUTTON::anim_hide()
{
    anim->timeLine()->setDirection(QTimeLine::Backward);
    anim->timeLine()->start();
}
