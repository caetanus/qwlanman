#ifndef WIFINETLIST_H
#define WIFINETLIST_H

#include <QObject>
#include <QProcess>
#include <QRegExp>
#include <QtGui>
#include "cell.h"
class WifiNetList : public QObject
{
    Q_OBJECT
    friend class Cell;


public:
    explicit WifiNetList(QObject *parent = 0);
    void list(QMap<QString,Cell> nets);

signals:

public slots:

};

#endif // WIFINETLIST_H
