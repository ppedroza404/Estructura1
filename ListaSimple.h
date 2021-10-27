#pragma once
#include "NodoS.h"

class ListaSimple
{
private:
	NodoS* cab;
	int largo;

public:
	ListaSimple(); //contsructor del tad
	~ListaSimple(); // destructor del tad

	NodoS* getCab();
	int getLargo();

	void setCab(NodoS*);
	void setLargo(int);

	void desplegar();
	void agregarInicio(int);
	bool agregarAntesDe(int, int);

};


