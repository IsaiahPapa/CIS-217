/*
  Student Name: Isaiah Paparella
  Course info:  CIS 217
  Assignment:   Assignment 1
  IDE:          Visual Studio Code
  Description:  Based on a word given by the user, generate a hangman game that the user can play.
*/

#include <iostream>
#include <deque>
#include <string>
#include <ctype.h> 
#include <stdio.h> 
#include "functions.h"

using namespace std;

string wordToGuess;
deque <string> dqGuesses;

int main() {
    //Fill the deque with spaces based on word length
    
    cout << "Welcome to hangman. A random word will be chosen from our list." << endl;

    //Look into making a http request from pastebin?
    wordToGuess = getWordFromFile("words.txt");
    

    
    initDQ(wordToGuess, dqGuesses);
    

    char inputGuess;
    bool isGuessing = true;
    int guessCount;

    cout << "Welcome {{USER}} to hangman ";
    cout << "Guess the word: \n\t";

    printGuesses(wordToGuess, dqGuesses);

    while (isGuessing) {
        cout << "\n[Console] Guess: ";
        cin >> inputGuess;
        inputGuess = tolower(inputGuess);

        for (int i = 0; i < wordToGuess.size(); i++) {

            if (wordToGuess[i] == inputGuess) {

                //convert char to string to add to dq
                string letterString(1, inputGuess);

                dqGuesses.at(i) = letterString;

                cout << "[Console] Guessed " << letterString << " correctly! " << endl;

            }

        }

        //We need a new bool to see if the word is complete
        //We need to keep a bool alwasy at true, and if something is wrong we change its value. or vice versa, either way we can only change its state once. 
        
        printGuesses(wordToGuess, dqGuesses);
        guessCount++;

        bool doneGuessing = true;

        for (int i = 0; i < dqGuesses.size(); i++) {
            //if there is a underscore, the word has not been complete yet, so if there is not one the word is guessed successful 
            //convert char to string so we can check the comparison.
            string stringOfWord(1, wordToGuess[i]);

            if (dqGuesses.at(i) != stringOfWord) {
                doneGuessing = false;
            }

            if (doneGuessing) {
                isGuessing = false;
            } else {
                isGuessing = true;
            }
        }
    }

    cout << "[Console] Word guessed correctly!" << endl;
    cout << "[Console] You guessed " << guessCount << " time(s)!" << endl;
    cout << "[Console] Have a great day!" << endl;

    return 0;
}