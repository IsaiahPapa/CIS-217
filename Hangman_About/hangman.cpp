

/*
void playHangmanGame(){

    QString userInput;
    int guessCount = 0;
    hangman game;
    deque <QString> dqGuesses;
    bool isGuessing =  true;

    QString wordToGuess = game.getWordFromFile("words.txt");


    while (isGuessing) {

        ui->label_Console->setText("[Console] Please make a guess.");

        //userInput = ui->le_guessInput->text().toLower();


        for (unsigned int i = 0; i < wordToGuess.size(); i++) {

            if (wordToGuess[i] == userInput) {

                //convert char to string to add to dq
                //string letterString(1, userInput);

                dqGuesses.at(i) = userInput;
                ui->label_Console->setText("[Console] Guessed " + userInput + " correctly!");
                //cout << "[Console] Guessed " << letterString << " correctly! " << endl;

            }

        }

        //We need a new bool to see if the word is complete
        //We need to keep a bool alwasy at true, and if something is wrong we change its value. or vice versa, either way we can only change its state once.
        ui->label_CorrectGuesses->setText(game.progressString(dqGuesses));
        guessCount++;

        bool doneGuessing = true;

        for (unsigned int i = 0; i < dqGuesses.size(); i++) {

            if (dqGuesses.at(i) != wordToGuess[i]) {
                doneGuessing = false;
            }

            if (doneGuessing) {
                isGuessing = false;
            } else {
                isGuessing = true;
            }
        }
    }
}
*/
