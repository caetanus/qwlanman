#ifndef CELL_H
#define CELL_H
#include <QtGui>


class Cell : public QObject
{
    Q_OBJECT

private:
    QString cell;
    QString essid;
    int quality;
    bool crypt;
    bool wpa;
    QString protocol;
    int timeout;


public:
    explicit Cell(QObject *parent = 0);
    Cell(const Cell& c);
    void setEssid(QString essid);
    void setCell(QString cell);
    void setEncryption(bool encryption);
    void setWpa(bool wpa);
    void setQuality(int quality);
    void setProtocol(QString protocol);
    QString getEssid();
    QString getCell();
    bool getEncryption();
    bool getWpa();
    int getQuality();
    QString getProtocol();


signals:

public slots:

};

#endif // CELL_H
