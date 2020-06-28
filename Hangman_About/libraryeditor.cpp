#include "libraryeditor.h"
#include "ui_libraryeditor.h"

#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

libraryeditor::libraryeditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::libraryeditor)
{
    ui->setupUi(this);
}

libraryeditor::~libraryeditor()
{
    delete ui;
}

void libraryeditor::on_pb_Exit_clicked()
{
    this->close();
}

void libraryeditor::on_pb_Save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Open Word Library"), "",
            tr("Library (*.txt);;All Files (*)"));

        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);

        QString data = ui->txt_Library->toPlainText();
        QStringList strList = data.split(QRegExp("[\n]"),QString::SkipEmptyParts);

        for (int i = 0; i < strList.size(); ++i)
             out << strList.at(i).toLocal8Bit().constData() << Qt::endl;

}

void libraryeditor::on_pb_Load_clicked()
{
        QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Word Library"), "",
            tr("Library (*.txt);;All Files (*)"));

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);


        while (!in.atEnd()) {
            ui->txt_Library->append(in.readLine());
           // process_line(line);
        }

       file.close();
}
