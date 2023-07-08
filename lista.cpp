#include "lista.h"

lista::lista(){
	pinicio = NULL;
	paux = NULL;
}

bool lista::insertar(linea * line){
	nodo * nuevo = new nodo(line, NULL);
	if (pinicio == NULL) {
		pinicio = nuevo;
	}
	else {
		paux = pinicio;
		while (paux->getSig() != NULL ) {
			paux = paux->getSig();
		}
		paux->setSig(nuevo);
	}
	can++;
	return true;
}

bool lista::isEmpty(){
	return (pinicio == NULL) ? true : false;
}

string lista::toString(){
	stringstream s;
	if (!isEmpty()) {
		paux = pinicio;
		while (paux != NULL) {
			s << paux->getDato()->toString();
			paux = paux->getSig();
		}
	}
	else {
		s << "Lista vacia...." << endl;
	}
	return s.str();
}


double lista::totalMontosSinDescuento(){
	double suma=0;
	paux = pinicio;
	while (paux != NULL) {
		suma += (paux->getDato()->getPrecioUnitarioSinDescuento())   *  (paux->getDato()->getCantidad());
		paux = paux->getSig();
	}
	return suma;
}

double lista::totalMontosConDescuento() {
	double suma = 0;
	paux = pinicio;
	while (paux != NULL) {
		suma += (paux->getDato()->getPrecioUnitarioConDescuento() )  *  (paux->getDato()->getCantidad());
		paux = paux->getSig();
	}
	return suma;
}

void lista::guardar(string nombreFichero) {
	salida.open(nombreFichero.c_str());

	if (salida.good())
	{
		paux = pinicio;
		stringstream s;
		while (paux != NULL)
		{
			paux->getDato()->guardar(salida);
			paux = paux->getSig();
		}
	}
	else
	{
		cout << endl << "error al abrir fichero de salida" << endl << endl;
	}
	salida.close();
}

void  lista::recuperar(string nombreFichero)
{
	if (entrada.is_open())
	{
		return;  // ya esta abierto no se debe volver a abrir
	}
	entrada.open(nombreFichero.c_str());
	if (entrada)
	{
		cout << endl << "<<Leyendo Archivos>>" << endl << endl;
		linea *ptemp;
		while (entrada.good()) {
			ptemp = linea::recuperar(entrada);
			if (entrada.good()) {
				this->insertar(ptemp);
			}
		}
		entrada.close();
	}
	else
	{
		cout << endl << "error al abrir fichero de entrada" << endl << endl;
	}
}


bool lista::eliminaInicio() {
	if (pinicio == NULL)  // caso 1: la lista esta vacia
	{
		return false;
	}
	else // caso 2: la lista no esta vacia
	{
		paux = pinicio;
		pinicio = pinicio->getSig();
		delete paux;
		return true;
	}
}

void lista::cerrarFicheros() {
	entrada.close();
	salida.close();
}

bool lista::is_openEntrada() {
	return entrada.is_open();
}

lista::~lista() {
	while (!isEmpty())
	{
		eliminaInicio();
	}
}