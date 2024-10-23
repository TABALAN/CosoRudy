#pragma once
#include "Libro.h"
#include <string>
#include <iostream>
using namespace std;

class Cola
{

private:
    struct NodoCola
    {
        Libro* libro;
        NodoCola* siguiente;

        NodoCola(Libro* lbr)
        {
            libro = lbr;
            siguiente = nullptr;
        }
    };

    NodoCola* cabeza;
    NodoCola* final;

public:
    Cola() {
        cabeza = final = nullptr;
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }

    void encolar(Libro* lbr) {
        NodoCola* nuevoNodo = new NodoCola(lbr);
        if (estaVacia())
        {
            cabeza = final = nuevoNodo;
        }
        else
        {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }

        cout << endl;
    }

    void desencolar() {
        if (estaVacia())
        {
            cout << endl;
            cout << "La cola esta vacia." << endl;
            return;
        }
        NodoCola* nodoRecorrido = cabeza;
        cabeza = cabeza->siguiente;

        if (cabeza == nullptr)
        {
            final = nullptr;
        }
        cout << endl;
        cout << "Libro " << nodoRecorrido->libro->devolverNombre() << " ha sido devuelto..." << endl;
        delete nodoRecorrido;
    }
    void imprimirCola()
    {
        if (estaVacia()) {
            cout << "La cola esta vacia." << endl;
            return;
        }

        NodoCola* nodoRecorrido = cabeza;

        while (nodoRecorrido != nullptr)
        {
            cout << endl;
            cout << "Nombre del libro: " << nodoRecorrido->libro->devolverNombre() << endl;
            nodoRecorrido = nodoRecorrido->siguiente;
        }
    }

    void datosLibroDevolver()
    {
        cout << endl;
        cout << "Nombre del libro a devolver: " << cabeza->libro->devolverNombre() << endl;
    }

    Libro* libroDevolver()
    {
        return cabeza->libro;
    }
};

