#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ROCK = 0;
const int PAPER = 1;
const int SCISSORS = 2;

int getUserChoice() {
    int choice;
    do {
        cout << "Choose (0) Rock, (1) Paper, or (2) Scissors: ";
        cin >> choice;

        if (choice < 0 || choice > 2) {
            cout << "Invalid choice. Please enter a number between 0 and 2." << endl;
        }

    } while (choice < 0 || choice > 2);

    return choice;
}

int getComputerChoice() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 0 and 2
    return rand() % 3;
}

void determineWinner(int user, int computer) {
    cout << "You chose ";
    switch (user) {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
    }

    cout << ". Computer chose ";
    switch (computer) {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
    }

    cout << ". ";

    // Determine the winner
    if (user == computer) {
        cout << "It's a tie!";
    } else if ((user == ROCK && computer == SCISSORS) ||
    (user == PAPER && computer == ROCK) ||
    (user == SCISSORS && computer == PAPER)) {
        cout << "You win!";
    } else {
        cout << "Computer wins!";
    }

    cout << endl;
}

int main() {
    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    char playAgain;
    do {
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();

        determineWinner(userChoice, computerChoice);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}
