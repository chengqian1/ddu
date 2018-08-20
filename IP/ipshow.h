#ifndef IPSHOW_H
#define IPSHOW_H

#include <QDialog>
#include "changeip.h"

namespace Ui {
class IPShow;
}

class IPShow : public QDialog
{
    Q_OBJECT

public:
    explicit IPShow(QWidget *parent = 0);
    ~IPShow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void getinterfacesdata(QString data);

signals:
    void send(QString);

private:
    Ui::IPShow *ui;
    int flag;
    ChangeIP *ch1;
    QString eth0status,eth1status;
    QString inface,status,ipAddress,netMask;
    QString ip,mask;
};

#endif // IPSHOW_H
