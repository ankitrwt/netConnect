#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "wireless/iwlib.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    QString imgWiFiLevel1 = ":/new/prefix1/wifi_0.png";
    QString imgWiFiLevel2 = ":/new/prefix1/wifi_1.png";
    QString imgWiFiLevel3 = ":/new/prefix1/wifi_2.png";
    QString imgWiFiLevel4 = ":/new/prefix1/wifi_3.png";

private slots:
    void on_configurationCombo_currentIndexChanged(const QString &arg1);
    void on_connectPushButton_clicked();
    void on_connectWireless_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
