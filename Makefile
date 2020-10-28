bin/prueba: obj/prueba.o obj/imagenES.o obj/Imagen.o
	g++ -g -o bin/prueba obj/prueba.o obj/imagenES.o obj/Imagen.o

obj/Imagen.o: include/imagenES.h include/Imagen.hpp src/Imagen.cpp
	g++ -g -c -o obj/Imagen.o -I./include src/Imagen.cpp

obj/imagenES.o: src/imagenES.cpp include/imagenES.h
	g++ -g -c -o obj/imagenES.o -I./include src/imagenES.cpp

obj/prueba.o : src/prueba.cpp
	g++ -g -c -o obj/prueba.o -I./include src/prueba.cpp
