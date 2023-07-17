#ifndef TIMEBOARD_H
#define TIMEBOARD_H

#include <vector>
#include <string>
#include <QTime>
#include <QApplication>
#include <QObject>
#include "timeformat.h"
#include "solvetime.h"
#include <QIODevice>
#include <QFile>
#include <QTextStream>

class TimeBoard: public QObject
{
    Q_OBJECT
public:
    void addToList(SolveTime);
    void removeFromList(int);
    void clearList();
    QString calculateAverageOfN(int);
    void saveToFile(QString);
signals:
    void averageUpdated(QString, QString);
    void tableUpdated(QString);
    void tableElementRemoved(int);
private:
    std::vector<SolveTime> list;
};

#endif // TIMEBOARD_H
