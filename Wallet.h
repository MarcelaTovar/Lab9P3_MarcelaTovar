#pragma once
#include <iostream>
#include <string>
#include "UsuarioPaypal.h"
using namespace std;
class Wallet{
public:
	string Usuario;
	//UsuarioPaypal* userPaypal;
	string contra;
	void compra();
	//Wallet(string , string , UsuarioPaypal* );
};

