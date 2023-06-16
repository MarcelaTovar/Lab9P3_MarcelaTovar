#pragma once
#include<iostream>
#include<fstream>
#include "UsuarioPaypal.h"
using namespace std;
class AdministradoradeArchivos{
public:
	void escribirArchivo(string,UsuarioPaypal*);
	void leerArchivo(string);
};

