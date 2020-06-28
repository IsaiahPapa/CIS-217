#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>
#include <QObject>

class myTimer : public QObject
{
    Q_OBJECT
public:
    myTimer();
    QTimer *timer;

public slots:
    void myTimerSlot();
};

#endif // MYTIMER_H
