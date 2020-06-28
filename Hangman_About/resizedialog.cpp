#include "resizedialog.h"
#include "ui_resizedialog.h"
#include "mainwindow.h"
#include <QDesktopWidget>

#include <QApplication>
#include <QDateTime>


//https://justcheckingonall.wordpress.com/2013/11/27/get-mainwindow-qt/
//I needed to get the pointer of the main window to be able to change the window dimensions.
QMainWindow* getMainWindow()
{
    QWidgetList widgets = qApp->topLevelWidgets();
    for (QWidgetList::iterator i = widgets.begin(); i != widgets.end(); ++i)
        if ((*i)->objectName() == "MainWindow")
            return (QMainWindow*) (*i);
    return NULL;
}

ResizeDialog::ResizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResizeDialog)
{
    ui->setupUi(this);
}

ResizeDialog::~ResizeDialog()
{
    delete ui;
}

void ResizeDialog::on_buttonBox_accepted()
{

    QMainWindow *m = getMainWindow();

    int inputWidth = ui->input_width->text().toInt();
    int inputHeight = ui->input_height->text().toInt();

    m->setFixedSize(inputWidth, inputHeight);
    m->adjustSize();


}
