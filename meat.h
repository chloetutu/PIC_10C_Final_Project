#ifndef MEAT_H
#define MEAT_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPainter>
#include "food.h"

class Meat: public Food{
public:
   Meat(QString);
     void print();

};

#endif // MEAT_H
