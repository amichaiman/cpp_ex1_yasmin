//
// Created by amichai on 26/10/18.
//

#include "Player.h"
#include <cctype>
#include <sstream>
#include <limits>
#include <iostream>
#include <iomanip>
#include <cmath>

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
        cout << fixed << setprecision(getPrecision(grades[i])) << grades[i] << (i==numberOfJudges-1 ? "]" : ",");
    }
    cout << endl;
}

void Player::printMean() {
    cout << getName() << ", " << getMean() << endl;
}

int Player::getPrecision(float n){
    if (floor(n) == n){
        return 0;
    }
    if (floor(n*10) == n*10){
        return 1;
    }
    return 2;
}

float Player::getMean() {
    float sum = 0;

    for (int i=0; i<numberOfJudges; i++){
        sum += grades[i];
    }
    return sum/numberOfJudges;
}
