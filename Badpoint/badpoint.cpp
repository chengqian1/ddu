#include "badpoint.h"
#include "ui_badpoint.h"
#include <QTimer>
#include <QColor>
#include <QPalette>
#include <QBrush>
#include <QDebug>
#include <QMouseEvent>


BadPoint::BadPoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BadPoint)
{
    ui->setupUi(this);
    this->setModal(true);
    QPalette palette;
    QColor col;
    col.setRgb(1,1,1);
    palette.setColor(QPalette::Background,col);
    this->setPalette(palette);
    ui->pushButton_3->setStyleSheet("font: 15pt Noto Sans;");
    ui->pushButton_4->setStyleSheet("font: 15pt Noto Sans;");

}

BadPoint::~BadPoint()
{
    delete ui;
}

void BadPoint::on_pushButton_3_clicked()
{
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    //timer->start(1000);
    QPalette palette;
    palette.setColor(QPalette::Background,Qt::black);
    this->setPalette(palette);
    //this->setStyleSheet("background-color:rgb(0,0,0)");//black
    //this->setStyleSheet("background-color:rgb(255,255,255)");
    //this->setStyleSheet("background-color:rgb(255,0,0)");
    //this->setStyleSheet("background-color:rgb(0,255,0)");
    //this->setStyleSheet("background-color:rgb(0,0,255)");
}

void BadPoint::on_pushButton_4_clicked()
{
    this->close();
}

void BadPoint::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        QPalette pal = this->palette();
        QBrush brush = pal.background();
        QColor c = brush.color();
        if(c.red()==0&&c.green()==0&&c.blue()==0)
        {
            QPalette palette;
            palette.setColor(QPalette::Background,Qt::white);
            this->setPalette(palette);
            //this->setStyleSheet("background-color:rgb(255,255,255)");
        }
        else if(c.red()==255&&c.green()==255&&c.blue()==255)
        {
            QPalette palette;
            palette.setColor(QPalette::Background,Qt::red);
            this->setPalette(palette);
            //this->setStyleSheet("background-color:rgb(255,0,0)");
        }
        else if(c.red()==255&&c.green()==0&&c.blue()==0)
        {
            QPalette palette;
            palette.setColor(QPalette::Background,Qt::green);
            this->setPalette(palette);
            //this->setStyleSheet("background-color:rgb(0,255,0)");
        }
        else if(c.red()==0&&c.green()==255&&c.blue()==0)
        {
            QPalette palette;
            palette.setColor(QPalette::Background,Qt::blue);
            this->setPalette(palette);
            //this->setStyleSheet("background-color:rgb(0,0,255)");
        }
        else if(c.red()==0&&c.green()==0&&c.blue()==255)
        {
            ui->pushButton_3->show();
            ui->pushButton_4->show();
            QPalette palette;
            QColor col;
            col.setRgb(1,1,1);
            palette.setColor(QPalette::Background,col);
            this->setPalette(palette);
        }
    }
}


