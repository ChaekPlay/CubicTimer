#include "timeboard.h"

void TimeBoard::addToList(SolveTime time) {
    list.push_back(time);
    QString ao5 = calculateAverageOfN(5);
    QString ao12 = calculateAverageOfN(12);
    emit averageUpdated(ao5, ao12);
    emit tableUpdated(TimeFormat::generateFormatForTime(time.getTime()));
}

void TimeBoard::clearList() {
    list.clear();
    emit averageUpdated("-", "-");
    emit tableUpdated("-");
}

void TimeBoard::removeFromList(int id) {
    list.erase(list.begin()+(id-1));
    QString ao5 = calculateAverageOfN(5);
    QString ao12 = calculateAverageOfN(12);
    emit averageUpdated(ao5,ao12);
    emit tableElementRemoved(id);
}

QString TimeBoard::calculateAverageOfN(int n) {
    if(list.size() < n)
        return QString("-");
    std::vector<SolveTime> aoNList(list.end() - n, list.end());
    auto max = std::max_element(aoNList.begin(), aoNList.end(),
        [] (SolveTime& first, SolveTime& second)
            {return first.getTime() > second.getTime();});
    auto min = std::min_element(aoNList.begin(), aoNList.end(),
        [] (SolveTime& first, SolveTime& second)
            {return first.getTime() < second.getTime();});
    aoNList.erase(max);
    aoNList.erase(min);
    uint64_t average = 0;
    for(auto& it: aoNList) {
        average += it.getTime().hour()*3600*1000+it.getTime().minute()*60*1000
                   +it.getTime().second()*1000+it.getTime().msec();
    }
    average /= (n-2);
    const int MS_TO_HOURS = 3600 * 1000, MS_TO_MINUTES = 60*1000, MS_TO_SECONDS = 1000;
    short minutes = (average % MS_TO_HOURS) / MS_TO_MINUTES;
    short seconds = (average % MS_TO_MINUTES) / MS_TO_SECONDS;
    QTime averageTime(average / MS_TO_HOURS,minutes,seconds,average % MS_TO_SECONDS);
    return TimeFormat::generateFormatForTime(averageTime);
}

void TimeBoard::saveToFile(QString path) {
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    int i = 1;
    for(auto& it: list) {
        QString formattedTime = TimeFormat::generateFormatForTime(it.getTime());
        out << QString::number(i) << " Time: " << formattedTime << "\nScramble: " << it.getScramble() << "\n";
        i++;
    }
    file.close();
}
