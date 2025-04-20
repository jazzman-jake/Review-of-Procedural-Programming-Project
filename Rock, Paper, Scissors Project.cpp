//Terrence Williamson
//CSC 222
//02.10.25
//Review of Procedural Programming Project
//R-P-S-Project

#include <iostream>
#include <random>
using namespace std;

//declare functions that will be initialized later for use in main function
void scores(), winner();

//set variables to count number of wins for both the user and computer,
//and both player's selections
int pw = 0, CPUw = 0, choice, CPUrng;

//variable to set program to either continuing or stopping
bool quit = false;

//random number generation, for computer's choices during game. Can only be 1-3
random_device random;
uniform_int_distribution<int>rng(1, 3);

//inside main function, menu is created showing available options, and has a validation loop for input 
int main()
{
    cout << "Welcome to the Rock, Paper, Scissors Tournament. Type '4' at any time to end the tournament.\n"
        "Select from the following options:\n\n1. Rock\n2. Paper\n3. Scissors\n4. Quit Game\n\n";
    cin >> choice;
    
    while (quit == false) {
        winner();
        if (choice < 1 || choice > 4) {
            cout << "Error: Invalid input. Please refer to the options. ";
            cin >> choice;
        }
        CPUrng = rng(random);
        switch (choice) {
        case 1:
            scores();
            break;
        case 2:
            scores();
            break;
        case 3:
            scores();
            break;
        case 4:
            quit = true;
            break;
        }
    }
    return 0;
}
//Remember, 1 = rock, 2 = paper, 3 = scissors

//this function tabulates scores from each round, declares the current round's winner and,
//if necessary, declares a draw and displays a mirrored score if both players chose the same option
void scores() {
    if (CPUrng == choice) {
        cout << "\nThis round was a draw. CPU chose the same as you.\n"
            "The current score is...\n\nPlayer: " << pw << "\nCPU: " << CPUw << endl;
    }
    else if ((choice == 1 && CPUrng == 2) || (choice == 2 && CPUrng == 3)
        || (choice == 3 && CPUrng == 1)) {
        ++CPUw;
        cout << "\nCPU won that round. CPU chose " << CPUrng << " which beats your " << choice << endl;
            cout << "The current score is...\n\nPlayer: " << pw << "\nCPU: " << CPUw << endl;
    } else if ((choice == 1 && CPUrng == 3) || (choice == 3 && CPUrng == 2)
        || (choice == 2 && CPUrng == 1)) {
        ++pw;
        cout << "\n1 point to you, player. CPU chose " << CPUrng << " which lost to your " << choice << endl;
        cout << "The current score is...\n\nPlayer: " << pw << "\nCPU: " << CPUw << endl;
  }
    cout << "Input for next round: ", cin >> choice;
}
//this function will determine who won the entire tournament when the player ends the game,
//then declares the winner if there is one, or declares a draw, and ends the program
void winner() {
    if (choice == 4) {
        cout << "\nThe tournament is now over.\n\n";
        cout << "You have " << pw << " points.\n";
        cout << "CPU has " << CPUw << " points.\n";
        if (pw > CPUw) {
            cout << "You won the tournament, player. Congratulations!!!\n\n";
        }
        else if (pw < CPUw) {
            cout << "The computer won this tournament. Better luck next time.\n\n";
        }
        else if (pw == CPUw) {
            cout << "This tournament ended in a draw. Well played!\n\n";
        }  
    }  
}