#ifndef BEEPER_H
#define BEEPER_H

#include <QDialog>
#include <QDialog>
#include "disphw32.h"
#include "windefs.h"
#include <QTimer>

namespace Ui {
class Beeper;
}

class Beeper : public QDialog
{
    Q_OBJECT

public:
    explicit Beeper(QWidget *parent = 0);
    ~Beeper();

private slots:
    void beeper_init();
    void slotStopBeeper();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Beeper *ui;
    QTimer *m_pBeeperStopTimer;
    ENV_BeeperState_t beeper;
    ENV_BeeperState_t beeperoff;
};

#endif // BEEPER_H
