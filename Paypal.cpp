#include "Paypal.h"
Paypal::Paypal(){}
void Paypal::crearUsuario() {
	bool revisar = false;
	string nombre,identidad,contrasenia;
	int dinero;
	cout << "Ingrese el nombre de usuario: " << endl;
	cin >> nombre;
	cout << "Ingrese el numero de identidad: " << endl;
	cin >> identidad;
	cout << "Ingrese la contrasenia: " << endl;
	cin >> contrasenia;
	cout << "Ingrese la cantidad de dinero inicial: " << endl;
	cin >> dinero;
	for (size_t i = 0; i < usuarios.size(); i++){
		if (usuarios.at(i)->nombreUsuario == nombre){
			revisar = true;
			break;
		}
		else if (usuarios.at(i)->numeroIdentidad == identidad) {
			revisar = true;
			break;
		}
		else if (usuarios.at(i)->contra == contrasenia) {
			revisar = true;
			break;
		}
		else if (contrasenia.size() < 8) {
			revisar = true;
		}
		for (size_t i = 0; i < contrasenia.size(); i++){
			if (!isalnum(contrasenia.at(i))) {
				revisar = true;
				break;
			}
		}
	}
	if (revisar) {
		cout << "Ese usuario/contrasenia/identidad no son validos" << endl;
	}
	else {
		UsuarioPaypal* us = new UsuarioPaypal(nombre, identidad, contrasenia,dinero);
		usuarios.push_back(us);
		Admin->escribirArchivo(identidad,us);
	}
	
}
