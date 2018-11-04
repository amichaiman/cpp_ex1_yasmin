//
// Created by amichai on 04/11/18.
//

#ifndef CPP_EX1_MAINFUNCTIONS_H
#define CPP_EX1_MAINFUNCTIONS_H
#include <iostream>
using namespace std;

inline void print_usage() {
    cerr << "ERROR: USAGE <executable> NUM_REFEREES MAX_ATHLETES" << endl;
}

inline void invalid_input() {
    cerr << "ERROR: invalid input" << endl;
}
void print_options();
void parse_args(int argc, char **argv, int *num_of_referees, int *num_of_athletes);
int get_input();
bool cinGoodStatus();
void handleGame(int numOfReferees, int numOfAthletes);



#endif //CPP_EX1_MAINFUNCTIONS_H
