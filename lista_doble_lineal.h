#pragma once
#include "NodoD.h"
#include "lista_simple.h"

class lista_doble_lineal
{
private:
	NodoD* cab; // puntero cabeza de la lista Apunta al primer nodo de la lista
	int largo; // Cantidad de nodoso que tiene la lista, el largo de la lista
public:
	lista_doble_lineal(); //constructor del tad
	~lista_doble_lineal(); // destructor del tad

	NodoD* getCab();
	int getLargo();

	void setCab(NodoD*);
	void setLargo(int);

	// Operaciones miscelaneas, son privadas
	//Son iguales que lista simple
	NodoD* dirDato(int); // Direccion del nodo cuyo dato es el referenciado
	NodoD* dirUltimo(); //Direccion del ultimo nodo de la lista
	NodoD* dirAnteriorDato(int); //Direccion del nodo anterior al nodo cuyo dato es el referenciado

	//Son diferentes que lista simple 
	NodoD* dirAnteriorDato(NodoD*); //Direccion del nodo anterior al nodo de la direccion referenciada

	// TAD de la lista
	//Son iguales que lista simple
	int primero(); // Dato del primero de la lista
	int ultimo(); // Dato del ultimo de la lista

	//Son iguales que lista simple
	bool esVacia(); // Devuelve true si la lista esta vacia
	bool existe(int); // Devuelve true si el dato de referencia existe en la lista.
	int datoPos(int);

	void agregarInicio(int); // Agrega al inicio el dato de referencia
	void agregarFinal(int);  // Agrega al final el dato de referencia
	bool agregarAntesDe(int, int);  // Agrega al dato antes del nodo con la pocision de referencia
	bool agregarDespuesDe(int, int);  // Agrega al dato despues del nodo con la pocision de referencia

	//Operaciones de borrar
	bool borrar(int); // Eliminar el nodo cuyo dato sea un entero de entrada
	bool borrarLista();
	bool borrarPos(int); // Elimina el nodo que se ubuca en la posicion de referencia

	//Operaciones de desplegue
	//Es iguales que lista simple
	void desplegar();

	//Operaciones de ordenar
	void ordenarAscendente();
};
