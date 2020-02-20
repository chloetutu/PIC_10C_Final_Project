#include "veggie_bin.h"
Veggie_Bin::Veggie_Bin(int x, int y)
    : Bin(x,y){

}


void Veggie_Bin:: paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::green));
    QRectF pff(0,0,8,8);
    painter.drawEllipse(pff);

    return;
}
