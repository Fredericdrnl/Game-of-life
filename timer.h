#ifndef TIMER_H
#define TIMER_H
#include <QTimer>
#include <mascene.h>


class Timer : public QObject
{
    Q_OBJECT
public:
    Timer();
    QTimer *timer;

private slots:
    void Update();
};

#endif // TIMER_H
