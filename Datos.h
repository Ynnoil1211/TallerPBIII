#ifndef DATOS_H
#define DATOS_H

#include "Structs.h"
#include <vector>
using namespace std;

inline vector<CarritoDeCompras> carritos;
inline vector<Usuario> Usuarios;
inline vector<Producto> Productos;
inline vector<Comentario> comentarios;

inline void inicializarDatos() {
    Usuarios = {
        {1, "Juan Pérez", "juan.perez@email.com", "Qwerty123",
        "Carrera 45 #10-20", "Tarjeta de crédito"},
        {2, "Ana Gómez", "ana.gomez@email.com", "Pass456",
        "Calle 21 #35-50", "PayPal"},
    };

    Productos = {
        {1, "Laptop", "Portátil con pantalla Full HD y SSD de 512GB", 89999, 10},
        {2, "Smartphone", "Teléfono con cámara de 108MP y carga rápida", 49950, 20},
        {3, "Tablet", "Dispositivo con pantalla táctil de 10 pulgadas", 29999, 15},
        {4, "Auriculares", "Audífonos inalámbricos con cancelación de ruido", 12999, 25}
    };

    comentarios = {
        {1, Productos[0], "Juanchito", "Excelente rendimiento; muy rápida. ¡Me encanta!", "1/05/2025"},
        {2, Productos[1], "Gabriel", "Buena cámara pero la batería dura poco.", "3/05/2025"},
        {3, Productos[2], "Pepe", "No me gustó; pantalla de baja calidad.", "5/05/2025"},
        {4, Productos[3], "Yonaiker Dubleison", "Sonido aceptable pero el material parece frágil.", "6/05/2025"}
    };
}

#endif
