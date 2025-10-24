#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <windows.h>
#include "Structs.h"
#include "Datos.h"
using namespace std;

// Funciones para formato
void mostrarLineaSeparadora() {
    cout << string(135, '=') << endl;
}

void mostrarEncabezadoTabla(const string& titulo) {
    cout << "\n";
    mostrarLineaSeparadora();
    int espacios = (135 - titulo.length()) / 2;
    cout << string(espacios, ' ') << titulo << endl;
    mostrarLineaSeparadora();
}

void mostrarColumnas(bool conCantidad = false) {
    cout << left
         << setw(25) << "NOMBRE"
         << setw(80) << "DESCRIPCION"
         << setw(15) << "PRECIO"
         << setw(10) << (conCantidad ? "CANT." : "STOCK")
         << endl;
    mostrarLineaSeparadora();
}

void mostrarFilaProducto(int numero, const Producto& p, bool esCantidad = false, int cantidad = 1) {
    string nombre = p.nombre;
    if (nombre.length() > 25) {
        nombre = nombre.substr(0, 25);
    }

    string desc = p.descripcion;
    if (desc.length() > 80) {
        desc = desc.substr(0, 80);
    }

    cout << left
         << setw(25) << nombre
         << setw(80) << desc
         << setw(1) << "$"
         << right << setw(14) << fixed << setprecision(2) << p.precio
         << setw(10) << (esCantidad ? cantidad : p.stock)
         << endl;
}

//mostrar todos los usuarios
void listarUsuarios (){
    cout<<"//////Lista de Usuarios//////"<<endl;
    for(const auto& u : Usuarios){
        cout<<"ID: "<<u.idUsuario<<endl;
        cout<<"Nombre: "<<u.nombre<<endl;
        cout<<"Correo: "<<u.correoElectronico<<endl;
        cout<<"Direccion: "<<u.direccion<<endl;
        cout<<"Metodo de Pago: "<<u.metodoDePago<<endl;
        cout<<"-----------------------"<<endl;
    }
    cout<<"Usuarios cargados con exito. "<<endl;
}
//booleano para comparar dos fechas
bool compararFechas(const string& s1, const string& s2){
    int a1,a2,m1,m2,d1,d2;
    stringstream ss1(s1);
    stringstream ss2(s2);
    char slash;
    ss1>>d1>>slash>>m1>>slash>>a1;
    ss2>>d2>>slash>>m2>>slash>>a2;
    if(a1!=a2) return a1>a2;
    if (m1!=m2) return m1>m2;
    return d1>=d2;
}
//mostrar comentarios con la comparacion 
void cargarComentarios(const string &date){
    cout<<"Cargando Comentarios..."<<endl;
    system("cls");
    bool mostrar = false; 
    bool message = true;
    for(auto& comment : comentarios){
        if(compararFechas(comment.fecha, date)){
            if(message){
                cout<<"Comentarios (after "<<date<<") encontrados: "<<endl;
                message = false;
            }
            mostrar = true;
            cout<<"Id. Comentario: "<<comment.idComentario<<endl;
            cout<<"Producto: " <<comment.produc.nombre<<endl;
            cout<<"Usuario: " <<comment.user<<endl;
            cout<<"Comentario: "<<comment.comento<<endl;
            cout<<"Fecha: "<<comment.fecha<<endl;
        }
    }
    if(!mostrar){
        cout<<"0 comentario encontrado. "<<endl;
    }
}


void mostrarEncabezadoProductos() {
    mostrarEncabezadoTabla("PRODUCTOS CON BAJO STOCK (Menos de 15 unidades)");
    mostrarColumnas(false);
}

int contarProductosBajoStock() {
    int contador = 0;
    for (const auto& p : Productos) {
        if(p.stock < 15) {
            mostrarFilaProducto(p.idProducto, p, false);
            contador++;
        }
    }
    return contador;
}

void listarProductos() {
    mostrarEncabezadoProductos();
    int total = contarProductosBajoStock();
    mostrarLineaSeparadora();
    cout << "Total de productos con bajo stock: " << total << endl << endl;
}


void mostrarEncabezadoCarrito(const CarritoDeCompras &carrito) {
    mostrarEncabezadoTabla("CARRITO DE COMPRAS");
    cout << "Usuario: " << carrito.usuario.nombre << " (" << carrito.usuario.correoElectronico << ")" << endl;
    cout << "ID Carrito: " << carrito.idCarrito << endl;
    mostrarLineaSeparadora();
}

void mostrarProductosCarrito(const CarritoDeCompras &carrito) {
    mostrarColumnas(true);

    if (carrito.productos.empty()) {
        cout << "El carrito está vacío" << endl;
        mostrarLineaSeparadora();
        return;
    }

    for (size_t i = 0; i < carrito.productos.size(); i++) {
        const int idProducto = carrito.productos[i];
        const Producto& p = Productos[idProducto - 1];
        mostrarFilaProducto(static_cast<int>(i) + 1, p, true, 1);
    }
    mostrarLineaSeparadora();
}

void mostrarResumenCarrito(const CarritoDeCompras &carrito) {
    double total = carrito.subtotal + carrito.impuestos + ENVIO;

    cout << "\n" << "RESUMEN DE COMPRA" << endl;
    mostrarLineaSeparadora();

    cout << left << setw(120) << "Subtotal:"
         << setw(1) << "$"
         << right << setw(14) << fixed << setprecision(2) << carrito.subtotal << endl;

    cout << left << setw(120) << "Impuestos (19%):"
         << setw(1) << "$"
         << right << setw(14) << fixed << setprecision(2) << carrito.impuestos << endl;

    cout << left << setw(120) << "Envío:"
         << setw(1) << "$"
         << right << setw(14) << fixed << setprecision(2) << ENVIO << endl;

    mostrarLineaSeparadora();

    cout << left << setw(120) << "TOTAL A PAGAR:"
         << setw(1) << "$"
         << right << setw(14) << fixed << setprecision(2) << total << endl;

    mostrarLineaSeparadora();
}

void mostrarCarrito(const CarritoDeCompras &carrito) {
    system("cls");
    mostrarEncabezadoCarrito(carrito);
    mostrarProductosCarrito(carrito);
    mostrarResumenCarrito(carrito);
    cout << "\n";
}

void addProducto(CarritoDeCompras &carrito, const int idProducto, const int cantidad) {
    Productos[idProducto-1].stock -= cantidad;
	carrito.productos.push_back(idProducto);
	carrito.subtotal += Productos[idProducto - 1].precio * cantidad;
	carrito.impuestos = carrito.subtotal * 0.19;
}

void crearCarrito(const int idUsuario) {
	const int id = (carritos.empty() ? carritos.back().idCarrito+1 : 1);
	const CarritoDeCompras carrito = {id,Usuarios[idUsuario - 1],{},0.0,0.0};
	carritos.push_back(carrito);
}
void iniciarSesion() {
	
	string email;
	string pass;
	cout<<setw(15)<<"Inicio de sesion"<<endl;
	std::vector<Usuario>::iterator user;
	
	do {
		cout<<"Ingresar correo electronico: ";
		cin>>email;
	
		user = find_if(Usuarios.begin(), Usuarios.end(), [email](const Usuario& u) {
			return u.correoElectronico==email;
		});
	
		if(user!=Usuarios.end()) {
			
			cout<<"Usuario encontrado! "<<user->nombre<<"!!!";	
		}
		else {
			cout<<"Usuario no encontrado!, Ingrese uno nuevamente."<<endl;
		}
	} while(user==Usuarios.end());
	
	do {
		cout<<"Ingresar contraseña: ";
		cin>>pass;
		
		if (pass==user->contra) {
            cout << "Bienvenid@ "<<user->nombre<< "!!!"<<endl;
            break;
        }
	    cout<<"Contraseña incorrecta, intente nuevamente."<<endl;
	} while(true);
	
	system("pause");
}
int main(){
    SetConsoleOutputCP(65001);
    inicializarDatos();
    listarUsuarios();
    cargarComentarios("3/05/2025");
    listarProductos();
    system("pause");
    crearCarrito(1);
    addProducto(carritos[0], 1);
    addProducto(carritos[0], 5);
    addProducto(carritos[0], 10);
    mostrarCarrito(carritos[0]);
    return 0;
}
