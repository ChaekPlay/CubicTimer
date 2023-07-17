#include "solvetime.h"

SolveTime::SolveTime(QTime time, QString scramble)
{
    this->time = time;
    this->scramble = scramble;
}

QString SolveTime::getScramble() {
    return scramble;
}

QTime SolveTime::getTime() {
    return time;
}
