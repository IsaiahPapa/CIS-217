#include <deque>
#include <string>
#include <fstream>

using namespace std;

string getWordFromFile(string fileName){

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


int initDQ(string word, deque<string> &guess){
    
    for(int i = 0; i < word.size(); i++){
    
        //fill blank dq with underscores
        //We will use these _'s to see if the word has been guessed correctly or not.

        guess.push_back("_");
  
    }

    return 0;
}


int printGuesses(string word, deque<string> &guess){
    for (int i = 0; i < guess.size(); i++) {
        cout << guess.at(i) << " ";
    }
    cout << endl;
    return 0;
}