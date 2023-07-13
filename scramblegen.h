#ifndef SCRAMBLEGEN_H
#define SCRAMBLEGEN_H

#include <QString>
#include <QChar>
#include <random>
#include <vector>
#include <cctype>

using u32 = uint_least32_t;
using engine = std::mt19937;

const short MOVE_ARR_LENGTH = 6;

class ScrambleGen
{
public:
    ScrambleGen();
    QString getCurrentScramble();
    QString generateScramble();
private:
    std::uniform_int_distribution<u32> uint_dist_move_length;
    std::uniform_int_distribution<u32> uint_dist_move_option;
    std::uniform_int_distribution<u32> uint_dist_is_prime;
    QChar moves[MOVE_ARR_LENGTH] = {'B', 'D', 'F', 'L', 'R', 'U'};
    int scrambleLength = 0;
    void calculateScrambleLength();
    engine generator;
    QString currentScramble = "";
};

#endif // SCRAMBLEGEN_H
