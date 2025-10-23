#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
struct Usuario {
    int idUsuario;
    string nombre, correoElectronico, contraseña, direccion, metodoDePago;
};

struct Producto {
    int idProducto;
    string nombre, descripcion;
    double precio;
    int stock;
};

struct CarritoDeCompras {
    int idCarrito;
    Usuario usuario;
    vector<int> productos;
    double subtotal, impuestos;
};

struct OrdenDeCompra {
    int idOrden;
    vector<Producto> productos;
    double subtotal, impuestos, envio, total;
};

struct Categoria {
    int idCategoria;
    string nombre;
};

struct Comentario {
    int idComentario;
    Producto produc;
    Usuario user;
    string comento;
    string fecha;
};
/////////Datos::////////////////
vector<Usuario> Usuarios = {
        {1, "Juan Pérez", "juan.perez@email.com", "Qwerty123",
        "Carrera 45 #10-20", "Tarjeta de crédito"},
        {2, "Ana Gómez", "ana.gomez@email.com", "Pass456",
        "Calle 21 #35-50", "PayPal"},
    };
vector<Producto> Productos = {
    {1, "Laptop", "Portátil con pantalla Full HD y SSD de 512GB", 89999, 10},
    {2, "Smartphone", "Teléfono con cámara de 108MP y carga rápida", 49950, 20},
    {3, "Tablet", "Dispositivo con pantalla táctil de 10 pulgadas", 29999, 15},
    {4, "Auriculares", "Audífonos inalámbricos con cancelación de ruido", 12999, 25}
    };
vector<Comentario> comentarios = {
    {1, Productos[0], Usuarios[0], "Excelente rendimiento; muy rápida. ¡Me encanta!", "1/05/2025"},
    {2, Productos[1], Usuarios[1], "Buena cámara pero la batería dura poco.", "3/05/2025"},
    {3, Productos[2], Usuarios[0], "No me gustó; pantalla de baja calidad.", "5/05/2025"},
    {4, Productos[3], Usuarios[1], "Sonido aceptable pero el material parece frágil.", "6/05/2025"}
};
//mostrar todos los usairoos 
void listarUsuarios (const vector<Usuario> &Usuarios){
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
void cargarComentarios(const vector<Comentario> &comentarios, string date){
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
            cout<<"Usuario: " <<comment.user.nombre<<endl;
            cout<<"Comentario: "<<comment.comento<<endl;
            cout<<"Fecha: "<<comment.fecha<<endl;
        }
    }
    if(!mostrar){
        cout<<"0 comentario encontrado. "<<endl;
    }
}
int main(){
    listarUsuarios(Usuarios);
    cargarComentarios(comentarios,"3/05/2025");
    return 0;
}
