#include "beeper.h"
#include "ui_beeper.h"


#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QPalette>


Beeper::Beeper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Beeper),
    m_pBeeperStopTimer(new QTimer(this))
{
    ui->setupUi(this);
    this->setModal(true);
    ui->pushButton->setStyleSheet("font: 15pt Noto Sans;");
    ui->pushButton_2->setStyleSheet("font: 15pt Noto Sans;");
    ui->pushButton_5->setStyleSheet("font: 15pt Noto Sans;");
    ui->pushButton_6->setStyleSheet("font: 15pt Noto Sans;");
    QPalette pale;
    pale.setColor(QPalette::Background,Qt::black);
    this->setPalette(pale);
    beeper_init();
    m_pBeeperStopTimer->setInterval(250);
    connect(m_pBeeperStopTimer,SIGNAL(timeout()),this,SLOT(slotStopBeeper()));
}

Beeper::~Beeper()
{
    delete ui;
    ENV_setBeeper(0,&beeper);
}

void Beeper::beeper_init()
{
    ENV_init();
    ENV_activateBeeper(0,true);
    beeper.bKeyStops = false;
    beeper.dwDuration = 0xFFFFFFFF;
    beeper.dwNum = 1;
    beeper.stSound[0].dwTime = 1000;

    beeperoff.dwDuration = 0;
    beeperoff.dwNum = 0;
}

void Beeper::slotStopBeeper()
{
    ENV_setBeeper(0, &beeperoff);
    m_pBeeperStopTimer->stop();
}

void Beeper::on_pushButton_clicked()//OK
{
    this->close();
    ENV_setBeeper(0, &beeperoff);
}

void Beeper::on_pushButton_2_clicked()//cancel
{
    this->close();
    ENV_setBeeper(0, &beeperoff);
}

void Beeper::on_pushButton_3_clicked()//singal
{
    ENV_setBeeper(0, &beeper);
    m_pBeeperStopTimer->start();
}

void Beeper::on_pushButton_4_clicked()//cyclic
{
    ENV_setBeeper(0,&beeper);
}
