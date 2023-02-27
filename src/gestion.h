#include <iostream>
#include <vector>
#include "tableau.h"
#ifndef GESTION_H

using namespace std;

// DOURNEL Frédéric TP-B

class Gestion{

    public:
        bool verifCoord(Tableau t, int x, int y);
        vector<int> verifCoordTore(Tableau t, int x, int y);
        vector<int> getHaut(Tableau t, int x, int y);
        vector<int> getBas(Tableau t, int x, int y);
        vector<int> getGauche(Tableau t, int x, int y);
        vector<int> getDroite(Tableau t, int x, int y);
        vector<int> getHautG(Tableau t, int x, int y);
        vector<int> getHautD(Tableau t, int x, int y);
        vector<int> getBasG(Tableau t, int x, int y);
        vector<int> getBasD(Tableau t, int x, int y);
        int getNbVoisin(Tableau &t, int x, int y);
        vector<vector<int>> getTabVoisin(Tableau &t);
        Tableau Transition(Tableau t);
};
#endif //GESTION_H

