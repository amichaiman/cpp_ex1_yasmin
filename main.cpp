#include <iostream>
#include "mainFunctions.h"

int main(int argc, char **argv) {
    int numOfReferees;
    int maxNumOfAthletes;
    parse_args(argc, argv, &numOfReferees, &maxNumOfAthletes);

    handleGame(numOfReferees, maxNumOfAthletes);

    return 0;
}

