#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "IP/ipshow.h"
#include "IP/changeip.h"
#include "Beeper/beeper.h"
#include "Brightness/brightness.h"
#include "Badpoint/badpoint.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    IPShow *i1;
    Beeper *s;
    Brightness *bn;
    BadPoint *bp;

};

#endif // MAINWINDOW_H
