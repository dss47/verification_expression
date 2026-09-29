// PileTableau.h : pile generique avec un tableau dynamique
#ifndef PILE_TABLEAU_H
#define PILE_TABLEAU_H

#include <iostream>
using namespace std;

template <typename T>
class PileTableau {
private:
    T* tab;        
    int capacite;  
    int sommet;    

    void agrandir() {
        int nouvelleCapacite = capacite * 2;
        T* nouveau = new T[nouvelleCapacite];
        for (int i = 0; i <= sommet; i++) {
            nouveau[i] = tab[i];
        }
        delete[] tab;
        tab = nouveau;
        capacite = nouvelleCapacite;
    }

public:
    PileTableau(int cap = 10) {
        capacite = cap;
        sommet = -1;
        tab = new T[capacite];
    }

    ~PileTableau() {
        delete[] tab;
    }

    void empiler(T valeur) {
        if (estPleine()) {
            agrandir();
        }
        sommet = sommet + 1;
        tab[sommet] = valeur;
    }

    void depiler() {
        if (estVide()) {
            cout << "Erreur : pile vide !" << endl;
            return;
        }
        sommet = sommet - 1;
    }

    T tete() {
        return tab[sommet];
    }

    bool estVide() {
        return sommet == -1;
    }

    bool estPleine() {
        return sommet + 1 == capacite;
    }

    int taille() {
        return sommet + 1;
    }
};

#endif
