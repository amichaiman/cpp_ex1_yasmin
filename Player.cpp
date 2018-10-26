//
// Created by amichai on 26/10/18.
//

#include "Player.h"
#include <cctype>
#include <sstream>
#include <limits>

Player::Player(const string &name, string grades,  int number_of_judges) {
    this->name = name;
    this->number_of_judges = number_of_judges;
    this->grades = new float[number_of_judges];

    stringstream ss;
    ss << grades;

    for (int i=0; i<number_of_judges; i++){
        ss >> grades[i];
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    }

}


const string &Player::getName() const {
    return name;
}

void Player::setName(const string &name) {
    Player::name = name;
}

float Player::getGrade(int i) const {
    if (i<0 || i>number_of_judges){
        return -1;
    }
    return grades[i];
}


bool Player::player_name_is_legal(string player_name) {
    for (int i=0; i<player_name.length(); i++){
       if (!isdigit(player_name[i]) && !isalpha(player_name[i])){
           return false;
       }
    }
    return true;
}
