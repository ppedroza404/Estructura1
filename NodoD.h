#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

class NodoD
{
private:
	int dato;
	NodoD* sgte;
	NodoD* anterior;

public:
	NodoD();
	NodoD(int); // puntero al siguiente nodo;

	int getDato();
	NodoD* getSgte();
	NodoD* getAnterior();

	void setDato(int dato);
	void setSgte(NodoD* sgte);
	void setAnterior(NodoD* anterior);
};

