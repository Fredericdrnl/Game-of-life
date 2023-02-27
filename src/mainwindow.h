#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsView>
#include "mascene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
private:
   QGraphicsView* m_view;
   MaScene* m_scene;

private slots:
    void Update();
};

#endif // MAINWINDOW_H
