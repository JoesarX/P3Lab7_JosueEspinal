#include "Categoria.h"

Categoria::Categoria(string categ){
	categoria = categ;
}

void Categoria::setCategoria(string categ){
	this->categoria = categ;
}

string Categoria::getCategoria(){
	return categoria;
}
Categoria::~Categoria(){
	
}