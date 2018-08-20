#ifndef BADPOINT_H
#define BADPOINT_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class BadPoint;
}

class BadPoint : public QDialog
{
    Q_OBJECT

public:
    explicit BadPoint(QWidget *parent = 0);
    ~BadPoint();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void mousePressEvent(QMouseEvent *e);


private:
    Ui::BadPoint *ui;
};

#endif // BADPOINT_H
