/*
 * Main.cpp
 *
 *  Created on: 07/09/2017
 *      Author: Mariana
 */

#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;


int main(){
	string sigma, l, w;

	//obtener las entradas

	getline(cin, sigma);
	getline(cin, l);
	getline(cin, w);

	//revisar si lenguaje y cadena pertenece al alfabeto
	//checar permutaciones de la cadena

	//crear dictionary
	map<int, map<string, int> > lenguaje;

	char * l_separado = new char[l.length()+1];
	strcpy (l_separado, l.c_str());
	l_separado = strtok(l_separado, ",");

	//DICCIONARIO GUARDA POR POSICIONES EMPEZANDO EN 1
	int posicion = 1;
	while(l_separado != NULL){
		//printf("%s\n", l_separado);
		lenguaje[posicion][l_separado] = strlen(l_separado);
		//printf("[%d][%s] = %d\n", posicion, l_separado, strlen(l_separado));
		posicion++;
		l_separado = strtok(NULL, ",");
	}

	//�rbol


	return 0;
}


