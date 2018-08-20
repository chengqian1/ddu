#include "IP/ipshow.h"
#include "ui_ipshow.h"
#include <QPainter>
#include <QColor>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QSettings>
#include <QNetworkInterface>
#include <QList>
#include <QPalette>

IPShow::IPShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IPShow)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->label->setStyleSheet("color:white;font: 15pt Noto Sans;");
    ui->label_2->setStyleSheet("color:white;font: 15pt Noto Sans;");
    ui->label_3->setStyleSheet("QLabel{background-color:white; color: black;border-radius: 10px;  border: 2px groove gray;border-style: outset;font: 15pt Noto Sans;}");
    ui->pushButton->setStyleSheet("font: 15pt Noto Sans");
    ui->pushButton_2->setStyleSheet("font: 15pt Noto Sans");
    ui->pushButton_3->setStyleSheet("font: 15pt Noto Sans");
    ui->pushButton_4->setStyleSheet("font: 15pt Noto Sans");
    ui->pushButton_5->setStyleSheet("font: 15pt Noto Sans");
    QPalette pale;
    pale.setColor(QPalette::Background,Qt::black);
    this->setPalette(pale);
    ui->widget->setObjectName("mywidget");
    ui->widget->setStyleSheet("QWidget#mywidget{background-color:black; border: 4px solid #A8A8A8}");
    ch1 = new ChangeIP(this);
    flag = -1;
    connect(ch1,SIGNAL(sendinterfacedata(QString)),this,SLOT(getinterfacesdata(QString)));
}

IPShow::~IPShow()
{
    delete ui;
}

void IPShow::on_pushButton_clicked()//eth0
{
    flag = 0;
    ui->label_3->clear();
    ui->pushButton->setStyleSheet("background-color:rgb(14,172,243);font: 15pt Noto Sans");
    ui->pushButton_2->setStyleSheet(0);
    ui->pushButton_2->setStyleSheet("font: 15pt Noto Sans");
    QFile file("/etc/network/interfaces");//etc/network/interfaces

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;
    QString str, data;
    QTextStream in(&file);
    QString strAll;
    strAll = in.readAll();
    QStringList strlist;
    strlist = strAll.split("\n");
    for(int i = 0;i < strlist.count();i++)
    {
        if(strlist.at(i) == "iface eth0 inet static")
        {
            qDebug()<<"eth0 is static";
            str = "eth0 is static";
            QString maskread = strlist.at(i+2);
            QString ipread = strlist.at(i+1);
            ip = ipread.mid(15);
            mask = maskread.mid(15);

            data = str + "\n" + "IP:" + ip +"\n"+"Netmask:"+mask;
            ui->label_3->setText(data);
            eth0status = "static";
        }
        else if(strlist.at(i) == "iface eth0 inet dhcp")
        {
            qDebug()<<"eth0 is dhcp";
            str = "eth0 is dhcp";
            data = str;
            ui->label_3->setText(data);
            eth0status = "dhcp";
            qDebug()<< " eth0status " << eth0status;
        }
    }
    file.close();
}

void IPShow::on_pushButton_2_clicked()//eth1
{
    flag = 1;
    ui->label_3->clear();
    ui->pushButton_2->setStyleSheet("background-color:rgb(14,172,243);font: 15pt Noto Sans");
    ui->pushButton->setStyleSheet(0);
    ui->pushButton->setStyleSheet("font: 15pt Noto Sans");

    QFile file("/etc/network/interfaces");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;
    QString str,data;
    QTextStream in(&file);
    QString strAll;
    strAll = in.readAll();
    QStringList strlist;
    strlist = strAll.split("\n");
    for(int i = 0;i < strlist.count();i++)
    {
        if(strlist.at(i) == "iface eth1 inet static")
        {
            qDebug()<<"eth1 is static";
            str = "eth1 is static";
            QString maskread = strlist.at(i+2);
            QString ipread = strlist.at(i+1);
            ip = ipread.mid(15);
            mask = maskread.mid(15);

            data = str + "\n" + "IP:" + ip +"\n"+"Netmask:"+mask;
            ui->label_3->setText(data);
            eth1status = "static";
        }
        else if(strlist.at(i) == "iface eth1 inet dhcp")
        {
            qDebug()<<"eth1 is dhcp";
            str = "eth1 is dhcp";
            data = str;
            ui->label_3->setText(data);
            eth1status = "dhcp";
        }
    }
    file.close();
}

void IPShow::on_pushButton_4_clicked()//cancel
{
    this->close();
    ui->label_3->clear();
    ui->pushButton->setStyleSheet(0);
    ui->pushButton_2->setStyleSheet(0);
    ui->pushButton->setStyleSheet("font: 15pt Noto Sans");
    ui->pushButton_2->setStyleSheet("font: 15pt Noto Sans");
    flag = -1;
}

void IPShow::on_pushButton_3_clicked()//enter changeip interface
{
    if(flag == 0)
    {
        if(eth0status == "static")
        {
            QString str =  "eth0";
            QString data = str + "/" +eth0status + "/"+ip+"/"+mask;
            emit send(data);
            ch1->show();
        }
        else if(eth0status == "dhcp")
        {
            QString str =  "eth0";
            QString data = str + "/" +eth0status;
            emit send(data);
            ch1->show();
        }
    }
    else if(flag == 1)
    {
        if(eth1status == "static")
        {
            QString str =  "eth1";
            QString data = str + "/" +eth1status + "/"+ip+"/"+mask;
            emit send(data);
            ch1->show();
        }
        else if(eth1status == "dhcp")
        {
            QString str =  "eth1";
            QString data = str + "/" +eth1status;
            emit send(data);
            ch1->show();
        }
    }
    else
    {
        return;
    }
}

void IPShow::on_pushButton_5_clicked()//sure
{
    QString strAll;
    QStringList strlist;
    QFile readfile("/etc/network/interfaces");//etc/network/interfaces
    if (readfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&readfile);
        strAll = in.readAll();
    }
    readfile.close();

    if(inface == "eth0")
    {
        if(status == "dhcp")
        {
            QFile writefile("/etc/network/interfaces");
            if(writefile.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream out(&writefile);
                strlist = strAll.split("\n");
                for(int i = 0;i < strlist.count();i++)
                {
                    qDebug()<<strlist.at(i);
                    if(strlist.at(i) == "iface eth0 inet dhcp")
                    {
                        return;
                    }
                    else if(strlist.at(i) == "iface eth0 inet static")
                    {
                        strlist.replace(i,"iface eth0 inet dhcp");
                        strlist.removeAt(i+2);
                        strlist.removeAt(i+1);

                    }
                    if(i==strlist.count()-1)
                    {
                        out<<strlist.at(i);
                    }
                    else
                    {
                        out<<strlist.at(i)+"\n";
                    }

                }
            }
            writefile.close();
        }
        else if(status == "static")
        {
            QFile writefile("/etc/network/interfaces");
            if(writefile.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream out(&writefile);
                strlist = strAll.split("\n");
                for(int i = 0;i < strlist.count();i++)
                {
                    qDebug()<<strlist.at(i);
                    if(strlist.at(i) == "iface eth0 inet dhcp")
                    {
                        strlist.replace(i,"iface eth0 inet static");
                        strlist.insert(i+1,"       address "+ipAddress);
                        strlist.insert(i+2,"       netmask "+netMask);
                    }
                    else if(strlist.at(i) == "iface eth0 inet static")
                    {
                        strlist.replace(i+1,"       address "+ipAddress);
                        strlist.replace(i+2,"       netmask "+netMask);
                    }


                    if(i==strlist.count()-1)
                    {
                        out<<strlist.at(i);
                    }
                    else
                    {
                        out<<strlist.at(i)+"\n";
                    }

                }
            }
            writefile.close();
        }
    }
    else if(inface == "eth1")
    {
        if(status == "dhcp")
        {
            QFile writefile("/etc/network/interfaces");
            if(writefile.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream out(&writefile);
                strlist = strAll.split("\n");
                for(int i = 0;i < strlist.count();i++)
                {
                    qDebug()<<strlist.at(i);
                    if(strlist.at(i) == "iface eth1 inet dhcp")
                    {
                        return;
                    }
                    else if(strlist.at(i) == "iface eth1 inet static")
                    {
                        strlist.replace(i,"iface eth1 inet dhcp");
                        strlist.removeAt(i+2);
                        strlist.removeAt(i+1);

                    }
                    if(i==strlist.count()-1)
                    {
                        out<<strlist.at(i);
                    }
                    else
                    {
                        out<<strlist.at(i)+"\n";
                    }

                }
            }
            writefile.close();
        }
        else if(status == "static")
        {
            QFile writefile("/etc/network/interfaces");
            if(writefile.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream out(&writefile);
                strlist = strAll.split("\n");
                for(int i = 0;i < strlist.count();i++)
                {
                    qDebug()<<strlist.at(i);
                    if(strlist.at(i) == "iface eth1 inet dhcp")
                    {
                        strlist.replace(i,"iface eth1 inet static");
                        strlist.insert(i+1,"       address "+ipAddress);
                        strlist.insert(i+2,"       netmask "+netMask);

                    }
                    else if(strlist.at(i) == "iface eth1 inet static")
                    {
                        strlist.replace(i+1,"       address "+ipAddress);
                        strlist.replace(i+2,"       netmask "+netMask);
                    }


                    if(i==strlist.count()-1)
                    {
                        out<<strlist.at(i);
                    }
                    else
                    {
                        out<<strlist.at(i)+"\n";
                    }

                }
            }
            writefile.close();
        }
    }

    this->close();
    inface = "";
    status = "";
    ipAddress = "";
    netMask = "";
}

void IPShow::getinterfacesdata(QString data)
{
    inface = "";
    status = "";
    ipAddress = "";
    netMask = "";
    QStringList list = data.split("/");
    inface = list.at(0);
    status = list.at(1);
    if(list.at(1) == "static")
    {
        ipAddress = list.at(2);
        netMask = list.at(3);
    }

}

