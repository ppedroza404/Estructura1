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
        cout << "\n\n************************" << endl;
        cout << "**  Menu de Opciones  **" << endl;
        cout << "************************" << endl;
        cout << "1. Agregar Nodo al inicio de la lista" << endl;
        cout << "2. Agregar Nodo al final de la lista" << endl;
        cout << "3. Agregar Nodo despues de (nuevo nodo,despues de)" << endl;
        cout << "4. Agregar Nodo antes de (nuevo nodo,antes de)" << endl;
        cout << "5. Agregar dato Asendientemente" << endl;
        cout << "6. Buscar posicion de dato" << endl;
        cout << "7. Mostrar El primer Dato" << endl;
        cout << "8. Mostrar El ultimo Dato" << endl;
        cout << "9. Intercambiar Primero con ultimo" << endl;
        cout << "10. Agregar Nodo en posicion (_dato,_pos)" << endl;
        cout << "11. Eliminar Nodo en posicion (_pos)" << endl;
        cout << "12. Eliminar todas las apariciones de (Numero) " << endl;
        cout << "13. Eliminar valores repetidos consecutivos " << endl;
        cout << "14. Eliminar valores repetidos no consecutivos " << endl;
        cout << "15. Crear copia de lista inversa " << endl;
        cout << "19. Mostrar Lista" << endl;
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
            // Agrega acendentemente un dato
            cout << "\nIngrese el dato que quiere agregar: ";
            cin >> nodo;

            if (LS->agregarAscendente(nodo)) {
                cout << "Se agrego el numero asendentemente \n";
                LS->desplegar();

            }
            else {
                cout << "No se agrego el numero \n";
            }

            break;
        case 6:
            // Regresa la posicion del dato buscado
            cout << "\nIngrese un dato: ";
            cin >> nodo;            
            cout << "El Dato "<< nodo << " esta en la posicion : " << LS->datoPos(nodo)<< endl;
            LS->desplegar();
            break;
        case 7:
            // Mustra el Primer Dato de la lista
            cout << "El primer dato de la lista es : " << LS->primero();
            break;
        case 8:
            // Mustra el Ultimo Dato de la lista
            cout << "El ultimo dato en la lista es : " << LS->ultimo();
            break;
        case 9:
            LS->desplegar();
            cout << endl;
            if (LS->intercambiar()) {
                cout << "Se intercambio el primero con el el ultimo: \n";
                LS->desplegar();
                
            }
            else {
                cout << "No se pudo intercambiar el primero y el ultimo: \n";
            }            
            
            break;
        case 10:
            cout << "\nIngrese nuevo nodo: ";
            cin >> nodo;
            cout << "\nPosicion  : ";
            cin >> nodo2;

            LS->agregarPos(nodo,nodo2);
            break;
        case 11:
            cout << "\nIngrese la posicion que desea borrar: ";
            cin >> nodo;

            if (LS->borrarPos(nodo)) {
                cout << "El nodo fue borrado \n";
                LS->desplegar();

            }
            else {
                cout << "No se borro el nodo \n";
            }
            break;
        case 12:
            cout << "\nIngrese el valor que desea borrar: ";
            cin >> nodo;
            LS->eliminarTodasLasApariciones(nodo);
            break;
        case 13:
            cout << "\nEliminando valores consecutivos: ";
            LS->eliminarValoresRepetidosConsecutivos();
            cout << "\nNueva Lista: ";
            LS->desplegar();
            break;
        case 14:
            // Implementar
            break;
        case 15:
            cout << "\nLa Lista inversa es: ";
            LS->copiarInversa();
            break;
        case 19:
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
