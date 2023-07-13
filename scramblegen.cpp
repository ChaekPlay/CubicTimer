#include "scramblegen.h"

ScrambleGen::ScrambleGen()
{
    std::random_device os_seed;
    const u32 seed = os_seed();
    generator = engine(seed);
    uint_dist_move_length = std::uniform_int_distribution<uint32_t>(0, 5);
    uint_dist_move_option = std::uniform_int_distribution<uint32_t>(0, MOVE_ARR_LENGTH-1);
    uint_dist_is_prime = std::uniform_int_distribution<uint32_t>(0, 1);
    calculateScrambleLength();
}

void ScrambleGen::calculateScrambleLength() {
    scrambleLength = 30 - uint_dist_move_length(generator);
}

QString ScrambleGen::getCurrentScramble() {
    return currentScramble;
}

QString ScrambleGen::generateScramble() {
    // TODO: refactor this
    calculateScrambleLength();
    std::vector<QString> scramble;
    for(short i = 0; i < scrambleLength; i++){
        bool prime = uint_dist_is_prime(generator) == 1;
        u32 option = uint_dist_move_option(generator);
        if(prime) {
            if(i == 0)
                scramble.push_back(QString(moves[option]+'\''));
            else if(moves[option]+'\'' == scramble.back())
                    scramble.back() = QString(moves[option]+'2');
            else if(moves[option] == scramble.back() || moves[option]+'2' == scramble.back()) {
                    u32 newOption = uint_dist_move_option(generator);
                    while(newOption == option) newOption = uint_dist_move_option(generator);
                    scramble.push_back(QString(moves[newOption]));
                }
            else {
                scramble.push_back(QString(moves[option]+'\''));
            }
        }
        else {
            if(i == 0)
                scramble.push_back(QString(moves[option]+'\''));
            else if(moves[option] == scramble.back())
                scramble.back() = QString(moves[option]+'2');
            else if(moves[option]+'\'' == scramble.back() || moves[option]+'2' == scramble.back()) {
                u32 newOption = uint_dist_move_option(generator);
                while(newOption == option) newOption = uint_dist_move_option(generator);
                scramble.push_back(QString(moves[newOption]));
            }
            else {
                scramble.push_back(QString(moves[option]));
            }
        }
    }
    QString newScramble;
    for(auto& move: scramble) {
        newScramble += move + ' ';
    }
    newScramble = newScramble.trimmed();
    currentScramble = newScramble;
    return currentScramble;
}
