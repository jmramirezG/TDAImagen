#include <Imagen.hpp>
#include <cassert>
#include <iostream>


Imagen::Imagen() {
    nF = 0;
    nC = 0;
    valores = 0;
}

Imagen::Imagen(const Imagen & J) {
    if (J.valores) {
        nF = J.nF;
        nC = J.nC;
        valores = new byte *[nF];

        for (int i = 0; i < nF; i++)
            valores[i] = new byte [nC];

        for (int i = 0; i < nF; i++) {
            for (int j = 0; j < nC; j++)
                valores[i][j] = J.valores[i][j];
        }
    } else {
        nF = 0;
        nC = 0;
        valores = 0;
    }
}

Imagen::Imagen(char * nombre) {
    TipoImagen tipo = LeerTipoImagen(nombre);
    byte * memoria;
    if (tipo == IMG_PGM) {
        memoria = LeerImagenPGM(nombre, nF, nC);
    } else if (tipo == IMG_PPM) {
        memoria = LeerImagenPPM(nombre, nF, nC);
    } else
        std::abort;
    
    valores = new byte *[nF];

    for (int i = 0; i < nF; i++)
        valores[i] = new byte [nC];
    
    rellenarImagen_grises(memoria, tipo);
}

Imagen::Imagen(int filas, int columnas) {
    assert(filas > 0 && columnas > 0);
    nF = filas;
    nC = columnas;
    valores = new byte *[nF];

    for (int i = 0; i < nF; i++)
        valores[i] = new byte [nC];
}

Imagen::~Imagen() {
    for (int i = 0; i < nF; i++)
        delete [] valores[i];
    delete [] valores;
}

int Imagen::num_filas() const {
    return nF;
}

int Imagen::num_columnas() const {
    return nC;
}

void Imagen::asigna_pixel(int fila, int col, byte valor) {
    assert(0 <= fila < num_filas() && 0 <= col < num_columnas());
    assert(0 <= valor < 256);
    valores[fila][col] = valor;
}

byte Imagen::valor_pixel(int fila, int col) const {
    assert(0 <= fila < num_filas() && 0 <= col < num_columnas());
    return valores[fila][col];
}

void Imagen::rellenarImagen_grises(byte * memoria, TipoImagen tipo) {
    if (tipo == IMG_PPM) {
        byte * grises = Igris(memoria);
        rellenarImagen_pgm(grises);
    } else
        rellenarImagen_pgm(memoria);
}

byte *Imagen::Igris(const byte *memoria) {

    long int tam = nF*nC;   //Tamaño del array memoria una vez que lo convirtamos a escala de grises
    byte * grises = new byte[tam];  //Reservamos memoria para la nueva imagen
    long int contador = 0;

    for (int i = 0; i < tam; i++) {
        grises[i] = (0.2989 * memoria[contador]) + (0.587 * memoria[contador+1]) + (0.114 * memoria[contador+2]);
        contador += 3;
    }

    return grises;
}

void Imagen::rellenarImagen_pgm(byte * memoria) {
    long int contador = 0;

    for (int f = 0; f < nF; f++) {
        for (int c = 0; c < nC; c++) {
            this->asigna_pixel(f,c,memoria[contador]);
            contador++;
        }
    }
}



//Fin de Imagen.cpp