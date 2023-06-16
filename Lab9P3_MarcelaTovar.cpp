#include <iostream>
#include "Paypal.h"
using namespace std;
void crear() {
    Paypal* p = new Paypal();
    p->crearUsuario();
}
void menu() {
    bool check = true;
    int opcion = 0;
    do {
        cout << "---MENU---" << endl;
        cout << "1. Crear cuenta de PayPal"<<endl;
        cout << "2. Crear Wallet" << endl;
        cout << "3. Cargar informacion" << endl;
        cout << "4. Acceder a PayPal" << endl;
        cout << "5. Acceder a Wallet" << endl;
        cout << "6. Salir" << endl;
        cout << "Que desea hacer?" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            crear();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            check = false;
            break;
        default:
            cout << "Escoja una opcion valida" << endl;
            break;
        }
    } while (check);
    cout << "Bye bye! :D" << endl;
}
int main(){
    menu();
}


