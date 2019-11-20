#include "arbol.h"
#include "Markup.h"

Node* arbol::newNode(string etiqueta,string descripcion)
{
	Node* temp = new Node;
	temp->etiqueta = etiqueta;
	temp->descripcion = descripcion;
	return temp;
}
void arbol::print(Node* root)
{
	if (root == NULL)
		return;

	// Creo un queue y le enqueue el inicio del arbol
	queue<Node*>q;
	q.push(root);

	// uso 2 ciclos para imprimir el arbol por grado  
	while (!q.empty())
	{
		int n = q.size();
		while (n > 0)
		{
			// creo un nodo p y le asigno el primero valor de el queue 
			Node* p = q.front();
			q.pop();
			cout <<" ( "<< p->etiqueta << " | " << p->descripcion << " ) ";

			// vuelvo a enqueue -1
			for (int i = 0; i < p->child.size(); i++)
				q.push(p->child[i]);
			n--;
		}

		cout << endl; // salto de linea para definir niveles
	}
}
Node * arbol::CargarArbol()
{
	string tmp;
	string contenido;
	CMarkup xml;
	xml.Load("play.xml");

	//lista PADRE
	xml.FindElem();
	tmp = xml.GetAttrib().c_str();
    root = newNode(tmp," ");
	xml.IntoElem();

	//product 1 HIJO 
	xml.FindElem();
	tmp = xml.GetAttrib().c_str();
	(root->child).push_back(newNode(tmp," "));
	xml.IntoElem();

	//Ingresando "nietos" NAME DESCRIPCION PRECIO CANTIDAD
	for (int i = 0; i < 4; i++)
	{
		xml.FindElem();
		tmp = xml.GetAttrib().c_str();
		contenido = xml.GetData().c_str();
		(root->child[0]->child).push_back(newNode(tmp, contenido));
	}
	
	//regresa para arriba
	xml.OutOfElem();
	//product 2 hijo
	xml.FindElem();
	tmp = xml.GetAttrib().c_str();
	(root->child).push_back(newNode(tmp," "));
	xml.IntoElem();

	//Ingresando "nietos" NAME DESCRIPCION PRECIO CANTIDAD
	for (int i = 0; i < 4; i++)
	{
		xml.FindElem();
		tmp = xml.GetAttrib().c_str();
		contenido = xml.GetData().c_str();
		(root->child[1]->child).push_back(newNode(tmp, contenido));

	}
	return root;
}