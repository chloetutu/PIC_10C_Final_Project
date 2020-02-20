#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>
#include "secondwindow.h"
#include <QGridLayout>
#include <QSpacerItem>

class MainWindow : public QMainWindow
{


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void buttonpressed();
    void buttonclose();
void setPartner(QWidget* partner);
public slots:
    void goToPage2();
private:
    QLabel* title;
    QLabel* challenge_level;
    QSlider* challenge;
    QPushButton* start;
    QPushButton* leave;
    QPushButton* instructions;
    QGridLayout* buttons;
    SecondWindow w2;

    QWidget* firstPage;
    QHBoxLayout* firstPageLayout;
    QWidget* mPartner;

};
#endif // MAINWINDOW_H
