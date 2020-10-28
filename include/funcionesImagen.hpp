#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <Imagen.hpp>
#include <imagenES.h>

/**
 * @brief Enmarca una imagen en un marco de color negro
 * @param I Imagen a enmarcar
 * @note Se modifica la imagen
 */
void enmarcar_imagen(Imagen & I);

/**
 * @brief Binariza la imagen, reduciendo los colores posibles a blanco o negro
 * @param I Imagen a binarizar
 * @note Se modifica la imagen
 */
void binarizar(Imagen & I);


#endif

//Fin de FuncionesImagen.hpp