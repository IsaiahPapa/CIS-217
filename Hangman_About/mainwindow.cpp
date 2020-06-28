#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "hangman.h"

#include "libraryeditor.h"
#include "mytimer.h"
#include "resizedialog.h"

#include <QMessageBox>
#include <QQueue>
#include <QObject>

#include <QLCDNumber>

hangman mainGame;
QString userInput;
int timeKeep = 0;
QTimer *CounterTimer = new QTimer();



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //We need to set the default check box value. I didn't find a "Default" attribute for radio button
    ui->rb_tries->setChecked(true);


}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::UpdateClock(){

    timeKeep++;
    ui->lcd_Timer->display(timeKeep);
}


void MainWindow::aboutButton_clicked()
{

    //Create a modal for our about box.
    QMessageBox::about(this,"Hangman","Isaiah's Hangman application.\nFirst Build 4/14");


}


void MainWindow::on_pb_Resize_clicked()
{

    ResizeDialog resize;
    resize.setModal(true);
    resize.exec();

}



void MainWindow::on_pb_Play_clicked()
{
    CounterTimer = new QTimer(this);

    /*Restart clock and reset varialbe */
    if(ui->rb_tries->isChecked()){

        ui->lcd_Timer->display(QString::number(mainGame.getGuessCount()));

    }else if(ui->rb_timer->isChecked()){

        timeKeep = 0;
        connect(CounterTimer, SIGNAL(timeout()), this, SLOT(UpdateClock()));
        CounterTimer->start(1000);

    }else{
        ui->label_guessCount->setText("No button checked ");
    }

    mainGame.newGame();

    ui->label_Console->setText("[Console] Please make a guess.");
    //make it so they cannot change the buttons or press the play button again
    ui->pb_Play->setEnabled(false);
    ui->rb_timer->setEnabled(false);
    ui->rb_tries->setEnabled(false);
    /*
    //This is returning a list with length 0, could be that the parent is not a QWidget?
    //Really don't want to tinker for hours with this just to dynamically get all the buttons and disable them
    QList<QRadioButton*> buttonInLCDDisplaySettings = ui->displayLayout->findChildren<QRadioButton*>();
    for(auto button = buttonInLCDDisplaySettings.begin(); button < buttonInLCDDisplaySettings.end(); ++button){
        (*button)->setEnabled(false);
        ui->label_Console->setText(QString::number((*button)->isEnabled()));

    }
    */


    QString wordToGuess = QString::fromStdString(mainGame.getWordFromFile(":/hangman_words.txt"));

    //initilze the Dqueue (We have to do this before we disply string)
    mainGame.initDQ(wordToGuess.toStdString());
    mainGame.setWordToGuess(wordToGuess);

    //Initlize the spaces/letters there are
    ui->label_CorrectGuesses->setText(mainGame.progressString());
    ui->le_guessInput->setText("");

}


void MainWindow::on_le_guessInput_returnPressed()
{

    //Get the string from the players input box
    QString guess = ui->le_guessInput->text();

    switch(mainGame.checkGuess(guess)){
        case 0:
            ui->label_Console->setText("[SERVER] WRONG GUESS! Try again :(");
            break;
        case 1:
            ui->label_Console->setText("[SERVER] CORRECT!! Nice work! :)");
            break;
        case 2:
            ui->label_Console->setText("[SERVER] YOU WON!!!!!");
            //enable everything again
            ui->pb_Play->setEnabled(true);
            ui->rb_timer->setEnabled(true);
            ui->rb_tries->setEnabled(true);

            if(ui->rb_timer->isEnabled()){
                CounterTimer->stop();
            }

            break;
        default:
            //Something broke if you got here;
            ui->label_Console->setText("Something broke");
    }

    //Print current game progess (ex = _ _ _ _ _)
    ui->label_CorrectGuesses->setText(mainGame.progressString());

    if(ui->rb_tries->isChecked()){
        ui->lcd_Timer->display(QString::number(mainGame.getGuessCount()));
    }

    //clear input so they don't have to space;
    ui->le_guessInput->setText("");
}

void MainWindow::on_pb_openFileMenu_clicked()
{
    libraryeditor LibraryEditorUi;
    //LibraryEditorUi.activateWindow();
    LibraryEditorUi.setModal(true);
    LibraryEditorUi.exec();
}
