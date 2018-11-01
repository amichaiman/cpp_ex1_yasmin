//
// Created by amichai on 26/10/18.
//

#include "Players.h"

void Players::addPlayer(Player *player) {
    Node *cur = playerList.head;

    if (playerList.head == NULL) { //list is empty
        Node *toAdd = new Node;
        toAdd->p = player;
        toAdd->next = NULL;
        playerList.head = toAdd;
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

    numberOfPlayer++;
}

Players::Players() {
    playerList.head = NULL;
    numberOfPlayer=0;
}

int Players::getNumberOfPlayers() {
    return numberOfPlayer;
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

    while (cur != NULL) {
        cur->p->printMean();
    }
}
