#include <iostream>
#include <vector>
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

struct Comentarios {
    int idComentarios;
    Producto producto;
    Usuario usuario;
    string comentario;
    string fecha;
};
// Prueba 3
// xd
int main(){

    return 0;
}