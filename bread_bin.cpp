#include "bread_bin.h"

Bread_Bin::Bread_Bin(int x,int y): Bin(x,y)
    {
  //  bread_bin_pos_x = 15;
   // bread_bin_pos_y = 1;
}


void Bread_Bin:: paintEvent(QPaintEvent* e){

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::gray));
    QRectF pff(0,0,8,8);
    painter.drawEllipse(pff);

    return;
}
