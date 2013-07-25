#include "message_item.h"

MESSAGE_ITEM::MESSAGE_ITEM(QPixmap avatar, QString name, QString text, DIRECTION direct, QGraphicsItem *parent):QGraphicsObject(parent)
{
    this->avatar = avatar.scaled(60, 60, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    this->name = name;
    this->text = text;
    this->direct = direct;

    boundRect.setRect(0, 0, 300, 70);
    avatar_margin = 5;

    QGraphicsDropShadowEffect *shadow;
    shadow = new QGraphicsDropShadowEffect();
    shadow->setOffset(0);
    shadow->setBlurRadius(20);

    this->setGraphicsEffect(shadow);

    //add text
    item_name = new QGraphicsTextItem(this);
    item_text = new QGraphicsTextItem(this);

    if(this->direct == OUT){
        item_name->setPos(80, 5);
        item_text->setPos(80, 24);
    }

    ProcessMessageText();
}

MESSAGE_ITEM::~MESSAGE_ITEM()
{
    delete item_name;
    delete item_text;
}

void MESSAGE_ITEM::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();


    //draw rect
    painter->setBrush(QBrush(QColor(255, 255, 255, 230)));
    painter->setPen(Qt::NoPen);

    painter->drawRoundedRect(boundRect, 8, 8);

    //draw avatar
    if(direct == OUT)
        painter->drawPixmap(avatar_margin, avatar_margin, avatar);
    else
        painter->drawPixmap(boundRect.width() - avatar.width() - avatar_margin, boundRect.height() - avatar.height() - avatar_margin, avatar);

    painter->restore();
}

void MESSAGE_ITEM::ProcessMessageText()
{
    item_name->setPlainText(name);

    item_text->setPlainText(text);

    boundRect.setHeight(item_name->boundingRect().height());
    boundRect.setHeight(boundRect.height() + item_text->boundingRect().height());

    if(boundRect.height() < avatar.height() + (avatar_margin*2)){
        boundRect.setHeight(avatar.height() + (avatar_margin*2));
    }
}

void MESSAGE_ITEM::slot_anim_init()
{
}

void MESSAGE_ITEM::slot_anim_show()
{
}

void MESSAGE_ITEM::slot_anim_hide()
{
}


QRectF MESSAGE_ITEM::boundingRect() const
{
    return boundRect;
}
