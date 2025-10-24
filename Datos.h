#ifndef DATOS_H
#define DATOS_H

#include "Structs.h"
#include <vector>
using namespace std;

inline constexpr double IMPUESTO = 0.19;
inline constexpr double ENVIO = 1250.16;

inline vector<CarritoDeCompras> carritos;
inline vector<Usuario> Usuarios;
inline vector<Producto> Productos;
inline vector<Comentario> comentarios;

inline void inicializarDatos() {
    Usuarios = {
        {1, "Juan Perez", "juan.perez@email.com", "Qwerty123",
        "Carrera 45 #10-20", "Tarjeta de credito"},
        {2, "Ana Gomez", "ana.gomez@email.com", "Pass456",
        "Calle 21 #35-50", "PayPal"},
        {3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789",
        "Avenida Principal #100", "Transferencia bancaria"},
        {4, "Sofia Martinez", "sofia.martinez@email.com", "Clave987",
        "Calle 8 #20-30", "Efectivo"},
        {5, "Diego Fernandez", "diego.fernandez@email.com", "Contra654",
        "Carrera 77 #40-60", "Tarjeta debito"}
    };

    Productos = {
        {1, "Laptop", "Portatil con pantalla Full HD y SSD de 512GB", 89999, 10},
        {2, "Smartphone", "Telefono con camara de 108MP y carga rapida", 49950, 20},
        {3, "Tablet", "Dispositivo con pantalla tactil de 10 pulgadas", 29999, 15},
        {4, "Auriculares", "Audifonos inalambricos con cancelacion de ruido", 12999, 25},
        {5, "Teclado", "Teclado mecanico con iluminacion RGB", 8999, 30},
        {6, "Mouse", "Raton inalambrico con sensor optico de alta precision", 5999, 50},
        {7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 49900, 12},
        {8, "Impresora", "Laser multifuncional con Wi-Fi", 17999, 18},
        {9, "Camara", "Camara digital con lente profesional", 79999, 8},
        {10, "Smartwatch", "Reloj inteligente con GPS y monitoreo cardiaco", 19999, 22},
        {11, "Silla Gamer", "Silla ergonomica ajustable con soporte lumbar", 29999, 14},
        {12, "Microondas", "Horno microondas con multiples funciones", 12999, 40},
        {13, "Refrigerador", "Frigorifico doble puerta con sistema No Frost", 119999, 5},
        {14, "Lavadora", "Lavadora automatica con capacidad de 10kg", 59999, 7},
        {15, "Cafetera", "Cafetera express con vaporizador de leche", 14999, 35},
        {16, "Drone", "Drone con camara 4K y estabilizador", 69999, 9},
        {17, "Bocina Bluetooth", "Altavoz portatil con sonido envolvente", 8999, 33},
        {18, "Videocamara", "Videocamara profesional con grabacion en 4K", 99999, 6},
        {19, "TV LED", "Televisor inteligente de 55 pulgadas con HDR", 74999, 11},
        {20, "Bateria Externa", "Bateria de 20000mAh con carga rapida", 3999, 45},
        {21, "Disco Duro", "Disco duro externo de 2TB", 12999, 28},
        {22, "Memoria USB", "Pendrive de 128GB", 2999, 60},
        {23, "Router", "Router Wi-Fi 6 de alta velocidad", 19999, 16},
        {24, "Joystick", "Control inalambrico para videojuegos", 7999, 20},
        {25, "Fuente de Poder", "Fuente de alimentacion para PC de 750W", 8999, 17},
        {26, "SSD", "Unidad de almacenamiento SSD de 1TB", 14999, 32},
        {27, "Altavoces", "Par de bocinas estereo con subwoofer", 13999, 23},
        {28, "Webcam", "Camara web Full HD con microfono integrado", 6999, 37},
        {29, "Procesador", "CPU Intel i7 de ultima generacion", 34999, 9},
        {30, "Motherboard", "Placa base compatible con procesadores modernos", 19999, 13},
        {31, "Memoria RAM", "Modulo de RAM DDR4 de 16GB", 7999, 41},
        {32, "Fuente Solar", "Panel solar portatil con bateria integrada", 24999, 4},
        {33, "Control Remoto", "Mando universal para TV y dispositivos", 2499, 50},
        {34, "Termostato", "Termostato digital programable", 9999, 22},
        {35, "Smart Lock", "Cerradura electronica con huella digital", 19999, 6},
        {36, "Proyector", "Proyector LED con resolucion Full HD", 29999, 12},
        {37, "Switch Ethernet", "Switch de red de 8 puertos", 5999, 38},
        {38, "Reloj Digital", "Reloj inteligente con pantalla AMOLED", 8999, 26},
        {39, "Luces LED", "Tiras LED RGB con control remoto", 3999, 55},
        {40, "Estabilizador", "Estabilizador de voltaje para dispositivos electronicos", 15999, 10},
        {41, "Cargador Inalambrico", "Base de carga inalambrica rapida", 4999, 30},
        {42, "HDD Externo", "Disco duro portatil de 4TB", 17999, 15},
        {43, "Microfono", "Microfono profesional para grabacion", 14999, 7},
        {44, "Altavoz Inteligente", "Asistente de voz con altavoz integrado", 12999, 20},
        {45, "Antena Wi-Fi", "Amplificador de senal inalambrico", 7999, 33},
        {46, "Climatizador", "Aire acondicionado portatil con control remoto", 29999, 5},
        {47, "Raspberry Pi", "Kit de desarrollo con Raspberry Pi 4", 12999, 19},
        {48, "Capturadora", "Placa de captura de video en alta resolucion", 19999, 8},
        {49, "Smart Plug", "Enchufe inteligente compatible con asistentes virtuales", 3999, 42},
        {50, "Timbre Inteligente", "Timbre con camara y conexion a Wi-Fi", 14999, 10}
    };

    comentarios = {
        {1, Productos[0], "Juan Perez", "Excelente rendimiento, muy rapida. ¡Me encanta!", "1/05/2025"},
        {2, Productos[1], "Ana Gomez", "Buena camara pero la bateria dura poco.", "3/05/2025"},
        {3, Productos[2], "Carlos Ruiz", "No me gusto, pantalla de baja calidad.", "5/05/2025"},
        {4, Productos[3], "Sofia Martinez", "Sonido aceptable pero el material parece fragil.", "6/05/2025"},
        {5, Productos[4], "Diego Fernandez", "Muy buen teclado mecanico, excelente respuesta.", "8/05/2025"},
        {6, Productos[5], "Ana Gomez", "El sensor no es tan preciso como esperaba.", "10/05/2025"},
        {7, Productos[6], "Carlos Ruiz", "Colores vibrantes y buena resolucion. Muy satisfecho.", "12/05/2025"},
        {8, Productos[7], "Juan Perez", "Tarda mucho en imprimir, no me convence.", "13/05/2025"},
        {9, Productos[8], "Sofia Martinez", "Increible calidad de imagen, fotos super nitidas.", "15/05/2025"},
        {10, Productos[9], "Diego Fernandez", "Buena bateria, pero la pantalla no es muy brillante.", "18/05/2025"},
        {11, Productos[10], "Lucia Rodriguez", "Comodidad espectacular, perfecto para largas sesiones de juego.", "20/05/2025"},
        {12, Productos[11], "Andres Ramirez", "Calienta bien pero hace mucho ruido.", "22/05/2025"},
        {13, Productos[12], "Maria Garcia", "Espacioso y enfria rapido, muy recomendado.", "24/05/2025"},
        {14, Productos[13], "Javier Martinez", "Lava bien pero el ciclo es muy largo.", "26/05/2025"},
        {15, Productos[14], "Carolina Lopez", "Hace cafe delicioso, facil de usar.", "28/05/2025"},
        {16, Productos[15], "Daniel Castro", "Muy divertido pero la bateria dura poco.", "30/05/2025"},
        {17, Productos[16], "Paola Herrera", "Sonido potente y buena conexion Bluetooth.", "1/06/2025"},
        {18, Productos[17], "Esteban Rojas", "Perfecta para grabaciones profesionales.", "3/06/2025"},
        {19, Productos[18], "Fernanda Sanchez", "Imagen excelente pero el sonido podria mejorar.","5/06/2025"},
        {20, Productos[19], "Camilo Torres", "Carga bien pero es un poco pesada.", "7/06/2025"},
        {21, Productos[20], "Gabriela Suarez", "Gran capacidad de almacenamiento, funciona rapido.", "9/06/2025"},
        {22, Productos[21], "Raul Espinosa", "Buen tamano pero la velocidad de transferencia es baja.", "11/06/2025"},
        {23, Productos[22], "Veronica Mendoza", "Senal potente, cubre toda la casa.", "13/06/2025"},
        {24, Productos[23], "Fabio Jimenez", "Comodo y resistente, ideal para gaming.", "15/06/2025"},
        {25, Productos[24], "Ricardo Vargas", "Funciona bien pero los cables son muy cortos.", "17/06/2025"},
        {26, Productos[25], "Silvia Gomez", "Velocidad increible, mi PC va mucho mas rapido ahora.", "19/06/2025"},
        {27, Productos[26], "Martin Aguilar", "Sonido envolvente, muy buena compra.", "21/06/2025"},
        {28, Productos[27], "Valentina Perez", "Imagen clara pero el microfono es deficiente.", "23/06/2025"},
        {29, Productos[28], "Jose Ramirez", "Rendimiento impecable, ideal para gaming y diseno.", "25/06/2025"},
        {30, Productos[29], "Natalia Correa", "Buenas prestaciones pero la instalacion fue complicada.", "27/06/2025"},
        {31, Productos[30], "Julio Fernandez", "Expande muy bien el rendimiento del sistema.", "29/06/2025"},
        {32, Productos[31], "Amanda Castro", "Energia confiable pero la bateria es pequena.", "1/07/2025"},
        {33, Productos[32], "Pedro Duarte", "Facil de usar, reconoce muchos dispositivos.", "3/07/2025"},
        {34, Productos[33], "Isabela Medina", "Regula bien la temperatura, intuitivo de usar.", "5/07/2025"},
        {35, Productos[34], "Oscar Rodriguez", "Seguridad y tecnologia en un solo dispositivo.", "7/07/2025"},
        {36, Productos[35], "Cristina Vargas", "Imagen nitida pero requiere una sala oscura.", "9/07/2025"},
        {37, Productos[36], "Mario Hernandez", "Buena velocidad de conexion, estable.", "11/07/2025"},
        {38, Productos[37], "Sofia Ramirez", "Pantalla atractiva pero la bateria dura poco.", "13/07/2025"},
        {39, Productos[38], "Andrea Gutierrez", "Buenas opciones de colores, buen diseno.", "15/07/2025"},
        {40, Productos[39], "Pablo Medina", "Protege bien contra variaciones de voltaje.", "17/07/2025"},
        {41, Productos[40], "Patricia Lopez", "Carga rapido pero requiere posicionamiento preciso.", "19/07/2025"},
        {42, Productos[41], "Gonzalo Espinoza", "Mucho espacio, resistente y confiable.", "21/07/2025"},
        {43, Productos[42], "Elena Herrera", "Calidad de sonido profesional, ideal para podcast.", "23/07/2025"},
        {44, Productos[43], "Diego Soto", "Responde bien a comandos de voz, util en casa.", "25/07/2025"},
        {45, Productos[44], "Miguel Rojas", "Amplifica bien la senal pero el rango es limitado.", "27/07/2025"},
        {46, Productos[45], "Estefania Carrillo", "Enfria rapido pero es algo ruidoso.", "29/07/2025"},
        {47, Productos[46], "Manuel Vargas", "Perfecto para proyectos electronicos y programacion.", "31/07/2025"},
        {48, Productos[47], "Luisa Mejia", "Ideal para streaming y grabaciones en alta calidad.", "2/08/2025"},
        {49, Productos[48], "Victoria Torres", "Muy practico, facil de conectar y configurar.", "4/08/2025"},
        {50, Productos[49], "Federico Montoya", "Buena camara, util para seguridad.", "6/08/2025"}
    };
}

#endif
