#include "wlanman.h"
#include <stdio.h>


WlanMan::WlanMan(QWidget *parent)
    : QSystemTrayIcon(parent)
{

    //starting icons
    icons[100]=QIcon(":/images/wifi100.png");
    icons[70]= QIcon(":/images/wifi70.png");
    icons[50]= QIcon(":/images/wifi50.png");
    icons[30]= QIcon(":/images/wifi30.png");
    icons[15]= QIcon(":/images/wifi15.png");
    icons[0] = QIcon(":/images/wifi0.png");
    icon = -1;
    UpdateStatus();
    setVisible(true);
    timeout.setInterval(2000);
    timeout.setSingleShot(false);
    timeout.connect(&timeout,SIGNAL(timeout()),this,SLOT(UpdateStatus()));
    timeout.start();




}
int WlanMan::getIconQuality(int quality){
    int ret;
    if (quality > 70) ret = 100;
    else if (quality > 50) ret = 70;
    else if (quality > 30) ret = 50;
    else if (quality > 15) ret = 30;
    else if (quality > 0)  ret = 15;
    else  ret = 0;
    return ret;
}

int WlanMan::getQuality(){
    QFile f("/proc/net/wireless");
    f.open(QFile::ReadOnly);

    QString a;

    f.readLine();


    f.readLine();

    a = QString(f.readLine());

    f.close();

    return a.split(" ",QString::SkipEmptyParts)[2].toInt();


}

void WlanMan::UpdateStatus(){
    int quality;
    int micon;
    quality = getQuality();

    QString();

    this->setToolTip(QString::number(quality) + "%");
    printf("quality: %d, icon %d\n",quality,getIconQuality(quality));
    if ((micon = getIconQuality(quality)) != icon)
        this->setIcon(icons[micon]);


}

WlanMan::~WlanMan()
{

}
