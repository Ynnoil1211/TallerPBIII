#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include "Structs.h"
#include "Datos.h"
using namespace std;

void mostrarLineaSeparadora() {
    cout << string(145, '=') << endl;
}

void mostrarEncabezadoTabla(const string& titulo) {
    cout << "\n";
    mostrarLineaSeparadora();
    const int espacios = (145 - titulo.length()) / 2;
    cout << string(espacios, ' ') << titulo << endl;
    mostrarLineaSeparadora();
}

void mostrarColumnas(const bool conCantidad = false) {
    cout << left
         << setw(5) << "ID"
         << setw(25) << "NOMBRE"
         << setw(80) << "DESCRIPCION"
         << setw(15) << "PRECIO"
         << setw(10) << (conCantidad ? "CANT." : "STOCK")
         << endl;
    mostrarLineaSeparadora();
}

void mostrarFilaProducto(const Producto& p, bool esCantidad = false, int cantidad = 1) {
    cout << left
         << setw(5) << p.idProducto
         << setw(25) << p.nombre
         << setw(80) << p.descripcion
         << setw(1) << "$"
         << setw(14) << fixed << setprecision(2) << p.precio
         << setw(10) << (esCantidad ? cantidad : p.stock)
         << endl;
}

void listarUsuarios (){
    cout<<"====== Lista de Usuarios ======"<<endl;
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

bool compararFechas(const string& s1, const string& s2){
    int a1,a2,m1,m2,d1,d2;
    stringstream ss1(s1);
    stringstream ss2(s2);
    char slash;
    ss1>>a1>>slash>>m1>>slash>>d1;
    ss2>>a2>>slash>>m2>>slash>>d2;
    if(a1!=a2) return a1>a2;
    if (m1!=m2) return m1>m2;
    return d1>=d2;
}

void cargarComentarios(const string &date){
    cout<<"Cargando Comentarios..."<<endl;
    system("cls");

    mostrarEncabezadoTabla("COMENTARIOS DESPUES DE " + date);

    cout << left
         << setw(5) << "ID"
         << setw(25) << "PRODUCTO"
         << setw(25) << "USUARIO"
         << setw(70) << "COMENTARIO"
         << setw(15) << "FECHA"
         << endl;
    mostrarLineaSeparadora();

    int contador = 0;
    for(auto& comment : comentarios){
        if(compararFechas(comment.fecha, date)){
            contador++;

            cout << left
                 << setw(5) << comment.idComentario
                 << setw(25) << comment.produc.nombre
                 << setw(25) << comment.user
                 << setw(70) << comment.comento
                 << setw(15) << comment.fecha
                 << endl;
        }
    }

    mostrarLineaSeparadora();

    if(contador == 0) cout << "No hay comentarios despues de " << date << "." << endl;
    else cout << "Total de comentarios encontrados: " << contador << endl;

    cout << endl;
}

int productosBajoStock() {
    int contador = 0;
    for (const auto& p : Productos) {
        if(p.stock < 15) {
            mostrarFilaProducto(p, false);
            contador++;
        }
    }
    return contador;
}

void listarProductos() {
    mostrarEncabezadoTabla("LISTA DE PRODUCTOS");
    mostrarColumnas(false);
    for (const auto& p : Productos) mostrarFilaProducto(p, false);
    mostrarLineaSeparadora();
    cout << "Total de productos: " << Productos.size() << endl << endl;
}

void bajoStock() {
    mostrarEncabezadoTabla("PRODUCTOS CON BAJO STOCK (Menos de 15 unidades)");
    mostrarColumnas(false);
    const int total = productosBajoStock();
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
    for (const auto &id : carrito.productos) mostrarFilaProducto(Productos[id-1], true, 1);
    mostrarLineaSeparadora();
}

void mostrarResumenCarrito(const CarritoDeCompras &carrito) {
    const double total = carrito.subtotal + carrito.impuestos + ENVIO;

    cout << "\n" << "RESUMEN DE COMPRA" << endl;
    mostrarLineaSeparadora();

    cout << left << setw(130) << "Subtotal:"
         << setw(1) << "$"
         << right << setw(14) << fixed << setprecision(2) << carrito.subtotal << endl;

    cout << left << setw(130) << "Impuestos (19%):"
         << setw(1) << "$"
         << right << setw(14) << fixed << setprecision(2) << carrito.impuestos << endl;

    cout << left << setw(130) << "Envío:"
         << setw(1) << "$"
         << right << setw(14) << fixed << setprecision(2) << ENVIO << endl;

    mostrarLineaSeparadora();

    cout << left << setw(130) << "TOTAL A PAGAR:"
         << setw(1) << "$"
         << right << setw(14) << fixed << setprecision(2) << total << endl;

    mostrarLineaSeparadora();
}

void mostrarCarrito(const CarritoDeCompras &carrito) {
    system("cls");
    if (carrito.productos.empty()) {
        cout << "El carrito de compras esta vacio." << endl;
        return;
    }

    mostrarEncabezadoCarrito(carrito);
    mostrarProductosCarrito(carrito);
    mostrarResumenCarrito(carrito);
    cout << "\n";
}

void addProducto(CarritoDeCompras &carrito, const int idProducto) {
    Productos[idProducto-1].stock--;
	carrito.productos.push_back(idProducto);
	carrito.subtotal += Productos[idProducto - 1].precio;
	carrito.impuestos = carrito.subtotal * IMPUESTO;
}

void guardarCarritosEnArchivo() {
    ofstream file("carritos.txt");

    if (!file.is_open()) {
        cout << "Error al abrir el archivo para guardar los carritos." << endl;
        return;
    }

    // Escribir encabezado
    file << "========================================" << endl;
    file << "       CARRITOS DE COMPRAS GUARDADOS   " << endl;
    file << "========================================" << endl << endl;

    for (const auto& carrito : carritos) {
        if (carrito.productos.empty()) continue; // Solo guardar carritos con productos

        const double total = carrito.subtotal + carrito.impuestos + ENVIO;

        file << "ID Carrito: " << carrito.idCarrito << endl;
        file << "Usuario: " << carrito.usuario.nombre << endl;
        file << "Correo: " << carrito.usuario.correoElectronico << endl;
        file << "Direccion: " << carrito.usuario.direccion << endl;
        file << "Metodo de Pago: " << carrito.usuario.metodoDePago << endl;
        file << string(80, '-') << endl;

        file << "PRODUCTOS:" << endl;
        for (const auto& idProd : carrito.productos) {
            const auto& p = Productos[idProd - 1];
            file << "  - " << p.nombre
                 << " | $" << fixed << setprecision(2) << p.precio << endl;
        }

        file << string(80, '-') << endl;
        file << "Subtotal: $" << fixed << setprecision(2) << carrito.subtotal << endl;
        file << "Impuestos (19%): $" << fixed << setprecision(2) << carrito.impuestos << endl;
        file << "Envio: $" << fixed << setprecision(2) << ENVIO << endl;
        file << "TOTAL: $" << fixed << setprecision(2) << total << endl;
        file << string(80, '=') << endl << endl;
    }

    file.close();
    cout << "Carritos guardados exitosamente en 'carritos.txt'" << endl;
}

void crearCarrito(const int idUsuario) {
	const int id = (carritos.empty() ? 1 : carritos.back().idCarrito+1);
	const CarritoDeCompras carrito = {id,Usuarios[idUsuario - 1],{},0.0,0.0};
	carritos.push_back(carrito);
}
vector<Usuario>::iterator iniciarSesion() {
	
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
			
			cout<<"Usuario encontrado! "<<user->nombre<<"!!!"<<endl;
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
    return user;
}
void entradaEnRango(int &val, const int min, const int max, const string &msg, const string &error) {
    do {
        cout<<msg;
        cin>>val;
        if (val>max || val<min) cout<<error<<endl;
    } while (val>max || val<min);
}
int main(){
    SetConsoleOutputCP(65001);
    inicializarDatos();
    const auto user = iniciarSesion();
    crearCarrito(user->idUsuario);
    for (int opcion=-1;;) {
        system("cls");
        cout << "====== Menu Principal ======" << endl;
        cout << "1. Listar usuarios" << endl;
        cout << "2. Listar productos" << endl;
        cout << "3. Cargar comentarios despues de una fecha" << endl;
        cout << "4. Añadir producto al carrito de compras" << endl;
        cout << "5. Salir" << endl;
        entradaEnRango(opcion, 1, 5, "Seleccione una opcion (1-5): ", "Opcion invalida. Intente nuevamente.");
        system("cls");
        switch (opcion) {
            case 1: {
                listarUsuarios();
                break;
            }
            case 2: {
                cout << "====== Listar Productos ======" << endl;
                cout << "1. Todos los productos" << endl;
                cout <<"2. Productos con bajo stock" << endl;
                int subOpcion;
                entradaEnRango(subOpcion, 1, 2, "Seleccione una opcion (1-2): ", "Opcion invalida. Intente nuevamente.");
                system("cls");
                if (subOpcion == 1) listarProductos();
                else bajoStock();
                break;
            }
            case 3: {
                string date;
                cout << "Ingrese la fecha (aaaa/mm/dd): ";
                cin >> date;
                cargarComentarios(date);
                break;
            }
            case  4: {
                CarritoDeCompras &carrito = carritos.back();

                int idProducto;
                do {
                    entradaEnRango(idProducto, 0, Productos.size(), "Ingrese el ID del producto a añadir (0 para salir): ", "ID invalido. Intente nuevamente.");
                    if (idProducto == 0) break;
                    if (Productos[idProducto-1].stock==0) cout<<"Ese producto ya no esta en stock."<<endl;
                    else{
                    addProducto(carrito, idProducto);
                    cout << "Producto añadido al carrito." << endl;
                    }
                } while (true);
                system("cls");
                mostrarCarrito(carrito);
                break;
            }
            case 5: {
                guardarCarritosEnArchivo();
                guardarCarritosPersistentes();
                cout << "Gracias" << endl;
                return 0;
            }
        }
        system("pause");
    }
}