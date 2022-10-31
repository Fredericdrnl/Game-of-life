#include "stats.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <time.h>

using namespace std;

// DOURNEL Frédéric TP-B

// Compte le nombre de cellules vivantes
int Stats::getNb1(vector<vector<int>> tab){
    int compteur = 0;
    for ( int i = 0; i < tab.size() ; i++ ) {
        for (int j = 0; j < tab[i].size(); j++) {
            if (tab[i][j] == 1){
                compteur += 1;
            }
        }
    }
    return compteur;
}

int Stats::pourcentage1(vector<vector<int>> tab){
    Stats s = Stats();
    int nb1 = s.getNb1(tab);
    int resultat = nb1 * 100 / (tab.size() * tab[0].size());
    return resultat;
}
