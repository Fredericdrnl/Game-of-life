#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QObject>
#include <QWidget>


class customWidget : public QWidget
{
    Q_OBJECT
public:
    explicit customWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // CUSTOMWIDGET_H
