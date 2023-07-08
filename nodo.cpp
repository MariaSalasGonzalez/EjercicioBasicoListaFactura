#include "nodo.h"

nodo::nodo(linea * line, nodo * sig){
	this->line = line;
	this->sig = sig;
}

nodo * nodo::getSig(){
	return sig;
}

linea * nodo::getDato(){
	return line;
}

void nodo::setSig(nodo * sig){
	this->sig = sig;
}

nodo::~nodo(){
	delete line;
}
