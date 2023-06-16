#pragma once
#include <iostream>
#include <string>
using namespace std;
class UsuarioPaypal{
public:
	string nombreUsuario;
	int numeroIdentidad;
	string contra;
	UsuarioPaypal(string,int,string);
	UsuarioPaypal();
};

