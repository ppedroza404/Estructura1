#include "lista_simple.h"

#include <iostream>

lista_simple::lista_simple()
{
	this->cab = NULL;
	this->largo = 0;
}

NodoS* lista_simple::getCab()
{
	return this->cab;
}

int lista_simple::getLargo()
{
	return this->largo;
}

void lista_simple::setCab(NodoS* ptr)
{
	this->cab = ptr;
}

void lista_simple::setLargo(int n)
{
	this->largo = n;
}

NodoS* lista_simple::dirDato(int dato)
{// Devolver la direccion en la que se ubica el dato, sino existe en la lista devulve NULL	
	NodoS* dir = NULL;
	NodoS* aux = getCab();

	while (aux != NULL && dir == NULL) {
		if (aux->getDato() == dato) {
			dir = aux;
		}
		else {
			aux = aux->getSgte();
		}
	}
	return dir;
}

NodoS* lista_simple::dirAnteriorDato(int dato)
{ // Direccion del nodo anterior al nodo en que se ubica dato
	NodoS* aux = getCab();
	NodoS* ant = NULL;
	while (aux != NULL && aux->getSgte() != NULL && ant == NULL) {
		if (aux->getSgte()->getDato() == dato) {
			ant = aux;
		}
		else {
			aux = aux->getSgte();
		}
	}

	return ant;
}

NodoS* lista_simple::dirAnteriorDato(NodoS* x)
{
	NodoS* aux = getCab();
	NodoS* ant = NULL;
	while (aux != NULL && aux->getSgte() != NULL && ant == NULL) {
		if (aux->getSgte()->getDato() == x->getDato()) {
			ant = aux;
		}
		else {
			aux = aux->getSgte();
		}
	}

	return ant;
}

NodoS* lista_simple::dirUltimo()
{
	NodoS* x = getCab();
	NodoS* ultimo = new NodoS();
	while (x->getSgte() != NULL) {
		ultimo = x->getSgte();
		x = x->getSgte();
	}
	return ultimo;
}

int lista_simple::primero()
{
	return getCab()->getDato();
}

int lista_simple::ultimo()
{
	NodoS* primero = getCab();
	int ultimo = 0;
	while (primero->getSgte() != NULL) {
		ultimo = primero->getSgte()->getDato();
		primero = primero->getSgte();
	}
	return ultimo;
}

bool lista_simple::esVacia()
{
	return this->cab == NULL;
}

bool lista_simple::existe(int dato)
{// Devuelve true si el dato esta en la lista
	return dirDato(dato) != NULL;
}

void lista_simple::desplegar()
{
	NodoS* aux = getCab();
	std::cout << "ELEMENTOS EN LA LISTA:" << std::endl;
	while (aux != NULL) {
		cout << aux->getDato() << "->";
		aux = aux->getSgte();
	}
	cout << "Final \n\n";

}

void lista_simple::agregarInicio(int x)
{
	NodoS* nuevo = new NodoS(x); //Paso 1. Crear el nodo
	nuevo->setSgte(getCab());//Paso 2. Enlazar el nuevo nodo a la lista
	setCab(nuevo); //Paso 3. Reacomodar la lista con el nuevo nodo
	setLargo(getLargo() + 1);
}

void lista_simple::agregarFinal(int x)
{
	NodoS* nuevo = new NodoS(x); //Paso 1. Crear el nodo
	NodoS* primero = getCab();

	while (primero->getSgte() != NULL)
	{
		primero = primero->getSgte();
	}

	if (primero->getSgte() == NULL) {
		setLargo(getLargo() + 1);
		primero->setSgte(nuevo);
	}
}

bool lista_simple::agregarAntesDe(int x, int ref)
{
	bool agregado = false;
	if (!esVacia()) { // O if (getCab() != NULL) {
		if (getCab()->getDato() == ref) { // esto es para agregar si solo hay un elemento que no tiene nada anterior
			agregarInicio(x);
			agregado = true;
		}
		else {
			NodoS* ant = getCab(); // O NodoS* ant = dirAnteriorDato(x)
			while (ant->getSgte() != NULL && !agregado) { // O ant != NULL
				if (ant->getSgte()->getDato() == ref) {
					NodoS* nuevo = new NodoS(x); //Paso 1. Crear el nodo
					nuevo->setSgte(ant->getSgte()); //Paso 2. Enlazar el nuevo nodo a la lista
					ant->setSgte(nuevo); //Paso 3. Reacomodar la lista con el nuevo nodo
					largo++; // setLargo(getLargo() + 1);
					agregado = true;
				}
				else {
					ant = ant->getSgte();
				}

			}
		}
	}
	return agregado;
}

bool lista_simple::agregarDespuesDe(int x, int ref)
{
	bool agregado = false;
	if (esVacia()) {
		if (getCab()->getDato() == ref) { // esto es para agregar si solo hay un elemento que no tiene nada anterior
			agregarInicio(x);
			agregado = true;
		}
	}
	else {
		NodoS* ant = getCab();
		while (ant->getSgte() != NULL && !agregado) {
			if (ant->getDato() == ref) {
				NodoS* siguiente = ant->getSgte();
				NodoS* nuevo = new NodoS(x);
				ant->setSgte(nuevo);
				nuevo->setSgte(siguiente);
				largo++;
				agregado = true;
			}
			else {
				ant = ant->getSgte();
			}
		}
	}
	return agregado;
}

bool lista_simple::borrar(int _dato)
{
	bool eliminado = false;
	NodoS* aux = NULL; //señalar el nodo que va a ser eliminado

	if (!esVacia()) {

		if (getCab()->getDato() == _dato) {
			aux = getCab();  //señalar el nodo a eliminar
			setCab(aux->getSgte()); //Reacomodar la lista con el nuevo nodo
		}
		else { //Sirve para eliminar en medio y el último
			NodoS* ant = dirAnteriorDato(_dato);
			if (ant != NULL) {
				aux = ant->getSgte(); //Señalar el nodo a eliminar
				ant->setSgte(aux->getSgte()); //Reacomodar la lista con el nuevo nodo
			}

		}
		if (aux != NULL) {
			delete aux;
			setLargo(getLargo() - 1);
			eliminado = true;
		}
	}
	return  eliminado;
}

void lista_simple::borrarLista()
{
	bool borrada = false;
	NodoS* aux = getCab();

	if (!esVacia()) {
		while (aux != NULL) {
			setCab(aux->getSgte());
			delete aux;
			setLargo(getLargo() - 1);
			aux = getCab();
		}
		borrada = true;
	}
}

bool lista_simple::agregarPos(int dato, int pos)
{
	bool agregado = false;
	if (!esVacia()) {
		NodoS* ant = getCab();
		int contador = 1;
		while (ant->getSgte() != NULL && !agregado) {
			if (contador + 1 == pos) {
				NodoS* nuevo = new NodoS(dato);
				nuevo->setSgte(ant->getSgte());
				ant->setSgte(nuevo);
				largo++;
				agregado = true;
			}
			else {
				ant = ant->getSgte();
				contador++;
			}
		}
	}
	return agregado;
}

int lista_simple::datoPos(int dato)
{
	NodoS* aux = getCab();
	int pos = -1;
	bool encontrado = false;
	while (aux != NULL && encontrado != true) {
		pos = pos + 1;
		if (aux->getDato() == dato) {
			encontrado = true;
		}
		else {
			aux = aux->getSgte();
			if (aux == NULL) {
				pos = 0;
			}
		}
	}
	return pos;
}

bool lista_simple::borrarPos(int pos)
{
	bool eliminado = false;
	NodoS* aux = NULL;
	NodoS* ant = getCab();
	int contador = 1;

	if (!esVacia()) {
		while (aux == NULL && !eliminado) {
			if (contador + 1 == pos) {
				aux = ant->getSgte(); //Señalar el nodo a eliminar
				ant->setSgte(aux->getSgte()); //Reacomodar la lista con el nuevo nodo
			}
			else {
				ant = ant->getSgte();
				contador++;
			}
		}
		if (aux != NULL) {
			delete aux;
			setLargo(getLargo() - 1);
			eliminado = true;
		}
	}
	return eliminado;
}

bool lista_simple::intercambiar() 
{
	bool sucess = false;
	NodoS* aux = new NodoS();
	NodoS* prim = getCab();
	NodoS* ult = dirUltimo();
	if (prim != NULL && prim != ult && largo > 1) {
		aux ->setDato(prim->getDato());
		prim->setDato(ult->getDato());
		ult->setDato(aux->getDato());
		sucess = true;
	}

	return sucess;
};

bool lista_simple::agregarAscendente(int _dato)
{
	bool sucess = false;
	bool repetido = false;
	if (esVacia()) {
		agregarInicio(_dato);
		sucess = true;
	}
	else {
		NodoS* aux = getCab();

		while (aux != NULL && !sucess && !repetido) {
			if (aux->getDato() == _dato) {
				repetido = true;
			}
			else if (aux->getDato() > _dato) {
				//agregar Antes de
				agregarAntesDe(_dato, aux->getDato());
				sucess = true;
			}
			else if (ultimo() < _dato) {
				agregarFinal(_dato);
				sucess = true;
			}

			aux = aux->getSgte();
		}
	}
	return sucess;
}

void lista_simple::eliminarTodasLasApariciones(int _dato) {

	NodoS* aux = getCab();
	/// <summary>
	/// No esta funcionando
	/// </summary>
	/// <param name="_dato"></param>
	if (!esVacia()) {
		while (aux != NULL ) {
			borrar(_dato);
			if (aux->getSgte() != NULL) {
				aux = aux->getSgte();
			}
			else {
				aux = NULL;
			}
			
		}
	}
}
