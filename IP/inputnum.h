#ifndef INPUTNUM_H
#define INPUTNUM_H

#include <QDialog>

namespace Ui {
class InputNum;
}

class InputNum : public QDialog
{
    Q_OBJECT

public:
    explicit InputNum(QWidget *parent = 0);
    ~InputNum();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_clicked();
    bool eventFilter(QObject *object,QEvent *event);
    void on_pushButton_2_clicked();
    void on_pushButton_14_clicked();

signals:
    void sendData(QString);

private:
    Ui::InputNum *ui;
    QString IPAddress;
};

#endif // INPUTNUM_H
