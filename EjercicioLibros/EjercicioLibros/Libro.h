#pragma once
#include <string>
using namespace std;

class Libro
{

private:
	string nombre;
	int contadorPrestamos = 0;
	string autor;
	int ID;

public:
	Libro(string nombrex, string autors, int id) : nombre(nombrex), autor(autors), ID(id) {}

	void mostrarInformacionLibro() const;
	void setSumarPrestamo(int n);
	string devolverNombre() { return nombre; }
	int devolverCantidadPrestamos() { return contadorPrestamos; }
	int devolverId() { return ID; }
};

