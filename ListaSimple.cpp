// ListaSimple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include "lista_simple.h"
using namespace std;

int main()
{
    int opcion;
    int nodo;
    int nodo2;
    bool repetir = true;
    lista_simple* LS = new lista_simple(); // Instancia de lista simple, LS tiene el puntero a la estructura

    do {

        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Agregar Nodo al inicio de la lista" << endl;
        cout << "2. Agregar Nodo al final de la lista" << endl;
        cout << "3. Agregar Nodo despues de (nuevo nodo,despues de nodo)" << endl;
        cout << "4. Agregar Nodo antes de (nuevo nodo,despues de nodo)" << endl;
        cout << "5. Buscar posicion de dato" << endl;
        cout << "6. Mostrar El primer Dato" << endl;
        cout << "7. Mostrar El ultimo Dato" << endl;
        cout << "9. Mostrar Lista" << endl;
        cout << "20. borrar Lista" << endl;
        cout << "0. SALIR" << endl;

        cout << "\nIngrese una opcion: ";       
        cin >> opcion;
        system("CLS");

        switch (opcion) {
        case 1:
            // Agrega un Nodo al inicio de la lista
            cout << "\nIngrese un dato al inicio: ";
            cin >> nodo;
            LS->agregarInicio(nodo);
            break;

        case 2:
            // Agrega un Nodo al final de la lista  
            cout << "\nIngrese un dato al final: ";
            cin >> nodo;
            LS->agregarFinal(nodo);
            break;
        case 3:
            // Agrega un Nodo despues de (nuevo,existente)
            cout << "\nIngrese nuevo nodo: ";
            cin >> nodo;
            cout << "\nDespues de : ";
            cin >> nodo2;
            LS->agregarDespuesDe(nodo, nodo2);
            break;
        case 4:
            // Agrega un Nodo Antes de (nuevo,existente)
            cout << "\nIngrese nuevo nodo: ";
            cin >> nodo;
            cout << "\nAntes de : ";
            cin >> nodo2;
            LS->agregarAntesDe(nodo, nodo2);
            break;
        case 5:
            // Regresa la posicion del dato buscado
            cout << "\nIngrese un dato: ";
            cin >> nodo;
            cout << "El Dato esta en la posicion : " << LS->datoPos(nodo);
            break;
        case 6:
            // Mustra el Primer Dato de la lista
            cout << "El primer dato de la lista es : " << LS->primero();
            break;
        case 7:
            // Mustra el Ultimo Dato de la lista
            cout << "El Dato esta en la posicion : " << LS->ultimo();
            break;
        case 9:
            // Despliega la lista                

            if (LS->esVacia()) {
                cout << "La lista esta vacia" << endl;
            }
            else {
                cout << "La lista no esta vacia" << endl;
                LS->desplegar();
            }

            break;           
        case 20:
      
            LS->borrarLista();
            LS->desplegar();

            break;
        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

    return 0;

   /* cout<<LS->dirDato(30)<<endl;
    cout<<LS->dirAnteriorDato(30)<<endl;
    cout << LS->dirUltimo()<<endl;*/ 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
