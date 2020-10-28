#include <Imagen.hpp>
#include <funcionesImagen.hpp>
#include <iostream>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros

  unsigned char *image;
  int nf, nc, npixeles; // Num. de filas y columnas de las imagenes

  // Comprobar validez de la llamada
  if (argc != 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
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
  
  npixeles = nf*nc;
  long int contador = 0;
  image = new unsigned char[npixeles];
  for (int f = 0; f < nf; f++) {
      for (int c = 0; c < nc; c++) {
          image[contador] = i.valor_pixel(f,c);
          contador++;
      }
  }
  
  // Guardar la imagen resultado en el fichero
  if (EscribirImagenPGM (destino, image, nf, nc))
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