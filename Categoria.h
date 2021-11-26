#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <vector>
#include <iostream>

using std::string;
using std::vector;
class Categoria
{
	public:
		Categoria(string);
		~Categoria();
		void setCategoria(string);
		string getCategoria();
	private:
		string categoria;
	protected:
};

#endif