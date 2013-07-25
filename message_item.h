#ifndef MESSAGE_ITEM_H
#define MESSAGE_ITEM_H

#include <QtGui>

enum DIRECTION{
    IN = 0,
    OUT
};

class MESSAGE_ITEM : public QGraphicsObject
{
    Q_OBJECT
private:
    QPixmap avatar;

    QString name;
    QString text;

    DIRECTION direct;

    QGraphicsTextItem *item_name;
    QGraphicsTextItem *item_text;

    QRectF boundRect;
    int avatar_margin;



public:
    MESSAGE_ITEM(QPixmap avatar, QString name, QString text, DIRECTION direct, QGraphicsItem *parent = 0);
    ~MESSAGE_ITEM();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;

    void ProcessMessageText();

public slots:
    void slot_anim_init();
    void slot_anim_show();
    void slot_anim_hide();
};

#endif // MESSAGE_ITEM_H
