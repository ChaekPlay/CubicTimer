#ifndef SOLVETIME_H
#define SOLVETIME_H

#include <QTime>
#include <QString>

class SolveTime
{
public:
    SolveTime(QTime, QString);
    QTime getTime();
    QString getScramble();
private:
    QTime time;
    QString scramble;
};

#endif // SOLVETIME_H
