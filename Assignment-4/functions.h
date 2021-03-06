#include <algorithm>
#include <deque>
#include <string>
#include <fstream>
#include <set>

using namespace std;

class hangman{
    public:
        void addGuessCount(){ guessCount++;};
        int getGuessCount(){ return guessCount; };
        string getWordFromFile(string fileName);
        int initData(string word);
        string printGuesses();
        void setWord(string word){ wordToGuess = word; };
        bool checkIsGuessing(){return isGuessing;};
        void checkDone();
        void checkGuess(char str);
        
    
    private:
        deque<string> guess;
        set<string> guessSet;
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


int hangman::initData(string word){

    for (auto it = word.cbegin() ; it != word.cend(); ++it) {
        string s(1, *it);
        guessSet.insert(s);
    }

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
    string s(1, str);

    //<algorithm> count
    int found = std::count(guessSet.cbegin(), guessSet.cend(), s);
    if( found == 1){
        //Do stuff to the Set
        auto pos = guessSet.find(s);
        guessSet.erase(pos);
    }

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
    //Sets make the game check much easier
    if(guessSet.size() <= 0){
        isGuessing = false;
    }

}