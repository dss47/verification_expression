// PileChainee.h : pile generique avec une liste chainee
#ifndef PILE_CHAINEE_H
#define PILE_CHAINEE_H

#include <iostream>
using namespace std;

template <typename T>
class PileChainee
{
private:
    struct Noeud
    {
        T valeur;
        Noeud *suivant;
    };
    Noeud *sommet; 
    int nb_elem; 

public:
    PileChainee()
    {
        sommet = nullptr;
        nb_elem = 0;
    }

    ~PileChainee()
    {
        while (sommet)
        {
            Noeud *tmp = sommet;
            sommet = sommet->suivant;
            delete tmp;
        }
    }

    void empiler(T valeur)
    {
        Noeud *elem = new Noeud;
        elem->valeur = valeur;
        elem->suivant = sommet;
        sommet = elem;
        nb_elem = nb_elem + 1;
    }

    void depiler()
    {
        if (estVide())
        {
            cout << "Erreur : pile vide !" << endl;
            return;
        }
        Noeud *tmp = sommet;
        sommet = sommet->suivant;
        delete tmp;
        nb_elem = nb_elem - 1;
    }

    T tete()
    {
        return sommet->valeur;
    }

    bool estVide()
    {
        return sommet == nullptr;
    }

    int taille()
    {
        return nb_elem;
    }
};

#endif
