/**
  * @file funcionesImagen.h
  * @brief Fichero cabecera para las funciones de funcionesImagen
  *
  * Permite realizar determinadas operaciones con archivos de tipo PGM,PPM
  *
  */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Imagen.h>
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

/**
 * @brief Pone los pixeles de una imagen a blanco si no se encuentran en el umbral (T1 - T2)
 * @pre T1 < T2
 * @param I Imagen a umbralizar
 * @param T1 Valor inferior del umbral
 * @param T2 Valor superior del umbral
 * @note La imagen "I" será modificadaa
 */
void umbralizarImagen(Imagen & I, byte T1, byte T2);


#endif

//Fin de FuncionesImagen.hpp