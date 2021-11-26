#ifndef ARTICULOS_H
#define ARTICULOS_H
#include <iostream>
#include <stdlib.h>
#include "Categoria.h"
#include <bits/stdc++.h>
#include <vector>
using std::string;
using std::cout;
using namespace std;

class Articulos
{
	public:
		Articulos(string,vector<char>,double,int ,double,Categoria*);
		~Articulos();
		void setNombre(string);
        string getNombre();

        void setPrecio(int);
        double getPrecio();
        void setCantidad(int);
        int getCantidad();
        void setCategoria(string);
        Categoria* getCategoria();
        double getDescuento();
        void setDescuento(double);
        string toString();
        string printVector();
        vector<char> getTallas();
	private:
		string nombre;
		vector<char> tallas;
		double precio;
		int cantidad;
		double descuento;
		Categoria* categoria;
		
	protected:
};

#endif