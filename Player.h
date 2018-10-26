//
// Created by amichai on 26/10/18.
//

#ifndef CPP_EX1_PLAYER_H
#define CPP_EX1_PLAYER_H
#include <string>
using namespace std;

class Player {
public:
    Player(const string &name, string grades, int number_of_judges);

    const string &getName() const;
    void setName(const string &name);
    float getGrade(int i) const;

    static bool player_name_is_legal(string player_name);

private:
    string name;
    int number_of_judges;
    float *grades;
};


#endif //CPP_EX1_PLAYER_H
