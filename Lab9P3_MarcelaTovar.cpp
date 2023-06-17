#include <iostream>
#include "Paypal.h"
#include "UsuarioPaypal.h"
#include "Wallet.h"
#include <vector>
#include <iomanip>
using namespace std;
//Metodo de crear
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
//Menu principal
void menu() {
    string path = "./";
    string ext = ".lab";
    int cantidadDeposito = 0;
    int cantidadRetiro = 0;
    string usuarioIniciarPaypal;
    string contraIniciarPaypal;
    bool check = true;
    int opcion = 0;
    bool checking = true;
    bool terminarSubMenuPay = true;
    bool terminarSubMenuWallet = true;
    int submenu1 = 0;
    int submenu2 = 0;
    bool revisarEx = true;
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
            //Crear Wallet
            UsuarioPaypal* temp = new UsuarioPaypal();
            cout << "Ingrese el usuario de la cuenta vinculada: " << endl;
            cin >> userPaypal;
            for (size_t i = 0; i < p->usuarios.size(); i++) {
                if (p->usuarios.at(i)->nombreUsuario == userPaypal) {
                    temp = p->usuarios.at(i);
                    revisarEx = false;
                }
            }
            if (revisarEx){
                cout << "Usuario no encontrado";
            }
            else {
                cout << "Ingrese el usuario: " << endl;
                cin >> user;
                cout << "Ingrese la contrasenia: " << endl;
                cin >> contra;
                Wallet* w = new Wallet(user, contra, temp);
                wallets.push_back(w);
            }

            break;
        }
        case 3:
            
            p->Admin->leerArchivo((path));
            break;
        case 4: {
            UsuarioPaypal* temp = new UsuarioPaypal();
            checking = true;
            cout << "Ingrese su identidad: " << endl;
            cin >> usuarioIniciarPaypal;
            cout << "Ingrese su contra: " << endl;
            cin >> contraIniciarPaypal;
            for (size_t i = 0; i < p->usuarios.size(); i++) {
                if (p->usuarios.at(i)->numeroIdentidad == usuarioIniciarPaypal) {
                    if (p->usuarios.at(i)->contra == contraIniciarPaypal) {
                        temp = p->usuarios.at(i);
                        checking = false;
                    }
                }
            }
            if (checking) {
                cout << "Usuario o contrasenia incorrectos" << endl;
            }
            else {
                terminarSubMenuPay = true;
                do {
                    cout << "---BIENVENIDO---" << endl;
                    cout << "1. Ver estado de cuenta" << endl;
                    cout << "2. Hacer deposito a mi propia cuenta" << endl;
                    cout << "3. Hacer retiro a mi propia cuenta" << endl;
                    cout << "4. Ver historial de cuenta" << endl;
                    cout << "5. Salir" << endl;
                    cin >> submenu1;
                    if (submenu1 == 1) {
                        cout << "Su dinero es: " << temp->dinero;
                    }
                    else if (submenu1 == 2) {
                        cout << "De que cantidad desea el deposito: " << endl;
                        cin >> cantidadDeposito;
                        temp->dinero = temp->dinero + cantidadDeposito;
                        cout << "Deposito realizado con exito!" << endl;
                        string h = "Se ha depositado" + cantidadDeposito;
                        temp->historial.push_back(h);
                    }
                    else if (submenu1 == 3) {
                        cout << "De cuanto desea el retiro: " << endl;
                        cin >> cantidadRetiro;
                        temp->dinero = temp->dinero - cantidadRetiro;
                        string h = "Se ha retirado" + cantidadRetiro;
                        temp->historial.push_back(h);
                    }
                    else if (submenu1 == 4) {
                        for (size_t i = 0; i < temp->historial.size(); i++) {
                            cout << temp->historial.at(i) << endl;
                        }
                    }
                    else if (submenu1 == 5) {
                        terminarSubMenuPay = false;
                    }
                } while (terminarSubMenuPay);
            }
            break;
        }
        //Acceder a Wallet
        case 5:{
            Wallet * temp = new Wallet();
            checking = true;
            cout << "Ingrese su usuario Wallet: " << endl;
            cin >> usuarioIniciarPaypal;
            cout << "Ingrese su Wallet: " << endl;
            cin >> contraIniciarPaypal;
            for (size_t i = 0; i < wallets.size(); i++) {
                if (wallets.at(i)->Usuario == usuarioIniciarPaypal) {
                    if (wallets.at(i)->contra == contraIniciarPaypal) {
                        temp = wallets.at(i);
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
                    cout << "2. Comprar Cryptos" << endl;
                    cout << "3. Vender Cryptos" << endl;
                    cout << "4. Salir" << endl;
                    cin >> submenu2;
                    if (submenu2 == 1) {
                        cout << "Tu estado de cuenta es: " << temp->userPaypal->dinero;
                    }
                    else if (submenu2 == 2) {
                        temp->compra();
                    }
                    else if (submenu2 == 3) {
                        temp->vender();
                        string h = "Se ha depositado" + temp->cantidadVendida;
                        temp->userPaypal->historial.push_back(h);
                    }
                    else if (submenu2 == 4) {
                        terminarSubMenuWallet = false;

                    }
                } while (terminarSubMenuWallet);
            }
        }
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
    //Liberar memoria
    for (size_t i = 0; i < p->usuarios.size(); i++) {
        delete p->Admin;
        delete p->usuarios.at(i);
    }for (size_t i = 0; i < wallets.size(); i++)
    {
        delete wallets.at(i);
    }
}
int main(){
    menu();
}


