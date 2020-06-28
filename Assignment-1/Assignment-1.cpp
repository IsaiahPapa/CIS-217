#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Initalizing a string and vector, so that
//program is dynamic and changes when our word changes

string word = "hello";
vector<string> guess;

int initVector(){
  for(int i = 0; i < word.size(); i++){
    
    //fill blank vector with underscores
    //We will use these _'s to see if the word has been guessed correctly or not.

    guess.push_back("_");
  
  }
  return 0;
}

int main()
{
    initVector();
    char letter;
    bool guessing = true;
    

    cout << "Word Size: " << word.size() << " | Guess Size: " << guess.size() << endl;
    cout << "Welcome to hangman ";
    cout << "Guess the word: " << endl << "\t";

    for(int i = 0; i < word.size(); i++){
        cout << "_ ";
        
    }
    cout << endl;
    
    while(guessing){

        cin >> letter;

        for(int i = 0; i < word.size(); i++){
            
            if(word[i] == letter){

                //convert char to string to add to vector
                string temp(1, letter);
                guess.at(i) = temp;

                cout << "Guessed '"<< temp << "' correctly! " << endl;

            }
            
        }
        
        //We need a new bool to see if the word is complete
        //We need to keep a bool alwasy at true, and if something is wrong we change its value. or vice versa, either way we can only change its state once. 

        bool done = true;
        for(int i = 0; i < guess.size(); i++){
          //if there is a underscore, the word has not been complete yet, so if there is not one the word is guessed successful 

          cout << guess.at(i) << " ";
          //convert char to string so we can check the comparison.
          string stringOfWord(1, word[i]);

          if(guess.at(i) != stringOfWord){
            done = false;
          }

          if(done){
            guessing = false;
          }else{
            guessing = true;
          }
          
          

        }

        cout << endl;
    }

    cout << "Word guess correctly! Have a great day!" << endl;
    
    return 0;
}

