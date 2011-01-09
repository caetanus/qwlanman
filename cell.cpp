#include "cell.h"


Cell::Cell(QObject *parent) :
    QObject(parent)
{
}

Cell::Cell(const Cell &c){
    qMemCopy(this,&c,sizeof(this));

}

void Cell::setEssid(QString ess){
    essid = ess;
}

void Cell::setCell(QString cell){
    this->cell = cell;
}

void Cell::setEncryption(bool encryption){
    this->crypt = encryption;
}

void Cell::setWpa(bool wpa){
    this->wpa = wpa;
}

void Cell::setQuality(int quality){
    this->quality = quality;
}



QString Cell::getEssid(){
    return essid;
}

QString Cell::getCell(){
    return cell;
}

bool Cell::getEncryption(){
    return crypt;
}

bool Cell::getWpa(){
    return wpa;
}

int Cell::getQuality(){
    return quality;
}

void Cell::setProtocol(QString proto)
{
    protocol = proto;
}

QString Cell::getProtocol(){
    return protocol;
}
