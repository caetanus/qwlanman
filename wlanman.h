#ifndef WLANMAN_H
#define WLANMAN_H

#include <QtGui>

class WlanMan : public QSystemTrayIcon
{
    Q_OBJECT
public slots:
    void UpdateStatus(void);
private:
    int icon;
    int getIconQuality(int quality);
    int getQuality();
    QMap<int,QIcon> icons;

public:
    QTimer timeout;
    WlanMan(QWidget *parent = 0);



    ~WlanMan();
};

#endif // WLANMAN_H
