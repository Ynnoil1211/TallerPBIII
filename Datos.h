#ifndef DATOS_H
#define DATOS_H

#include "Structs.h"
#include <vector>
#include <fstream>
using namespace std;

constexpr double IMPUESTO = 0.19;
constexpr double ENVIO = 1250.16;

vector<CarritoDeCompras> carritos;
vector<Usuario> Usuarios;
vector<Producto> Productos;
vector<Comentario> comentarios;


inline void inicializarUsuarios() {

}
inline void inicializarProductos() {

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
        comentarios.back().produc = *(find_if(Productos.begin(), Productos.end(), [=](const Producto &p) {
            return p.nombre == (line.substr(begin, pos - begin));
        }));

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
