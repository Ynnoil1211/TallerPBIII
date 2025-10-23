#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <vector>
using namespace std;

struct Usuario {
    int idUsuario;
    string nombre, correoElectronico, contra, direccion, metodoDePago;
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
    string user;
    string comento;
    string fecha;
};

#endif

