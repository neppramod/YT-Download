#include "yt.h"

Yt::Yt()
{

}

QString Yt::getLocation()
{
    return this->location;
}

void Yt::setLocation(QString location)
{
    this->location = location;
}

QString Yt::getURI()
{
    return this->uri;
}

void Yt::setURI(QString uri)
{
    this->uri = uri;
}

QList<QString> Yt::getFlags()
{
    return this->flags;
}

void Yt::setFlags(QList<QString> flags)
{
    this->flags = flags;
}
