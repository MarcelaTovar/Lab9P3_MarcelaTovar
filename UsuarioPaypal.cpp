#include "UsuarioPaypal.h"
UsuarioPaypal::UsuarioPaypal(string nombre, int id, string contrasenia) {
	this->nombreUsuario = nombre;
	this->numeroIdentidad = id;
	this->contra = contrasenia;
}
UsuarioPaypal::UsuarioPaypal(){}