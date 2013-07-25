#ifndef MESSAGE_BUTTON_H
#define MESSAGE_BUTTON_H

#include <QtGui>



class MESSAGE_BUTTON : public QGraphicsObject
{
    Q_OBJECT
private:
    QPixmap icon;
    QPixmap bg;

    QGraphicsItemAnimation *anim;

public:
    MESSAGE_BUTTON(QGraphicsItem *parent = 0);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;

    void anim_init();
    void anim_show();
    void anim_hide();
};

#endif // MESSAGE_BUTTON_H
