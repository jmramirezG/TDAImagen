#include <Imagen.h>
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
    TipoImagen Tipo = LeerTipoImagen(nombre);
    byte * memoria;
    if (Tipo == IMG_PGM) {
        memoria = LeerImagenPGM(nombre, nF, nC);
    } else if (Tipo == IMG_PPM) {
        memoria = LeerImagenPPM(nombre, nF, nC);
    } else
        std::abort;
    if (Tipo == IMG_PPM) {
        std::cout << "Desea que la imagen se pase a escala de grises? (y/n) ";
        char r;
        std::cin >> r;
        assert(r == 'y' || r == 'n');
        if (r == 'y') {
            this->tipo = IMG_PGM;
            valores = new byte *[nF];
            for (int i = 0; i < nF; i++)
                valores[i] = new byte [nC];

            rellenarImagen_grises(memoria);
        } else {
            this->tipo = IMG_PPM;
            valores = new byte *[nF];
            for (int i = 0; i < nF; i++)
                valores[i] = new byte [nC*3];

            rellenarImagen_ppm(memoria);
        }
    } else {
        this->tipo = IMG_PGM;
        valores = new byte *[nF];
        for (int i = 0; i < nF; i++)
            valores[i] = new byte [nC];

        rellenarImagen_pgm(memoria);
    }
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

TipoImagen Imagen::getTipo() const {
    return tipo;
}

byte * Imagen::punteroMemoria_pgm() const {
    assert(valores);
    long int nPixeles = nF*nC;
    byte *memoria = new byte[nPixeles];
    nPixeles = 0;
    for (int f = 0; f < nF; f++) {
        for (int c = 0; c < nC; c++) {
            memoria[nPixeles] = valor_pixel(f,c);
            nPixeles++;
        }
    }
    return memoria;
}


byte * Imagen::punteroMemoria_ppm() const {
    assert(valores);

    long int nBytes = nF*nC*3;
    byte *memoria = new byte[nBytes];
    nBytes = 0;
    for (int f = 0; f < nF; f++) {
        for (int c = 0; c < nC*3; c++) {
            memoria[nBytes] = valor_pixel(f,c);
            nBytes++;
        }
    }

    return memoria;
}


void Imagen::asigna_pixel(int fila, int col, byte valor) {
    assert(0 <= fila < num_filas() && 0 <= col < num_columnas()*3);
    assert(0 <= valor < 256);
    valores[fila][col] = valor;
}

byte Imagen::valor_pixel(int fila, int col) const {
    assert(0 <= fila < num_filas() && 0 <= col < num_columnas()*3);
    return valores[fila][col];
}

void Imagen::rellenarImagen_grises(byte * memoria) {
    byte * grises = Igris(memoria);
    rellenarImagen_pgm(grises);
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

void Imagen::rellenarImagen_ppm(byte * memoria) {
    long int contador = 0;
    for (int f = 0; f < nF; f++) {
        for (int c = 0; c < nC*3; c++){
            asigna_pixel(f,c,memoria[contador]);
            contador++;
        }
    }
}



//Fin de Imagen.cpp