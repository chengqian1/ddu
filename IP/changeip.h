#ifndef CHANGEIP_H
#define CHANGEIP_H

#include <QDialog>
#include "inputnum.h"

namespace Ui {
class ChangeIP;
}

class ChangeIP : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeIP(QWidget *parent = 0);
    ~ChangeIP();

private slots:
    void paintEvent(QPaintEvent *e);
    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();
    void receivedata(QString data);


    void on_lineEdit_selectionChanged();

    void on_lineEdit_2_selectionChanged();

    void getMsg(QString);
    void on_pushButton_clicked();

signals:
    void sendinterfacedata(QString data);

private:
    Ui::ChangeIP *ui;
    InputNum *ipn1;
    int flag;
    int flag1;
    int flag2;
};

#endif // CHANGEIP_H
