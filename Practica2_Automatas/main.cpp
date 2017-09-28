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

void getTransitionsTable(string * sigma, string * states, string ** table){
	//string[][] transitionstable = new string[(*states).size()][(*sigma).size()];
	//string transitionstable[(*states).size()][(*sigma).size()];
	for(int i = 0; i <= (signed)(*states).size(); i++){
		for(int x = 0; x <= (signed)(*sigma).size(); x++){
			cout<<" ("<<states[i]<<","<<sigma[x]<<") = ";
			cin>>table[i][x];
		}
		//cout<<endl;
	}
	return;
	//return transitionstable;
}

int main(){
	string sigma_in, states_in, finalstates_in;
	string * sigma;
	string * states;
	string * finalstates;

	getline(cin, sigma_in);
	sigma = separate(sigma_in);
	getline(cin, states_in);
	states = separate(states_in);
	getline(cin, finalstates_in);
	finalstates = separate(finalstates_in);

	/*printvalues(sigma);
	printvalues(states);
	printvalues(finalstates);*/

	string **table;
	table = (string**)malloc((*states).size() * sizeof(string*));
	for(int i = 0; i<= (signed)(*states).size(); i++){
		table[i] = (string*)malloc((*sigma).size() * sizeof(string));
	}
	getTransitionsTable(sigma, states, table);
	for(int i = 0; i <= (signed)(*states).size(); i++){
		printvalues(table[i]);
	}

	return 0;
}



