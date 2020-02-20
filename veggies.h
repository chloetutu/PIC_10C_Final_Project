#ifndef VEGGIES_H
#define VEGGIES_H
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
class Veggies: public Food{
public:
   Veggies(QString);
 void print();

};
#endif // VEGGIES_H
