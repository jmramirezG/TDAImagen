all: bin/prueba doc/html

clear:
	rm -r bin/prueba obj/*.o lib/*.a doc/*

bin/prueba: obj/prueba.o lib/libformas.a
	g++ -Llib/ -o bin/prueba obj/prueba.o -lformas

lib/libformas.a: obj/imagenES.o obj/Imagen.o obj/funcionesImagen.o
	ar rvs lib/libformas.a obj/imagenES.o obj/Imagen.o obj/funcionesImagen.o

obj/funcionesImagen.o: src/funcionesImagen.cpp include/funcionesImagen.h include/Imagen.h include/imagenES.h
	g++ -g -c -o obj/funcionesImagen.o -I./include src/funcionesImagen.cpp

obj/Imagen.o: include/imagenES.h include/Imagen.h src/Imagen.cpp
	g++ -g -c -o obj/Imagen.o -I./include src/Imagen.cpp

obj/imagenES.o: src/imagenES.cpp include/imagenES.h
	g++ -g -c -o obj/imagenES.o -I./include src/imagenES.cpp

obj/prueba.o : src/prueba.cpp
	g++ -g -c -o obj/prueba.o -I./include src/prueba.cpp

doc/html: Doxyfile
	doxygen Doxyfile
