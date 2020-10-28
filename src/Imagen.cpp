#include <Imagen.hpp>
#include <cassert>

Imagen::Imagen() {
    nF = 0;
    nC = 0;
    valores = 0;
}

Imagen::Imagen(const Imagen & J) {
    if (J.valores) {
        nF = J.nF;
        nC = J.nC;
        valores = new unsigned char *[nF];

        for (int i = 0; i < nF; i++)
            valores[i] = new unsigned char [nC];

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

Imagen::Imagen(int filas, int columnas) {
    assert(filas > 0 && columnas > 0);
    nF = filas;
    nC = columnas;
    valores = new unsigned char *[nF];

    for (int i = 0; i < nF; i++)
        valores[i] = new unsigned char [nC];
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

void Imagen::asigna_pixel(int fila, int col, unsigned char valor) {
    assert(0 <= fila < num_filas() && 0 <= col < num_columnas());
    assert(0 <= valor < 256);
    valores[fila][col] = valor;
}

unsigned char Imagen::valor_pixel(int fila, int col) const {
    assert(0 <= fila < num_filas() && 0 <= col < num_columnas());
    return valores[fila][col];
}

//Fin de Imagen.cpp