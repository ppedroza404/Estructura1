#pragma once
#include "NodoS.h"

class lista_simple
{
private:
	NodoS* cab; // puntero cabeza de la lista Apunta al primer nodo de la lista
	int largo; // Cantidad de nodoso que tiene la lista, el largo de la lista

public:
	lista_simple(); //constructor del tad
	~lista_simple(); // destructor del tad

	NodoS* getCab();
	int getLargo();

	void setCab(NodoS*);
	void setLargo(int);

	// Operaciones miscelaneas, son privadas
	NodoS* dirDato(int); // Direccion del nodo cuyo dato es el referenciado
	NodoS* dirAnteriorDato(int); //Direccion del nodo anterior al nodo cuyo dato es el referenciado 
	NodoS* dirAnteriorDato(NodoS*); //Direccion del nodo anterior al nodo de la direccion referenciada
	NodoS* dirUltimo(); //Direccion del ultimo nodo de la lista

	// TAD de la lista
	int primero(); // Dato del primero de la lista
	int ultimo(); // Dato del ultimo de la lista
	

	bool esVacia(); // Devuelve true si la lista esta vacia
	bool existe(int); // Devuelve true si el dato de referencia existe en la lista.
	

	void agregarInicio(int); // Agrega al inicio el dato de referencia
	void agregarFinal(int);  // Agrega al final el dato de referencia
	bool agregarAntesDe(int, int);  // Agrega al dato antes del nodo con la pocision de referencia
	bool agregarDespuesDe(int, int);  // Agrega al dato despues del nodo con la pocision de referencia

	// Inicio Tarea
	bool agregarAscendente(int dato); // Agrega de forma ascendente el dato en la lista, Si el Dato ya existe retorna Falso y no lo agrega. 
	void eliminarValoresRepetidosConsecutivos(); //Considere una lista con valores repetidos, pero todos consecutivos
	void eliminarValoresRepetidosNoConsecutivos(); // Depura la lista para eliminar las repeticiones.
	void copiarInversa(lista_simple _lsOri, lista_simple _lsDst);// de la clase de dos listas
	 
	//Final Tarea
	
	// Lab #6
	int datoPos(int);  //Devuelve el dato en la posicion (del 1 hata 1+1....) retorna 0 si el dato no es encontrado.
	bool agregarPos(int _dato, int _pos);// Agrega a _dato en la posición cardinal _pos
	bool borrarPos(int _pos); // Eliminar el dato en la posición cardinal _pos
	bool intercambiar(); //El valor del primero con el valor del último. Si es un solo nodo o está vacia devuelve false.
	void eliminarTodasLasApariciones(int _dato); //Elimina de la lista todas las apariciones de _dato en la lista

	// Lab #6
	//Operaciones de borrar
	bool borrar(int); // Eliminar el nodo cuyo dato sea un entero de entrada
	void borrarLista(); // Eliminar toda La lista

	void desplegar();

};

