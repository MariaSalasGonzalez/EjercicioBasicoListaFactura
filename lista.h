#pragma once
#include "nodo.h"

// lista para lineas de producto
class lista {
private:
	nodo * pinicio;
	nodo * paux;
	int can;
	ifstream entrada;
	ofstream salida;

public:
	lista();
	bool insertar(linea*);
	bool eliminaInicio();
	bool isEmpty();
	string toString();
	double totalMontosSinDescuento();
	double totalMontosConDescuento();
	void guardar(string);
	void recuperar(string);
	bool is_openEntrada();// devuelve true si el archivo de entrada esta abierto
	void cerrarFicheros();
	~lista();
};