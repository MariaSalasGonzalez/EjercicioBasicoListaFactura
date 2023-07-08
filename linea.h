#pragma once
#include "tipoArticulo.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class linea {
private:
	tipoArticulo * art;
	int cantidad;
	
public:
	linea(tipoArticulo*, int);
	string toString();
	int getCantidad();
	double getPrecioUnitarioConDescuento();
	double getPrecioUnitarioSinDescuento();
	double getPrecioLineaTotal();
	static linea* recuperar(ifstream&);
	virtual void guardar(ofstream&);
};