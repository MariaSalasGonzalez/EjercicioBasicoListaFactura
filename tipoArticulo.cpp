#include "tipoArticulo.h"

void tipoArticulo::setPorDescuento(double d) { porDescuento = d; }
double tipoArticulo::getPorDescuento() { return porDescuento; }

tipoArticulo::tipoArticulo(double p, string c, string n, int e){
	porDescuento = 0;
	precio = p;
	codigo = c;
	nombre = n;
	existencias = e;
}

string tipoArticulo::toString() {
	stringstream s;
	s << " Codigo: " << codigo << ", existencias: " << existencias<<", nombre: " << nombre << ", precio: " << precio;
	return s.str();
}

double tipoArticulo::getPrecio() {
	return precio;
}
double tipoArticulo::getPrecioConDescuento() {
	return precio -   (precio* (porDescuento/100));
}

string tipoArticulo::getNombre() {
	return nombre;
}

string tipoArticulo::getCodigo() {
	return codigo;
}


int tipoArticulo::getExistencias() { return existencias; }
void tipoArticulo::setExistencias(int e) { existencias = e; }


