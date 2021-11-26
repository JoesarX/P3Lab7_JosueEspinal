#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Articulos.h"
#include "Categoria.h"
#include "Tienda.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;

int menu();
int menuTallas();
int menu2();

int main(int argc, char** argv) {
	int opcionmenu = 0;
	opcionmenu = menu();
	Tienda* t = new Tienda;
	vector<char> tt;
	tt.push_back('S');
	t->agregarArticulo(new Articulos("Camiseta",tt,100,4,71,t->getCategorias().at(0)));
	t->agregarArticulo(new Articulos("2",tt,100,4,71,t->getCategorias().at(0)));
	t->agregarArticulo(new Articulos("3",tt,100,4,71,t->getCategorias().at(1)));
	t->agregarArticulo(new Articulos("4",tt,100,4,71,t->getCategorias().at(0)));

	while (opcionmenu != 5) {
		switch(opcionmenu) {
			case 1: {
				cout << "Ingrese la nueva categoria: ";
				string categ = "";
				cin >> categ;
				t->agregarCategoria(new Categoria(categ));
				break;
			}
			case 2: {
				int opcion2 = 0;
				opcion2 = menu2();
				switch(opcion2) {
					case 1: {
						cout << endl;
						t->printCategorias();
						int queCateg = 0;

						string nombre;
						double precio;
						int cantidad;
						double descuento;
						cout<<"Elija categoria del articulo: ";
						cin >> queCateg;
						cout<<"Nombre: ";
						cin >> nombre;
						vector<char> tallas;
						char si = 'S';
						char talla=' ';
						while(si == 'S') {//Talla en mayuscula
							cout<<"Elija talla(S,M,L): ";
							cin>> talla;
							tallas.push_back(talla);
							cout<<"Desea seguir agregando?(S/N): ";
							cin>>si;
						}
						cout<<"Ingrese precio: ";
						cin>>precio;
						cout<<"Ingrese cantidad: ";
						cin>>cantidad;
						cout<<"Ingrese descuento: ";
						cin>>descuento;
						t->agregarArticulo(new Articulos(nombre,tallas,precio,cantidad,descuento,t->getCategorias().at(queCateg)));
						break;
					}
					case 2: {
						cout << "Que articulo desea modificar\n";
						t->printArticulos();
						int articulo = 0;
						cin >> articulo;


						break;
					}

					case 3: {
						cout << "Que articulo desea eliminar:\n";
						t->printArticulos();
						int articulo = 0;
						cin >> articulo;
						t->eraseArticulo(articulo);
						break;
					}
					case 4: {
						t->printArticulos();
						cout<<"\n";
						break;
					}
				}
				break;
			}

			case 3: {
				t->listarArticulos();
				break;
			}
			case 4: {
				cout << "Que categoria desea ver\n";
				t->printCategorias();
				int categ = 0;
				cin >> categ;
				if(categ == t->getCategorias().size()){
					categ = -1;
				}
				int talla = menuTallas();
				t->buscarArticulos(categ,talla);
				break;
			}
		}
		opcionmenu = menu();
	}
	cout << "\nGracias por utilizar el programa. ";
	t->~Tienda();
	return 0;
}
int menu2() {
	int opcion = 0;
	cout << "\n========SubMenu=========" << endl
	     << "1) Agregar Articulo" << endl;
	cout << "2) Modificar Articulo" << endl;
	cout << "3) Eliminar Articulo" << endl;
	cout << "4) Listar Articulos" << endl;
	cout << "Ingrese su opcion: ";
	cin >> opcion;
	return opcion;
}
int menu() {
	int opcion = 0;
	cout << "===========Menu===========" << endl
	     << "1) Agregar Categorias" << endl;
	cout << "2) Mantenimiento de Articulos" << endl;
	cout << "3) Estadisticas Generales" << endl;
	cout << "4) Busquedas Generales" << endl;
	cout << "5) Salir" << endl;
	cout << "Ingrese su opcion: ";
	cin >> opcion;
	return opcion;
}
int menuTallas() {
	int opcion = 0;
	cout << "ELIJA EL TAMANIO:" << endl;
	cout << "1) S" << endl;
	cout << "2) M" << endl;
	cout << "3) L" << endl;
	cout << "4) Ninguna"<<endl;
	cin >> opcion;
	if(opcion == 4){
		opcion = -1;
	}
	return opcion;
}