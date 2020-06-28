#include "mainwindow.h"

#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>

#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    //Make it so we cannot resize
    w.setFixedSize(w.size());

    //Set image
    QPixmap splashImage(":/images/splash.png");

    //Fill the images with a white color
    //SplashImage.fill(Qt::white);

    //Create a splashscreen image and hold the image on top of all other windows
    QSplashScreen HangmanSplashScreen(splashImage, Qt::WindowStaysOnTopHint);

    //Display spash screen
    HangmanSplashScreen.show();

    //Hold Splashscreen open until user clicks mouse
    a.processEvents();

    //If used will hold the splashscreen on the screen for 5 seconds
    QTimer::singleShot(1500, &HangmanSplashScreen, SLOT(close())); // keep displayed for 5 seconds



    w.show();

    return a.exec();
}


