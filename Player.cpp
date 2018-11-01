//
// Created by amichai on 26/10/18.
//

#include "Player.h"
#include <cctype>
#include <sstream>
#include <limits>
#include <iostream>

Player::Player(int numberOfJudges) {
    this->numberOfJudges = numberOfJudges;
    this->grades = new float[numberOfJudges];
}

void Player::addGrades(float grades[]){
    for (int i=0; i<numberOfJudges; i++){
        this->grades[i] = grades[i];
    }
}
const string &Player::getName() const {
    return name;
}

bool Player::setName(const string &name) {
    if (!playerNameIsLegal(name)) {
        return false;
    }
    Player::name = name;
    return true;
}

float Player::getGrade(int i) const {
    if (i<0 || i>numberOfJudges){
        return -1;
    }
    return grades[i];
}


bool Player::playerNameIsLegal(string playerName) {
    for (unsigned int i=0; i<playerName.length(); i++){
       if (!isdigit(playerName[i]) && !isalpha(playerName[i])){
           return false;
       }
    }
    return true;
}

Player::~Player() {
    delete grades;
}

void Player::printGrades() {
    cout << getName() << "=[";
    for (int i=0; i<numberOfJudges; i++){
        cout << grades[i] << (i==numberOfJudges-1 ? "]" : ",");
    }
    cout << endl;
}

void Player::printMean() {
    float sum = 0;

    for (int i=0; i<numberOfJudges; i++){
        sum += grades[i];
    }
    cout << getName() << ", " << sum/numberOfJudges << endl;
}
