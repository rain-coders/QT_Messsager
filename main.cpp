#include "viewer.h"

int main(int c, char **v){
    QApplication app(c, v);

    VIEWER view;
    view.show();

    return app.exec();
}
