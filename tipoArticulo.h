#pragma once
#include <sstream>
#include <iostream>
using namespace std;


class tipoArticulo {
private:
	double precio;
	string codigo;
	string nombre;
	double porDescuento;
	int existencias;

public:
	tipoArticulo(double, string, string, int);
	string toString();
	double getPrecioConDescuento();
	double getPrecio();
	string getCodigo();
	string getNombre();
	int getExistencias();
	void setExistencias(int);
	void setPorDescuento(double);
	double getPorDescuento();
};