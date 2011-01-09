#include <QtGui/QApplication>
#include "wlanman.h"
#include "wifinetlist.h"
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WlanMan w;
    w.show();
    //WifiNetList();

    return a.exec();
}
