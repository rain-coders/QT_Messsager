#ifndef VIEWER_H
#define VIEWER_H

#include <QtGui>
#include "message_button.h"
#include "message_item.h"


class VIEWER : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    MESSAGE_BUTTON *button_message;


public:
    explicit VIEWER(QWidget *parent = 0);
    ~VIEWER();

    void resizeEvent(QResizeEvent *);
    
};

#endif // VIEWER_H
