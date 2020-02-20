#include "mainwindow.h"
#include "secondwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(875,700);
    QPixmap bkgnd(":/menu.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    buttons = new QGridLayout();
    challenge = new QSlider();
    challenge->setRange(1,3);
    start = new QPushButton();

    QPixmap startPix(":/play.png");
    startPix = startPix.scaled(185, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon startIcon(startPix);
    start->setIcon(startIcon);
    start->setIconSize(startPix.rect().size());
    start->setFixedSize(startPix.rect().size());

    leave = new QPushButton();
    QPixmap leavePix(":/exit.png");
    leavePix = leavePix.scaled(185, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon leaveIcon(leavePix);
    leave->setIcon(leavePix);
    leave->setIconSize(leavePix.rect().size());
    leave->setFixedSize(leavePix.rect().size());

    instructions = new QPushButton();
    QPixmap instPix(":/training.png");
    instPix = instPix.scaled(275, 100, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon instIcon(instPix);
    instructions->setIcon(instIcon);
    instructions->setIconSize(instPix.rect().size());
    instructions->setFixedSize(instPix.rect().size());

    QSpacerItem* top = new QSpacerItem(100, 220, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QSpacerItem* bottom = new QSpacerItem(100, 120, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QSpacerItem* right = new QSpacerItem(100, 100, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QSpacerItem* middle = new QSpacerItem(100, 100, QSizePolicy::Maximum, QSizePolicy::Maximum);
//    connect(start, &QPushButton::pressed, this,&MainWindow::buttonpressed);
    connect(leave,&QPushButton::pressed, this, &MainWindow::buttonclose);
    buttons->addItem(top, 1, 1, 1, 3, Qt::AlignCenter);
    buttons->addItem(bottom, 5, 1, 1, 3, Qt::AlignCenter);
    buttons->addItem(middle, 2, 3, 3, 3, Qt::AlignCenter);
    buttons->addItem(right, 3, 4, 3, 3, Qt::AlignCenter);
    buttons->addWidget(challenge, 2, 2, 3, 1, Qt::AlignLeft);
    buttons->addWidget(start, 2, 5, Qt::AlignCenter);
    buttons->addWidget(instructions, 3, 5, Qt::AlignCenter);
    buttons->addWidget(leave, 4, 5, Qt::AlignCenter);

    QWidget* central = new QWidget();
    central->setLayout(buttons);
    this->setCentralWidget(central);
}

void MainWindow::setPartner(QWidget* partner)
    {
        if(partner == 0)
            return;
        if(mPartner != partner)
        {
            if(mPartner != 0)
            {
                disconnect(start, SIGNAL(clicked()), this, SLOT(hide()));
                disconnect(start, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
            }
            mPartner = partner;

            connect(start, SIGNAL(clicked()), this, SLOT(hide()));
            connect(start, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
        }
    }

MainWindow::~MainWindow(){}

//void MainWindow::buttonpressed(){

//  w2.show();
//}

void MainWindow::buttonclose(){
MainWindow::close();
w2.close();
}




