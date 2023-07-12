#include "timeformat.h"

QString TimeFormat::generateFormatForTime(QTime time) {
    QString format = "s.zzz";
    if(time.minute() != 0)
        format = "m.s" + format;
    if(time.hour() != 0)
        format = "hh.m" + format;
    return time.toString(format);
}
