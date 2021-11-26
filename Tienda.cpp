#include "Tienda.h"

Tienda::Tienda() {

	agregarCategoria(new Categoria("Camisetas"));
	agregarCategoria(new Categoria("Pantalones"));
	agregarCategoria(new Categoria("Zapatos"));

}

Tienda::~Tienda() {
	for(int i = 0; i < articulos.size(); i++) {
		delete articulos[i];
	}
	for(int i = 0 ; i < categorias.size() ; i++) {
		delete categorias[i];
	}

}


vector<Categoria*> Tienda::getCategorias() {
	return categorias;
}


void Tienda::printCategorias() {
	int opcion;
	for(int i = 0; i < categorias.size(); i++) {
		cout<< i << ") " <<categorias.at(i)->getCategoria() << "\n";
		opcion = i;
	}
	opcion++;
	cout<< opcion << ") " <<"Ninguna" << "\n";
}

void Tienda::agregarCategoria(Categoria* categ) {
	this->categorias.push_back(categ);
}

void Tienda::agregarArticulo(Articulos* art) {
	this->articulos.push_back(art);
}

void Tienda::printArticulos() {
	int opcion;
	for(int i = 0; i < articulos.size(); i++) {
		cout<< i << ") " << articulos.at(i)->toString() << "\n";
	}
}
void Tienda::eraseArticulo(int cual) {
	articulos.erase(articulos.begin()+cual);
}
void Tienda::eraseCategoria(int cual) {
	categorias.erase(categorias.begin()+cual);
}

void Tienda::listarArticulos() {
	double totalPrecio = 0;
	int totalUnidades = 0;
	cout<<"\n";
	for(int i =0; i <categorias.size(); i++) {
		int categoriaPrecio = 0;
		int categoriaUnidades = 0;
		cout<<"Articulos " << categorias.at(i)->getCategoria()<<"\n";
		for(int j=0; j < articulos.size(); j++) {
			//cout<<categorias.at(i)->getCategoria()<<" y "<<articulos.at(j)->getCategoria()->getCategoria() << "\n";
			if(categorias.at(i)->getCategoria().compare(articulos.at(j)->getCategoria()->getCategoria()) == 0) {
				cout<< " - " << (articulos.at(i)->toString())<< "\n";
				totalPrecio += articulos.at(i)->getPrecio();
				categoriaPrecio += articulos.at(i)->getPrecio();
				categoriaUnidades += articulos.at(i)->getCantidad();
				totalUnidades += articulos.at(i)->getCantidad();
			}
		}
		cout <<" = PRECIO DE CATEGORIA TOTAL: "<< categoriaPrecio<<"\n";
		cout <<" = UNIDADES DE CATEGORIA TOTAL: "<< categoriaUnidades<<"\n\n\n";
	}
	cout <<"========RESUMEN TOTAL========\n";
	cout <<" PRECIO TOTAL: " << totalPrecio<<"\n";
	cout <<" UNIDADES TOTALES: " << totalUnidades<<"\n";
	cout <<" PRODUCTOS UNICOS: " << articulos.size()<<"\n\n\n";

}
void Tienda::buscarArticulos(int categ, int size) {
	if(categ == -1) {
		if(size == -1) {
			for(int i = 0; i < articulos.size(); i++) {
				cout<< " - " << (articulos.at(i)->toString())<< "\n";
			}
		} else {
			for(int i = 0; i < articulos.size(); i++) {

			}
		}
	} else {
		if(size == -1) {
			for(int i = 0; i < articulos.size(); i++) {
				if(categorias.at(categ)->getCategoria().compare(articulos.at(i)->getCategoria()->getCategoria()) == 0) {
					cout<< " - " << (articulos.at(i)->toString())<< "\n";
				}
			}
		}
	}
	cout<<"\n";
}
