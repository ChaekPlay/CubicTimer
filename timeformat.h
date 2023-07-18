#ifndef TIMEFORMAT_H
#define TIMEFORMAT_H

#include <QString>
#include <QTime>

class TimeFormat
{
public:
    static QString generateFormatForTime(QTime);
    static QString generateFixedFormat(QTime);
};

#endif // TIMEFORMAT_H
