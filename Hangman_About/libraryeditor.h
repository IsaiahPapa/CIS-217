#ifndef LIBRARYEDITOR_H
#define LIBRARYEDITOR_H

#include <QDialog>

namespace Ui {
class libraryeditor;
}

class libraryeditor : public QDialog
{
    Q_OBJECT

public:
    explicit libraryeditor(QWidget *parent = nullptr);
    ~libraryeditor();

private slots:
    void on_pb_Exit_clicked();

    void on_pb_Save_clicked();

    void on_pb_Load_clicked();

private:
    Ui::libraryeditor *ui;
};

#endif // LIBRARYEDITOR_H
