#include "mainwindow.h"
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    :  QMainWindow(parent)
{
    setWindowTitle("Jeu de la Vie");

    //TIMER
      // create a timer
      QTimer *timer = new QTimer(this);
      // setup signal and slot
      timer->setInterval(100);
      QObject::connect(timer, SIGNAL(timeout()),
            this, SLOT(Update()));
      // msec
      timer->start(10);


  //SETUP FEN
    m_view = new QGraphicsView(this);
    m_scene = new MaScene(m_view);

    m_view->setScene(m_scene);
    m_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    m_view ->centerOn(0, 0);
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCentralWidget(m_view);

}

void MainWindow::Update()
{
    m_scene->UpdateScene();
    qDebug() << "update";
}


