//
// Created by amichai on 26/10/18.
//

#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "Players.h"

void Players::addPlayer(Player *player) {
    Node *cur = playerList.head;

    if (playerList.head == NULL) { //list is empty
        Node *toAdd = new Node;
        toAdd->p = player;
        toAdd->next = NULL;
        playerList.head = toAdd;
        currentNumberOfPlayer++;
        return;
    }
    if (cur->p->getName() == player->getName()) { //check if first node's value is equal to the value we want to insert
        delete cur->p;
        cur->p =  player;
        return;
    }
    while (cur->next != NULL) { //list is not empty: iterate to end of list
        if (cur->p->getName() == player->getName()) { //check if player already exists. if yes: replace
            delete cur->p;
            cur->p =  player;
            return;
        }
        cur = cur->next;
    }

    Node *toAdd = new Node;
    toAdd->p = player;
    toAdd->next = NULL;
    cur->next = toAdd;

    currentNumberOfPlayer++;
}

Players::Players() {
    playerList.head = NULL;
    currentNumberOfPlayer=0;
}

int Players::getNumberOfPlayers() {
    return currentNumberOfPlayer;
}

Players::~Players() {
    while(playerList.head != NULL) {
        Node *toDelete = playerList.head;
        playerList.head = toDelete->next;
        delete toDelete->p;
        delete toDelete;
    }
}

Player *Players::getPlayer(string playerName) {
    Node *cur = playerList.head;
    while (cur != NULL) {
        if (cur->p->getName() == playerName) {
            return cur->p;
        }
        cur=cur->next;
    }
    return NULL;
}

void Players::printAllPlayersMean() {
    Node *cur = playerList.head;
    if (cur == NULL){
        cerr << "ERROR: no records in the system" << endl;
        return;
    }
    while (cur != NULL) {
        cur->p->printMean();
        cur = cur->next;
    }
}

void Players::printAllJudgesMean() {
    stringstream ss;

    Node *cur = playerList.head;
    if (cur == NULL){
        cerr << "ERROR: no records in the system" << endl;
        return;
    }
    ss << "mean=[";
    for (int i=0; i<numberOfJudges; i++){
        float judgeMean = getJudgeMean(i);
        ss << fixed << setprecision(getPrecision(judgeMean)) << judgeMean << (i == numberOfJudges-1 ? "]" : ",");
    }
    cout << ss.str() << endl;
}

int Players::getNumberOfJudges() const {
    return numberOfJudges;
}

void Players::setNumberOfJudges(int numberOfJudges) {
    Players::numberOfJudges = numberOfJudges;
}

float Players::getJudgeMean(int judgeNumber) {
    Node *cur = playerList.head;
    float sum = 0;

    while (cur != NULL){
        sum += cur->p->getGrade(judgeNumber);
        cur = cur->next;
    }
    return sum/currentNumberOfPlayer;

}

int Players::getPrecision(float n) {
    n = static_cast<float>((round(n * 100)) / 100);
    if (floor(n) == n){
        return 0;
    }
    if (floor(n*10) == n*10){
        return 1;
    }
    return 2;
}

void Players::printCovarianceMatrix() {
    stringstream ss;
    ss << "cov=[\n";
    Node *cur = playerList.head;
    if (cur == NULL){
        cerr << "ERROR: no records in the system" << endl;
        return;
    }
    for (int i=0; i<numberOfJudges; i++){
        for (int j=0; j<numberOfJudges; j++){
            float covariance = computeCovariance(i,j);
            ss << fixed << setprecision(getPrecision(covariance)) << covariance << (j == numberOfJudges-1 ? "\n" : ",");
        }
    }
    ss << "]";
    cout << ss.str() << endl;
}

float Players::computeCovariance(int i, int j) {
    float ui = getJudgeMean(i);
    float uj = getJudgeMean(j);

    double sum = 0;

    for (int k=0; k<currentNumberOfPlayer; k++){
        sum += (getPlayerAt(k)->getGrade(i)-ui)*(getPlayerAt(k)->getGrade(j)-uj);
    }
    return static_cast<float>(currentNumberOfPlayer == 1 ? sum / currentNumberOfPlayer : sum / (currentNumberOfPlayer - 1));
}

Player* Players::getPlayerAt(int index) {
    Node *cur = playerList.head;

    if (index > currentNumberOfPlayer){
        return cur->p;
    }
    while (index--) {
        cur = cur->next;
    }
    return cur->p;
}
