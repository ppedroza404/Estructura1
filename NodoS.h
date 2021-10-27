#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

class NodoS
{
	private:
		int dato;
		NodoS* sgte;
	public:
		NodoS();
		NodoS(int); // puntero al siguiente nodo;

		int getDato();
		NodoS* getSgte();

		void setDato(int dato);
		void setSgte(NodoS *sgte);
};

