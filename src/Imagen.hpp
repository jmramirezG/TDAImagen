#ifndef IMAGEN_HPP
#define IMAGE_HPP

#include <imagenES.h>

class Imagen {
    private:
        int nF,                     //Número de filas de la imagen
            nC;                     //Número de columnas de la imagen
        unsigned char **valores;    //Matriz de valores (entre 0 y 255)

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
         * @brief Constructor con parámentros de la imagen
         * @param filas Número de filas (píxeles verticales) que contiene la imagen
         * @param columnas Número de columnas (píxeles horizontales) que contiene la imagen
         * @pre filas > 0 && columnas > 0
         * @post La imagen creada tiene "filas" filas y "columnas" columnas, contiene valores basura (no inicializada)
         */
        Imagen(int filas, int columnas);

        /**
         * @brief Destructor de la clase, libera los recursos ocupados por la misma
         * @post No devuelve nada. La imagen destruida no puede volver a usarse a no ser que vuelva a crearse
         */
        ~Imagen();

        /**
         * @brief Consultor del número de filas de la imagen
         * @return Devuelve el número de filas
         * @post La imagen no se modifica
         */
        int num_filas() const;

        /**
         * @brief Consultor del número de columnas de la imagen
         * @return Devuelve el número de columnas
         * @post La imagen no se modifica
         */
        int num_columnas() const;

        /**
         * @brief Asigna un valor a un píxel
         * @param fila Fila de la imagen a la que asigna el valor
         * @param col Columna de la imagen a la que asigna el valor
         * @param valor Valor que se le asigna al píxel
         * @pre 0 <= fila < num_filas() && 0 <= col < num_columnas() && 0 <= valor < 256
         * @post No devuelve nada y se modifica la imagen en el píxel (fila, col)
         */
        void asigna_pixel(int fila, int col, unsigned char valor);

        /**
         * @brief Consulta el valor de un píxel de la imagen
         * @param fila Fila de la que queremos consultar el valor
         * @param col Columna de la que queremos consultar el valor
         * @return Devuelve el valor del píxel (fila, col)
         * @pre 0 <= fila < num_filas() && 0 <= col < num_columnas()
         * @post No se modifica la imagen y 0 <= valor < 256
         */
        unsigned char valor_pixel(int fila, int col) const;
};

//Fin de Imagen.hpp

#endif