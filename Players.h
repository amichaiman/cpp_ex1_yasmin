//
// Created by amichai on 26/10/18.
//

#ifndef CPP_EX1_PLAYERS_H
#define CPP_EX1_PLAYERS_H

#include "Player.h"

typedef struct node{
    Player *p;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} PlayerList;


class Players {
public:
    Players();
    ~Players();

    void addPlayer(Player *player);
    int getNumberOfPlayers();
    Player *getPlayer(string playerName);
    void printAllPlayersMean();
    void printAllJudgesMean();
    int getNumberOfJudges() const;
    void setNumberOfJudges(int numberOfJudges);
    void printCovarianceMatrix();
private:
    int numberOfJudges;
    int currentNumberOfPlayer;
    PlayerList playerList;
    float getJudgeMean(int judgeNumber);
    int getPrecision(float n);
    float computeCovariance(int i, int j);
    Player * getPlayerAt(int i);
};

#endif //CPP_EX1_PLAYERS_H
