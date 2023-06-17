#include "Wallet.h"
Wallet::Wallet(){}
Wallet::Wallet(string user, string _contra, UsuarioPaypal* _cuentaPaypal) {
	this->Usuario = user;
	this->contra = _contra;
	this->userPaypal = _cuentaPaypal;
}
void Wallet::compra() {
	int escoger = 0;
	cout << "Ingrese que desea comprar: " << endl;
	cout << "1. Dodge coin" << endl;
	cout << "2. Etherium" << endl;
	cout << "3. WalterCoin" << endl;
	cin >> escoger;
	if (escoger == 1) {
		if (this->userPaypal->dinero > 0.6) {
			userPaypal->dinero = userPaypal->dinero - 0.6;
			cout << "Compra exitosa" << endl;
		}
		else {
			cout << "No hay suficientes fondos" << endl;
		}
	}
	else if (escoger == 2) {
		if (this->userPaypal->dinero > 1000) {
			userPaypal->dinero = userPaypal->dinero - 1000;
			cout << "Compra exitosa" << endl;
		}
		else {
			cout << "No hay suficientes fondos" << endl;
		}
	}
	else if (escoger == 3) {
		if (this->userPaypal->dinero > 0.6) {
			userPaypal->dinero = userPaypal->dinero - 0.6;
			cout << "Compra exitosa" << endl;
		}
		else {
			cout << "No hay suficientes fondos" << endl;
		}
	}
	else {
		cout << "Escoja una opcion valida" << endl;
	}
}
void Wallet::vender() {
	int escoger = 0;
	int cantidad = 0;
	cout << "Ingrese que desea vender: " << endl;
	cout << "1. Dodge coin" << endl;
	cout << "2. Etherium" << endl;
	cout << "3. WalterCoin" << endl;
	cin >> escoger;
	cout << "Cuanto desea vender?" << endl;
	cin >> cantidad;
	if (escoger == 1) {
		if (this->userPaypal->dinero > 0.6) {
			userPaypal->dinero = userPaypal->dinero + ((cantidad*0.6));
			cout << "venta exitosa" << endl;
		}
		else {
			cout << "No hay suficientes fondos" << endl;
		}
	}
	else if (escoger == 2) {
		if (this->userPaypal->dinero > 1000) {
			userPaypal->dinero = userPaypal->dinero + ((cantidad * 1000));
			cout << "venta exitosa" << endl;
		}
		else {
			cout << "No hay suficientes fondos" << endl;
		}
	}
	else if (escoger == 3) {
		if (this->userPaypal->dinero > 5) {
			userPaypal->dinero = userPaypal->dinero + ((cantidad * 5));
			cout << "venta exitosa" << endl;
		}
		else {
			cout << "No hay suficientes fondos" << endl;
		}
	}
	else {
		cout << "Escoja una opcion valida" << endl;
	}
}
