#include "Datos.h"

#include "xlsxwriter.h"  // libreria LIBXLSXWRITE se ocupa para escribir en archivos .xlsx

#include <iostream>
#include <string>
#include <vector>
#include <omp.h>


using namespace std;



//deja la el agrelo de horario[6][7] con el valor "-"  
void set_salasHorario(vector<Salas> &Salitas){

    for(int i=0;i<Salitas.size();i++){

        //cout<<Salitas[i].edificioMasSala<<endl;

        for(int k=0;k<6;k++){
            for(int m=0;m<7;m++){

                Salitas[i].horario[k][m]= "-";

                //cout<<Salitas[i].horario[k][m];

            }
        
            //cout<<endl;
        }

        //cout<<endl;
    }

}



void Escribirxlsx(vector<Salas> &Salitas){

    lxw_workbook *LibroExcel = workbook_new("Resultado.xlsx");
    lxw_format *format = workbook_add_format(LibroExcel);
    
    format_set_align(format,LXW_ALIGN_CENTER);

    #pragma omp parallel for
    for(int i=0; i<Salitas.size(); i++){
        
        lxw_worksheet *hoja = workbook_add_worksheet(LibroExcel,Salitas[i].edificioMasSala.c_str());
        worksheet_set_column(hoja,0,7,20,NULL);

        worksheet_write_string(hoja, 0, 0, "  ", format);
        worksheet_write_string(hoja, 0, 1, " Lunes ", format);
        worksheet_write_string(hoja, 0, 2, " Martes ", format);
        worksheet_write_string(hoja, 0, 3, " Miercoles ", format);
        worksheet_write_string(hoja, 0, 4, " Jueves ", format);
        worksheet_write_string(hoja, 0, 5, " Viernes ", format);
        worksheet_write_string(hoja, 0, 6, " Sabado ", format);
        worksheet_write_string(hoja, 1, 0, " Bloque 1 ", format);
        worksheet_write_string(hoja, 2, 0, " Bloque 2 ", format);
        worksheet_write_string(hoja, 3, 0, " Bloque 3 ", format);
        worksheet_write_string(hoja, 4, 0, " Bloque 4 ", format);
        worksheet_write_string(hoja, 5, 0, " Bloque 5 ", format);
        worksheet_write_string(hoja, 6, 0, " Bloque 6 ", format);
        worksheet_write_string(hoja, 7, 0, " Bloque 7 ", format);


        for(int fila=1; fila<8; fila++){
            for(int col=1; col<7 ; col++){
            
                worksheet_write_string(hoja, fila, col, Salitas[i].horario[col-1][fila-1].c_str() , format);

            }

        }

    }

    workbook_close(LibroExcel);

}


void HacerHorario(vector<DocentesInfo> &Docentes, vector<Salas> &Salitas, vector<Cursos> &Cursitos){

    string CursoAux;
    string DocenteAux;
    string UnirDatos;

    //int cantidadBloques = 0; 
    int horaPedagogicaCurso = 0;

    bool colocarCurso = false;

    /*
    for(int cbloque=0; cbloque<Cursitos.size() ; cbloque++ ){
        cantidadBloques = cantidadBloques + Cursitos[cbloque].HorasPedagogicas;
    }
    */
    //cout<<"Cantidad de bloques inicio: "<<cantidadBloques <<endl;   //988 bloques en total 


    #pragma omp parallel for schedule( auto )
    for(int i=0;i < Cursitos.size(); ){

        colocarCurso = false;

        CursoAux = Cursitos[i].CodigoCurso;
        //En Cursitos se guarda el id asi "2153.0" y en Docentes se guarda asi "2153", por eso se aplica erase(4.2) para que sean iguales
        DocenteAux = Cursitos[i].idDocenteCurso.erase(4,2);
        
        if(horaPedagogicaCurso==0){
            horaPedagogicaCurso = Cursitos[i].HorasPedagogicas;
            
        }
        

        //cout<<CursoAux<<" "<<DocenteAux<<" "<<horaPedagogicaCurso<<" "<<endl;
        
        if(CursoAux.compare(0,3,"INF") == 0){

            for(int k=0;k<Docentes.size(); k++){

                if( Docentes[k].idDocente.compare(DocenteAux) == 0){

                    //cout<<DocenteAux<<" " << Docentes[k].idDocente<<"  Son iguales"<<endl;

                    for(int D=0; D<6; D++){
                        for(int B=0; B<7; B++){

                            if(Docentes[k].BloquesDisponible[D][B] == 1){

                                //cout<<DocenteAux <<" disponible en el dia: "<<D<<" en el bloque: "<<B<<" "<<endl;

                                for( int sal=0; sal<Salitas.size(); sal++){

                                    if(Salitas[sal].edificio.compare("LAB") == 0){

                                        if(Salitas[sal].horario[D][B].compare("-") == 0 ){  
                                        
                                            //cout<<"Disponible la sala: "<<Salitas[sal].edificioMasSala<<" en el dia: "<<D<<" en el bloque: "<<B<<endl;
                                            

                                            UnirDatos = CursoAux + " - " + DocenteAux;
                                            Salitas[sal].horario[D][B] = UnirDatos;
                                            Docentes[k].BloquesDisponible[D][B] = 0;

                                            horaPedagogicaCurso = horaPedagogicaCurso - 1; 
                                            //cantidadBloques = cantidadBloques - 1;    
                                        
                                            colocarCurso = true;

                                            if(horaPedagogicaCurso == 0){
                                            
                                                i = i + 1;

                                            }

                                            break;

        
                                        }
                                        
                                    }
                                

                                }

                            }

                            if(colocarCurso == true){
                                break;
                       
                            }
                            

                        }
                        
                        if(colocarCurso == true){   
                            break;
                       
                        }
                    
                    }

                }
                
                if(colocarCurso==true){

                    break;

                }

            }

        }
        if(CursoAux.compare(0,3,"INF") != 0){ //otros cursos que no son "INF"

            for(int p=0; p<Docentes.size(); p++){   

                if( Docentes[p].idDocente.compare(DocenteAux) == 0){

                    //cout<<"Docente igual al docenteAux"<<endl;
                    for(int Di=0; Di<6; Di++){
                        for(int Blo=0; Blo<7; Blo++){

                            if(Docentes[p].BloquesDisponible[Di][Blo] == 1){

                                //cout<<DocenteAux <<" disponible en el dia: "<<Di<<" en el bloque: "<<Blo<<" "<<endl;

                                for( int Y=0; Y<Salitas.size(); Y++){

                                    if(Salitas[Y].edificio.compare("LAB") != 0){

                                        if(Salitas[Y].horario[Di][Blo].compare("-") == 0 ){

                                            //cout<<"Disponible la sala: "<<Salitas[Y].edificioMasSala<<" en el dia: "<<Di<<" en el bloque: "<<Blo<<endl;


                                            UnirDatos = CursoAux + " - " + DocenteAux;
                                            Salitas[Y].horario[Di][Blo] = UnirDatos;
                                            Docentes[p].BloquesDisponible[Di][Blo] = 0;

                                            horaPedagogicaCurso = horaPedagogicaCurso - 1; 
                                            //cantidadBloques = cantidadBloques - 1;    
                                        
                                            colocarCurso = true;

                                            if(horaPedagogicaCurso == 0){
                                            
                                                i = i + 1;

                                            }

                                            break;


                                        }


                                    }



                                }


                            }


                            if(colocarCurso == true){
                                break;
                       
                            }

                            
                        }

                        if(colocarCurso == true){   
                            break;
                       
                        }


                    }
                


                }

                if(colocarCurso == true){   
                    break;
                       
                }


            }

        }

    

    }

    //cout<<"Cantidad de bloques al final: "<<cantidadBloques<<endl;

}

