#ifndef ARBOL_H
#define ARBOL_H
#include"Markup.h"
#include <queue>
#include <string>
#include<iostream>

using namespace std;
struct Node
{
	string etiqueta;
	string descripcion;
	vector<Node*>child;
};
class arbol
{

public:
	arbol():root(0)
	{}
	Node* newNode(string etiqueta,string descripcion);
	void print(Node*);
	Node * CargarArbol();
private:
	Node* root;
};





#endif // !ARBOL_H


