// test_piles.cpp : menu interactif empiler / depiler
#include <iostream>
#include <string>
#include "PileTableau.h"
#include "PileChainee.h"
using namespace std;

void afficherMenu()
{
    cout << "1. Empiler" << endl;
    cout << "2. Depiler" << endl;
    cout << "3. Voir tete" << endl;
    cout << "4. Taille" << endl;
    cout << "5. Quitter" << endl;
    cout << "Choix : ";
}

void menuTableau()
{
    PileTableau<int> p;
    int choix = 0, x;
    while (choix != 5)
    {
        afficherMenu();
        cin >> choix;
        switch (choix)
        {
        case 1:
            cout << "Nombre : ";
            cin >> x;
            p.empiler(x);
            break;
        case 2:
            p.depiler();
            cout << "Depile !" << endl;
            break;
        case 3:
            if (p.estVide())
                cout << "Pile vide !" << endl;
            else
                cout << "tete = " << p.tete() << endl;
            break;
        case 4:
            cout << "taille = " << p.taille() << endl;
            break;
        case 5:
            cout << "Au revoir !" << endl;
            break;
        default:
            cout << "Choix invalide !" << endl;
            break;
        }
    }
}

void menuChainee()
{
    PileChainee<int> p;
    int choix = 0, x;
    while (choix != 5)
    {
        afficherMenu();
        cin >> choix;

        switch (choix)
        {
        case 1:
            cout << "Nombre : ";
            cin >> x;
            p.empiler(x);
            break;
        case 2:
            p.depiler();
            cout << "Depile !" << endl;
            break;
        case 3:
            if (p.estVide())
                cout << "Pile vide !" << endl;
            else
                cout << "tete = " << p.tete() << endl;
            break;
        case 4:
            cout << "taille = " << p.taille() << endl;
            break;
        case 5:
            cout << "Au revoir !" << endl;
            break;
        default:
            cout << "Choix invalide !" << endl;
            break;
        }
    }
}

int main()
{
    int type = 0;
    cout << "============== MENU PRINCIPAL ==============" << endl;
    cout << "1. Pile tableau" << endl;
    cout << "2. Pile chainee" << endl;
    cout << "Choix : ";
    cin >> type;
    switch (type)
    {
    case 1:
        menuTableau();
        break;
    case 2:
        menuChainee();
        break;
    default:
        cout << "Choix invalide !" << endl;
        break;
    }
    return 0;
}
