#include "AdministradoradeArchivos.h"
//Escribir el archivo
void AdministradoradeArchivos::escribirArchivo(string id, UsuarioPaypal* a) {
	string temp = id + ".lab";
	fstream archive(temp, ios::binary | ios::out);
	archive.write((char*)a, sizeof(a));
	archive.close();
}
//Leer el archivo
void AdministradoradeArchivos::leerArchivo(string id) {
	string temp = id + ".lab";
	fstream archive(temp, ios::binary | ios::in);
	UsuarioPaypal aux;
	while (archive.read((char*)&aux,sizeof(aux))) {
		cout << "Usuario: " << aux.nombreUsuario;
		cout << "Numero de Identidad" << aux.numeroIdentidad;
		cout << "Contrasenia: " << aux.contra;
		cout << "Cuenta Bancaria: " << aux.dinero;
	}
	archive.close();
}
