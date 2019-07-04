
#include "xlsxio_read.h" //libreria XLSXIO se ocupa para leer archivos .xlsx
#include "xlsxwriter.h"  // libreria LIBXLSXWRITE se ocupa para escribir en archivos .xlsx

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include <omp.h>

#include "Datos.h"

using namespace std;



int main(int argc, char** argv) {
    
    const char* ArchivoSalas = NULL;
    const char* ArchivoCursos = NULL;
    const char* ArchivoDocentes = NULL;

    int largo = argc;
    
    bool arguSalas = false;
    bool arguDocentes = false;
    bool arguCursos = false;

    if(largo > 0){
        for(int w=0; w<largo; w++){
            if(strcmp("-s",argv[w])==0){

               ArchivoSalas = argv[w+1];
               arguSalas = true;
          
            }if(strcmp("-c",argv[w])==0){

                ArchivoCursos = argv[w+1];
                arguDocentes = true;

            }if(strcmp("-d",argv[w])==0){

                ArchivoDocentes = argv[w+1];
                arguCursos = true;

            }

        }   

    } 


    if(  (arguSalas == true) && (arguCursos == true) && (arguDocentes == true) ){

        vector<DocentesInfo> ListaDocentesInfo; //se crea el vector de docentes
        vector<Salas> ListaSalas;       //se crea el vector de salas
        vector<Cursos> ListaCursos;     //se crea el vector de cursos

        #pragma omp parallel
        {
        #pragma omp sections
        {
                
            #pragma omp section 
            {
                    GuardarListaDocenteLunes(ListaDocentesInfo, ArchivoDocentes);//se guarda y se crean los elemnetos del vector (240 docentes)
                    GuardarListaDocente(ListaDocentesInfo, "Martes", ArchivoDocentes);  //se llena el resto de los dias 
                    GuardarListaDocente(ListaDocentesInfo, "Miércoles", ArchivoDocentes);
                    GuardarListaDocente(ListaDocentesInfo, "Jueves", ArchivoDocentes);
                    GuardarListaDocente(ListaDocentesInfo, "Viernes", ArchivoDocentes);
                    GuardarListaDocente(ListaDocentesInfo, "Sábado", ArchivoDocentes);
                    ListaDocentesInfo.erase(ListaDocentesInfo.begin()); //elimina primer elemento del vector, que son los nombres de las columnas
                    //ImprimirDocentes(ListaDocentesInfo); //muestra los datos
                
            }

            #pragma omp section
            {
                    GuardarSalas(ListaSalas, ArchivoSalas);       //se llena el vector de salas
                    ListaSalas.erase(ListaSalas.begin());//elimina primer elemento del vector, que son los nombres de las columnas
                    //ImprimirSalas(ListaSalas);    //imprime lista de salas
                    
                    set_salasHorario(ListaSalas);   //deja los campos del horario con "-"
            }

            #pragma omp section
            {
                    GuardadCursos(ListaCursos, ArchivoCursos);
                    ListaCursos.erase(ListaCursos.begin());//elimina primer elemento del vector, que son los nombres de las columnas
                    //ImprimirCursos(ListaCursos);  //muestra los datos
            }
               

        }//fin secciones

        }// fin parallel



        //Planificacion academica
        HacerHorario(ListaDocentesInfo, ListaSalas, ListaCursos); //se paraleliza el ciclo 


        //escribir los resultados en el xlsx
        Escribirxlsx(ListaSalas); //se paraleliza el ciclo 


        return 0;


    }else{

        cout<< "Ingrese correctamente los argumentos ( -s archivoSalas.xlsx -d archivoDocentes.xlsx -c archivoCursos.xlsx )"<<endl;
        return 0;
    }


}

