#ifndef YT_H
#define YT_H

#include <QString>
#include <QList>

class Yt
{
private:
    QString location;
    QString uri;
    QList<QString> flags;
public:
    Yt();
    QString getLocation();
    void setLocation(QString location);
    QString getURI();
    void setURI(QString uri);
    QList<QString> getFlags();
    void setFlags(QList<QString> flags);
};

#endif // YT_H
