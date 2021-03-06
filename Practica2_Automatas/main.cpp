/*
 * main.cpp
 *
 *  Created on: 28/09/2017
 *      Author: Mariana
 */

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

string * separate (string string_in){
	string * string_out = new string[string_in.length()+1];
	char * string_x = new char[string_in.length() + 1];

	strcpy(string_x, string_in.c_str());
	string_x = strtok(string_x, ",");

	int x = 0;
	while(string_x != NULL){
		string_out[x] = string_x;
		string_x = strtok(NULL, ",");
		x++;
	}
	return string_out;
}

void printvalues( string * out){
	cout<<(*out).size()<<endl;
	for(int i = 0; i <= (signed)(*out).size(); i++){
		cout<<out[i]<<" ";
	}
	cout<<endl;
	return;
}



int main(){
	string sigma_in, states_in, finalstates_in;
	string * sigma;
	string * states;
	string * final_states;

	cout<<"Ingresa sigma separado por comas:"<<endl<<"Por ejemplo: a,b,c"<<endl;
	getline(cin, sigma_in);
	fflush(stdin);
	sigma = separate(sigma_in);
	cout<<"Ingresa los estados del AFD separados por comas: ";
	getline(cin, states_in);
	states = separate(states_in);
	fflush(stdin);
	cout<<"Ingresa el estado final: ";
	getline(cin, finalstates_in);
	final_states = separate(finalstates_in);
	int states_size = (*states).size();
	int sigma_size = (*sigma).size();
	string transitionstable[states_size][sigma_size];
	int counter;
	string w;
	for(int r = 0; r <= states_size; r++){
		for(int c = 0; c <= sigma_size; c++){
			cout<<" ("<<states[r]<<" "<<r<<","<<sigma[c]<<" "<<c<<") = ";
			fflush(stdin);
			getline(cin,transitionstable[r][c]);
		}
	}

	for(int r = 0; r <= states_size; r ++){
		for(int c = 0; c <= sigma_size; c ++){
			cout<<r<<" - "<<c;
			cout<<transitionstable[r][c]<<" ";
		}
		cout<<endl;
	}
	cout<<"Ingresa la cantidad de palabras a leer:";
	cin>>counter;
	cin.ignore();
	fflush(stdin);

	do{
		cout << "Ingresa la palabra:" << endl << "w = ";
		getline(cin, w);


	}while(counter > 0);
	/*printvalues(sigma);
	printvalues(states);
	printvalues(finalstates);*/



	return 0;
}



