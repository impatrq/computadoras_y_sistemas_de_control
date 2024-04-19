# Fuerzo la recompilacion
.PHONY: all build

all:
	@mkdir build;	\
	cd build;		\
	cmake ..;		\
	make

clean:
	@rm -rf build

build:
	@cd build;		\
	make

flash:
	@cp build/*.uf2 /media/$(shell whoami)/RPI-RP2

help:
	@echo "Raspberry Pi Pico Makefile v1.0"
	@echo "-------------------------------"
	@echo "Opciones para escribir con make"
	@echo "all: Compilacion completa (por defecto)"
	@echo "build: Compilacion solo si cuando, despues de correr make all, se hayan hecho cambios solo en archivos de codigo fuente"
	@echo "clean: Elimina el directorio build con los binarios compilados"
	@echo "flash: Copia el binario en la Raspberry Pi Pico"
	@echo "help: Muestra estos comandos"
