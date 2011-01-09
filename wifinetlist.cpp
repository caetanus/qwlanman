#include "wifinetlist.h"
#include <QtGui>

WifiNetList::WifiNetList(QObject *parent) :
    QObject(parent)
{
}
void WifiNetList::list(QMap<QString,Cell> netlist)
{
    QString out, line, essid, protocol,cell;
    int quality;
    int match, init;
    bool encryption, wpa=false, state = false;
    QProcess a;
    a.execute("iwlist scanning");
    a.readAllStandardError();
    while (!a.atEnd()){
        line = (QString)a.readLine();
        //state machine for parsing networks
        if (line.contains(QRegExp("Cell \\d+"))){

            //@TODO implements mutexes for threading
            if (state){
                netlist[essid].setEssid(essid);
                netlist[essid].setCell(cell);
                netlist[essid].setEncryption(encryption);
                netlist[essid].setWpa(wpa);
                netlist[essid].setQuality(quality);


            }
            for (match = 0; line[match]!= ':'; match++);
            match++;
            init = match;
            match = line.length();
            cell = line.mid(init,match);

        }

        else if(line.contains("ESSID")){
            //expects ESSID now
            init = 0;
            for (match = 0; line[match]!= '"'; match++);
            init = match;
            for (; line[match]!= '"'; match++);
            essid = line.mid(init,match-init);
            continue;
        }
        //else if (line.contains())

    }
    out = (QString)a.readAll();
    qDebug() << out;


}
