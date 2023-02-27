#ifndef MASCENE_H
#define MASCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "monrect.h"
#include "gestion.h"

class MaScene : public QGraphicsScene
{
private:
    Tableau tab;
public:
    MaScene(QObject *parent = Q_NULLPTR);
    ~MaScene();
    void UpdateScene();

    QList<MonRect*> m_items;
};

#endif // MASCENE_H
