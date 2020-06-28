#ifndef HANGMAN_H
#define HANGMAN_H

#include <deque>
#include <string>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"

using namespace std;

class hangman{
    public:
        //hangman();
        void newGame(){
            guess.clear();
            wordToGuess = "";
            guessCount = 0;
            isGuessing = true;
        };
        string getWordFromFile(QString fileName);
        int initDQ(string word);
        QString progressString();
        void setWordToGuess(QString word){ wordToGuess = word; };
        int checkGuess(QString userInput);
        int getGuessCount(){ return guessCount; };

    private:
        deque<QString> guess;
        QString wordToGuess = "";
        int guessCount = 0;
        bool isGuessing = true;
};

string hangman::getWordFromFile(QString fileName){

    deque<string> words;
    QFile file;

    file.setFileName(fileName);

    if (file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        while (!in.atEnd())
        {
           QString line = in.readLine();
           words.push_back(line.toStdString());
        }
        file.close();
    }
    return words[rand() % words.size()];

}


int hangman::initDQ(string word){

    for(unsigned int i = 0; i < word.size(); i++){

        //fill blank dq with underscores
        //We will use these _'s to see if the word has been guessed correctly or not.

        guess.push_back("_");

    }

    return 0;
}


QString hangman::progressString(){
    QString output = "";
    for (unsigned int i = 0; i < guess.size(); i++) {
        output += guess.at(i) + " ";
    }

    return output;
}

int hangman::checkGuess(QString userInput){
    guessCount++;

    bool doneGuessing = true, guessedCorrectly = false;

    for (int i = 0; i < wordToGuess.size(); i++) {

        if (wordToGuess[i] == userInput) {

            //convert char to string to add to dq
            //string letterString(1, userInput);

            guess.at(i) = userInput;
            //ui->label_Console->setText("[Console] Guessed " + userInput + " correctly!");
            guessedCorrectly = true;

        }

    }



    for (unsigned int i = 0; i < guess.size(); i++) {

        if (guess.at(i) != wordToGuess[i]) {
            doneGuessing = false;
        }

        if (doneGuessing) {
            isGuessing = false;
        } else {
            isGuessing = true;
        }
    }




    if(doneGuessing){
        return 2;
    }else if(guessedCorrectly){
        return 1;
    }else{
        return 0;
    }

    //We need a new bool to see if the word is complete
    //We need to keep a bool alwasy at true, and if something is wrong we change its value. or vice versa, either way we can only change its state once.
    //ui->label_CorrectGuesses->setText(game.progressString(guess));


}

#endif // HANGMAN_H
