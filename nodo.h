#pragma once
#include "linea.h"

class nodo {
private:
	linea * line;
	nodo * sig;

public:
	nodo(linea*, nodo*);
	nodo* getSig();
	linea* getDato();
	void setSig(nodo*);
	~nodo();
};