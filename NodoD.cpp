#include "NodoD.h"
#include <stdlib.h>

NodoD::NodoD()
{
    this->dato = 0;
    this->sgte = NULL;
    this->anterior = NULL;

}

NodoD::NodoD(int dato)
{
    this->dato = dato;
    this->sgte = NULL;
    this->anterior = NULL;

}

int NodoD::getDato()
{
    return this->dato;
}

NodoD* NodoD::getSgte()
{
    return this->sgte;
}

NodoD* NodoD::getAnterior()
{
    return this->anterior;
}

void NodoD::setDato(int dato)
{
    this->dato = dato;
}

void NodoD::setSgte(NodoD* sgte)
{
    this->sgte = sgte;
}

void NodoD::setAnterior(NodoD* anterior)
{
    this->anterior = anterior;
}
