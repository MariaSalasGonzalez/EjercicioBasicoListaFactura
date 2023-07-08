#include "linea.h"
#include "utiles.h"
#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

linea::linea(tipoArticulo * art, int cantidad){
	this->art = art;
	this->cantidad = cantidad;
	//precioUnitarioSinDescuento = art->getPrecioSinDescuento();
	//precioUnitarioConDescuento = art->getPrecioConDescuento();
	//precioLinea = cantidad * art->getPrecioConDescuento();
}

string linea::toString(){
	stringstream s;
	s << "\t"<<art->toString();
	s << ", can: " << cantidad;
	s<< ", precioLinea: " << getPrecioLineaTotal() <<endl;
	return s.str();
}

int linea::getCantidad(){
	return cantidad;
}

double linea::getPrecioUnitarioConDescuento(){
	return art->getPrecioConDescuento(); 
}
double linea::getPrecioUnitarioSinDescuento() {
	return art->getPrecio();
}

double linea::getPrecioLineaTotal(){
	return cantidad * art->getPrecioConDescuento();
}

linea* linea::recuperar(ifstream &entrada) {
	string nom, cod, prec, desc, cant, exist; // TODO SE LEE COMO STRING

	getline(entrada, cod, DELIMITA_CAMPO);
	getline(entrada, nom, DELIMITA_CAMPO);
	getline(entrada, prec, DELIMITA_CAMPO);
	getline(entrada, exist, DELIMITA_CAMPO);
	getline(entrada, desc, DELIMITA_CAMPO);
	getline(entrada, cant, DELIMITA_REGISTRO);

	int iExist = convertirInt(exist);
	int iCant = convertirInt(cant);

	double iDesc = convertirDouble(desc);
	double iPrecio = convertirDouble(prec);
	tipoArticulo *art1 = new tipoArticulo(iPrecio, cod, nom, iExist);
	return new linea(art1, iCant);
}

void linea::guardar(ofstream &salida) {
	salida << art->getCodigo() << DELIMITA_CAMPO;
	salida << art->getNombre() << DELIMITA_CAMPO;
	salida << art->getPrecio() << DELIMITA_CAMPO;
	salida << art->getExistencias() << DELIMITA_CAMPO;
	salida << art->getPorDescuento() << DELIMITA_CAMPO;
	salida << this->getCantidad() << DELIMITA_REGISTRO;
}


