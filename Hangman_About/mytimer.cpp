#include "mytimer.h"

myTimer::myTimer()
{
    timer =  new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(myTimerSlot()));
    timer->start(1000);
}

void myTimer::myTimerSlot(){

}
