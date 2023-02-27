#include "mascene.h"
#include <QTimer>


MaScene::MaScene(QObject *parent) : QGraphicsScene(parent)
//Stockage de donnée
{
    this->tab = Tableau(50, 50, "random", false);
    setSceneRect(0, 0, this->tab.getN() * 10, this->tab.getM() * 10);
}

MaScene::~MaScene(){

  for (int i = 0; m_items.size(); i++){
      delete m_items.at(i);
  }
}

void MaScene::UpdateScene()
{
    Gestion g = Gestion();
    tab.setTab(g.Transition(tab));
    for (int i = 0; i < tab.getTab().size(); i++)
    {
        for (int j = 0; j < tab.getTab()[i].size(); j ++){
            if (tab.getTab()[i][j] == 1){
                MonRect* item = new MonRect(Qt::blue);
                item->setPos(i*10, j*10);
                m_items.append(item);
                addItem(item);
            }else{
                MonRect* item = new MonRect(Qt::white);
                item->setPos(i*10, j*10);
                m_items.append(item);
                addItem(item);
            }
        }
    }
}
