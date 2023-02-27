#include "gestion.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

// DOURNEL Frédéric TP-B

// Verifie que les coordonnées sont bien dans le tableau
bool Gestion::verifCoord(Tableau t, int x, int y){
    bool resultat = true;
    if (x < 0){
        resultat = false;
    }
    if (x > t.getTab().size() - 1){
        resultat = false;
    }
    if (y < 0){
        resultat = false;
    }
    if (y > t.getTab().size() - 1){
        resultat = false;
    }
    return resultat;
}

// Verifie que les coordonnées sont bien dans le tableau
vector<int> Gestion::verifCoordTore(Tableau t, int x, int y){
    vector<int> resultat(2);
    if (x < 0){
        x = t.getTab().size() - 1;
    }
    if (x > t.getTab().size() - 1){
        x = 0;
    }
    if (y < 0){
        y = t.getTab()[0].size() - 1;
    }
    if (y > t.getTab().size() - 1){
        y = 0;
    }
    resultat[0] = x;
    resultat[1] = y;
    return resultat;
}

// GETTER VOISINS { HAUT, BAS, GAUCHE, DROITE, HAUT GAUCHE, HAUT DROITE, BAS GAUCHE, BAS DROITE}
vector<int> Gestion::getHaut(Tableau t, int x, int y){

    vector<int> resultat(2);
    resultat[0] = x - 1;
    resultat[1] = y;
    return resultat;
}
vector<int> Gestion::getBas(Tableau t, int x, int y){
    vector<int> resultat(2);
    resultat[0] = x + 1;
    resultat[1] = y;
    return resultat;
}
vector<int> Gestion::getGauche(Tableau t, int x, int y){
    vector<int> resultat(2);
    resultat[0] = x;
    resultat[1] = y - 1;
    return resultat;
}
vector<int> Gestion::getDroite(Tableau t, int x, int y){
    vector<int> resultat(2);
    resultat[0] = x;
    resultat[1] = y + 1;
    return resultat;
}
vector<int> Gestion::getHautG(Tableau t, int x, int y){
    vector<int> resultat(2);
    resultat[0] = x - 1;
    resultat[1] = y - 1;
    return resultat;
}
vector<int> Gestion::getHautD(Tableau t, int x, int y){
    vector<int> resultat(2);
    resultat[0] = x - 1;
    resultat[1] = y + 1;
    return resultat;
}
vector<int> Gestion::getBasG(Tableau t, int x, int y){
    vector<int> resultat(2);
    resultat[0] = x + 1;
    resultat[1] = y - 1;
    return resultat;
}
vector<int> Gestion::getBasD(Tableau t, int x, int y){
    vector<int> resultat(2);
    resultat[0] = x + 1;
    resultat[1] = y + 1;
    return resultat;
}

//Compte le nombre de voisins d'une case
int Gestion::getNbVoisin(Tableau &t, int x, int y){

    int compteur = 0;
    Gestion g = Gestion();

    //NON TORE
    if (t.getTore() == false){
        vector<int> voisins1 = g.getHaut(t, x, y);
        if (g.verifCoord(t, voisins1[0], voisins1[1]) == true){
                if (t.getTab()[voisins1[0]][voisins1[1]] == 1){
                    compteur = compteur + 1;
            }
        }
        vector<int> voisins2 = g.getBas(t, x, y);
        if (g.verifCoord(t, voisins2[0], voisins2[1]) == true){
            if (t.getTab()[voisins2[0]][voisins2[1]] == 1){
                compteur = compteur + 1;
            }
        }
        vector<int> voisins3 = g.getGauche(t, x, y);
        if (g.verifCoord(t, voisins3[0], voisins3[1]) == true){
            if (t.getTab()[voisins3[0]][voisins3[1]] == 1){
                compteur = compteur + 1;
            }
        }
        vector<int> voisins4 = g.getDroite(t, x, y);
        if (g.verifCoord(t, voisins4[0], voisins4[1]) == true){
            if (t.getTab()[voisins4[0]][voisins4[1]] == 1){
                compteur = compteur + 1;
            }
        }
        vector<int> voisins5 = g.getHautG(t, x, y);
        if (g.verifCoord(t, voisins5[0], voisins5[1]) == true){
            if (t.getTab()[voisins5[0]][voisins5[1]] == 1){
                compteur = compteur + 1;
            }
        }
        vector<int> voisins6 = g.getHautD(t, x, y);
        if (g.verifCoord(t, voisins6[0], voisins6[1]) == true){
            if (t.getTab()[voisins6[0]][voisins6[1]] == 1){
                compteur = compteur + 1;
            }
        }
        vector<int> voisins7 = g.getBasG(t, x, y);
        if (g.verifCoord(t, voisins7[0], voisins7[1]) == true){
            if (t.getTab()[voisins7[0]][voisins7[1]] == 1){
                compteur = compteur + 1;
            }
        }
        vector<int> voisins8 = g.getBasD(t, x, y);
        if (g.verifCoord(t, voisins8[0], voisins8[1]) == true){
            if (t.getTab()[voisins8[0]][voisins8[1]] == 1){
                compteur = compteur + 1;
            }
        }
    }

    //TORE
    else{
        vector<int> voisins1 = g.getHaut(t, x, y);
        vector<int> coordValides1 = g.verifCoordTore(t, voisins1[0], voisins1[1]);
        if (t.getTab()[coordValides1[0]][coordValides1[1]] == 1){
            compteur = compteur + 1;
        }

        vector<int> voisins2 = g.getBas(t, x, y);
        vector<int> coordValides2 = g.verifCoordTore(t, voisins2[0], voisins2[1]);
        if (t.getTab()[coordValides2[0]][coordValides2[1]] == 1){
            compteur = compteur + 1;
        }

        vector<int> voisins3 = g.getGauche(t, x, y);
        vector<int> coordValides3 = g.verifCoordTore(t, voisins3[0], voisins3[1]);
        if (t.getTab()[coordValides3[0]][coordValides3[1]] == 1){
            compteur = compteur + 1;
        }

        vector<int> voisins4 = g.getDroite(t, x, y);
        vector<int> coordValides4 = g.verifCoordTore(t, voisins4[0], voisins4[1]);
        if (t.getTab()[coordValides4[0]][coordValides4[1]] == 1){
            compteur = compteur + 1;
        }

        vector<int> voisins5 = g.getHautG(t, x, y);
        vector<int> coordValides5 = g.verifCoordTore(t, voisins5[0], voisins5[1]);
        if (t.getTab()[coordValides5[0]][coordValides5[1]] == 1){
            compteur = compteur + 1;
        }

        vector<int> voisins6 = g.getHautD(t, x, y);
        vector<int> coordValides6 = g.verifCoordTore(t, voisins6[0], voisins6[1]);
        if (t.getTab()[coordValides6[0]][coordValides6[1]] == 1){
            compteur = compteur + 1;
        }

        vector<int> voisins7 = g.getBasG(t, x, y);
        vector<int> coordValides7 = g.verifCoordTore(t, voisins7[0], voisins7[1]);
        if (t.getTab()[coordValides7[0]][coordValides7[1]] == 1){
            compteur = compteur + 1;
        }

        vector<int> voisins8 = g.getBasD(t, x, y);
        vector<int> coordValides8 = g.verifCoordTore(t, voisins8[0], voisins8[1]);
        if (t.getTab()[coordValides8[0]][coordValides8[1]] == 1){
            compteur = compteur + 1;
        }
    }
    return compteur;
}

//Renvoie un tableau un avec le nombre de voisins de chaque case
vector<vector<int>> Gestion::getTabVoisin(Tableau &t){
    Gestion g = Gestion();
    int taille = t.getTab().size();
    int taille2 = t.getTab()[0].size();
    vector<vector<int>> nvTab(taille);
    for (int i = 0; i < taille; i++){
        vector<int> temp(taille2);
        for (int j = 0; j < taille2; j++){
            int nb = g.getNbVoisin(t, i, j);
            temp[j] = nb;
        }
        nvTab[i] = temp;
    }
    return nvTab;
}

//Effectue la transition avec les conditions du jeu de la vie
Tableau Gestion::Transition(Tableau t){

    Gestion g = Gestion();
    vector<vector<int>> tabVoisins = g.getTabVoisin(t);

    Tableau new_tab = Tableau(t);
    int taille_tab = new_tab.getTab().size();
    for ( int i = 0; i < taille_tab ; i++ ) {
        int taille_tab2 = new_tab.getTab()[i].size();
        for (int j = 0; j < taille_tab2; j++ ) {
            if ( t.getTab()[i][j] == 1){
                if (tabVoisins[i][j] != 2 && tabVoisins[i][j] !=3){
                    t.setCase(i, j, 0);
                }
            }else{
                if (tabVoisins[i][j] == 3){
                    t.setCase(i, j, 1);
                }else{
                    t.setCase(i, j, 0);
                }
            }
        }
    }
    return t;
}


