#include "tableau.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

// DOURNEL Frédéric TP-B

// Constructeur par défaut
Tableau::Tableau(){
    this->m=0;
    this->n=0;
    vector<vector<int>> tab(this->n);
    this->tab = tab;
    this->tore = tore;
}


Tableau::Tableau(const Tableau &t){
    this->n = t.n;
    this->m = t.m;
    this->tab = t.tab;
    this->tore = tore;
}

// Constructeur avec les différents types de tableau
Tableau::Tableau(const int n, const int m, const string type ,const bool tore){
    this->m = m;
    this->n = n;
    this->tore = tore;
    if (type == "0"){
        vector<vector<int>> tab(this->n);
        for ( int i = 0; i < this->n ; i++ ) {
            vector<int> temp(this->m, 0);
            tab[i] = temp;
        }
    this->tab = tab;
    }
    if (type == "1"){
        vector<vector<int>> tab(this->n);
        for ( int i = 0; i < this->n ; i++ ) {
            vector<int> temp(this->m, 1);
            tab[i] = temp;
        }
        this->tab = tab;
    }
    if (type == "damier"){
        vector<vector<int>> tab(this->n);
        int taille_tab = tab.size();
        for ( int i = 0; i < taille_tab ; i++ ) {
            vector<int> temp(this->m);
            int taille_temp = temp.size();
            for (int j = 0; j < taille_temp; j++ ) {
                if (i % 2 == 0){
                    if (j % 2 != 0){
                        temp[j] = 1;
                    }else{
                        temp[j] = 0;
                    }
                }else{
                    if (j % 2  == 0) {
                        temp[j] = 1;
                    }else{
                        temp[j] = 0;
                    }
                }
            }
            tab[i] = temp;
        }
        this->tab = tab;
    }
    if (type == "random"){
        srand (time(NULL));
        vector<vector<int>> tab(this->n);
        for ( int i = 0; i < this->n ; i++ ) {
            vector<int> temp(this->m);
            for (int j = 0; j < this->m ; j++ ) {
            int nb = (rand() % 2);
            temp[j] = nb;
            }
            tab[i] = temp;
        }
        this->tab = tab;
    }
}

//Constructeur avec liste
Tableau::Tableau(const int n, const int m, const vector<vector<int>> coord, const bool tore){
    this->m= m;
    this->n= n;
    this->tore = tore;
    vector<vector<int>> tab(this->n);
    for ( int i = 0; i < tab.size() ; i++ ) {
        vector<int> temp(this->m);
        tab[i] = temp;
    }
    for ( int j = 0; j < coord.size() ; j++ ) {
        tab[coord[j][0]][coord[j][1]] = 1;

    }
    this->tab = tab;
}

// Setter tab
void Tableau::setTab(Tableau t){
    this->m = t.m;
    this->n = t.n;
    this->tab = t.tab;
}

// Setter case in tab
void Tableau::setCase(int x, int y, int val){
    this->tab[x][y] = val;
}

// Getter tore
bool Tableau::getTore(){
    return this->tore;
}

// Getter case in tab
int Tableau::getCase(int x, int y){
    return this->tab[x][y];
}

// Getter M
int Tableau::getM(){
    return this->m;
}

// Getter N
int Tableau::getN(){
    return this->n;
}


// Getter Tab
vector<vector<int>> Tableau::getTab(){
    return this->tab;
}

// Affichage
void Tableau::affichage() const
{
    for ( int i = 0; i < this->tab.size() ; i++ ) {
        for (int j = 0; j < this->tab[i].size(); j++) {
            std::cout << tab[i][j] << ' ';
        }
        std::cout <<  std::endl;
    }
    std::cout <<  std::endl;
}
