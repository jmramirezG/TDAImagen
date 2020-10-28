#include <funcionesImagen.hpp>

void enmarcar_imagen(Imagen & I) {
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


//Fin de funcionesImagen.cpp