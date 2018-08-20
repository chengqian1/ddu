#include "brightness.h"
#include "ui_brightness.h"
#include "disphw32.h"
#include "windefs.h"
#include <QDebug>
#include <QPalette>
#include <QCheckBox>

Brightness::Brightness(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Brightness)
{
    ui->setupUi(this);
    this->setModal(true);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(autobrighrness()));
    timer->start(1000);
    QPalette pale;
    pale.setColor(QPalette::Background,Qt::black);
    //pale1.setColor(QPalette::WindowText,Qt::white);
    ui->label->setStyleSheet("color:white;font: 15pt Noto Sans");
    ui->checkBox->setStyleSheet("QCheckBox{background-color:white; color:black; font: 15pt Noto Sans;border-radius: 10px; border: 2px groove gray;border-style: outset; }");

    //ui->checkBox->setStyleSheet("QCheckBox{color:rgb(255,255,255);font:15pt Noto Sans};");
    this->setPalette(pale);
    ui->horizontalSlider->setMaximum(250);
    ui->horizontalSlider->setMinimum(0);
    this->seachFile();
}

Brightness::~Brightness()
{
    delete ui;
}

void Brightness::seachFile()
{
    m_pSetting = new QSettings("tod.conf", QSettings::IniFormat, this);
    m_pSetting->beginGroup("Communication");
    m_theBrightness = m_pSetting->value("Brightness",150).toInt();
    qDebug() << m_theBrightness;
    m_pSetting->endGroup();
    ui->horizontalSlider->setValue(m_theBrightness);
    ENV_setBrightnessRelative(ENV_DISPLAY,m_theBrightness);

}

void Brightness::on_horizontalSlider_valueChanged(int value)
{
    ENV_activateAutomaticBrightness(FALSE,0);
    m_pSetting->setValue("Brightness",value);
    ENV_setBrightnessRelative(ENV_DISPLAY,value);
    //unsigned char *m_address = new unsigned char();
    //ENV_getAddress(m_address);
    //qDebug() << "address= " << *m_address;
}

void Brightness::on_pushButton_clicked()
{
    this->close();
}

void Brightness::on_pushButton_4_clicked()
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value()-25);
}

void Brightness::on_pushButton_3_clicked()
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value()+25);
}

void Brightness::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()==true)
    {
        ENV_activateAutomaticBrightness(TRUE,0);
        int value;
        ENV_getBrightnessRelative(ENV_DISPLAY,&value);
        qDebug()<<"auto brightness:"<<value;
        ui->horizontalSlider->setValue(value);
    }
    else if(ui->checkBox->isChecked()==false)
    {
        ENV_activateAutomaticBrightness(FALSE,0);
        ui->horizontalSlider->setValue(150);
    }
}

void Brightness::autobrighrness()
{
    if(ui->checkBox->isChecked()==true)
    {
        ENV_activateAutomaticBrightness(TRUE,0);
        int value;
        ENV_getBrightnessRelative(ENV_DISPLAY,&value);
        qDebug()<<"auto brightness:"<<value;
        ui->horizontalSlider->setValue(value);
    }
}
