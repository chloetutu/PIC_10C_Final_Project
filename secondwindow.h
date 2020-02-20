#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include "wall.h"
#include "target.h"
#include "health.h"
#include "player.h"
#include "meat.h"
#include "cheese.h"
#include "bread.h"
#include "bread_bin.h"
#include "cheese_bin.h"
#include "meat_bin.h"
#include "veggie_bin.h"
#include "veggies.h"

//Desgins a Second Window that will say Welcome to Particle board and then print the grid of particles

class SecondWindow: public QWidget
{
    Q_OBJECT

public:
    //Secondary window declaration
    SecondWindow(QWidget *parent = nullptr);

    //void printgrid(int, int);
    ~SecondWindow();
        //virtual void paintEvent(QPaintEvent* e);
    void draw_walls();
    void draw_targets();
    void change_health();
    void set_up_customers();
    void keyPressEvent(QKeyEvent *event);
    void setPartner(QWidget* partner);
public slots:
    void customer_order1();
    void customer_order2();
    void customer_order3();
    void customer_order4();
private:
    //The different text that will appear on the window
    QLabel* text1;
   // Health* player_health;
    QLabel* health_text;
    qreal health =10;
    int challenge_number;
    QGridLayout* play_space;
    QHBoxLayout* title_space;
//    QHBoxLayout* order_space;
    QGridLayout* sandwich_layout;
    QVBoxLayout* fullwindow;
    Player* main_character;
    Bread_Bin* binb1;
    Bread_Bin* binb2;
    Bread_Bin* binb3;

    Cheese_Bin* binc1;
    Cheese_Bin* binc2;
    Cheese_Bin* binc3;

    Meat_Bin* binm1;
    Meat_Bin* binm2;
    Meat_Bin* binm3;

    Veggie_Bin* binv1;
    Veggie_Bin* binv2;
    Veggie_Bin* binv3;

    Player* customer1;
    QPushButton* order1;
    Player* customer2;
    QPushButton* order2;
    Player* customer3;
  QPushButton* order3;
    Player* customer4;
   QPushButton* order4;


   QWidget* secondPage;
   QWidget* mPartner;
   QPushButton* homeScreen;



signals:
};

#endif // SECONDWINDOW_H
