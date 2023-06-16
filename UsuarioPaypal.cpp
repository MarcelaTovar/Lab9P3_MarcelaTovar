#include "UsuarioPaypal.h"
UsuarioPaypal::UsuarioPaypal(string nombre, string id, string contrasenia,int dinero) {
	this->nombreUsuario = nombre;
	this->numeroIdentidad = id;
	this->contra = contrasenia;
	this->dinero = dinero;
}
UsuarioPaypal::UsuarioPaypal(){}