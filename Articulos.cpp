#include "Articulos.h"

Articulos::Articulos(string x,vector<char> y,double z,int xx,double yy,Categoria* zz){
    this->nombre = x;
    this->tallas = y;
    this->precio = z;
    this->cantidad = xx;
    this->descuento = yy; 
    this->categoria = zz;

}

Articulos::~Articulos(){
	delete[] categoria;
}
string Articulos::toString(){
	string print = "[";
	print += nombre;
	print += " ,";
	print += to_string(precio);
	print += ", ";
	print += to_string(cantidad);
	print +=", ";
	print +=to_string(descuento);
	print +=", ";
	print +=categoria->getCategoria();
	print +=", ";
	print +=printVector();
	print += "]";
	return print;
}
string Articulos::printVector(){
    string print="";
    for(int i = 0 ; i <tallas.size(); i++){
        print+= "(" ;
        print+= tallas.at(i);
        print+= ") ";
    }
    return print;
}
Categoria* Articulos::getCategoria(){
	return categoria;
}
int Articulos::getCantidad(){
	return cantidad;
}
double Articulos::getPrecio(){
	return precio;
}
vector<char> Articulos::getTallas(){
    return tallas;
}