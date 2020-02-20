#include "secondwindow.h"
#include "player.h"
#include "wall.h"
#include "target.h"


#include <QGridLayout>

//Makes the second window which will be able to recieve the signal from MainWindow
SecondWindow::SecondWindow(QWidget *parent)
    : QWidget(parent)
{
this->setFixedSize(875,700);
QPixmap bkgnd(":/main.png");
bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
QPalette palette;
palette.setBrush(QPalette::Background, bkgnd);
this->setPalette(palette);

setFocusPolicy(Qt::ClickFocus);

fullwindow = new QVBoxLayout();
title_space = new QHBoxLayout();
play_space = new QGridLayout();
sandwich_layout = new QGridLayout();
homeScreen = new QPushButton("Home Screen");

QLabel* bread1 = new QLabel("WB");
QLabel* bread2 = new QLabel("WWB");
QLabel* bread3 = new QLabel("PB");

QLabel* cheese1 = new QLabel("AC");
QLabel* cheese2 = new QLabel("SC");
QLabel* cheese3 = new QLabel("VC");

QLabel* meat1 = new QLabel("TM");
QLabel* meat2 = new QLabel("S");
QLabel* meat3 = new QLabel("IM");

QLabel* veggies1 = new QLabel("L");
QLabel* veggies2 = new QLabel("P");
QLabel* veggies3 = new QLabel("Sp");


//player_health
this->setFixedSize(700,700);
text1 = new QLabel("Welcome to Heck's Kitchen!");
health_text= new QLabel("Health: "+ QString::number(health) );
main_character = new Player;
 binb1 = new Bread_Bin(12,1);
 binb2 = new Bread_Bin(13,1);
 binb3 = new Bread_Bin(14,1);

 binc1 = new Cheese_Bin(12,3);
 binc2 = new Cheese_Bin(13,3);
 binc3 = new Cheese_Bin(14,3);

 binm1 = new Meat_Bin(12,5);
 binm2 = new Meat_Bin(13,5);
 binm3 = new Meat_Bin(14,5);

 binv1 = new Veggie_Bin(12,7);
 binv2 = new Veggie_Bin(13,7);
 binv3 = new Veggie_Bin(14,7);

//SET UP CUSTOMER
             customer1 = new Player(1,1);
             customer2 = new Player(1,2);
             customer3 = new Player(1,3);
             customer4 = new Player(1,4);
             order1 = new QPushButton ("Order1");
             order2 = new QPushButton ("Order2");
             order3 = new QPushButton ("Order3");
             order4 = new QPushButton ("Order4");
            connect(order1, SIGNAL(clicked()), this,SLOT(customer_order1()));
            connect(order2, SIGNAL(clicked()), this,SLOT(customer_order2()));
            connect(order3, SIGNAL(clicked()), this,SLOT(customer_order3()));
            connect(order4, SIGNAL(clicked()), this,SLOT(customer_order4()));
            customer1->set_basic_sandwich();
            customer2->set_basic_sandwich();
            customer3->set_basic_sandwich();
            customer4->set_basic_sandwich();

 draw_walls();
 draw_targets();

title_space->addWidget(text1);
title_space->addWidget(health_text);
title_space->addWidget(menu);

play_space->addWidget(customer1,customer1->get_pos_y(),customer1->get_pos_x());
play_space->addWidget(order1, customer1->get_pos_y(),customer1->get_pos_x()+1);
play_space->addWidget(customer2,customer2->get_pos_y(),customer2->get_pos_x());
play_space->addWidget(order2, customer2->get_pos_y(),customer2->get_pos_x()+1);
play_space->addWidget(customer3,customer3->get_pos_y(),customer3->get_pos_x());
play_space->addWidget(order3, customer3->get_pos_y(),customer3->get_pos_x()+1);
play_space->addWidget(customer4,customer4->get_pos_y(),customer4->get_pos_x());
play_space->addWidget(order4, customer4->get_pos_y(),customer4->get_pos_x()+1);

play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());

play_space->addWidget(binb1,binb1->get_bin_pos_y(),binb1->get_bin_pos_x());
play_space->addWidget(bread1,binb1->get_bin_pos_y(),binb1->get_bin_pos_x());

play_space->addWidget(binb2,binb2->get_bin_pos_y(),binb2->get_bin_pos_x());
play_space->addWidget(bread2,binb2->get_bin_pos_y(),binb2->get_bin_pos_x());

play_space->addWidget(binb3,binb3->get_bin_pos_y(),binb3->get_bin_pos_x());
play_space->addWidget(bread3,binb3->get_bin_pos_y(),binb3->get_bin_pos_x());


play_space->addWidget(binc1,binc1->get_bin_pos_y(),binc1->get_bin_pos_x());
play_space->addWidget(cheese1,binc1->get_bin_pos_y(),binc1->get_bin_pos_x());

play_space->addWidget(binc2,binc2->get_bin_pos_y(),binc2->get_bin_pos_x());
play_space->addWidget(cheese2,binc2->get_bin_pos_y(),binc2->get_bin_pos_x());

play_space->addWidget(binc3,binc3->get_bin_pos_y(),binc3->get_bin_pos_x());
play_space->addWidget(cheese3,binc3->get_bin_pos_y(),binc3->get_bin_pos_x());


play_space->addWidget(binm1,binm1->get_bin_pos_y(),binm1->get_bin_pos_x());
play_space->addWidget(meat1,binm1->get_bin_pos_y(),binm1->get_bin_pos_x());

play_space->addWidget(binm2,binm2->get_bin_pos_y(),binm2->get_bin_pos_x());
play_space->addWidget(meat2,binm2->get_bin_pos_y(),binm2->get_bin_pos_x());

play_space->addWidget(binm3,binm3->get_bin_pos_y(),binm3->get_bin_pos_x());
play_space->addWidget(meat3,binm3->get_bin_pos_y(),binm3->get_bin_pos_x());

play_space->addWidget(binv1,binv1->get_bin_pos_y(),binv1->get_bin_pos_x());
play_space->addWidget(veggies1,binv1->get_bin_pos_y(),binv1->get_bin_pos_x());

play_space->addWidget(binv2,binv2->get_bin_pos_y(),binv2->get_bin_pos_x());
play_space->addWidget(veggies2,binv2->get_bin_pos_y(),binv2->get_bin_pos_x());

play_space->addWidget(binv3,binv3->get_bin_pos_y(),binv3->get_bin_pos_x());
play_space->addWidget(veggies3,binv3->get_bin_pos_y(),binv3->get_bin_pos_x());


fullwindow->addLayout(title_space);
fullwindow->addLayout(play_space);
//fullwindow->addLayout(sandwich_layout);
setLayout(fullwindow);
}

void SecondWindow:: customer_order1(){
    customer1->test_print_sandwich();
    //fullwindow-> addLayout(customer1->print_sandwich());
    return;
}

void SecondWindow:: customer_order2(){
     customer2->test_print_sandwich();
   // fullwindow-> addLayout(customer2->print_sandwich());
    return;
}

void SecondWindow:: customer_order3(){
     customer3->test_print_sandwich();
   // fullwindow-> addLayout(customer3->print_sandwich());
    return;
}

void SecondWindow:: customer_order4(){
     customer4->test_print_sandwich();
    //fullwindow-> addLayout(customer4->print_sandwich());
    return;
}

void SecondWindow:: draw_walls(){
    for (int i= 0; i<8; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,i,0);
    }
    for (int i= 0; i<8; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,i,16);
    }
    for (int i= 0; i<16; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,0,i);
    }
    for (int i= 0; i<16; i++){
        Wall* a= new Wall;
        play_space->addWidget(a,8,i);
    }
}

void SecondWindow:: draw_targets(){
    for (int i =1; i<8; i++){
        Target* a= new Target;
        play_space->addWidget(a,i, 2);
    }
}

void SecondWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer1->get_pos_x() &&main_character->get_pos_y()==customer1->get_pos_y()){
        main_character->print_sandwich();
        if (main_character->check_order(customer1) == true){
            QLabel* winner = new QLabel( "You win the game!!");
            winner->show();
             main_character->delete_sandwich();
             customer1->delete_sandwich();
             customer1->remove_event();
        }
        else{
            QLabel* looser = new QLabel( "You Lost!!");
            looser->show();
             main_character->delete_sandwich();
        }

    }
    else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer2->get_pos_x() &&main_character->get_pos_y()==customer2->get_pos_y()){
        main_character->print_sandwich();
        if (main_character->check_order(customer2) == true){
            QLabel* winner = new QLabel( "You win the game!!");
            winner->show();
             main_character->delete_sandwich();
             customer2->delete_sandwich();
             customer2->remove_event();
        }
        else{
            QLabel* looser = new QLabel( "You Lost!!");
            looser->show();
             main_character->delete_sandwich();
        }

    }

   else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer3->get_pos_x() &&main_character->get_pos_y()==customer3->get_pos_y()){
        main_character->print_sandwich();
        if (main_character->check_order(customer3) == true){
            QLabel* winner = new QLabel( "You win the game!!");
            winner->show();
             main_character->delete_sandwich();
             customer3->delete_sandwich();
             customer3->remove_event();
        }
        else{
            QLabel* looser = new QLabel( "You Lost!!");
            looser->show();
             main_character->delete_sandwich();
        }

    }

    else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer4->get_pos_x() &&main_character->get_pos_y()==customer4->get_pos_y()){
        main_character->print_sandwich();
        if (main_character->check_order(customer4) == true){
            QLabel* winner = new QLabel( "You win the game!!");
            winner->show();
             main_character->delete_sandwich();
             customer4->delete_sandwich();
             customer4->remove_event();
        }
        else{
            QLabel* looser = new QLabel( "You Lost!!");
            looser->show();
             main_character->delete_sandwich();
        }

    }

    if(event->key() == Qt::Key_A||event->key() == Qt::Key_Left){
    if(main_character->get_pos_x()>2){
    main_character->move_left();
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
    }

    }
    else if(event->key() == Qt::Key_D||event->key() == Qt::Key_Right){
        if(main_character->get_pos_x()<16){
    main_character->move_right();
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    }

    else if(event->key() == Qt::Key_W||event->key() == Qt::Key_Up){
        if(main_character->get_pos_y()>0){
    main_character->move_up();
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    }

    else if(event->key() == Qt::Key_S||event->key() == Qt::Key_Down){
        if(main_character->get_pos_y()<8){
    main_character->move_down();
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    }

   if(event->key() == Qt::Key_Space){
        if(main_character->get_pos_x() == binc1->get_bin_pos_x()&&main_character->get_pos_y() == binc1->get_bin_pos_y() ){
            Food* a = new Cheese("American Cheese");
            main_character->add_food(a);

        }
        if(main_character->get_pos_x() == binc2->get_bin_pos_x()&&main_character->get_pos_y() == binc2->get_bin_pos_y() ){
                 Food* a = new Cheese("Swiss Cheese");
                 main_character->add_food(a);

        }
       if(main_character->get_pos_x() == binc3->get_bin_pos_x()&&main_character->get_pos_y() == binc3->get_bin_pos_y() ){
               Food* a = new Cheese("Vegan Cheese");
               main_character->add_food(a);

                  }



        if(main_character->get_pos_x() == binb1->get_bin_pos_x() && main_character->get_pos_y() == binb1->get_bin_pos_y() ){
            Food* a = new Bread("White Bread");
            main_character->add_food(a);

        }
        if(main_character->get_pos_x() == binb2->get_bin_pos_x() && main_character->get_pos_y() == binb2->get_bin_pos_y() ){
            Food* a = new Bread("Whole Wheat Bread");
            main_character->add_food(a);

        }
        if(main_character->get_pos_x() == binb3->get_bin_pos_x() && main_character->get_pos_y() == binb3->get_bin_pos_y() ){
            Food* a = new Bread("Prezel Bun");
            main_character->add_food(a);

        }



        if(main_character->get_pos_x() == binm1->get_bin_pos_x() && main_character->get_pos_y() == binm1->get_bin_pos_y() ){
            Food* a = new Meat("Turkey Meat");
            main_character->add_food(a);

        }
        if(main_character->get_pos_x() == binm2->get_bin_pos_x() && main_character->get_pos_y() == binm2->get_bin_pos_y() ){
            Food* a = new Meat("Steak");
            main_character->add_food(a);

        }
        if(main_character->get_pos_x() == binm3->get_bin_pos_x() && main_character->get_pos_y() == binm3->get_bin_pos_y() ){
            Food* a = new Meat("Impossible Meat");
            main_character->add_food(a);

        }





        if(main_character->get_pos_x() == binv1->get_bin_pos_x() && main_character->get_pos_y() == binv1->get_bin_pos_y() ){
            Food* a = new Veggies("Lettuce");
            main_character->add_food(a);

        }
        if(main_character->get_pos_x() == binv2->get_bin_pos_x() && main_character->get_pos_y() == binv2->get_bin_pos_y() ){
            Food* a = new Veggies("Peppers");
            main_character->add_food(a);

        }
        if(main_character->get_pos_x() == binv3->get_bin_pos_x() && main_character->get_pos_y() == binv3->get_bin_pos_y() ){
            Food* a = new Veggies("Spinage");
            main_character->add_food(a);

        }



    }

    return;
}

void SecondWindow::setPartner(QWidget* partner)
    {
        if(partner == 0)
            return;
        if(mPartner != partner)
        {
            if(mPartner != 0)
            {
                disconnect(menu, SIGNAL(clicked()), this, SLOT(hide()));
                disconnect(menu, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
            }
            mPartner = partner;

            connect(menu, SIGNAL(clicked()), this, SLOT(hide()));
            connect(menu, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
        }
    }

SecondWindow::~SecondWindow(){
    delete main_character;
    delete customer1;
    /*delete customer2;
    delete customer3;
    delete customer4;*/
}


//Makes the second window which will be able to recieve the signal from MainWindow
//SecondWindow::SecondWindow(QWidget *parent)
//    : QWidget(parent), mPartner(0)
//{
//    this->setFixedSize(875,700);
//    QPixmap bkgnd(":/main.png");
//    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
//    QPalette palette;
//    palette.setBrush(QPalette::Background, bkgnd);
//    this->setPalette(palette);

//    setFocusPolicy(Qt::ClickFocus);

//fullwindow = new QVBoxLayout();
//title_space = new QHBoxLayout();
//play_space = new QGridLayout();
//order_space = new QHBoxLayout();
//sandwich_layout = new QGridLayout();
//menu = new QPushButton("Menu");


//QLabel* bread1 = new QLabel("WB");
//QLabel* bread2 = new QLabel("WWB");
//QLabel* bread3 = new QLabel("PB");

//QLabel* cheese1 = new QLabel("AC");
//QLabel* cheese2 = new QLabel("SC");
//QLabel* cheese3 = new QLabel("VC");

//QLabel* meat1 = new QLabel("TM");
//QLabel* meat2 = new QLabel("S");
//QLabel* meat3 = new QLabel("IM");

//QLabel* veggies1 = new QLabel("L");
//QLabel* veggies2 = new QLabel("P");
//QLabel* veggies3 = new QLabel("Sp");


//player_health
//text1 = new QLabel("Welcome to Heck's Kitchen!");
//health_text= new QLabel("Health: "+ QString::number(health) );
//main_character = new Player;
// binb1 = new Bread_Bin(12,1);
// binb2 = new Bread_Bin(13,1);
// binb3 = new Bread_Bin(14,1);

// binc1 = new Cheese_Bin(12,3);
// binc2 = new Cheese_Bin(13,3);
// binc3 = new Cheese_Bin(14,3);

// binm1 = new Meat_Bin(12,5);
// binm2 = new Meat_Bin(13,5);
// binm3 = new Meat_Bin(14,5);

// binv1 = new Veggie_Bin(12,7);
// binv2 = new Veggie_Bin(13,7);
// binv3 = new Veggie_Bin(14,7);

////SET UP CUSTOMER
//             customer1 = new Player(1,1);
//             customer2 = new Player(1,2);
//             customer3 = new Player(1,3);
//             customer4 = new Player(1,4);
////             order1 = new QPushButton ("Order1");
////             order2 = new QPushButton ("Order2");
////             order3 = new QPushButton ("Order3");
////             order4 = new QPushButton ("Order4");
////            connect(order1, SIGNAL(clicked()), this,SLOT(customer_order1()));
////            connect(order2, SIGNAL(clicked()), this,SLOT(customer_order2()));
////            connect(order3, SIGNAL(clicked()), this,SLOT(customer_order3()));
////            connect(order4, SIGNAL(clicked()), this,SLOT(customer_order4()));
//            customer1->set_basic_sandwich();
//            customer2->set_basic_sandwich();
//            customer3->set_basic_sandwich();
//            customer4->set_basic_sandwich();

// draw_walls();
// draw_targets();


//title_space->addWidget(text1);
//title_space->addWidget(health_text);
//title_space->addWidget(menu);

//    QLabel* title_label = new QLabel;
//    QPixmap title_pic(":/title.png");
//    QPalette title_palette;
//    title_palette.setBrush(QPalette::Background, bkgnd);
//    this->setPalette(title_palette);

//play_space->addWidget(customer1,customer1->get_pos_y(),customer1->get_pos_x());
//play_space->addWidget(order1, customer1->get_pos_y(),customer1->get_pos_x()+1);
//play_space->addWidget(customer2,customer2->get_pos_y(),customer2->get_pos_x());
//play_space->addWidget(order2, customer2->get_pos_y(),customer2->get_pos_x()+1);
//play_space->addWidget(customer3,customer3->get_pos_y(),customer3->get_pos_x());
//play_space->addWidget(order3, customer3->get_pos_y(),customer3->get_pos_x()+1);
//play_space->addWidget(customer4,customer4->get_pos_y(),customer4->get_pos_x());
//play_space->addWidget(order4, customer4->get_pos_y(),customer4->get_pos_x()+1);

//play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());

//play_space->addWidget(binb1,binb1->get_bin_pos_y(),binb1->get_bin_pos_x());
//play_space->addWidget(bread1,binb1->get_bin_pos_y(),binb1->get_bin_pos_x());

//play_space->addWidget(binb2,binb2->get_bin_pos_y(),binb2->get_bin_pos_x());
//play_space->addWidget(bread2,binb2->get_bin_pos_y(),binb2->get_bin_pos_x());

//play_space->addWidget(binb3,binb3->get_bin_pos_y(),binb3->get_bin_pos_x());
//play_space->addWidget(bread3,binb3->get_bin_pos_y(),binb3->get_bin_pos_x());


//play_space->addWidget(binc1,binc1->get_bin_pos_y(),binc1->get_bin_pos_x());
//play_space->addWidget(cheese1,binc1->get_bin_pos_y(),binc1->get_bin_pos_x());

//play_space->addWidget(binc2,binc2->get_bin_pos_y(),binc2->get_bin_pos_x());
//play_space->addWidget(cheese2,binc2->get_bin_pos_y(),binc2->get_bin_pos_x());

//play_space->addWidget(binc3,binc3->get_bin_pos_y(),binc3->get_bin_pos_x());
//play_space->addWidget(cheese3,binc3->get_bin_pos_y(),binc3->get_bin_pos_x());


//play_space->addWidget(binm1,binm1->get_bin_pos_y(),binm1->get_bin_pos_x());
//play_space->addWidget(meat1,binm1->get_bin_pos_y(),binm1->get_bin_pos_x());

//play_space->addWidget(binm2,binm2->get_bin_pos_y(),binm2->get_bin_pos_x());
//play_space->addWidget(meat2,binm2->get_bin_pos_y(),binm2->get_bin_pos_x());

//play_space->addWidget(binm3,binm3->get_bin_pos_y(),binm3->get_bin_pos_x());
//play_space->addWidget(meat3,binm3->get_bin_pos_y(),binm3->get_bin_pos_x());


//play_space->addWidget(binv1,binv1->get_bin_pos_y(),binv1->get_bin_pos_x());
//play_space->addWidget(veggies1,binv1->get_bin_pos_y(),binv1->get_bin_pos_x());

//play_space->addWidget(binv2,binv2->get_bin_pos_y(),binv2->get_bin_pos_x());
//play_space->addWidget(veggies2,binv2->get_bin_pos_y(),binv2->get_bin_pos_x());

//play_space->addWidget(binv3,binv3->get_bin_pos_y(),binv3->get_bin_pos_x());
//play_space->addWidget(veggies3,binv3->get_bin_pos_y(),binv3->get_bin_pos_x());

//QLabel* orderz = new QLabel("ORDERZ");
//order_space->addWidget(orderz);
////order_space->addWidget(customer_order1());

//fullwindow->addLayout(title_space);
//fullwindow->addLayout(play_space);
//fullwindow->addLayout(order_space);
////fullwindow->addLayout(sandwich_layout);
//setLayout(fullwindow);
//}

////QWidget* SecondWindow:: customer_order1(){
////    return customer1->test_print_sandwich();
////    //fullwindow-> addLayout(customer1->print_sandwich());
////}

//void SecondWindow:: customer_order1(){
//    customer1->test_print_sandwich();
//    //fullwindow-> addLayout(customer1->print_sandwich());
//    return;
//}

//void SecondWindow:: customer_order2(){
//     customer2->test_print_sandwich();
//   // fullwindow-> addLayout(customer2->print_sandwich());
//    return;
//}

//void SecondWindow:: customer_order3(){
//     customer3->test_print_sandwich();
//   // fullwindow-> addLayout(customer3->print_sandwich());
//    return;
//}

//void SecondWindow:: customer_order4(){
//     customer4->test_print_sandwich();
//    //fullwindow-> addLayout(customer4->print_sandwich());
//    return;
//}

//void SecondWindow:: draw_walls(){
//    for (int i= 0; i<8; i++){
//        Wall* a= new Wall;
//        play_space->addWidget(a,i,0);
//    }
//    for (int i= 0; i<8; i++){
//        Wall* a= new Wall;
//        play_space->addWidget(a,i,16);
//    }
//    for (int i= 0; i<16; i++){
//        Wall* a= new Wall;
//        play_space->addWidget(a,0,i);
//    }
//    for (int i= 0; i<16; i++){
//        Wall* a= new Wall;
//        play_space->addWidget(a,8,i);
//    }
//}

//void SecondWindow:: draw_targets(){
//    for (int i =1; i<8; i++){
//        Target* a= new Target;
//        play_space->addWidget(a,i, 2);
//    }
//}

//void SecondWindow::keyPressEvent(QKeyEvent *event){
//    if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer1->get_pos_x() &&main_character->get_pos_y()==customer1->get_pos_y()){
//        main_character->print_sandwich();
//        if (main_character->check_order(customer1) == true){
//            QLabel* winner = new QLabel( "You win the game!!");
//            winner->show();
//             main_character->delete_sandwich();
//             customer1->delete_sandwich();
//             customer1->remove_event();
//        }
//        else{
//            QLabel* looser = new QLabel( "You Lost!!");
//            looser->show();
//             main_character->delete_sandwich();
//        }

//    }
//    else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer2->get_pos_x() &&main_character->get_pos_y()==customer2->get_pos_y()){
//        main_character->print_sandwich();
//        if (main_character->check_order(customer2) == true){
//            QLabel* winner = new QLabel( "You win the game!!");
//            winner->show();
//             main_character->delete_sandwich();
//             customer2->delete_sandwich();
//             customer2->remove_event();
//        }
//        else{
//            QLabel* looser = new QLabel( "You Lost!!");
//            looser->show();
//             main_character->delete_sandwich();
//        }

//    }

//   else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer3->get_pos_x() &&main_character->get_pos_y()==customer3->get_pos_y()){
//        main_character->print_sandwich();
//        if (main_character->check_order(customer3) == true){
//            QLabel* winner = new QLabel( "You win the game!!");
//            winner->show();
//             main_character->delete_sandwich();
//             customer3->delete_sandwich();
//             customer3->remove_event();
//        }
//        else{
//            QLabel* looser = new QLabel( "You Lost!!");
//            looser->show();
//             main_character->delete_sandwich();
//        }

//    }

//    else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer4->get_pos_x() &&main_character->get_pos_y()==customer4->get_pos_y()){
//        main_character->print_sandwich();
//        if (main_character->check_order(customer4) == true){
//            QLabel* winner = new QLabel( "You win the game!!");
//            winner->show();
//             main_character->delete_sandwich();
//             customer4->delete_sandwich();
//             customer4->remove_event();
//        }
//        else{
//            QLabel* looser = new QLabel( "You Lost!!");
//            looser->show();
//             main_character->delete_sandwich();
//        }

//    }

//    if(event->key() == Qt::Key_A||event->key() == Qt::Key_Left){
//    if(main_character->get_pos_x()>2){
//    main_character->move_left();
//    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
//    }

//    }
//    else if(event->key() == Qt::Key_D||event->key() == Qt::Key_Right){
//        if(main_character->get_pos_x()<16){
//    main_character->move_right();
//    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
//        }
//    }

//    else if(event->key() == Qt::Key_W||event->key() == Qt::Key_Up){
//        if(main_character->get_pos_y()>0){
//    main_character->move_up();
//    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
//        }
//    }

//    else if(event->key() == Qt::Key_S||event->key() == Qt::Key_Down){
//        if(main_character->get_pos_y()<8){
//    main_character->move_down();
//    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
//        }
//    }

//   if(event->key() == Qt::Key_Space){
//        if(main_character->get_pos_x() == binc1->get_bin_pos_x()&&main_character->get_pos_y() == binc1->get_bin_pos_y() ){
//            Food* a = new Cheese("American Cheese");
//            main_character->add_food(a);

//        }
//        if(main_character->get_pos_x() == binc2->get_bin_pos_x()&&main_character->get_pos_y() == binc2->get_bin_pos_y() ){
//                 Food* a = new Cheese("Swiss Cheese");
//                 main_character->add_food(a);

//        }
//       if(main_character->get_pos_x() == binc3->get_bin_pos_x()&&main_character->get_pos_y() == binc3->get_bin_pos_y() ){
//               Food* a = new Cheese("Vegan Cheese");
//               main_character->add_food(a);

//                  }



//        if(main_character->get_pos_x() == binb1->get_bin_pos_x() && main_character->get_pos_y() == binb1->get_bin_pos_y() ){
//            Food* a = new Bread("White Bread");
//            main_character->add_food(a);

//        }
//        if(main_character->get_pos_x() == binb2->get_bin_pos_x() && main_character->get_pos_y() == binb2->get_bin_pos_y() ){
//            Food* a = new Bread("Whole Wheat Bread");
//            main_character->add_food(a);

//        }
//        if(main_character->get_pos_x() == binb3->get_bin_pos_x() && main_character->get_pos_y() == binb3->get_bin_pos_y() ){
//            Food* a = new Bread("Prezel Bun");
//            main_character->add_food(a);

//        }



//        if(main_character->get_pos_x() == binm1->get_bin_pos_x() && main_character->get_pos_y() == binm1->get_bin_pos_y() ){
//            Food* a = new Meat("Turkey Meat");
//            main_character->add_food(a);

//        }
//        if(main_character->get_pos_x() == binm2->get_bin_pos_x() && main_character->get_pos_y() == binm2->get_bin_pos_y() ){
//            Food* a = new Meat("Steak");
//            main_character->add_food(a);

//        }
//        if(main_character->get_pos_x() == binm3->get_bin_pos_x() && main_character->get_pos_y() == binm3->get_bin_pos_y() ){
//            Food* a = new Meat("Impossible Meat");
//            main_character->add_food(a);

//        }





//        if(main_character->get_pos_x() == binv1->get_bin_pos_x() && main_character->get_pos_y() == binv1->get_bin_pos_y() ){
//            Food* a = new Veggies("Lettuce");
//            main_character->add_food(a);

//        }
//        if(main_character->get_pos_x() == binv2->get_bin_pos_x() && main_character->get_pos_y() == binv2->get_bin_pos_y() ){
//            Food* a = new Veggies("Peppers");
//            main_character->add_food(a);

//        }
//        if(main_character->get_pos_x() == binv3->get_bin_pos_x() && main_character->get_pos_y() == binv3->get_bin_pos_y() ){
//            Food* a = new Veggies("Spinage");
//            main_character->add_food(a);

//        }



//    }

//    return;
//}

//void SecondWindow::setPartner(QWidget* partner)
//    {
//        if(partner == 0)
//            return;
//        if(mPartner != partner)
//        {
//            if(mPartner != 0)
//            {
//                disconnect(menu, SIGNAL(clicked()), this, SLOT(hide()));
//                disconnect(menu, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
//            }
//            mPartner = partner;

//            connect(menu, SIGNAL(clicked()), this, SLOT(hide()));
//            connect(menu, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
//        }
//    }

//SecondWindow::~SecondWindow(){
//    delete main_character;
//    delete customer1;
//    /*delete customer2;
//    delete customer3;
//    delete customer4;*/
//}

