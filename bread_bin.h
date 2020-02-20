#ifndef BREAD_BIN_H
#define BREAD_BIN_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPainter>
#include "bin.h"

class Bread_Bin:public Bin{
    public:
       Bread_Bin(int,int);
        void paintEvent(QPaintEvent* e);

private:

};



#endif // BREAD_BIN_H
