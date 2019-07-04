
#include <string>
#include <vector>



typedef struct DocentesInfo{
    std::string idDocente;
    int BloquesDisponible[6][7]; //matriz donde se guarda la disponibilidad en cada bloque del docente, siendo 1 = disponible y 0=noDisponible 
                                 // [6] son los dias de la semana y [7] la cantidad de bloques por dia.
}DocentesInfo;



typedef struct Salas{
    std::string edificio;
    std::string salaNumero;
    std::string edificioMasSala;
    std::string horario[6][7]; //[6] son los dias de la semana y [7] la cantidad de bloques por dia.

}Salas;



typedef struct Cursos{
    std::string CodigoCurso;
    std::string idDocenteCurso;
    int HorasPedagogicas;

}Cursos;


//colocar el std:: ¡NO OLVIDAR!

//funciones Docente
void GuardarListaDocenteLunes(std::vector<DocentesInfo> &Docentes, const char* Archivo);  //crea vector y le agrega los valores del dia lunes
void GuardarListaDocente(std::vector<DocentesInfo> &Docentes, const char* DiaHoja, const char* Archivo);  // solo agregan el valor del resto de los dias
void ImprimirDocentes(std::vector<DocentesInfo> &Docentes);

//Funciones Salas
void GuardarSalas(std::vector<Salas> &Salitas, const char* Archivo);
void ImprimirSalas(std::vector<Salas> &Salitas);

//Funciones Cursos
void GuardadCursos(std::vector<Cursos> &Cursitos, const char* Archivo);
void ImprimirCursos(std::vector<Cursos> &Cursitos);


//Salida.cpp
void set_salasHorario(std::vector<Salas> &Salitas);
void Escribirxlsx(std::vector<Salas> &Salitas);


//Planificacion academica
void HacerHorario(std::vector<DocentesInfo> &Docentes, std::vector<Salas> &Salitas, std::vector<Cursos> &Cursitos);


