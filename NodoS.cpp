#include "NodoS.h"
#include <stdlib.h>

NodoS::NodoS()
{
	this->dato = 0;
	this->sgte = NULL;
}

NodoS::NodoS(int _dato)
{
	this->dato = _dato;
	this->sgte = NULL;
}

int NodoS::getDato()
{
	return this->dato;
}

NodoS* NodoS:: getSgte()
{
	return this->sgte;
}

void NodoS::setDato(int _dato)
{
	this->dato = _dato;
}

void NodoS::setSgte(NodoS* sgte)
{
	this->sgte = sgte;
}