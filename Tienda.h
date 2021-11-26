#ifndef TIENDA_H
#define TIENDA_H
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Articulos.h"
#include "Categoria.h"
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
//using vector::at();


class Tienda
{
	public:
		Tienda();
		~Tienda();
		Categoria* elegirCategoria();
		void agregarCategoria(Categoria*);
		void agregarArticulo(Articulos*);
		vector<Categoria*> getCategorias();
		void printCategorias();
		void printArticulos();
		void eraseArticulo(int);
		void eraseCategoria(int);
		void listarArticulos();
		void buscarArticulos(int, int);
	private:
		int opcionMenu;
		vector<Categoria*> categorias;
		vector<Articulos*> articulos;
		
		
	protected:
};

#endif