#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include "Wallet.h"
using namespace std;
class UsuarioPaypal {
public:
	string nombreUsuario;
	string numeroIdentidad;
	string contra;
	int dinero;
	//vector<Wallet*>wallets;
	vector<string>historial;
	UsuarioPaypal(string, string, string, int);
	UsuarioPaypal();
};
