#include "factura.h"

factura::factura(int consec){
	porDesc=0;
	consecutivo = consec;
	list = new lista();
}
void factura::setImpuesto(double imp) {
	impuesto = imp;
}

bool factura::agregarArticulo(tipoArticulo * art, int cantidad){
	if (art->getExistencias() - cantidad < 0)
	{

		cout << "Error, existencias insuficientes " << endl;
		return false;

	}
	art->setExistencias(art->getExistencias() - cantidad);
	if (list->insertar(new linea(art, cantidad))) {
		return true;
	}
	return false;
}

void factura::setPorcDesc(double d) {
	porDesc = d;
}

double factura::calculaSumatoriaProductos(){
	return list->totalMontosSinDescuento();
}


double factura::calculaMontoImpuesto() {
	return (calculaSumatoriaProductos() * impuesto/100);
}


double factura::calcularMontoDescuento(){
	return calculaSumatoriaProductos() * (porDesc /100);
}

double factura::getMontoFinal(){
	double montoFinal = calculaSumatoriaProductos();
	montoFinal -= calcularMontoDescuento();
	montoFinal += calculaMontoImpuesto();
	return montoFinal;
}

string factura::toString(){
	stringstream s;
	s << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
	s << "                                 Factura # " <<consecutivo<< endl;
	s << "Detalle:" << endl;
	s << list->toString() << endl << endl;

	s << " Monto  sin IV: " << calculaSumatoriaProductos() << endl;
	s << "   (-)  Descuento General " <<"(" <<porDesc<< char(37) <<")" << ":" << calcularMontoDescuento() <<endl;
	s << "   (-)  Descuento en productos  " <<list->totalMontosSinDescuento() - list->totalMontosConDescuento()<< endl;
	s << "   (+)  Impuesto " << "(" << impuesto << char(37) << ")" << ":" << calculaMontoImpuesto() << endl << endl;
	s << " Monto Final : " << getMontoFinal() << endl;
	s << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl << endl;
	return s.str();
}

void factura::guardar(string nombreFichero) {
	list->guardar(nombreFichero);
}

void factura::leer(string nombreFichero) {
	list->recuperar(nombreFichero);

}


factura::~factura() {
	delete list;

}