#include <iostream>
#include "Paypal.h"
#include "UsuarioPaypal.h"
#include "Wallet.h"
#include <vector>
using namespace std;
void crear() {
    Paypal* p = new Paypal();
    p->crearUsuario();
}
void crearWallet() {
    string user, contra;
    string userPaypal;
    cout << "Ingrese el usuario de la cuenta vinculada: " << endl;
    cin >> userPaypal;
    cout << "Ingrese el usuario: " << endl;
    cin >> user;
    cout << "Ingrese la contrasenia: " << endl;
    cin >> contra;
}
void menu() {
    string usuarioIniciarPaypal;
    string contraIniciarPaypal;
    bool check = true;
    int opcion = 0;
    bool checking = true;
    bool terminarSubMenuPay = true;
    Paypal* p = new Paypal();
    string user, contra;
    string userPaypal;
    vector<Wallet*>wallets;
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
        case 1: {
            p->crearUsuario();
            break;
        }
        case 2: {
            UsuarioPaypal* temp = new UsuarioPaypal();
            cout << "Ingrese el usuario de la cuenta vinculada: " << endl;
            cin >> userPaypal;
            for (size_t i = 0; i < p->usuarios.size(); i++){
                if (p->usuarios.at(i)->nombreUsuario == userPaypal){
                    temp = p->usuarios.at(i); check = false;
                }
            }
            
            cout << "Ingrese el usuario: " << endl;
            cin >> user;
            cout << "Ingrese la contrasenia: " << endl;
            cin >> contra;
            Wallet* w = new Wallet(user,contra,temp);
            wallets.push_back(w);
            
            break;
        }
        case 3:
            
           
            break;
        case 4: {
            checking = true;
            cout << "Ingrese su usuario: " << endl;
            cin >> usuarioIniciarPaypal;
            cout << "Ingrese su contra: " << endl;
            cin >> contraIniciarPaypal;
            for (size_t i = 0; i < p->usuarios.size(); i++){
                if (p->usuarios.at(i)->nombreUsuario == usuarioIniciarPaypal){
                    if (p->usuarios.at(i)->contra == contraIniciarPaypal) {
                        checking = false;
                    }
                }
            }
            if (checking) {
                cout << "Usuario o contrasenia incorrectos" << endl;
            }
            else {
                do {
                    cout << "---BIENVENIDO---" << endl;
                    cout << "1. Ver estado de cuenta" << endl;
                    cout << "2. Hacer deposito a mi propia cuenta" << endl;
                    cout << "3. Hacer retiro a mi propia cuenta" << endl;
                    cout << "4. Ver historial de cuenta" << endl;
                    cout << "5. Salir" << endl;
                } while (check);
            }
            break;
        }
            
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


