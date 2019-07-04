
### Programa que realiza la programacion de horarios de clase y asignacion de sala
Con los 3 archivos .xlsx `Docentes, Salas, Cursos` se crea el horario de ocupacion de las salas de clase, y entrega `Resultados.xlsx` como el resultado que contiene todos los horarios de las salas de clase.

------------

 
#### Se utilizaron las siguientes librerias para trabajar con los archivos .xlsx

- [XLSX I/O](https://github.com/brechtsanders/xlsxio "XLSX I/O")
- [libxlsxwriter](https://github.com/jmcnamara/libxlsxwriter "libxlsxwriter")

------------


#### Stack de construcción 
El proyecto  está construido usando Ubuntu 18.04 de 64 bits y las herramientas usadas fueron
- Make (apt-get install make)
- CMake (apt-get install cmake)
- g++ (apt-get install build-essential)

------------

#### Instalar XLSX I/O
**Esta libreria se utiliza para leer los archivos .xlsx**

para instalar la libreria se requieren las siguientes dependencias
- sudo apt install libexpat1-dev 
- sudo apt install libzip-dev
- sudo apt install libminizip-dev
- sudo apt install doxygen 
> para ver la documentacion que esta en la libreria

Luego

```shell
$  mkdir unNombreCualquieraParaUnaCarpeta 
$  cd unNombreCualquieraParaUnaCarpeta/
$  git clone https://github.com/brechtsanders/xlsxio.git
$  cd xlsxio/  
$  cmake -G"Unix Makefiles"
$  make install
```
en la carpeta donde uno instala/descarga la libreria xlsx se crea un archivo     `install_manifest.txt` donde se encuentran los directorios de instalacion de los diferentes archivos, para ejecutar un programa se necesita saber donde estan los archivos, por defecto quedan asi:

- libxlsxio_read.so :esta está en ` /usr/local/lib/libxlsxio_read.so`
- libxlsxio_write.so :esta está en `/usr/local/lib/libxlsxio_write.so` 

>  .so = librerias dinamicas

------------

#### Instalar libxlsxwriter
**Esta libreria se utiliza para escribir el archivos .xlsx final**

Para instalar la libreria se requieren las siguientes dependencias
- sudo apt-get install -y zlib1g-dev

Luego
```shell
$  mkdir OtroNombreCualquieraParaUnaCarpeta 
$  cd OtroNombreCualquieraParaUnaCarpeta/
$  git clone https://github.com/jmcnamara/libxlsxwriter.git
$  cd libxlsxwriter
$  make
$  sudo make install
```
Por defecto la libreria queda en `/usr/local/lib/libxlsxwriter.so ` 
>  .so = librerias dinamicas

------------

#### Para Compilar
```
$  mkdir ProgramaHorarios
$  cd ProgramaHorarios/
$  git clone https://github.com/Soulwolfos/Cursos_Paralela.git
$  cd Cursos_Paralela
$  g++ main.cpp Datos.cpp Salida.cpp /usr/local/lib/libxlsxwriter.so /usr/local/lib/libxlsxio_read.so
$ ./a.out -s Salas.xlsx -d Docentes.xlsx -c Cursos.xlsx 
```
**La salida es un archivo .xlsx llamado Resultados.xlsx**

------------

#### Integrantes
> Rodrigo Lobos 
> Matias Camus
> Michel Hernández 










