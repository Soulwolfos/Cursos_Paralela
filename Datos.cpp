#include "Datos.h"

#include <iostream>

#include "xlsxio_read.h" //libreria XLSXIO se ocupa para leer archivos .xlsx

#include <string>
#include <vector>

#include <omp.h>

using namespace std;



void GuardarListaDocenteLunes(vector<DocentesInfo> &Docentes, const char* Archivo){

    char* valorCelda;
    int ContAux=0;
    int Bloque=0;

    string Disponible = "DISPONIBLE";

    DocentesInfo DocenteAux;

    xlsxioreader handle;
    
    if ((handle = xlsxioread_open(Archivo)) == NULL){
        fprintf(stderr, "Error al arbrir el archivo .xlsx de Docentes \n");
    }
    
    xlsxioreadersheet hoja;
    const char* nombreHoja = "Lunes";

    if ((hoja = xlsxioread_sheet_open(handle, nombreHoja, XLSXIOREAD_SKIP_EMPTY_ROWS)) != NULL){   

        while (xlsxioread_sheet_next_row(hoja)){

            while ( (valorCelda = xlsxioread_sheet_next_cell(hoja)) != NULL){
                if(ContAux == 0){  //si el ContAux es 0 esta leyendo los ID  
                    DocenteAux.idDocente.assign(valorCelda);
                }
                if(ContAux == 3){ //si el CountAux es 3 es leyendo el Bloque 1
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[0][Bloque] = 1;
                        Bloque = Bloque +1;                            
                    }else{
                        DocenteAux.BloquesDisponible[0][Bloque] = 0;
                        Bloque = Bloque +1;
                    }
                }
                if(ContAux == 4){ //si el CountAux es 4 es leyendo el Bloque 2
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[0][Bloque] = 1;
                        Bloque = Bloque +1;    
                    }else{
                        DocenteAux.BloquesDisponible[0][Bloque] = 0;
                        Bloque = Bloque +1;    
                    }

                }
                if(ContAux == 5){ //si el CountAux es 5 es leyendo el Bloque 3
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[0][Bloque] = 1;
                        Bloque = Bloque +1;
                    }else{
                        DocenteAux.BloquesDisponible[0][Bloque] = 0;
                        Bloque = Bloque +1;
                    }

                }
                if(ContAux == 6){ //si el CountAux es 6 es leyendo el Bloque 4
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[0][Bloque] = 1;
                        Bloque = Bloque +1;
                    }else{
                        DocenteAux.BloquesDisponible[0][Bloque] = 0;
                        Bloque = Bloque +1;
                    }

                }
                if(ContAux == 7){ //si el CountAux es 7 es leyendo el Bloque 5
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[0][Bloque] = 1;
                        Bloque = Bloque +1;
                    }else{
                        DocenteAux.BloquesDisponible[0][Bloque] = 0;
                        Bloque = Bloque +1;
                    }

                }
                if(ContAux == 8){ //si el CountAux es 8 es leyendo el Bloque 6
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[0][Bloque] = 1;
                        Bloque = Bloque +1;
                    }else{
                        DocenteAux.BloquesDisponible[0][Bloque] = 0;
                        Bloque = Bloque +1;
                    }

                }
                if(ContAux == 9){ //si el CountAux es 9 es leyendo el Bloque 7
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[0][Bloque] = 1;
                        Bloque = Bloque +1;
                    }else{
                        DocenteAux.BloquesDisponible[0][Bloque] = 0;
                        Bloque = Bloque +1;
                    }
                }


                ContAux = ContAux +1;
                free(valorCelda);
            
            }  

            ContAux = 0;
            Bloque = 0;

            Docentes.push_back(DocenteAux);
        }

        xlsxioread_sheet_close(hoja);
    }

    xlsxioread_close(handle);
    
}


void GuardarListaDocente(vector<DocentesInfo> &Docentes, const char* DiaHoja, const char* Archivo){

    string Dias[6] ={"Lunes","Martes","Miércoles","Jueves","Viernes","Sábado"};

    int DiaSemana;

    if(Dias[0].compare(DiaHoja)==0){
        DiaSemana = 0;

    }if(Dias[1].compare(DiaHoja)==0){
        DiaSemana = 1;
    
    }if(Dias[2].compare(DiaHoja)==0){
        DiaSemana = 2;

    }if(Dias[3].compare(DiaHoja)==0){
        DiaSemana = 3;
        
    }if(Dias[4].compare(DiaHoja)==0){
        DiaSemana = 4;
        
    }if(Dias[5].compare(DiaHoja)==0){
        DiaSemana = 5;
    }
    
    
    
    char* valorCelda;
    int ContAux = 0;
    int Bloque = 0;

    DocentesInfo DocenteAux;

    string Disponible = "DISPONIBLE";

    xlsxioreader handle;

    if ((handle = xlsxioread_open(Archivo)) == NULL) {
        fprintf(stderr, "Error al arbrir el archivo .xlsx de Docentes \n");
    }

    xlsxioreadersheet hoja;
    const char* nombreHoja = DiaHoja;

    if ((hoja = xlsxioread_sheet_open(handle, nombreHoja, XLSXIOREAD_SKIP_EMPTY_ROWS)) != NULL){   

        while (xlsxioread_sheet_next_row(hoja)){

            while ( (valorCelda = xlsxioread_sheet_next_cell(hoja)) != NULL){

                if(ContAux == 0){  //si el ContAux es 0 esta leyendo los ID  
                    DocenteAux.idDocente.assign(valorCelda);
                }
                if(ContAux == 3){ //si el CountAux es 3 es leyendo el Bloque 1
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 1;
                        Bloque = Bloque +1;                            
                    }else{
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 0;
                        Bloque = Bloque +1;
                    }
                }
                if(ContAux == 4){ //si el CountAux es 4 es leyendo el Bloque 2
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 1;
                        Bloque = Bloque +1;    
                    }else{
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 0;
                        Bloque = Bloque +1;    
                    }

                }
                if(ContAux == 5){ //si el CountAux es 5 es leyendo el Bloque 3
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 1;
                        Bloque = Bloque +1;
                    }else{
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 0;
                        Bloque = Bloque +1;
                    }

                }
                if(ContAux == 6){ //si el CountAux es 6 es leyendo el Bloque 4
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 1;
                        Bloque = Bloque +1;
                    }else{
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 0;
                        Bloque = Bloque +1;
                    }

                }
                if(ContAux == 7){ //si el CountAux es 7 es leyendo el Bloque 5
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 1;
                        Bloque = Bloque +1;
                    }else{
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 0;
                        Bloque = Bloque +1;
                    }

                }
                if(ContAux == 8){ //si el CountAux es 8 es leyendo el Bloque 6
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 1;
                        Bloque = Bloque +1;
                    }else{
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 0;
                        Bloque = Bloque +1;
                    }

                }
                if(ContAux == 9){ //si el CountAux es 9 es leyendo el Bloque 7
                    if(Disponible.compare(valorCelda)==0){
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 1;
                        Bloque = Bloque +1;
                    }else{
                        DocenteAux.BloquesDisponible[DiaSemana][Bloque] = 0;
                        Bloque = Bloque +1;
                    }
                }


                ContAux = ContAux +1;
                free(valorCelda);


            }

            ContAux = 0;
            Bloque = 0;

            for(int i=0;i<Docentes.size();i++){
                if(Docentes[i].idDocente.compare(DocenteAux.idDocente)==0){
                    for(int k=0;k<7;k++){
                        Docentes[i].BloquesDisponible[DiaSemana][k] = DocenteAux.BloquesDisponible[DiaSemana][k];
                        if( (DiaSemana == 5) && (k >= 4) ){
                            
                            Docentes[i].BloquesDisponible[DiaSemana][k] = 0;

                        }
                    }
                }

            }

        }

        xlsxioread_sheet_close(hoja);
    }

    xlsxioread_close(handle);

}



void ImprimirDocentes(vector<DocentesInfo> &Docentes){
    for(int i=0;i<Docentes.size();i++){
        cout<< "ID Docente: " <<Docentes[i].idDocente<<endl;
        for(int j=0;j<6;j++){
            
            for(int k=0;k<7;k++){
                
                cout<<" " << Docentes[i].BloquesDisponible[j][k]<<" "; 

            }

            cout<<endl;
        }

        cout<<endl;
    }

}



void GuardarSalas(vector<Salas> &Salitas, const char* Archivo){

    xlsxioreader handle;
    if ((handle = xlsxioread_open(Archivo)) == NULL) {
        fprintf(stderr, "Error al arbrir el archivo .xlsx de Salas \n");
    }
    
    int ContAux = 0;
    Salas salitaAuxiliar;
    string UnirNombre;

    char* valorCelda;
    xlsxioreadersheet hoja;
    //lee las celdas de la hoja que se coloque en "nombreHoja"
    const char* nombreHoja = "Sheet1";

    //printf("contenido de la Hoja de Salas:\n");
    if ((hoja = xlsxioread_sheet_open(handle, nombreHoja, XLSXIOREAD_SKIP_EMPTY_ROWS)) != NULL) {
    //Leer las Filas
        while (xlsxioread_sheet_next_row(hoja)) {
            //Leer cada elemendo de la Fila 
            while ( (valorCelda = xlsxioread_sheet_next_cell(hoja)) != NULL) {

                if(ContAux == 0 ){  //si el ContAux es 0 esta leyendo los edificios, si es 1 son las salas 
                    salitaAuxiliar.edificio = valorCelda;
                    //cout<<" valorCelda: "<<valorCelda<<"  valor salitaAuxiliar.edificio: "<<salitaAuxiliar.edificio<<endl;
                    
                    
                }if(ContAux == 1 ){ //cuando ContAux es igual a 1
                    salitaAuxiliar.salaNumero = valorCelda;
                    //cout<<" valorCelda: "<<valorCelda<<"  valor salitaAuxiliar.salaNumero: "<<salitaAuxiliar.salaNumero<<endl;
            
                }     

                if(ContAux == 0){
                    ContAux = 1;
                }
                free(valorCelda);
            }
            //cout<<"valor salitaAuxiliar.edificio: "<<salitaAuxiliar.edificio <<" valor salitaAuxiliar.salaNumero: "<<salitaAuxiliar.salaNumero<<endl;
            //printf("\n");

            UnirNombre = salitaAuxiliar.edificio + " " + salitaAuxiliar.salaNumero;
            salitaAuxiliar.edificioMasSala = UnirNombre;

            Salitas.push_back(salitaAuxiliar);

            if(ContAux == 1){
                ContAux = 0;
            }
        }
        xlsxioread_sheet_close(hoja);
    }

    //cerrando todo 
    xlsxioread_close(handle);

}


void ImprimirSalas(vector<Salas> &Salitas){
    for(int i = 0 ; i < Salitas.size(); i++ ){
        cout<<"Edificio: " << Salitas[i].edificio;
        cout<<"  Numero de sala: "<< Salitas[i].salaNumero;
        cout<<"  Edificio mas sala: "<< Salitas[i].edificioMasSala<<endl;
        //cout<< Salitas[i].horario<<endl;
    }
}


void GuardadCursos(vector<Cursos> &Cursitos, const char* Archivo){
    
    int ContAux = 0;
   
    string horasAux;
    
    Cursos CursoAux;
    

    xlsxioreader handle;
    if ((handle = xlsxioread_open(Archivo)) == NULL) {
        fprintf(stderr, "Error al arbrir el archivo .xlsx de Cursos \n");
    }

    char* valorCelda;
    
    xlsxioreadersheet hoja;

    //lee las celdas de la hoja que se coloque en "nombreHoja"
    const char* nombreHoja = "Secciones";

    if ((hoja = xlsxioread_sheet_open(handle, nombreHoja, XLSXIOREAD_SKIP_EMPTY_ROWS)) != NULL) {
    //read all rows
        while (xlsxioread_sheet_next_row(hoja)) {
            //read all columns
            while ((valorCelda = xlsxioread_sheet_next_cell(hoja)) != NULL) {
                if(ContAux == 0){
                    CursoAux.CodigoCurso.assign(valorCelda);
                }
                if(ContAux == 2){
                    CursoAux.idDocenteCurso.assign(valorCelda);
                }
                if(ContAux == 5){
                    horasAux.assign(valorCelda); 
                           
                    
                    if( horasAux.compare("1.0")==0){
                        CursoAux.HorasPedagogicas = 1;  
                    }
                    if( horasAux.compare("4.0")==0){
                        CursoAux.HorasPedagogicas = 2;  
                    }
                    if( horasAux.compare("6.0")==0){
                        CursoAux.HorasPedagogicas = 3;  
                    }
                    
            
                }

                ContAux = ContAux +1;
                free(valorCelda);
            }

            ContAux = 0;
           

            Cursitos.push_back(CursoAux);
        }

        xlsxioread_sheet_close(hoja);
    }

    xlsxioread_close(handle);

}



void ImprimirCursos(vector<Cursos> &Cursitos){

    #pragma omp for schedule( auto )
    for(int i = 0 ; i < Cursitos.size(); i++ ){
        cout<<"  Codigo Curso: " << Cursitos[i].CodigoCurso;
        cout<<"  ID Docente: "<< Cursitos[i].idDocenteCurso;
        cout<<"  Horas Pedagogicas: "<< Cursitos[i].HorasPedagogicas<<endl;
    }
    
}





























