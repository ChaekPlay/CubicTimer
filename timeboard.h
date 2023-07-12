#ifndef TIMEBOARD_H
#define TIMEBOARD_H

#include <vector>
#include <string>
#include <QTime>
#include <QApplication>
#include <QObject>
#include "timeformat.h"

class TimeBoard: public QObject
{
    Q_OBJECT
public:
    void addToList(QTime);
    void removeFromList(int);
    void clearList();
    QString calculateAverageOfN(int);
signals:
    void averageUpdated(QString, QString);
    void tableUpdated(QString);
private:
    std::vector<QTime> list;
};

#endif // TIMEBOARD_H
