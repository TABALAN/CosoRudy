#include "Libro.h"
#include <queue> //Cola
#include <stack> //Pila
#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include <vector>

//Hecho por Ruddys y Tony
vector <Libro*> biblio;

void mostrarMenu()
{
    cout << "\n ---Menu de opciones--\n";
    cout << "1. Realizar prestamo de un libro\n";
    cout << "2. Devolver un libro\n";
    cout << "3. Ordenar libros\n";
    cout << "4. Salir\n";
    cout << endl;
    cout << "Seleccione una opcion: ";
}

void ordenamientoBurbuja()
{
    int longitud = biblio.size();
    if(biblio.empty())
    { 
        cout << "No hay libros prestados aun..." << endl;
    }
    else
    {
        for (int i = 0; i < longitud - 1; i++)
        {
            for (int j = 0; j < longitud - i - 1; j++)
            {
                if (biblio[j]->devolverCantidadPrestamos() < biblio[j + 1]->devolverCantidadPrestamos())
                {
                    // Intercambiar los libros
                    Libro* temp = biblio[j];
                    biblio[j] = biblio[j + 1];
                    biblio[j + 1] = temp;
                }
            }
        }
    }
}


int main()
{
    Cola colaLibros;
    Pila pilaLibros;
    int opcion;

    Libro* libro1 = new Libro("100 años de soledad", "Pilin",1);
    biblio.push_back(libro1);
    Libro* libro2 = new Libro("El principito", "Luis vohn An",2);
    biblio.push_back(libro2);
    Libro* libro3 = new Libro("Rayo", "Mcqueen",3);
    biblio.push_back(libro3);

    do {
        mostrarMenu();
        do
        {
            cin >> opcion;
        } while (opcion < 1 || opcion > 4);

        switch (opcion)
        {
        case 1:
        {
            cout << endl;
            cout << "--------------------------- Datos del libro ------------------------" << endl;
            for (auto& libro : biblio)
            {
                cout << "Libro: " << libro->devolverNombre() << endl;
                cout << "Cantidad prestamos: " << libro->devolverCantidadPrestamos() << endl;
                cout << "ID: " << libro->devolverId() << endl;
                cout << endl;
            }

            int id;
            do
            {
                cout << "Ingrese el numero del libro a mostrar: ";
                cin >> id;
            } while (id < 1 && id >> 3);

            if (id == libro1->devolverId())
            {
                
                colaLibros.encolar(libro1);
                libro1->setSumarPrestamo(1);
            }
            else if (id == libro2->devolverId())
            {
                colaLibros.encolar(libro2);
                libro2->setSumarPrestamo(1);
            }
            else if (id == libro2->devolverId())
            {
                colaLibros.encolar(libro3);
                libro3->setSumarPrestamo(1);
            }

            cout << endl;
            cout << "Libro prestado exitosamente..." << endl;

            break;
        }

        case 2:
        {
            cout << endl;
            cout << "--------------------------- Devolver un libro ------------------------" << endl;
            if (colaLibros.estaVacia())
            {
                cout << endl;
                cout << "Aun no hay libros prestados... " << endl;
            }
            else
            {
                colaLibros.datosLibroDevolver();
                pilaLibros.push(colaLibros.libroDevolver());
                colaLibros.desencolar();
            }
            break;
        }

        case 3:
        {
            cout << endl;
            cout << "--------------------------- Libros ordenados ------------------------" << endl;
            ordenamientoBurbuja();
            if (biblio.empty())
            {
                cout << endl;
            }
            else 
            {
                for (auto& libro : biblio)
                {
                    cout << "Libro: " << libro->devolverNombre() << endl;
                    cout << "Cantidad prestamos: " << libro->devolverCantidadPrestamos() << endl;
                    cout << endl;
                }
            }
            break;
        }
        case 4:
        {
            break;
        }
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);


    return 0;
}
