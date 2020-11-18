/**
  * @file Imagen.h
  * @brief Fichero cabecera para la clase Imagen, base del manejo de las imágenes
  *
  * Permite el manejo de archivos de tipo PGM,PPM
  *
  */

#ifndef IMAGEN_H
#define IMAGEN_H

#include <imagenES.h>

typedef unsigned char byte;     //<-Definimos un unsigned char como "byte"

class Imagen {
    private:

        int nF,                     //<-Número de filas de la imagen
            nC;                     //<-Número de columnas de la imagen
        byte **valores;             //<-Matriz de valores (entre 0 y 255)
        TipoImagen tipo;            //<-Tipo de la imagen con la que estamos trabajando

    public:

        /**
         * @brief Constructor por defecto de la imagen
         */
        Imagen();

        /**
         * @brief Constructor de copia de la imagen
         * @param J Imagen que se pretende copiar
         */
        Imagen(const Imagen & J);

        /**
         * @brief Constructor que lee de una imagen (.ppm o .pgm) existente
         * @param f Imagen de la que leemos
         * @pre La imagen tiene que tener formato .ppm o .pgm
         * @see LeerTipoImagen(const char *nombre)
         * @see LeerImagenPPM (const char *nombre, int& fils, int& cols)
         * @see LeerImagenPGM (const char *nombre, int& fils, int& cols)
         * @see rellenarImagen_grises(byte * memoria)
         * @see rellenarImagen_pgm(byte * memoria)
         * @see rellenarImagen_ppm(byte * memoria)
         */
        Imagen(char * f);

        /**
         * @brief Constructor con parámentros de la imagen
         * @param filas Número de filas (píxeles verticales) que contiene la imagen
         * @param columnas Número de columnas (píxeles horizontales) que contiene la imagen
         * @pre filas > 0
         * @pre columnas > 0
         * @note La imagen creada tiene "filas" filas y "columnas" columnas, contiene valores basura (no inicializada)
         */
        Imagen(int filas, int columnas);

        /**
         * @brief Destructor de la clase, libera los recursos ocupados por la misma
         * @note No devuelve nada. La imagen destruida no puede volver a usarse a no ser que vuelva a crearse
         */
        ~Imagen();

        /**
         * @brief Consultor del número de filas de la imagen
         * @return Devuelve el número de filas
         * @note La imagen no se modifica
         */
        int num_filas() const;

        /**
         * @brief Consultor del número de columnas de la imagen
         * @return Devuelve el número de columnas
         * @note La imagen no se modifica
         */
        int num_columnas() const;

        /**
         * @brief Consultor para el tipo de imagen con el que estamos trabajando
         * @return Devuelve el tipo de imagen con el que estamos trabajando
         * @note No se modifica el tipo de imagen
         */
        TipoImagen getTipo() const;

        /**
         * @brief setear tipo de imagen
         * @param t el tipo de imagen a setear
         */
        void setTipo(TipoImagen t);

        /**
         * @brief Consultor el puntero "valores" para una imagen .pgm
         * @return Puntero que contiene los datos relativos a la imagen, dispuestos para escribir en una imagen .pgm
         * @note La imagen no se modifica
         */
        byte * punteroMemoria_pgm() const;

        /**
         * @brief Consultor el puntero "valores" para una imagen .ppm
         * @return Puntero que contiene los datos relativos a la imagen, dispuestos para escribir en una imagen .ppm
         * @note La imagen no se modifica
         */
        byte * punteroMemoria_ppm() const;

        /**
         * @brief Asigna un valor a un píxel
         * @param fila Fila de la imagen a la que asigna el valor
         * @param col Columna de la imagen a la que asigna el valor
         * @param valor Valor que se le asigna al píxel
         * @pre 0 <= fila < num_filas()
         * @pre 0 <= col < num_columnas()
         * @pre 0 <= valor < 256
         * @note No devuelve nada y se modifica la imagen en el píxel (fila, col)
         */
        void asigna_pixel(int fila, int col, byte valor);

        /**
         * @brief Consulta el valor de un píxel de la imagen
         * @param fila Fila de la que queremos consultar el valor
         * @param col Columna de la que queremos consultar el valor
         * @return Devuelve el valor del píxel (fila, col)
         * @pre 0 <= fila < num_filas()
         * @pre 0 <= col < num_columnas()
         * @note No se modifica la imagen y 0 <= valor < 256
         */
        byte valor_pixel(int fila, int col) const;

        /**
         * @brief Rellena un objeto de la clase Imagen (pgm) con el contenido de una imagen (PPM o PGM)
         * @param memoria Zona de memoria que contiene a la imagen
         * @see Igris()
         * @see rellenarImagen_pgm()
         * @note Modifica la imagen que le pasamos por parámetros
         */
        void rellenarImagen_grises(byte * memoria);

        /**
         * @brief Pasa de una zona de memoria dispuesta para una imagen .ppm a una dispuesta para una imagen .pgm
         * @param memoria Zona de memoria que contiene a la imagen
         * @note No modifica la imagen que le pasamos por parámetros
         */
        byte *Igris(const byte * memoria);

        /**
         * @brief Rellena un objeto de la clase Imagen con el contenido de una imagen .pgm
         * @param memoria Zona de memoria que contiene a la imagen
         * @note Modifica la zona de memoria que le pasamos por parámetros
         */
        void rellenarImagen_pgm(byte * memoria);

        /**
         * @brief Rellena un objeto de la clase Imagen con el contenido de una imagen .ppm
         * @param memoria Zona de memoria que contiene a la imagen
         * @note Modifica la zona de memoria que le pasamos por parámetros
         */
        void rellenarImagen_ppm(byte * memoria);
        
};


#endif

/* Fin Fichero: Imagen.h*/
