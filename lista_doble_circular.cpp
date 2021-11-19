#include "lista_doble_circular.h"
#include "NodoD.h"

lista_doble_circular::lista_doble_circular()
{
	this->cab = NULL;
	this->largo = 0;
}

NodoD* lista_doble_circular::getCab()
{
	return this->cab;
}

int lista_doble_circular::getLargo()
{
	return this->largo;
}

void lista_doble_circular::setCab(NodoD* ptr)
{
	this->cab = ptr;
}

void lista_doble_circular::setLargo(int n)
{
	this->largo = n;
}

NodoD* lista_doble_circular::dirDato(int dato)
{
	NodoD* dir = NULL;
	NodoD* aux = getCab();

	// Recorre la lista desde la cabeza hasta el ultimo Nodo

	for (int i = 1; i <= getLargo() - 1; i++) {
		// Si el valor del aux es igual al dato, iguala dir a dato
		// en caso de que exista mas de un nodo con el mismo dato regresara la direccion del ultimo
		if (aux->getDato() == dato) {
			dir = aux;
		}
		aux = aux->getSgte();
	}
	return dir;
}

NodoD* lista_doble_circular::dirUltimo()
{
	NodoD* aux = NULL;
	// Si la lista es vacia regresa null si no regresa en anterior a la cabeza 

	if (!esVacia()) {
		aux = getCab()->getAnterior();
	}

	return aux;
}

NodoD* lista_doble_circular::dirAnteriorDato(int dato)
{
	NodoD* dir = NULL;
	NodoD* aux = getCab();

	// Recorre la lista desde la cabeza hasta el ultimo Nodo

	for (int i = 1; i <= getLargo() - 1; i++) {
		// Si el valor del aux es igual al dato, iguala dir a dato
		// en caso de que exista mas de un nodo con el mismo dato regresara la direccion del dato anterio 
		// en el ultimo nodo
		if (aux->getDato() == dato) {
			dir = aux->getAnterior();
		}
		aux = aux->getSgte();
	}
	return dir;
}

NodoD* lista_doble_circular::dirAnteriorDato(NodoD* nodo)
{
	NodoD* dir = NULL;
	NodoD* aux = getCab();

	// Recorre la lista desde la cabeza hasta el ultimo Nodo

	for (int i = 1; i <= getLargo() - 1; i++) {
		// Si el valor del aux es igual al dato, iguala dir a dato
		// en caso de que exista mas de un nodo con el mismo dato regresara la direccion del ultimo 

		if (aux->getDato() == nodo->getDato()) {
			dir = aux->getAnterior();
		}
		aux = aux->getSgte();
	}
	return dir;
}

int lista_doble_circular::primero()
{
	int dato = 0;
	if (!esVacia()) {
		dato = getCab()->getDato();
	}
	return dato;
}

int lista_doble_circular::ultimo()
{
	int dato = 0;
	if (!esVacia()) {
		dato = getCab()->getAnterior()->getDato();
	}
	return dato;
}

bool lista_doble_circular::esVacia()
{
	return this->cab == NULL;
}

bool lista_doble_circular::existe(int dato)
{
	bool existe = false;
	if (!esVacia()) {
		NodoD* aux = getCab();
		for (int i = 1; i <= getLargo() - 1; i++) {
			// Si el valor del aux es igual al dato, iguala dir a dato
			// en caso de que exista mas de un nodo con el mismo dato regresara la direccion del ultimo 
			if (aux->getDato() == dato) {
				existe = true;
			}
			aux = aux->getSgte();
		}
	}
	return existe;
}

int lista_doble_circular::datoPos(int dato)
{
	int pos = 0;
	if (!esVacia()) {
		NodoD* aux = getCab();
		for (int i = 1; i <= getLargo() - 1; i++) {
			// Si el valor del aux es igual al dato, iguala dir a dato
			// en caso de que exista mas de un nodo con el mismo dato regresara la direccion del ultimo 
			if (aux->getDato() == dato) {
				pos = i;
			}
			aux = aux->getSgte();
		}
	}
	return pos;
}

void lista_doble_circular::desplegar()
{
	NodoD* aux = getCab();
	std::cout << "ELEMENTOS EN LA LISTA:" << std::endl;
	for (int i = 1; i <= getLargo(); i++) {
		cout << "(" << aux->getDato() << ")" << "->";
		aux = aux->getSgte();
	}
	cout << "Final \n\n\n";
}

void lista_doble_circular::ordenarAscendente()
{
	// No Implementada
}

void lista_doble_circular::agregarInicio(int dato)
{
	NodoD* nuevo = new NodoD(dato); //Paso 1. Crear el nodo


	if (!esVacia()) {
		nuevo->setSgte(getCab()); //Paso 2. Enlazar el nuevo nodo a la lista
		nuevo->setAnterior(getCab()->getAnterior());
		//Paso 3 Reacomodar la lista con el nuevo nodo

		getCab()->getAnterior()->setSgte(nuevo);

		getCab()->setAnterior(nuevo);
	}
	else {
		nuevo->setSgte(nuevo);
		nuevo->setAnterior(nuevo);
	}

	setCab(nuevo);
	setLargo(getLargo() + 1);
	cout << getLargo();
}

void lista_doble_circular::agregarFinal(int dato)
{

	NodoD* nuevo = new NodoD(dato); //Paso 1. Crear el nodo

	if (!esVacia()) {
		nuevo->setSgte(getCab()); //Paso 2. Enlazar el nuevo nodo a la lista
		nuevo->setAnterior(getCab()->getAnterior());
		//Paso 3 Reacomodar la lista con el nuevo nodo
		getCab()->getAnterior()->setSgte(nuevo);
		getCab()->setAnterior(nuevo);
	}
	else {
		nuevo->setSgte(nuevo);
		nuevo->setAnterior(nuevo);
	}

	setLargo(getLargo() + 1);
	cout << getLargo();
}

bool lista_doble_circular::agregarAntesDe(int _datoRef, int _dato)
{
	// No Implementada
	return false;
}

bool lista_doble_circular::agregarDespuesDe(int _datoRef, int _dato)
{
	bool agregado = false;

	if (getCab()->getDato() == _dato) {
		agregarInicio(_dato);
		agregado = true;
	}
	else {
		NodoD* aux = getCab();
		while (!agregado) {
			if (aux->getDato() == _datoRef) {
				NodoD* nuevo = new NodoD(_dato);
				if (aux->getSgte() == NULL) {
					aux->setSgte(nuevo);
					aux->setAnterior(nuevo);
					nuevo->setSgte(aux);
					nuevo->setAnterior(aux);
				}
				else {
					NodoD* siguiente = aux->getSgte();
					nuevo->setSgte(siguiente);
					aux->setSgte(nuevo);
					aux->getSgte()->setAnterior(aux);
					nuevo->setAnterior(aux);
					aux->getAnterior()->setAnterior(siguiente);
					siguiente->setAnterior(nuevo);

				}
				agregado = true;
			}
			else {
				aux = aux->getSgte();
			}
		}
	}
	return agregado;
}

bool lista_doble_circular::borrar(int _dato)
{
	bool eliminado = false;
	NodoD* aux = dirDato(_dato); //Paso 1. Se�alo el nodo a eliminar
	if (aux != NULL) {
		//Paso 2. Reacomodar la lista sin el nodo
		if (aux == getCab()) { // en caso de ser la cabeza la que se va a borrar
			setCab(aux->getSgte());
		}
		else {
			aux->getAnterior()->setSgte(aux->getSgte());
		}

		if (aux->getSgte() != NULL) {
			aux->getSgte()->setAnterior(aux->getAnterior());
		}

		delete aux; //eliminar el nodo.
		setLargo(getLargo() - 1);
		eliminado = true;
	}
	return eliminado;
}

bool lista_doble_circular::borrarLista()
{
	bool eliminado = false;
	if (!esVacia()) {
		NodoD* aux = getCab();
		NodoD* ultimo = aux->getAnterior();
		while (aux != NULL) {
			if (aux == ultimo) {
				aux->setSgte(NULL);
				aux->setAnterior(NULL);
			}
			setCab(aux->getSgte());
			delete aux;
			setLargo(getLargo() - 1);
			aux = getCab();
		}
	}
	return eliminado;
}

bool lista_doble_circular::borrarPos(int pos)
{
	bool eliminado = false;
	NodoD* aux = NULL;
	NodoD* ant = getCab();
	int contador = 1;

	if (!esVacia()) {
		while (aux == NULL && !eliminado) {
			if (contador + 1 == pos) {
				aux = ant->getSgte(); //Se�alar el nodo a eliminar
				ant->setSgte(aux->getSgte()); //Reacomodar la lista con el nuevo nodo
				ant->getSgte()->setAnterior(ant);
			}
			else if (contador == 1 && contador == pos) {
				aux = getCab();  //se�alar el nodo a eliminar
				setCab(aux->getSgte()); //Reacomodar la lista con el nuevo nodo
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

bool lista_doble_circular::agregarPos(int dato, int pos)
{
	bool agregado = false;
	if (!esVacia()) {
		NodoD* ant = getCab();
		int contador = 1;
		while (!agregado) {
			NodoD* nuevo = new NodoD(dato);
			if (contador + 1 == pos) {
				nuevo->setSgte(ant->getSgte());
				nuevo->setAnterior(ant);
				ant->setSgte(nuevo);
				ant->setAnterior(nuevo->getSgte());
				ant->getAnterior()->setSgte(ant);
				ant->getAnterior()->setAnterior(nuevo);
				largo++;
				agregado = true;
			}
			else if (pos == 1) {
				setCab(nuevo);
				ant->setAnterior(getCab());
				ant->setSgte(getCab());
				nuevo->setAnterior(ant);
				nuevo->setSgte(ant);
			}
			else {
				ant = ant->getSgte();
				contador++;
			}
		}
	}
	return agregado;
}


bool lista_doble_circular::agregarAscendente(int)
{
	return false;
}

void lista_doble_circular::eliminarValoresRepetidosConsecutivos()
{
}

void lista_doble_circular::eliminarValoresRepetidosNoConsecutivos()
{
}

void lista_doble_circular::copiarInversa()
{
}

bool lista_doble_circular::intercambiar()
{
	return false;
}

void lista_doble_circular::eliminarTodasLasApariciones(int _dato)
{
	// No Implementada
}

void lista_doble_circular::insetDiferencia()
{
	NodoD* aux = getCab()->getSgte();
	NodoD* nuevoaux = NULL;
	int tam = getLargo();

	for (int i = 2; i <= tam; i++) {

		if (i % 2 == 0) {
			// Paso 2 inset el nodo nuevo en la lista
			NodoD* nuevoaux = new NodoD();
			nuevoaux->setDato(aux->getDato() - aux->getAnterior()->getDato());
			nuevoaux->setAnterior(aux->getAnterior());
			nuevoaux->setSgte(aux);
			// Paso 3  Recomodar la lista con el nodo nuevo	
			// Primero el puntero del vecino ** siempre
			aux->getAnterior()->setSgte(nuevoaux);
			aux->setAnterior(nuevoaux);

			setLargo(getLargo() + 1);
		}
		aux = aux->getSgte();
	}
}

void lista_doble_circular::desplegarInversa() {
	int tam = getLargo();

	if (!esVacia()) {
		NodoD* aux = getCab()->getAnterior();
		for (int i = 1; i <= tam;i++) {
			cout << "(" << aux->getDato() << ")" << "->";
			aux = aux->getAnterior();
		}
		cout << "Final \n\n\n";
	}
}

float lista_doble_circular::promedio()
{
	float promedio = 0;
	if (!esVacia()) {
		NodoD* aux = getCab();

		for (int i = 1; i <= getLargo(); i++) {
			promedio += aux->getDato();
			aux = aux->getSgte();
		}
		aux = aux->getSgte();
		promedio = promedio / getLargo();
	}

	return promedio;
}

void lista_doble_circular::borrarPosicionPar()
{
	NodoD* aux = getCab();

	int tam = getLargo();

	for (int i = 0; i <= tam - 1; i++) {
		if (i % 2 == 0) {
			if (i == 0) {
				aux->getSgte()->setAnterior(aux->getAnterior());
				aux->getAnterior()->setSgte(aux->getSgte());
				setLargo(getLargo() - 1);
				setCab(aux->getSgte());
			}
			else {
				aux->getSgte()->setAnterior(aux->getAnterior());
				aux->getAnterior()->setSgte(aux->getSgte());
				setLargo(getLargo() - 1);
			}
		}
		aux = aux->getSgte();
	}


}