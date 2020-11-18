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

/**
 * @brief Crea un icono con coeficiente nx de reduccion de una imagen
 * @param I Imagen de la que se crea el icono
 * @param nf Numero de filas del icono
 * @param nc Numero de columnas del icono
 * @note Se crea un nuevo objeto imagen
 */
Imagen crearIcono(Imagen & I, int nf, int nc);

/**
 * @brief Aumenta el contraste de una imagen dados un valor min y max para el contraste
 * @param I Imagen a contrastar
 * @param min Extremo inferior del nuevo rango de la imagen
 * @param max Extremo superior del nuevo rango de la imagen
 * @note Se modifica la imagen
 */
void aumentoContraste(Imagen & I, int min, int max);


#endif

/* Fin Fichero: funcionesImagen.h*/
