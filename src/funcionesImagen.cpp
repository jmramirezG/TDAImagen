/**
  * @file funcionesImagen.cpp
  * @brief Fichero con definiciones para el archivo funcionesImagen.h
  *
  * Permite el realizar algunas funciones determinadas con archivos de tipo PGM,PPM
  *
  */

#include <funcionesImagen.h>
#include <iostream>

void enmarcar_imagen(Imagen & I) {
    if (I.getTipo() == IMG_PPM) {
        int nf = I.num_filas();
        int nc = I.num_columnas()*3;

        for (int f = 0; f < nf; f++) {       //Lado izquierdo
            I.asigna_pixel(f, 0, 0);
            I.asigna_pixel(f, 1, 0);
            I.asigna_pixel(f, 2, 0);
        }

        for (int f = 0; f < nf; f++) {       //Lado derecho
            I.asigna_pixel(f, nc-1, 0);
            I.asigna_pixel(f, nc-2, 0);
            I.asigna_pixel(f, nc-3, 0);
        }

        for (int c = 0; c < nc; c++)      //Lado superior
            I.asigna_pixel(0, c, 0);

        for (int c = 0; c < nc; c++)      //Lado inferior
            I.asigna_pixel(nf-1, c, 0);
    } else {
        int nf = I.num_filas();
        int nc = I.num_columnas();

        for (int f = 0; f < nf; f++)         //Lado izquierdo
            I.asigna_pixel(f, 0, 0);

        for (int f = 0; f < nf; f++)         //Lado derecho
            I.asigna_pixel(f, nc-1, 0);

        for (int c = 0; c < nc; c++)      //Lado superior
            I.asigna_pixel(0, c, 0);

        for (int c = 0; c < nc; c++)      //Lado inferior
            I.asigna_pixel(nf-1, c, 0);
        }
}

void binarizar(Imagen & I) {
    int nf = I.num_filas();
    int nc = I.num_columnas();
    const byte umbral = 128;

    for (int f = 0; f < nf; f++) {
        for (int c = 0; c < nc; c++) {
            if (I.valor_pixel(f, c) < umbral)
                I.asigna_pixel(f, c, 0);
            else
                I.asigna_pixel(f, c, 255);
        }
    }

}

void umbralizarImagen(Imagen & I, byte T1, byte T2) {
    int nf = I.num_filas();
    int nc = I.num_columnas();

    if(I.getTipo() == IMG_PGM){
        if(T1 > T2){
            byte T_temp = T2;
            T2 = T1;
            T1 = T_temp;
        }
    
        for (int f = 0; f < nf; f++){
            for (int c = 0; c < nc; c++){
                if(T1 > I.valor_pixel(f, c) || I.valor_pixel(f, c) > T2)
                    I.asigna_pixel(f, c, 255);
            }
        }
    }
    else{
        std::cout << "No es posible umbralizar una imagen a color.\n"; 
    }
}

Imagen crearIcono(Imagen & I, int nf, int nc){
    Imagen icono(nf, nc);
    int nf_secc = I.num_filas() / nf;
    int nc_secc = I.num_columnas() / nc;
    int fijo = nf_secc * nc_secc;

    icono.setTipo(I.getTipo());

    for(int f = 0; f < nf; f++){
        for(int c = 0; c < nc; c++){
            int suma = 0;
            for(int i = nf_secc*f; i < nf_secc*(f+1); i++){
                for(int j = c*nc_secc; j < nc_secc*(c+1); j++){
                    suma = suma + I.valor_pixel(i, j);
                }
            }
            suma = suma / fijo;
            icono.asigna_pixel(f, c, suma);
        }
    }
    return icono;
}

void aumentoContraste(Imagen & I, int min, int max){
    int nf = I.num_filas();
    int nc = I.num_columnas();

    int a = 255;
    int b = 0;

    for (int f = 0; f < nf; f++){
        for (int c = 0; c < nc; c++){
            if (I.valor_pixel(f, c) < a){
                a = I.valor_pixel(f, c);
            }
            if (I.valor_pixel(f, c) > b){
                b = I.valor_pixel(f, c);
            }
        }
    }

    double fijo = (max - min) / (b - a);
    for (int f = 0; f < nf; f++){
        for(int c = 0; c < nc; c++){
            double z = min + (fijo * (I.valor_pixel(f, c) - a));
            I.asigna_pixel(f, c, z);
        }
    }
}

//Fin de funcionesImagen.cpp