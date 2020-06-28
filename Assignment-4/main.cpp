/*
  Student Name: Isaiah Paparella
  Course info:  CIS 217
  Assignment:   Assignment 4
  IDE:          Visual Studio Code
  Description:  Based on a word given by the user, generate a hangman game that the user can play. Using Sets and non-modifying algorithms
*/

#include <iostream>
#include <deque>
#include <string>
#include "functions.h"

using namespace std;


int main() {
    //Fill the deque with spaces based on word length
    hangman game;


    cout << "Welcome to hangman. A random word will be chosen from our list." << endl;

    //Look into making a http request from pastebin?
    string word = game.getWordFromFile("words.txt");
    game.setWord(word);
    game.initData(word);
    

    char inputGuess;
    bool isGuessing = true;
    int guessCount;

    cout << "Welcome {{USER}} to hangman ";
    cout << "Guess the word: \n\t";

    cout <<  game.printGuesses() << endl;

    while (game.checkIsGuessing()) {
        cout << "\n[Console] Guess: ";
        cin >> inputGuess;
        inputGuess = tolower(inputGuess);

        game.checkGuess(inputGuess);
    
        cout <<  game.printGuesses() << endl;
        game.addGuessCount();
        game.checkDone();
    }

    cout << "[Console] Word guessed correctly!" << endl;
    cout << "[Console] You guessed " << game.getGuessCount() << " time(s)!" << endl;
    cout << "[Console] Have a great day!" << endl;

    return 0;
}