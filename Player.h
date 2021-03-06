//
// Created by amichai on 26/10/18.
//

#ifndef CPP_EX1_PLAYER_H
#define CPP_EX1_PLAYER_H
#include <string>
using namespace std;

class Player {
public:
    Player(int numberOfJudges1);
    ~Player();
    const string &getName() const;
    bool setName(const string &name);
    float getGrade(int i) const;
    void addGrades(float grades[]);
    bool playerNameIsLegal(string playerName);
    void printGrades();
    void printMean();

    float getMean();

private:
    string name;
    int numberOfJudges;
    float *grades;
    int getPrecision(float n);
};


#endif //CPP_EX1_PLAYER_H
