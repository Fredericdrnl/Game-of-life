#include <iostream>
#include <vector>
#include <string>
#ifndef TABLEAU_H

using namespace std;

// DOURNEL Frédéric TP-B

class Tableau{
    private:
        int n;
        int m;
        bool tore;
        vector<vector<int>> tab;
    public:
        Tableau(); // Constructeur par defaut
        Tableau(const Tableau &t); // Constructeur par copie
        Tableau(const int n, const int m, const string type ,const bool tore); // Constructeur avec soit que des 1, que des 0, nbr randrom, damier
        Tableau(const int n, const int m, const vector<vector<int>> coord, const bool tore);
        void setTab(Tableau t);
        void setCase(int x, int y, int val);
        int getCase(int x, int y);
        bool getTore();
        int getN();
        int getM();
        vector<vector<int>> getTab();
        void affichage() const;
};
#endif //TABLEAU_H
