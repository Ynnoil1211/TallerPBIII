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
void listarProductos() {
    cout << "\n╔══════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                      PRODUCTOS CON BAJO STOCK (Menos de 15 unidades)                     ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
    cout << left << setw(5) << "ID"
         << setw(20) << "NOMBRE"
         << setw(45) << "DESCRIPCION"
         << right << setw(12) << "PRECIO"
         << setw(10) << "STOCK" << endl;
    cout << string(92, '=') << endl;

    int contador = 0;
    for (const auto& p : Productos) {
        if(p.stock < 15) {
            cout << left << setw(5) << p.idProducto
                 << setw(20) << p.nombre
                 << setw(45) << p.descripcion
                 << right << setw(12) << fixed << setprecision(2) << "$" + to_string(p.precio).substr(0, to_string(p.precio).find('.')+3)
                 << setw(10) << p.stock << endl;
            contador++;
        }
    }
    cout << string(92, '=') << endl;
    cout << "Total de productos con bajo stock: " << contador << endl << endl;
}
void addProducto(CarritoDeCompras &carrito, int idProducto) {

}
void iniciarSesion() {
	
	string email;
	string pass;
	cout<<setw(15)<<"Inicio de sesion"<<endl;
	const Usuario* usuarioEncontrado=nullptr;
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
        } else {
            cout<<"Contraseña incorrecta, intente nuevamente."<<endl;
        }
	}while(true);
	
	system("pause");
}
int main(){
    SetConsoleOutputCP(65001);
    inicializarDatos();
    listarUsuarios();
    cargarComentarios("3/05/2025");
    listarProductos();
    return 0;
}
