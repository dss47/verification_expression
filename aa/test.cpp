#include <iostream>
using namespace std;


bool expressionValide(string expr);

int main() {

    if(expressionValide("1+2)")){
        cout << "Valide" << endl;
    }else{
        cout << "Invalide" << endl;
    }
    return 0;
}