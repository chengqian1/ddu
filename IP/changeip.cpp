#include "changeip.h"
#include "ui_changeip.h"
#include <QPainter>
#include <QDebug>
#include <QPalette>
#include <QStyleOption>

ChangeIP::ChangeIP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeIP)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->pushButton->setStyleSheet("font: 15pt Noto Sans");
    ui->pushButton_2->setStyleSheet("font: 15pt Noto Sans");
    QPalette pa;
    pa.setColor(QPalette::Background,Qt::black);
    this->setPalette(pa);
    ui->widget->setObjectName("mywidget");
    ui->widget->setStyleSheet("QWidget#mywidget{background-color:black; border: 4px solid #A8A8A8}");
    ui->radioButton->setStyleSheet("QRadioButton{background-color:white; color: black;   border-radius: 10px;font: 15pt Noto Sans;border: 2px groove gray;border-style: outset;}");
    ui->radioButton_2->setStyleSheet("QRadioButton{background-color:white; color: black;   border-radius: 10px;font: 15pt Noto Sans;border: 2px groove gray;border-style: outset;}");

    ipn1 = new InputNum(this);
    ui->label_3->setStyleSheet("color:white;border:none;font: 15pt Noto Sans");
    connect(ipn1,SIGNAL(sendData(QString)),this,SLOT(receivedata(QString)));
    connect(parent,SIGNAL(send(QString)),this,SLOT(getMsg(QString)));
}

ChangeIP::~ChangeIP()
{
    delete ui;
}

void ChangeIP::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(QColor(241,236,245));
    painter.drawLine(20,160,40,160);//20,160-40,160
    painter.drawLine(240,160,450,160);//240,160-450,160;
    painter.drawLine(20,160,20,350);//20,160-20,350
    painter.drawLine(20,350,450,350);//20,350-450,350
    painter.drawLine(450,160,450,350);//450,160-450,350
}

void ChangeIP::receivedata(QString data)
{
    if(flag == 0)
    {
        ui->lineEdit->setText(data);
    }
    else if(flag == 1)
    {
        ui->lineEdit_2->setText(data);
    }
}

void ChangeIP::getMsg(QString data)
{
    QStringList list = data.split("/");
    qDebug()<<list.at(0);
    qDebug()<<list.at(1);
    if(list.at(0) == "eth0")
    {
        flag1 = 0;
        if(list.at(1) == "dhcp")
        {
            flag2 = 0;
            ui->label_3->setText("eth0 is dhcp");
            ui->radioButton->setChecked(true);
            //QPalette pa;
            //pa.setColor(QPalette::Background,Qt::gray);
            //ui->label->setPalette(pa);
            //ui->label_2->setPalette(pa);
            ui->label->setStyleSheet("QLabel{color: gray;font: 15pt Noto Sans;}");
            ui->label_2->setStyleSheet("QLabel{color: gray;font: 15pt Noto Sans;}");
            ui->lineEdit->setStyleSheet("background-color:gray;font: 15pt Noto Sans");
            ui->lineEdit_2->setStyleSheet("background-color:gray;font: 15pt Noto Sans");
            ui->lineEdit->setReadOnly(true);
            ui->lineEdit_2->setReadOnly(true);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
        }
        else if(list.at(1) == "static")
        {
            flag2 = 1;
            ui->label_3->setText("eth0 is static");
            ui->radioButton_2->setChecked(true);
            //QPalette pa;
            //pa.setColor(QPalette::Background,Qt::white);
            // ui->label->setPalette(pa);
            //ui->label_2->setPalette(pa);
            ui->label->setStyleSheet("QLabel{color: White;font: 15pt Noto Sans;}");
            ui->label_2->setStyleSheet("QLabel{color: White;font: 15pt Noto Sans;}");
            ui->lineEdit->setStyleSheet("background-color:white;font: 15pt Noto Sans");
            ui->lineEdit_2->setStyleSheet("background-color:white;font: 15pt Noto Sans");
            ui->lineEdit->setReadOnly(false);
            ui->lineEdit->setText(list.at(2));
            ui->lineEdit_2->setReadOnly(false);
            ui->lineEdit_2->setText(list.at(3));
        }
    }
    else if(list.at(0) == "eth1")
    {
        flag1 = 1;
        if(list.at(1) == "dhcp")
        {
            flag2 = 0;
            ui->label_3->setText("eth1 is dhcp");
            ui->radioButton->setChecked(true);
            ui->label->setStyleSheet("QLabel{color: gray;font: 15pt Noto Sans;}");
            ui->label_2->setStyleSheet("QLabel{color: gray;font: 15pt Noto Sans;}");
            ui->lineEdit->setStyleSheet("background-color:gray;font: 15pt Noto Sans");
            ui->lineEdit_2->setStyleSheet("background-color:gray;font: 15pt Noto Sans");
            ui->lineEdit->setReadOnly(true);
            ui->lineEdit_2->setReadOnly(true);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
        }
        else if(list.at(1) == "static")
        {
            flag2 = 1;
            ui->label_3->setText("eth1 is static");
            ui->radioButton_2->setChecked(true);
            ui->label->setStyleSheet("QLabel{color: white;font: 15pt Noto Sans;}");
            ui->label_2->setStyleSheet("QLabel{color: white;font: 15pt Noto Sans;}");
            ui->lineEdit->setStyleSheet("background-color:white;font: 15pt Noto Sans");
            ui->lineEdit_2->setStyleSheet("background-color:white;font: 15pt Noto Sans");
            ui->lineEdit->setReadOnly(false);
            ui->lineEdit->setText(list.at(2));
            ui->lineEdit_2->setReadOnly(false);
            ui->lineEdit_2->setText(list.at(3));

        }
    }

}

void ChangeIP::on_pushButton_2_clicked()//cancel
{
    this->close();
}

void ChangeIP::on_radioButton_clicked()//dhcp is checked
{
    flag2 = 0;
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->label->setStyleSheet("QLabel{color: gray;font: 15pt Noto Sans;}");
    ui->label_2->setStyleSheet("QLabel{color: gray;font: 15pt Noto Sans;}");
    ui->lineEdit->setStyleSheet("background-color:gray;font: 15pt Noto Sans");
    ui->lineEdit_2->setStyleSheet("background-color:gray;font: 15pt Noto Sans");
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
}

void ChangeIP::on_radioButton_2_clicked()//static is checked
{
    flag2 = 1;
    ui->label->setStyleSheet("QLabel{color: white;font: 15pt Noto Sans;}");
    ui->label_2->setStyleSheet("QLabel{color: white;font: 15pt Noto Sans;}");
    ui->lineEdit->setStyleSheet("background-color:white;font: 15pt Noto Sans");
    ui->lineEdit_2->setStyleSheet("background-color:white;font: 15pt Noto Sans");
    ui->lineEdit->setReadOnly(false);
    ui->lineEdit_2->setReadOnly(false);
}

void ChangeIP::on_lineEdit_selectionChanged()
{
    if(flag2 == 1)
    {
        flag = 0;
        ipn1->show();
    }
}

void ChangeIP::on_lineEdit_2_selectionChanged()
{
    if(flag2 == 1)
    {
        flag = 1;
        ipn1->show();
    }

}

void ChangeIP::on_pushButton_clicked()//sure
{
    if(ui->radioButton->isChecked()==true)//dhcp
    {
        qDebug()<<"radio";
        if(flag1 == 0)//eth0 dhcp
        {
            QString data1 = "eth0";
            QString data2 = "dhcp";
            QString data = data1+"/"+data2;
            emit sendinterfacedata(data);
        }
        else if(flag1 == 1)//eth1 dhcp
        {
            QString data1 = "eth1";
            QString data2 = "dhcp";
            QString data = data1+"/"+data2;
            emit sendinterfacedata(data);
        }
    }
    else if(ui->radioButton_2->isChecked()==true)//static
    {
        qDebug()<<"radio2";
        if(flag1 == 0)//eth0 static
        {
            QString data1 = "eth0";
            QString data2 = "static";
            QString data3 = ui->lineEdit->text();
            QString data4 = ui->lineEdit_2->text();
            QString data = data1+"/"+data2+"/"+data3+"/"+data4;
            emit sendinterfacedata(data);
        }
        else if(flag1 == 1)//eth1 static
        {
            QString data1 = "eth1";
            QString data2 = "static";
            QString data3 = ui->lineEdit->text();
            QString data4 = ui->lineEdit_2->text();
            QString data = data1+"/"+data2+"/"+data3+"/"+data4;
            emit sendinterfacedata(data);
        }
    }
    this->close();
}
