//
// Created by amichai on 26/10/18.
//

#ifndef CPP_EX1_PLAYERS_H
#define CPP_EX1_PLAYERS_H

#include "Player.h"

typedef struct node{
    Player p;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} PlayerList;


class Players {
public:
private:
    PlayerList playerList;
};

#endif //CPP_EX1_PLAYERS_H
