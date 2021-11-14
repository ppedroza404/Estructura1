#include "lista_doble_lineal.h"
#include "NodoD.h"

lista_doble_lineal::lista_doble_lineal()
{
	this->cab = NULL;
	this->largo = 0;
}

NodoD* lista_doble_lineal::getCab()
{
	return this->cab;
}

int lista_doble_lineal::getLargo()
{
	return this->largo;
}

void lista_doble_lineal::setCab(NodoD* ptr)
{
	this->cab = ptr;
}

void lista_doble_lineal::setLargo(int n)
{
	this->largo = n;
}

int lista_doble_lineal::primero()
{
	int dato = 0;
	if (!esVacia()) {
		dato = getCab()->getDato();
	}
	return dato;
}

int lista_doble_lineal::ultimo()
{
	int dato = 0;
	if (!esVacia()) {
		NodoD* aux = getCab();
		while (aux->getSgte() != NULL) {
			aux = aux->getSgte();
		}
		dato = aux->getDato();
	}
	return dato;
}

bool lista_doble_lineal::esVacia()
{
	return this->cab == NULL;
}

bool lista_doble_lineal::existe(int dato)
{
	bool existe = false;
	if (!esVacia()) {
		NodoD* aux = getCab();
		while (aux->getSgte() != NULL && !existe) {
			if (aux->getDato() == dato) {
				existe = true;
			}
			else {
				aux = aux->getSgte();
			}
		}
	}
	return existe;
}

int lista_doble_lineal::datoPos(int dato)
{
	NodoD* aux = getCab();
	int pos = 0;
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

void lista_doble_lineal::desplegar()
{
	NodoD* aux = getCab();
	std::cout << "ELEMENTOS EN LA LISTA DOBLE LINEAL:" << std::endl;
	while (aux != NULL) {
		cout << aux->getDato() << "->";
		aux = aux->getSgte();
	}
	cout << "Final \n\n\n";

}
void lista_doble_lineal::ordenarAscendente()
{
}
void lista_doble_lineal::agregarInicio(int dato)
{
	NodoD* nuevo = new NodoD(dato); //Paso 1. Crear el nodo
	nuevo->setSgte(getCab()); //Paso 2. Enlazar el nuevo nodo a la lista
	//Paso 3 Reacomodar la lista con el nuevo nodo
	if (!esVacia()) {
		getCab()->setAnterior(nuevo);
	}
	setCab(nuevo);
	setLargo(getLargo() + 1);
}

void lista_doble_lineal::agregarFinal(int dato)
{
	NodoD* nuevo = new NodoD(dato);
	NodoD* aux = getCab();

	if (!esVacia()) {
		while (aux->getSgte() != NULL) {
			aux = aux->getSgte();
		}
		aux->setSgte(nuevo);
		nuevo->setAnterior(aux);
		setLargo(getLargo() + 1);
	}

}

NodoD* lista_doble_lineal::dirDato(int dato)
{// Devolver la direccion en la que se ubica el dato, sino existe en la lista devulve NULL	
	NodoD* dir = NULL;
	NodoD* aux = getCab();

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

NodoD* lista_doble_lineal::dirUltimo()
{
	NodoD* dir = NULL;
	NodoD* aux = getCab();

	while (aux->getSgte() != NULL) {
		aux = aux->getSgte();
	}
	dir = aux;
	return dir;
}

NodoD* lista_doble_lineal::dirAnteriorDato(int dato)
{
	NodoD* dir = NULL;
	NodoD* aux = getCab();

	while (aux != NULL && dir == NULL) {
		if (aux->getDato() == dato) {
			dir = aux->getAnterior();
		}
		else {
			aux = aux->getSgte();
		}
	}
	return dir;
}

NodoD* lista_doble_lineal::dirAnteriorDato(NodoD* nodo)
{
	NodoD* dir = NULL;
	NodoD* aux = getCab();

	while (aux != NULL && dir == NULL) {
		if (aux->getDato() == nodo->getDato()) {
			dir = aux->getAnterior();
		}
		else {
			aux = aux->getSgte();
		}
	}
	return dir;
}

bool lista_doble_lineal::agregarAntesDe(int _datoRef, int _dato)
{
	bool agregado = false;

	if (getCab()->getDato() == _dato) {
		agregarInicio(_dato);
		agregado = true;
	}
	else {
		NodoD* aux = dirDato(_datoRef);
		if (aux != NULL) {
			NodoD* nuevo = new NodoD(_dato);//Paso 1. Crear el nodo

			//Paso 2. Enlazar el nuevo nodo a la lista O sea guindar el nodo....
			nuevo->setSgte(aux);
			nuevo->setAnterior(aux->getAnterior());

			//Paso 3. Reacomodar la lista con el nuevo nodo. Recuede el orden....
			aux->getAnterior()->setSgte(nuevo);
			aux->setAnterior(nuevo);
			setLargo(getLargo() + 1);

			agregado = true;
		}
	}
	return agregado;
}

bool lista_doble_lineal::agregarDespuesDe(int _datoRef, int _dato)
{
	bool agregado = false;

	if (getCab()->getDato() == _dato) {
		agregarInicio(_dato);
		agregado = true;
	}
	else {
		NodoD* aux = getCab();
		while (aux->getSgte() != NULL && !agregado) {
			if (aux->getDato() == _datoRef) {
				NodoD* nuevo = new NodoD(_dato);
				NodoD* siguiente = aux->getSgte();
				aux->setSgte(nuevo);
				nuevo->setAnterior(aux);

				nuevo->setSgte(siguiente);
				siguiente->setAnterior(nuevo);
				agregado = true;
			}
			else {
				aux = aux->getSgte();
			}
		}
	}
	return agregado;
}

bool lista_doble_lineal::borrar(int _dato)
{
	bool eliminado = false;
	NodoD* aux = dirDato(_dato); //Paso 1. Señalo el nodo a eliminar
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

bool lista_doble_lineal::borrarLista()
{
	bool eliminado = true;
	if (!esVacia()) {
		NodoD* aux = getCab();
		while (aux->getSgte() != NULL) {
			setCab(aux->getSgte());
			delete aux;
			aux = getCab();
			largo--;
			eliminado = true;
		}
	}
	return eliminado;
}

bool lista_doble_lineal::agregarPos(int _dato, int _pos)
{
	return false;
}

bool lista_doble_lineal::borrarPos(int pos)
{
	bool eliminado = false;
	NodoD* aux = NULL;
	NodoD* ant = getCab();
	int contador = 1;

	if (!esVacia()) {
		while (aux == NULL && !eliminado) {
			if (contador + 1 == pos) {
				aux = ant->getSgte(); //Señalar el nodo a eliminar
				ant->setSgte(aux->getSgte()); //Reacomodar la lista con el nuevo nodo
			}
			else if (contador == 1 && contador == pos) {
				aux = getCab();  //señalar el nodo a eliminar
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

bool lista_doble_lineal::intercambiar()
{
	return false;
}

void lista_doble_lineal::eliminarTodasLasApariciones(int _dato)
{
}

bool lista_doble_lineal::agregarAscendente(int)
{
	return false;
}

void lista_doble_lineal::eliminarValoresRepetidosConsecutivos()
{
}

void lista_doble_lineal::eliminarValoresRepetidosNoConsecutivos()
{
}

void lista_doble_lineal::copiarInversa()
{
}
