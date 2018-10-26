#include <iostream>
#include <cstdlib>
#include <sstream>
#include <limits>
#include "Players.h"
#include "Player.h"


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


bool cin_good_status();

int main(int argc, char **argv) {
    const int QUIT = 0;
    int input;
    int num_of_referees;
    int num_of_athletes;
    Players players;

    parse_args(argc, argv, &num_of_referees, &num_of_athletes);
    input = get_input();

    while(input != QUIT){
        switch (input){
            case(1):{
                cout << "Enter player name, followed by grades" << endl;
                string player_name;
                cin >> player_name;
                if (!cin_good_status()){
                    invalid_input();
                    break;
                }
                string grades;
                cin >> grades;

                Player p(player_name, grades, num_of_referees);
            } break;
            case(2):{

            } break;
            case(3):{

            } break;
            case(4):{

            } break;
            case(5):{

            } break;
            case(6):{

            } break;
        }
        input = get_input();
    }

    return 0;
}

bool cin_good_status() {
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

    print_options();
    cin >> input;

    /* make sure number is between MIN and MAX values   */
    while (cin.fail() || input < MIN_INPUT_VALUE || input > MAX_INPUT_VALUE) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cerr << "ERROR: invalid command; type 0 for exit" << endl;
        cin >> input;
    }

    return input;
}

/* function makes sure:
 *  1) 2 parameters to program
 *  2) valid value in parameters*/
void parse_args(int argc, char **argv, int *num_of_referees, int *num_of_athletes) {
    const int MAX_NUM_REFEREES = 30;
    const int MAX_NUM_ATHLETES = 100;
    const int MIN_NUM_REFEREES = 2;
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