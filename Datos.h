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
        {3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789", 
        "Avenida Principal #100", "Transferencia bancaria"}, 
        {4, "Sofía Martínez", "sofia.martinez@email.com", "Clave987",
        "Calle 8 #20-30", "Efectivo"},
        {5, "Diego Fernández", "diego.fernandez@email.com", "Contra654",
        "Carrera 77 #40-60", "Tarjeta débito"}
    };

    Productos = {
        {1, "Laptop", "Portátil con pantalla Full HD y SSD de 512GB", 89999, 10},
        {2, "Smartphone", "Teléfono con cámara de 108MP y carga rápida", 49950, 20},
        {3, "Tablet", "Dispositivo con pantalla táctil de 10 pulgadas", 29999, 15},
        {4, "Auriculares", "Audífonos inalámbricos con cancelación de ruido", 12999, 25},
        {5, "Teclado", "Teclado mecánico con iluminación RGB", 8999, 30},
        {6, "Mouse", "Ratón inalámbrico con sensor óptico de alta precisión", 5999, 50},
        {7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 49900, 12},
        {8, "Impresora", "Láser multifuncional con Wi-Fi", 17999, 18},
        {9, "Cámara", "Cámara digital con lente profesional", 79999, 8},
        {10, "Smartwatch", "Reloj inteligente con GPS y monitoreo cardíaco", 19999, 22},
        {11, "Silla Gamer", "Silla ergonómica ajustable con soporte lumbar", 29999, 14},
        {12, "Microondas", "Horno microondas con múltiples funciones", 12999, 40},
        {13, "Refrigerador", "Frigorífico doble puerta con sistema No Frost", 119999, 5},
        {14, "Lavadora", "Lavadora automática con capacidad de 10kg", 59999, 7},
        {15, "Cafetera", "Cafetera express con vaporizador de leche", 14999, 35},
        {16, "Drone", "Drone con cámara 4K y estabilizador", 69999, 9},
        {17, "Bocina Bluetooth", "Altavoz portátil con sonido envolvente", 8999, 33},
        {18, "Videocámara", "Videocámara profesional con grabación en 4K", 99999, 6},
        {19, "TV LED", "Televisor inteligente de 55 pulgadas con HDR", 74999, 11},
        {20, "Batería Externa", "Batería de 20000mAh con carga rápida", 3999, 45},
        {21, "Disco Duro", "Disco duro externo de 2TB", 12999, 28},
        {22, "Memoria USB", "Pendrive de 128GB", 2999, 60},
        {23, "Router", "Router Wi-Fi 6 de alta velocidad", 19999, 16},
        {24, "Joystick", "Control inalámbrico para videojuegos", 7999, 20},
        {25, "Fuente de Poder", "Fuente de alimentación para PC de 750W", 8999, 17},
        {26, "SSD", "Unidad de almacenamiento SSD de 1TB", 14999, 32},
        {27, "Altavoces", "Par de bocinas estéreo con subwoofer", 13999, 23},
        {28, "Webcam", "Cámara web Full HD con micrófono integrado", 6999, 37},
        {29, "Procesador", "CPU Intel i7 de última generación", 34999, 9},
        {30, "Motherboard", "Placa base compatible con procesadores modernos", 19999, 13},
        {31, "Memoria RAM", "Módulo de RAM DDR4 de 16GB", 7999, 41},
        {32, "Fuente Solar", "Panel solar portátil con batería integrada", 24999, 4},
        {33, "Control Remoto", "Mando universal para TV y dispositivos", 2499, 50},
        {34, "Termostato", "Termostato digital programable", 9999, 22},
        {35, "Smart Lock", "Cerradura electrónica con huella digital", 19999, 6},
        {36, "Proyector", "Proyector LED con resolución Full HD", 29999, 12},
        {37, "Switch Ethernet", "Switch de red de 8 puertos", 5999, 38},
        {38, "Reloj Digital", "Reloj inteligente con pantalla AMOLED", 8999, 26},
        {39, "Luces LED", "Tiras LED RGB con control remoto", 3999, 55},
        {40, "Estabilizador", "Estabilizador de voltaje para dispositivos electrónicos", 15999, 10},
        {41, "Cargador Inalámbrico", "Base de carga inalámbrica rápida", 4999, 30},
        {42, "HDD Externo", "Disco duro portátil de 4TB", 17999, 15},
        {43, "Micrófono", "Micrófono profesional para grabación", 14999, 7},
        {44, "Altavoz Inteligente", "Asistente de voz con altavoz integrado", 12999, 20},
        {45, "Antena Wi-Fi", "Amplificador de señal inalámbrico", 7999, 33},
        {46, "Climatizador", "Aire acondicionado portátil con control remoto", 29999, 5},
        {47, "Raspberry Pi", "Kit de desarrollo con Raspberry Pi 4", 12999, 19},
        {48, "Capturadora", "Placa de captura de video en alta resolución", 19999, 8},
        {49, "Smart Plug", "Enchufe inteligente compatible con asistentes virtuales", 3999, 42},
        {50, "Timbre Inteligente", "Timbre con cámara y conexión a Wi-Fi", 14999, 10}
    };

    comentarios = {
        {1, Productos[0], "Juan Pérez", "Excelente rendimiento; muy rápida. ¡Me encanta!", "1/05/2025"},
        {2, Productos[1], "Ana Gómez", "Buena cámara pero la batería dura poco.", "3/05/2025"},
        {3, Productos[2], "Carlos Ruiz", "No me gustó; pantalla de baja calidad.", "5/05/2025"},
        {4, Productos[3], "Sofía Martínez", "Sonido aceptable pero el material parece frágil.", "6/05/2025"},
        {5, Productos[4], "Diego Fernández", "Muy buen teclado mecánico; excelente respuesta.", "8/05/2025"},
        {6, Productos[5], "Ana Gómez", "El sensor no es tan preciso como esperaba.", "10/05/2025"},
        {7, Productos[6], "Carlos Ruiz", "Colores vibrantes y buena resolución. Muy satisfecho.", "12/05/2025"},
        {8, Productos[7], "Juan Pérez", "Tarda mucho en imprimir; no me convence.", "13/05/2025"},
        {9, Productos[8], "Sofía Martínez", "Increíble calidad de imagen; fotos súper nítidas.", "15/05/2025"},
        {10, Productos[9], "Diego Fernández", "Buena batería; pero la pantalla no es muy brillante.", "18/05/2025"},
        {11, Productos[10], "Lucía Rodríguez", "Comodidad espectacular; perfecto para largas sesiones de juego.", "20/05/2025"},
        {12, Productos[11], "Andrés Ramírez", "Calienta bien pero hace mucho ruido.", "22/05/2025"},
        {13, Productos[12], "María García", "Espacioso y enfría rápido; muy recomendado.", "24/05/2025"},
        {14, Productos[13], "Javier Martínez", "Lava bien pero el ciclo es muy largo.", "26/05/2025"},
        {15, Productos[14], "Carolina López", "Hace café delicioso; fácil de usar.", "28/05/2025"},
        {16, Productos[15], "Daniel Castro", "Muy divertido pero la batería dura poco.", "30/05/2025"},
        {17, Productos[16], "Paola Herrera", "Sonido potente y buena conexión Bluetooth.", "1/06/2025"},
        {18, Productos[17], "Esteban Rojas", "Perfecta para grabaciones profesionales.", "3/06/2025"},
        {19, Productos[18], "Fernanda Sánchez", "Imagen excelente pero el sonido podría mejorar.","5/06/2025"},
        {20, Productos[19], "Camilo Torres", "Carga bien pero es un poco pesada.", "7/06/2025"},
        {21, Productos[20], "Gabriela Suárez", "Gran capacidad de almacenamiento; funciona rápido.", "9/06/2025"},
        {22, Productos[21], "Raúl Espinosa", "Buen tamaño pero la velocidad de transferencia es baja.", "11/06/2025"},
        {23, Productos[22], "Verónica Mendoza", "Señal potente; cubre toda la casa.", "13/06/2025"},
        {24, Productos[23], "Fabio Jiménez", "Comodo y resistente; ideal para gaming.", "15/06/2025"},
        {25, Productos[24], "Ricardo Vargas", "Funciona bien pero los cables son muy cortos.", "17/06/2025"},
        {26, Productos[25], "Silvia Gómez", "Velocidad increíble; mi PC va mucho más rápido ahora.", "19/06/2025"},
        {27, Productos[26], "Martín Aguilar", "Sonido envolvente; muy buena compra.", "21/06/2025"},
        {28, Productos[27], "Valentina Pérez", "Imagen clara pero el micrófono es deficiente.", "23/06/2025"},
        {29, Productos[28], "José Ramírez", "Rendimiento impecable; ideal para gaming y diseño.", "25/06/2025"},
        {30, Productos[29], "Natalia Correa", "Buenas prestaciones pero la instalación fue complicada.", "27/06/2025"},
        {31, Productos[30], "Julio Fernández", "Expande muy bien el rendimiento del sistema.", "29/06/2025"},
        {32, Productos[31], "Amanda Castro", "Energía confiable pero la batería es pequeña.", "1/07/2025"},
        {33, Productos[32], "Pedro Duarte", "Fácil de usar; reconoce muchos dispositivos.", "3/07/2025"},
        {34, Productos[33], "Isabela Medina", "Regula bien la temperatura; intuitivo de usar.", "5/07/2025"},
        {35, Productos[34], "Oscar Rodríguez", "Seguridad y tecnología en un solo dispositivo.", "7/07/2025"},
        {36, Productos[35], "Cristina Vargas", "Imagen nítida pero requiere una sala oscura.", "9/07/2025"},
        {37, Productos[36], "Mario Hernández", "Buena velocidad de conexión; estable.", "11/07/2025"},
        {38, Productos[37], "Sofía Ramírez", "Pantalla atractiva pero la batería dura poco.", "13/07/2025"},
        {39, Productos[38], "Andrea Gutiérrez", "Buenas opciones de colores; buen diseño.", "15/07/2025"},
        {40, Productos[39], "Pablo Medina", "Protege bien contra variaciones de voltaje.", "17/07/2025"},
        {41, Productos[40], "Patricia López", "Carga rápido pero requiere posicionamiento preciso.", "19/07/2025"},
        {42, Productos[41], "Gonzalo Espinoza", "Mucho espacio; resistente y confiable.", "21/07/2025"},
        {43, Productos[42], "Elena Herrera", "Calidad de sonido profesional; ideal para podcast.", "23/07/2025"},
        {44, Productos[43], "Diego Soto", "Responde bien a comandos de voz; útil en casa.", "25/07/2025"},
        {45, Productos[44], "Miguel Rojas", "Amplifica bien la señal pero el rango es limitado.", "27/07/2025"},
        {46, Productos[45], "Estefanía Carrillo", "Enfría rápido pero es algo ruidoso.", "29/07/2025"},
        {47, Productos[46], "Manuel Vargas", "Perfecto para proyectos electrónicos y programación.", "31/07/2025"},
        {48, Productos[47], "Luisa Mejía", "Ideal para streaming y grabaciones en alta calidad.", "2/08/2025"},
        {49, Productos[48], "Victoria Torres", "Muy práctico; fácil de conectar y configurar.", "4/08/2025"},
        {50, Productos[49], "Federico Montoya", "Buena cámara; útil para seguridad.", "6/08/2025"}
    };
}

#endif
