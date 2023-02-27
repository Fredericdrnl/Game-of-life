#include "timer.h"
#include <QTimer>
#include <QDebug>
#include "mainwindow.h"
#include "mascene.h"

Timer::Timer()
{
    //TIMER
      // create a timer
      QTimer *timer = new QTimer(this);
      // setup signal and slot
      timer->setInterval(100);
      QObject::connect(timer, SIGNAL(timeout()),
            this, SLOT(Update()));
      // msec
      timer->start(1000);
}

void Timer::Update()
{
    MaScene scene;
    scene.UpdateScene();
    qDebug() << "update";
}
