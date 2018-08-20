#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include <QDialog>
#include <QSettings>
#include <QTimer>

namespace Ui {
class Brightness;
}

class Brightness : public QDialog
{
    Q_OBJECT

public:
    explicit Brightness(QWidget *parent = 0);
    ~Brightness();

private slots:
    void seachFile();
    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_clicked();

    void autobrighrness();
private:
    Ui::Brightness *ui;
    QSettings *m_pSetting;
    int m_theBrightness;
    QTimer *timer;
};

#endif // BRIGHTNESS_H
