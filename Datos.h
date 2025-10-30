#ifndef DATOS_H
#define DATOS_H

#include "Structs.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>
using namespace std;

constexpr double IMPUESTO = 0.19;
constexpr double ENVIO = 1250.16;

vector<CarritoDeCompras> carritos;
vector<Usuario> Usuarios = {{1, "Juan Perez", "juan.perez@email.com", "Qwerty123", "a", "a"}};
vector<Producto> Productos;
unordered_map<string, size_t> pMap; // Para optimizar las busquedas
vector<Comentario> comentarios;


inline void inicializarUsuarios() {

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
inline void inicializarDatos() {
    inicializarUsuarios();
    inicializarProductos();
    inicializarComentarios();
}

#endif
