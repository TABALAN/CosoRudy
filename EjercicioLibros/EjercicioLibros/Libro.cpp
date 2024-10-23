#include "Libro.h"
#include <string>
#include <iostream>
using namespace std;

void Libro::mostrarInformacionLibro() const
{
	cout << "El nombre del libro es: " << nombre << endl;
	cout << "El nombre del autor del libro es: " << autor << endl;
	cout << "Cantidad de veces que ha sido prestado el libro: " << contadorPrestamos << endl;
}

void Libro::setSumarPrestamo(int n)
{
	contadorPrestamos += n;
}