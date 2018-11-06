//
// Created by amichai on 04/11/18.
//

#include <limits>
#include <sstream>
#include <cstdlib>
#include "mainFunctions.h"
#include "Players.h"

void handleGame(int numOfReferees, int maxNumOfAthletes) {

    const int QUIT = 0;
    int input;
    Players players;
    players.setNumberOfJudges(numOfReferees);
    input = get_input();

    while(input != QUIT){
        switch (input){
            case(1):{
//                cout << "Enter player name, followed by grades" << endl;
                string player_name;
                cin >> player_name;
                if (!cinGoodStatus()){
                    invalid_input();
                    break;
                }
                Player *p = new Player(numOfReferees);

                if (!p->setName(player_name)){ //returns false if player's name is invalid
                    invalid_input();
                    delete p;
                    break;
                }

                float grades[numOfReferees];
                for (int i=0; i<numOfReferees; i++){
                    cin >> grades[i];
                    char c;
                    cin.get(c);
                    if (i != numOfReferees-1 && c != ','){
                        cerr << "ERROR: invalid input" << endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                if (players.getNumberOfPlayers() >= maxNumOfAthletes) {
                    cerr << "ERROR: MAX_ATHLETES exceeded" << endl;
                    break;
                }
                p->addGrades(grades);
                players.addPlayer(p);
            } break;
            case(2):{
                string name;
                cin >> name;
                if (!cinGoodStatus()){
                    invalid_input();
                    break;
                }
                Player *p = players.getPlayer(name);
                if (!p) {
                    cerr << "ERROR: " << name << " does not exist" << endl;
                    break;
                }
                p->printGrades();
            } break;
            case(3):{
                string name;
                cin >> name;
                if (!cinGoodStatus()){
                    invalid_input();
                    break;
                }
                Player *p = players.getPlayer(name);
                if (!p) {
                    cerr << "ERROR: " << name << " does not exist" << endl;
                    break;
                }
                p->printMean();
            } break;
            case(4):{
                players.printAllPlayersMean();
            } break;
            case(5):{
                players.printAllJudgesMean();
            } break;
            case(6):{
                players.printCovarianceMatrix();
            } break;
        }
        input = get_input();
    }
}

void handleGame(){

}
bool cinGoodStatus() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int get_input() {
    const int MIN_INPUT_VALUE = 0;
    const int MAX_INPUT_VALUE = 6;
    int input;

//    print_options();
    cin >> input;

    /* make sure number is between MIN and MAX values   */
    while (cin.fail() || input < MIN_INPUT_VALUE || input > MAX_INPUT_VALUE) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cerr << "ERROR: invalid command; type 0 for exit" << endl;
//        print_options();
        cin >> input;
    }

    return input;
}

/* function makes sure:
 *  1) 2 parameters to program
 *  2) valid value in parameters*/
void parse_args(int argc, char **argv, int *num_of_referees, int *num_of_athletes) {
    const int MAX_NUM_REFEREES = 30;
    const int MAX_NUM_ATHLETES = 100000;
    const int MIN_NUM_REFEREES = 0;
    const int MIN_NUM_ATHLETES = 3;
    stringstream ss;

    if (argc < 3) {
        print_usage();
        exit(1);
    }

    ss << argv[1];
    ss >> *num_of_referees;

    if (ss.fail() || *num_of_referees > MAX_NUM_REFEREES || *num_of_referees < MIN_NUM_REFEREES){
        print_usage();
        exit(1);
    }

    ss.clear();

    ss << argv[2];
    ss >> *num_of_athletes;

    if (ss.fail() || *num_of_athletes > MAX_NUM_ATHLETES || *num_of_athletes < MIN_NUM_ATHLETES){
        print_usage();
        exit(1);
    }
}

void print_options() {
    cout << "0) exit" << endl;
    cout << "1) add grades for specific player" << endl;
    cout << "2) show grades for specific player" << endl;
    cout << "3) show mean for specific player" << endl;
    cout << "4) show mean for all players" << endl;
    cout << "5) show mean grades of judge" << endl;
    cout << "6) show covariance" << endl;
}
