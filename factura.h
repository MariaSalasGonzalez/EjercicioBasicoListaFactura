#pragma once
#include "lista.h"

static double impuesto =13; // se inicializa en 13, pero puede ser cambiado en cualquier momento

class factura {
private:
	double porDesc;
	int consecutivo;
	lista * list;

public:
	factura(int);
	bool agregarArticulo(tipoArticulo*, int);
	double calculaSumatoriaProductos();
	double calculaMontoImpuesto();
	double calcularMontoDescuento();
	void setPorcDesc(double);
	double getMontoFinal();
	static void setImpuesto(double);
	void guardar(string);
	void leer(string);
	string toString();
	~factura();
};