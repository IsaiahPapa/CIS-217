#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

public slots:
     void aboutButton_clicked();
     void UpdateClock();

private slots:
     void on_pb_Resize_clicked();
     void on_pb_Play_clicked();
     void on_le_guessInput_returnPressed();
     void on_pb_openFileMenu_clicked();
};
#endif // MAINWINDOW_H
