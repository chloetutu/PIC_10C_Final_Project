#ifndef BREAD_H
#define BREAD_H
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPainter>
#include "food.h"
//
class Bread: public Food{
public:
   Bread(QString);
 void print();

};

#endif // BREAD_H
