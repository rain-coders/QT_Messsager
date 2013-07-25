#include "viewer.h"

VIEWER::VIEWER(QWidget *parent) :
    QGraphicsView(parent)
{
    this->setFixedSize(450, 450);

    scene = new QGraphicsScene(QRectF(this->geometry()));
    this->setScene(scene);

    scene->setBackgroundBrush(QBrush(Qt::NoBrush));
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setStyleSheet("background-color: transparent; border-style: none;");
    this->setRenderHint(QPainter::Antialiasing, true);

    this->setAttribute(Qt::WA_X11NetWmWindowTypeDock, true);

    //add button
    button_message = new MESSAGE_BUTTON();
    scene->addItem(button_message);
    button_message->setPos(- this->width(), - this->height());


    //add message
    MESSAGE_ITEM *item = new MESSAGE_ITEM(QPixmap("avatar.png"), "Margarita Nikiforova", "Wazzaaaa wazzaaaa\n wssaaazaaaaa zsqaaazwzaa", OUT);
    scene->addItem(item);
    item->setPos(50, 50);

}

VIEWER::~VIEWER()
{
}

void VIEWER::resizeEvent(QResizeEvent *)
{
    this->setGeometry(QRect(QApplication::desktop()->width() - this->width(), QApplication::desktop()->height() - this->height(), this->width(), this->height()));
}
