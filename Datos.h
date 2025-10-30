#ifndef DATOS_H
#define DATOS_H

#include "Structs.h"
#include <vector>
#include <fstream>
#include <iomanip>
#include <unordered_map>
using namespace std;

constexpr double IMPUESTO = 0.19;
constexpr double ENVIO = 1250.16;

vector<CarritoDeCompras> carritos;
vector<Usuario> Usuarios;
vector<Producto> Productos;
unordered_map<string, size_t> pMap; // Para optimizar las busquedas
vector<Comentario> comentarios;


inline void inicializarUsuarios() {
 ifstream file("Usuarios.txt");
    string line;
    getline(file, line);
    while (getline(file, line)) {
        Usuarios.emplace_back();
        size_t begin = 0;
        size_t pos = line.find(',', begin);
        Usuarios.back().idUsuario = stoi(line.substr(begin, pos-begin));

        begin = pos+1;
        pos = line.find(',', begin);
        Usuarios.back().nombre = line.substr(begin, pos - begin);

        begin = pos+1;
        pos = line.find(',', begin);
        Usuarios.back().correoElectronico = line.substr(begin, pos - begin);

        begin = pos+1;
        pos = line.find(',', begin);
        Usuarios.back().contra = line.substr(begin, pos - begin);

       begin = pos+1;
        pos = line.find(',', begin);
        Usuarios.back().direccion= line.substr(begin, pos - begin);

        begin = pos+1;
        pos = line.find(',', begin);
        Usuarios.back().metodoDePago = line.substr(begin, pos - begin);
    }
    file.close();
}

inline void inicializarProductos() {
    ifstream file("productos.txt");
    string line;
    getline(file, line);
    while (getline(file, line)) {
        Productos.emplace_back();
        size_t begin = 0;
        size_t pos = line.find(',', begin);
        Productos.back().idProducto = stoi(line.substr(begin, pos-begin));

        begin = pos+1;
        pos = line.find(',', begin);
        Productos.back().nombre = line.substr(begin, pos - begin);
        // Mapa para optimizar busquedas en los comentarios
        pMap[Productos.back().nombre] = Productos.back().idProducto - 1;

        begin = pos+1;
        pos = line.find(',', begin);
        Productos.back().descripcion = line.substr(begin, pos - begin);

        begin = pos+1;
        pos = line.find(',', begin);
        Productos.back().precio = stod(line.substr(begin, pos - begin));

        begin = pos+1;
        Productos.back().stock = stoi(line.substr(begin));
    }
    file.close();
}
inline void inicializarComentarios() {
    ifstream file("comentarios.txt");
    string line;
    while(getline(file, line)){
        comentarios.emplace_back();
        size_t begin = 0;
        size_t pos = line.find(',', begin);
        comentarios.back().idComentario=(stoi(line.substr(begin, pos-begin)));

        begin=pos+1;
        pos = line.find(',', begin);
        string nom = line.substr(begin, pos-begin);
        comentarios.back().produc = Productos[pMap[nom]];

        begin=pos+1;
        pos = line.find(',', begin);
        comentarios.back().user=(line.substr(begin, pos-begin));

        begin=pos+1;
        pos = line.find(',', begin);
        comentarios.back().comento=(line.substr(begin, pos-begin));

        begin=pos+1;
        comentarios.back().fecha=(line.substr(begin));
    }
    file.close();
}

inline void cargarCarritos() {
    ifstream file("carritos_guardados.txt");
    if (!file.is_open()) return; // Si no existe el archivo, no hay carritos guardados

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        CarritoDeCompras carrito;
        size_t begin = 0;
        size_t pos = line.find(',', begin);
        carrito.idCarrito = stoi(line.substr(begin, pos - begin));

        begin = pos + 1;
        pos = line.find(',', begin);
        int idUsuario = stoi(line.substr(begin, pos - begin));
        carrito.usuario = Usuarios[idUsuario - 1];

        begin = pos + 1;
        pos = line.find(',', begin);
        carrito.subtotal = stod(line.substr(begin, pos - begin));

        begin = pos + 1;
        pos = line.find(',', begin);
        carrito.impuestos = stod(line.substr(begin, pos - begin));

        begin = pos + 1;
        string productosStr = line.substr(begin);
        if (!productosStr.empty()) {
            size_t prodBegin = 0;
            while (prodBegin < productosStr.length()) {
                size_t prodPos = productosStr.find(';', prodBegin);
                if (prodPos == string::npos) prodPos = productosStr.length();

                int idProducto = stoi(productosStr.substr(prodBegin, prodPos - prodBegin));
                carrito.productos.push_back(idProducto);

                prodBegin = prodPos + 1;
            }
        }

        carritos.push_back(carrito);
    }
    file.close();
}

inline void guardarCarritosPersistentes() {
    ofstream file("carritos_guardados.txt");
    if (!file.is_open()) return;

    for (const auto& carrito : carritos) {
        if (carrito.productos.empty()) continue;

        file << carrito.idCarrito << ","
             << carrito.usuario.idUsuario << ","
             << fixed << setprecision(2) << carrito.subtotal << ","
             << fixed << setprecision(2) << carrito.impuestos << ",";

        // Guardar IDs de productos separados por ;
        for (size_t i = 0; i < carrito.productos.size(); i++) {
            file << carrito.productos[i];
            if (i < carrito.productos.size() - 1) file << ";";
        }
        file << endl;
    }
    file.close();
}

inline void inicializarDatos() {
    inicializarUsuarios();
    inicializarProductos();
    inicializarComentarios();
    cargarCarritos();
}

#endif
