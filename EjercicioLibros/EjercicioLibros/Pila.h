#pragma once
#include "Libro.h"
#include <string>
#include <iostream>
using namespace std;

class Pila
{

private:
    struct NodoPila
    {
        Libro* libro;
        NodoPila* siguiente;

    };
    NodoPila* cima;

public:

    Pila() : cima(nullptr) {}

    void push(Libro* lbr)
    {
        NodoPila* nuevoNodo = new NodoPila;
        nuevoNodo->libro = lbr;
        nuevoNodo->siguiente = cima;
        cima = nuevoNodo;
    }

    void pop()
    {
        if (cima != nullptr)
        {
            NodoPila* nodoEliminar = cima;
            cima = cima->siguiente;
            delete nodoEliminar;
        }
        else
        {
            cout << "La pila esta vacia, no hay nada que eliminar." << endl;
        }
    }

    bool estaVacia()
    {
        return cima == nullptr;
    }

    void mostrarPila()
    {
        if (estaVacia())
        {
            cout << "La pila esta vacia." << endl;
        }

        else
        {
            NodoPila* temp = cima;
            cout << endl;
            while (temp != nullptr)
            {
                cout << "Nombre del libro: " << temp->libro->devolverNombre() << endl;
                temp = temp->siguiente;
                cout << endl;
            }
        }
    }

};

