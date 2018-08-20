#include "inputnum.h"
#include "ui_inputnum.h"
#include <QDebug>
#include <QPalette>

InputNum::InputNum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputNum)
{
    ui->setupUi(this);
    this->setModal(true);
    QPalette pale;
    pale.setColor(QPalette::Background,Qt::black);
    this->setPalette(pale);
    ui->widget->setObjectName("mywidget");
    ui->widget->setStyleSheet("QWidget#mywidget{background-color:black; border: 4px solid #A8A8A8}");
    ui->label->setStyleSheet("QLabel{color:white;font: 18pt Noto Sans;}");
    ui->label_2->setStyleSheet("QLabel{color:white;font: 18pt Noto Sans;}");
    ui->label_3->setStyleSheet("QLabel{color:white;font: 18pt Noto Sans;}");
    ui->spinBox->installEventFilter(this);
    ui->spinBox_2->installEventFilter(this);
    ui->spinBox_3->installEventFilter(this);
    ui->spinBox_4->installEventFilter(this);
    ui->spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox->setAlignment(Qt::AlignCenter);
    ui->spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_2->setAlignment(Qt::AlignCenter);
    ui->spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_3->setAlignment(Qt::AlignCenter);
    ui->spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_4->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_3->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_4->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_5->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_6->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_7->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_8->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_9->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_10->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_11->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_12->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_13->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_14->setFocusPolicy(Qt::NoFocus);
    ui->spinBox->setFocus();
}

InputNum::~InputNum()
{
    delete ui;
}

void InputNum::on_pushButton_3_clicked()//1
{
    if(ui->spinBox->hasFocus())
    {
        if(ui->spinBox->value() >25&&ui->spinBox->value() < 256)
        {
            ui->spinBox_2->setFocus();
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+1);
        }
        else
        {
            ui->spinBox->setValue(ui->spinBox->value()*10+1);
        }

    }
    else if(ui->spinBox_2->hasFocus())
    {
        if(ui->spinBox_2->value() >25&&ui->spinBox_2->value() < 256)
        {
            ui->spinBox_3->setFocus();
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+1);
        }
        else
        {
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+1);
        }

    }
    else if(ui->spinBox_3->hasFocus())
    {
        if(ui->spinBox_3->value() >25&&ui->spinBox_3->value() < 256)
        {
            ui->spinBox_4->setFocus();
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+1);
        }
        else
        {
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+1);
        }

    }
    else if(ui->spinBox_4->hasFocus())
    {
        if(ui->spinBox_4->value() >25&&ui->spinBox_4->value() <256)
        {
            return;
        }
        else
        {
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+1);
        }
    }

}

void InputNum::on_pushButton_4_clicked()//2
{
    if(ui->spinBox->hasFocus())
    {
        if(ui->spinBox->value() >25&&ui->spinBox->value() < 256)
        {
            ui->spinBox_2->setFocus();
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+2);
        }
        else
        {
            ui->spinBox->setValue(ui->spinBox->value()*10+2);
        }

    }
    else if(ui->spinBox_2->hasFocus())
    {
        if(ui->spinBox_2->value() >25&&ui->spinBox_2->value() < 256)
        {
            ui->spinBox_3->setFocus();
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+2);
        }
        else
        {
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+2);
        }

    }
    else if(ui->spinBox_3->hasFocus())
    {
        if(ui->spinBox_3->value() >25&&ui->spinBox_3->value() < 256)
        {
            ui->spinBox_4->setFocus();
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+2);
        }
        else
        {
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+2);
        }

    }
    else if(ui->spinBox_4->hasFocus())
    {
        if(ui->spinBox_4->value() >25&&ui->spinBox_4->value() <256)
        {
            return;
        }
        else
        {
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+2);
        }
    }

}

void InputNum::on_pushButton_5_clicked()//3
{
    if(ui->spinBox->hasFocus())
    {
        if(ui->spinBox->value() >25&&ui->spinBox->value() < 256)
        {
            ui->spinBox_2->setFocus();
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+3);
        }
        else
        {
            ui->spinBox->setValue(ui->spinBox->value()*10+3);
        }

    }
    else if(ui->spinBox_2->hasFocus())
    {
        if(ui->spinBox_2->value() >25&&ui->spinBox_2->value() < 256)
        {
            ui->spinBox_3->setFocus();
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+3);
        }
        else
        {
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+3);
        }

    }
    else if(ui->spinBox_3->hasFocus())
    {
        if(ui->spinBox_3->value() >25&&ui->spinBox_3->value() < 256)
        {
            ui->spinBox_4->setFocus();
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+3);
        }
        else
        {
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+3);
        }

    }
    else if(ui->spinBox_4->hasFocus())
    {
        if(ui->spinBox_4->value() >25&&ui->spinBox_4->value() <256)
        {
            return;
        }
        else
        {
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+3);
        }
    }


}

void InputNum::on_pushButton_9_clicked()//4
{
    if(ui->spinBox->hasFocus())
    {
        if(ui->spinBox->value() >25&&ui->spinBox->value() < 256)
        {
            ui->spinBox_2->setFocus();
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+4);
        }
        else
        {
            ui->spinBox->setValue(ui->spinBox->value()*10+4);
        }

    }
    else if(ui->spinBox_2->hasFocus())
    {
        if(ui->spinBox_2->value() >25&&ui->spinBox_2->value() < 256)
        {
            ui->spinBox_3->setFocus();
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+4);
        }
        else
        {
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+4);
        }

    }
    else if(ui->spinBox_3->hasFocus())
    {
        if(ui->spinBox_3->value() >25&&ui->spinBox_3->value() < 256)
        {
            ui->spinBox_4->setFocus();
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+4);
        }
        else
        {
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+4);
        }

    }
    else if(ui->spinBox_4->hasFocus())
    {
        if(ui->spinBox_4->value() >25&&ui->spinBox_4->value() <256)
        {
            return;
        }
        else
        {
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+4);
        }
    }

}

void InputNum::on_pushButton_10_clicked()//5
{
    if(ui->spinBox->hasFocus())
    {
        if(ui->spinBox->value() >25&&ui->spinBox->value() < 256)
        {
            ui->spinBox_2->setFocus();
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+5);
        }
        else
        {
            ui->spinBox->setValue(ui->spinBox->value()*10+5);
        }

    }
    else if(ui->spinBox_2->hasFocus())
    {
        if(ui->spinBox_2->value() >25&&ui->spinBox_2->value() < 256)
        {
            ui->spinBox_3->setFocus();
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+5);
        }
        else
        {
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+5);
        }

    }
    else if(ui->spinBox_3->hasFocus())
    {
        if(ui->spinBox_3->value() >25&&ui->spinBox_3->value() < 256)
        {
            ui->spinBox_4->setFocus();
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+5);
        }
        else
        {
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+5);
        }

    }
    else if(ui->spinBox_4->hasFocus())
    {
        if(ui->spinBox_4->value() >25&&ui->spinBox_4->value() <256)
        {
            return;
        }
        else
        {
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+5);
        }
    }

}

void InputNum::on_pushButton_11_clicked()//6
{
    if(ui->spinBox->hasFocus())
    {
        if(ui->spinBox->value() >25&&ui->spinBox->value() < 256)
        {
            ui->spinBox_2->setFocus();
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+6);
        }
        else
        {
            ui->spinBox->setValue(ui->spinBox->value()*10+6);
        }

    }
    else if(ui->spinBox_2->hasFocus())
    {
        if(ui->spinBox_2->value() >25&&ui->spinBox_2->value() < 256)
        {
            ui->spinBox_3->setFocus();
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+6);
        }
        else
        {
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+6);
        }

    }
    else if(ui->spinBox_3->hasFocus())
    {
        if(ui->spinBox_3->value() >25&&ui->spinBox_3->value() < 256)
        {
            ui->spinBox_4->setFocus();
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+6);
        }
        else
        {
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+6);
        }

    }
    else if(ui->spinBox_4->hasFocus())
    {
        if(ui->spinBox_4->value() >25&&ui->spinBox_4->value() <256)
        {
            return;
        }
        else
        {
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+6);
        }
    }

}

void InputNum::on_pushButton_6_clicked()//7
{
    if(ui->spinBox->hasFocus())
    {
        if(ui->spinBox->value() >25&&ui->spinBox->value() < 256)
        {
            ui->spinBox_2->setFocus();
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+7);
        }
        else
        {
            ui->spinBox->setValue(ui->spinBox->value()*10+7);
        }

    }
    else if(ui->spinBox_2->hasFocus())
    {
        if(ui->spinBox_2->value() >25&&ui->spinBox_2->value() < 256)
        {
            ui->spinBox_3->setFocus();
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+7);
        }
        else
        {
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+7);
        }

    }
    else if(ui->spinBox_3->hasFocus())
    {
        if(ui->spinBox_3->value() >25&&ui->spinBox_3->value() < 256)
        {
            ui->spinBox_4->setFocus();
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+7);
        }
        else
        {
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+7);
        }

    }
    else if(ui->spinBox_4->hasFocus())
    {
        if(ui->spinBox_4->value() >25&&ui->spinBox_4->value() <256)
        {
            return;
        }
        else
        {
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+7);
        }
    }

}

void InputNum::on_pushButton_7_clicked()//8
{
    if(ui->spinBox->hasFocus())
    {
        if(ui->spinBox->value() >25&&ui->spinBox->value() < 256)
        {
            ui->spinBox_2->setFocus();
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+8);
        }
        else
        {
            ui->spinBox->setValue(ui->spinBox->value()*10+8);
        }

    }
    else if(ui->spinBox_2->hasFocus())
    {
        if(ui->spinBox_2->value() >25&&ui->spinBox_2->value() < 256)
        {
            ui->spinBox_3->setFocus();
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+8);
        }
        else
        {
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+8);
        }

    }
    else if(ui->spinBox_3->hasFocus())
    {
        if(ui->spinBox_3->value() >25&&ui->spinBox_3->value() < 256)
        {
            ui->spinBox_4->setFocus();
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+8);
        }
        else
        {
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+8);
        }

    }
    else if(ui->spinBox_4->hasFocus())
    {
        if(ui->spinBox_4->value() >25&&ui->spinBox_4->value() <256)
        {
            return;
        }
        else
        {
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+8);
        }
    }

}

void InputNum::on_pushButton_8_clicked()//9
{
    if(ui->spinBox->hasFocus())
    {
        if(ui->spinBox->value() >25&&ui->spinBox->value() < 256)
        {
            ui->spinBox_2->setFocus();
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+9);
        }
        else
        {
            ui->spinBox->setValue(ui->spinBox->value()*10+9);
        }

    }
    else if(ui->spinBox_2->hasFocus())
    {
        if(ui->spinBox_2->value() >25&&ui->spinBox_2->value() < 256)
        {
            ui->spinBox_3->setFocus();
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+9);
        }
        else
        {
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+9);
        }

    }
    else if(ui->spinBox_3->hasFocus())
    {
        if(ui->spinBox_3->value() >25&&ui->spinBox_3->value() < 256)
        {
            ui->spinBox_4->setFocus();
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+9);
        }
        else
        {
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+9);
        }

    }
    else if(ui->spinBox_4->hasFocus())
    {
        if(ui->spinBox_4->value() >25&&ui->spinBox_4->value() <256)
        {
            return;
        }
        else
        {
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+9);
        }
    }

}

void InputNum::on_pushButton_12_clicked()//0
{
    if(ui->spinBox->hasFocus())
    {
        if(ui->spinBox->value() >25&&ui->spinBox->value() < 256)
        {
            ui->spinBox_2->setFocus();
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+0);
        }
        else
        {
            ui->spinBox->setValue(ui->spinBox->value()*10+0);
        }

    }
    else if(ui->spinBox_2->hasFocus())
    {
        if(ui->spinBox_2->value() >25&&ui->spinBox_2->value() < 256)
        {
            ui->spinBox_3->setFocus();
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+0);
        }
        else
        {
            ui->spinBox_2->setValue(ui->spinBox_2->value()*10+0);
        }

    }
    else if(ui->spinBox_3->hasFocus())
    {
        if(ui->spinBox_3->value() >25&&ui->spinBox_3->value() < 256)
        {
            ui->spinBox_4->setFocus();
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+0);
        }
        else
        {
            ui->spinBox_3->setValue(ui->spinBox_3->value()*10+0);
        }

    }
    else if(ui->spinBox_4->hasFocus())
    {
        if(ui->spinBox_4->value() >25&&ui->spinBox_4->value() <256)
        {
            return;
        }
        else
        {
            ui->spinBox_4->setValue(ui->spinBox_4->value()*10+0);
        }
    }

}

void InputNum::on_pushButton_clicked()//OK
{
    IPAddress = ui->spinBox->text()+"."+ui->spinBox_2->text()+"."+ui->spinBox_3->text()+"."+ui->spinBox_4->text();
    qDebug()<<IPAddress;
    emit sendData(IPAddress);
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->spinBox_4->setValue(0);
    ui->spinBox->setFocus();
    this->close();
}

void InputNum::on_pushButton_2_clicked()//del
{
    if(ui->spinBox->hasFocus())
    {
        ui->spinBox->setValue(0);
    }
    else if(ui->spinBox_2->hasFocus())
    {
        ui->spinBox_2->setValue(0);
        if(ui->spinBox_2->value() == 0)
        {
            ui->spinBox->setFocus();
        }
    }
    else if(ui->spinBox_3->hasFocus())
    {
        ui->spinBox_3->setValue(0);
        if(ui->spinBox_3->value() == 0)
        {
            ui->spinBox_2->setFocus();
        }
    }
    else if(ui->spinBox_4->hasFocus())
    {
        ui->spinBox_4->setValue(0);
        if(ui->spinBox_4->value() == 0)
        {
            ui->spinBox_3->setFocus();
        }
    }
}

void InputNum::on_pushButton_14_clicked()//Quit
{
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->spinBox_4->setValue(0);
    this->close();
}

bool InputNum::eventFilter(QObject *object,QEvent *event)
{
    if(object == ui->spinBox)
    {
        if(event->type() == QEvent::FocusIn)
        {
            ui->spinBox->selectAll();
            return true;
        }
        else if(event->type() == QEvent::KeyRelease)
        {
            if(ui->spinBox->value()>25 && ui->spinBox->value()<256)
            {
                ui->spinBox_2->setFocus();
            }
        }
    }
    else if(object == ui->spinBox_2)
    {
        if(event->type() == QEvent::FocusIn)
        {
            ui->spinBox_2->selectAll();
            return true;
        }
        else if(event->type() == QEvent::KeyRelease)
        {
            if(ui->spinBox_2->value()>25 && ui->spinBox_2->value()<256)
            {
                ui->spinBox_3->setFocus();
            }
        }
    }
    else if(object == ui->spinBox_3)
    {
        if(event->type() == QEvent::FocusIn)
        {
            ui->spinBox_3->selectAll();
            return true;
        }
        else if(event->type() == QEvent::KeyRelease)
        {
            if(ui->spinBox_3->value()>25 && ui->spinBox_3->value()<256)
            {
                ui->spinBox_4->setFocus();
            }
        }
    }
    else if(object == ui->spinBox_4)
    {
        if(event->type() == QEvent::FocusIn)
        {
            ui->spinBox_4->selectAll();
            return true;
        }
        else if(event->type() == QEvent::KeyRelease)
        {
            if(ui->spinBox_4->value()>25 && ui->spinBox_4->value()<256)
            {
                return true;
            }
        }
    }
    return false;
}

void InputNum::on_pushButton_13_clicked()//tab
{
    if(ui->spinBox->hasFocus())
    {
        ui->spinBox_2->setFocus();
    }
    else if(ui->spinBox_2->hasFocus())
    {
        ui->spinBox_3->setFocus();
    }
    else if(ui->spinBox_3->hasFocus())
    {
        ui->spinBox_4->setFocus();
    }
}

