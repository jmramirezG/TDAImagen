#include <Imagen.h>
#include <funcionesImagen.h>
#include <iostream>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros

  unsigned char *image;
  int nf, nc, npixeles; // Num. de filas y columnas de las imagenes

  // Comprobar validez de la llamada
  if (argc != 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: prueba <FichImagenOriginal> <FichImagenDestino>\n";
    exit (1);
  }

  origen  = argv[1];
  destino = argv[2];

  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;

  // Leer la imagen del fichero de entrada
  Imagen i(origen);
  if (!image){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    exit (1);
  }

  nf = i.num_filas();
  nc = i.num_columnas();

  // Mostrar los parametros calculados por LeerImagenPGM()
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  
  cout << "   Imagen   = " << nf  << " filas x " << nc << " columnas " << endl;
  
  enmarcar_imagen(i);
  image = i.getTipo() == IMG_PGM ? i.punteroMemoria_pgm() : i.punteroMemoria_ppm();

  bool correcto = i.getTipo() == IMG_PGM ? EscribirImagenPGM(destino, image, nf, nc) : EscribirImagenPPM(destino, image, nf, nc);
  
  // Guardar la imagen resultado en el fichero
  if (correcto)
    cout  << "La imagen se guardo en " << destino << endl;
  else{
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    exit (2);
  }

  // Liberar la imagen
  delete [] image;

  return (0);
}