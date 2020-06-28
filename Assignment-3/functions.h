#include <algorithm>
#include <deque>
#include <string>
#include <fstream>


using namespace std;

class hangman{
    public:
        void addGuessCount(){ guessCount++;};
        int getGuessCount(){ return guessCount; };
        string getWordFromFile(string fileName);
        int initDQ(string word);
        string printGuesses();
        void setWord(string word){
          wordToGuess = word;
        };
        bool checkIsGuessing(){return isGuessing;};
        void checkDone();
        void checkGuess(char str);
        
    
    private:
        deque<string> guess;
        string wordToGuess;
        int guessCount = 0;
        bool isGuessing = true;


};

string hangman::getWordFromFile(string fileName){

    deque<string> words;
    string line;
    ifstream wordFile (fileName);

    if (wordFile.is_open()){
        while ( getline (wordFile, line) ){
            if(!line.empty()){
                words.push_back(line);
            }
        }
        wordFile.close();
    }
    return words[rand() % words.size()];
}


int hangman::initDQ(string word){

    for(int i = 0; i < word.size(); i++){

        //fill blank dq with underscores
        //We will use these _'s to see if the word has been guessed correctly or not.

        guess.push_back("_");

    }

    return 0;
}


string hangman::printGuesses(){

    string output = "";

    for (int i = 0; i < guess.size(); i++) {
        output += guess.at(i) + " ";
    }

    return output;
}



void hangman::checkGuess(char str){
  for (int i = 0; i < wordToGuess.size(); i++) {

    if (wordToGuess[i] == str) {

        //convert char to string to add to dq
        string letterString(1, str);

        guess.at(i) = letterString;

        cout << "[Console] Guessed " << letterString << " correctly! " << endl;

    }

  }
}

void hangman::checkDone(){
  bool doneGuessing = true;

  for (int i = 0; i < guess.size(); i++) {
      //if there is a underscore, the word has not been complete yet, so if there is not one the word is guessed successful 
      //convert char to string so we can check the comparison.
      string stringOfWord(1, wordToGuess[i]);

      if (guess.at(i) != stringOfWord) {
          doneGuessing = false;
      }

      if (doneGuessing) {
          isGuessing = false;
      } else {
          isGuessing = true;
      }
  }
}