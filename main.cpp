#include "lista.h"
#include "factura.h"

int main() {
	
	factura::setImpuesto(13);
	factura * fact1 = new factura(1);
	factura * fact2 = new factura(2);
	
	fact1->setPorcDesc(15);
	fact2->setPorcDesc(20);
	tipoArticulo * art1 = new tipoArticulo(2000,"1","Clavos",1000);
	tipoArticulo * art2 = new tipoArticulo(2000,"2","Martillo", 1000);
	tipoArticulo * art3 = new tipoArticulo(2000,"4","Sierra", 1000);
	tipoArticulo * art4 = new tipoArticulo(2000,"5","Soldadura", 1000);
	tipoArticulo * art5 = new tipoArticulo(3000,"6","Bombilla", 1000);
	//-------------------------------------
	cout << "Revisando existencias" << endl;
	cout << art1->toString() << endl;
	cout << art2->toString() << endl;
	cout << art3->toString() << endl;
	cout << art4->toString() << endl << endl << endl;

	//------------------------------------
	art1->setPorDescuento(15);
	art2->setPorDescuento(25);
	fact1->agregarArticulo(art1, 4);
	fact1->agregarArticulo(art2, 5);
	fact1->agregarArticulo(art3, 6);
	fact1->agregarArticulo(art4, 7);

	// un mismo tipoArticulo puede estar en dos facturas
	fact2->agregarArticulo(art1, 1);
	fact2->agregarArticulo(art2, 12);
	fact2->agregarArticulo(art3, 60);

	fact1->getMontoFinal();
	fact2->getMontoFinal();
	cout << fact1->toString() << endl;
	cout << fact2->toString() << endl;


	//-------------------------------------
	cout << "Revisando existencias" << endl;
	cout<<	art1->toString()<<endl;
	cout << art2->toString() << endl;
	cout << art3->toString() << endl;
	cout << art4->toString() << endl << endl;

	//------------------------------------
	/*string nombreFichero = "../facturas.txt";
	fact1->guardar(nombreFichero);

	factura * fact3 = new factura(3);
	fact3->setPorcDesc(15);
	fact3->getMontoFinal();
	fact3->leer(nombreFichero);
	cout <<"imprimir factura guardada: "<<  endl << fact3->toString() << endl;

	delete  fact3;*/

	delete  art1;
	delete  art2;
	delete  art3;
	delete  art4;
	delete  art5;	
	delete  fact1;
	delete  fact2;
	
	system("pause");


}