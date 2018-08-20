#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   QPalette pale;
   pale.setColor(QPalette::Background,Qt::black);
   this->setPalette(pale);
   i1 = new IPShow(this);
   s = new Beeper(this);
   bn = new Brightness(this);
   bp = new BadPoint(this);
   ui->pushButton->setStyleSheet("font: 15pt Noto Sans;");
   ui->pushButton_2->setStyleSheet("font: 15pt Noto Sans;");
   ui->pushButton_3->setStyleSheet("font: 15pt Noto Sans;");
   ui->pushButton_4->setStyleSheet("font: 15pt Noto Sans;");

}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::on_pushButton_clicked()//setIP
{
   i1->show();
}

void MainWindow::on_pushButton_2_clicked()//beeper
{
   s->show();
}

void MainWindow::on_pushButton_3_clicked()//brightness
{
   bn->show();
}

void MainWindow::on_pushButton_4_clicked()//bad point
{
   int currentScreenWid = QApplication::desktop()->width();
   int currentScreenHei  = QApplication::desktop()->height();
   bp->resize(currentScreenWid,currentScreenHei);
   bp->show();
}
