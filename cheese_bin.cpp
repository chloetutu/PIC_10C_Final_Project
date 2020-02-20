#include "cheese_bin.h"

Cheese_Bin::Cheese_Bin(int x,int y)
    : Bin(x,y){

}


void Cheese_Bin:: paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::yellow));
    QRectF pff(0,0,8,8);
    painter.drawEllipse(pff);

    return;
}
