// verification.cpp : verifie si une expression est correcte
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool correspond(char ouvrante, char fermante) {
    if (ouvrante == '(' && fermante == ')') {
        return true;
    }
    if (ouvrante == '[' && fermante == ']') {
        return true;
    }
    if (ouvrante == '{' && fermante == '}') {
        return true;
    }
    return false;
}

bool estOperateur(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
        return true;
    }
    return false;
}

bool estChiffre(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool expressionValide(string expr) {
    stack<char> pile;
    bool attendNombre = true; // au debut on attend un nombre ou '('

    for (int i = 0; i < (int)expr.length(); i++) {
        char c = expr[i];

        if (c == ' ') {
            continue; // on ignore les espaces
        }
        if (estChiffre(c)) {
            if (attendNombre == false) {
                return false; // deux nombres avec un espace et sans operateur
            }
            // si le nombre a plusieurs chiffres (ex: 123), on les saute
            while (i + 1 < (int)expr.length() && estChiffre(expr[i + 1])) {
                i++;
            }
            attendNombre = false; // apres un nombre, on veut operateur ou ')'
        }
        else if (c == '(' || c == '[' || c == '{') {
            if (attendNombre == false) {
                return false; // ex: "3(" il manque un operateur
            }
            pile.push(c);
            attendNombre = true; // apres '(' on attend un nombre
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (pile.empty()) {
                return false; // on ferme sans avoir ouvert
            }
            if (attendNombre == true) {
                return false; // "()" vide -> faux
            }
            char ouv = pile.top();
            if (correspond(ouv, c) == false) {
                return false; // "(]" -> faux
            }
            pile.pop();
            attendNombre = false; // apres ')' c'est comme apres un nombre
        }
        else if (estOperateur(c)) {
            if (attendNombre == true) {
                // on accepte le moins du debut : "-5"
                if (c != '-') {
                    return false; // "3++4" -> faux
                }
            } else {
                attendNombre = true; // apres '+' on attend un nombre
            }
        }
        else {
            return false; // lettre ou caractere interdit
        }
    }

    // a la fin : tout doit etre ferme, et on ne finit pas par '+'
    if (!pile.empty() || attendNombre) return false;
    return true;
}

int main() {
    string expr;
    cout << "Entrez une expression (vide / q = quitter) : " << endl;
    while (true) {
        cout << "> ";
        getline(cin, expr);
        if (expr == "" || expr == "q") {
            cout << "Au revoir !" << endl;
            break;
        }
        if (expressionValide(expr)) {
            cout << "Expression VALIDE" << endl;
        } else {
            cout << "Expression INVALIDE" << endl;
        }
    }
    return 0;
}
