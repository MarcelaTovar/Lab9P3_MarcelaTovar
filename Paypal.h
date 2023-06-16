#pragma once
#include "UsuarioPaypal.h"
#include "AdministradoradeArchivos.h"
#include <iostream>
#include <vector>
using namespace std;
class Paypal{
public:
	Paypal();
	vector<UsuarioPaypal*>usuarios;
	void crearUsuario();
	AdministradoradeArchivos* Admin;
};

