#include "meat_bin.h"
Meat_Bin::Meat_Bin(int x,int y)
    : Bin(x,y){

}


void Meat_Bin:: paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::red));
    QRectF pff(0,0,8,8);
    painter.drawEllipse(pff);

    return;
}
