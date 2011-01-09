#ifndef CELL_H
#define CELL_H

#include <QObject>
#include "wifinetlist.h"

class Cell : public QObject
{
    friend class WifiNetList;
    Q_OBJECT

private:
    QString cell;
    QString essid;
    QBool crypt;
    QBool wpa;
    QString protocol;
    int timeout;


public:
    explicit Cell(QObject *parent = 0);


signals:

public slots:

};

#endif // CELL_H
