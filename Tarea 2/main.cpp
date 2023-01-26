#include <iostream>
#include <string.h>

//using namespace std;
class Materia{
private:
    int Clave;
    char Nombre[100];
    char ProfesorTit [100];
    char LibroTexto [100];
public:
    //Constructor por default
    Materia();
    Materia(int clave, char nombre[100], char profesor[100], char libroTexto[100]);
    void Imprime();
    void CambiaClave(int nuevaClave);
    void CambiaProfe(char nuevoProfesor[]);
};

Materia::Materia(){
    Clave = 123456;
    strcpy(Nombre, "Materia por default");
    strcpy(ProfesorTit, "Maestro por default");
    strcpy(LibroTexto, "Libro por default");
}

//Constructor por parametros
Materia::Materia(int clave, char *nombre, char *profesor, char *libroTexto){
    Clave = clave;
    strcpy(Nombre, nombre);
    strcpy(ProfesorTit, profesor);
    strcpy(LibroTexto, libroTexto);
}

void Materia::Imprime() {
    std::cout << "\n\tDATOS DE LA MATERIA" << std::endl;
    std::cout << "\tClave: " << Clave << std::endl;
    std::cout << "\tNombre: " << Nombre << std::endl;
    std::cout << "\tProfesor: " << ProfesorTit << std::endl;
    std::cout << "\tLibro Texto: " << LibroTexto << std::endl << std::endl;
}
void Materia::CambiaClave(int nuevaClave){
     Clave=nuevaClave;
}
void Materia::CambiaProfe(char *nuevoProfesor){
    strcpy(ProfesorTit, nuevoProfesor);
}
int Menu(){
    int opcion = 0;

    do {
        std::cout << "\tSELECCIONA UNA OPCION" << std::endl;
        std::cout << "\t1. Imprimir los datos de la materia de bases de datos" << std::endl;
        std::cout << "\t2. Imprimir los datos de la materia de programacion" << std::endl;
        std::cout << "\t3. Actualizar el maestro de bases de datos" << std::endl;
        std::cout << "\t4. Actualizar la clave de programacion" << std::endl;
        std::cout << "\t5. Salir" << std::endl;
        std::cin >> opcion;

        if (opcion < 1 || opcion > 4)
            std::cout << "\t SELECCIONA UNA OPCION VALIDA" << std::endl;

    } while (opcion < 1 || opcion > 4);

    return opcion;
}

int main()
{
    Materia MateriaDefault;
    Materia Programacion(123, "Programacion", "JOSE MAR", "C++ y sus metodos");
    Materia BasesDatos(456, "BASESDATOS", "Jose Maria", "BasesLocas");

    int opcionMenu;
    int clave;

    char nuevoProfesor[100];

    do {
        opcionMenu = Menu();

        switch (opcionMenu) {
            case 1:
                BasesDatos.Imprime();
                break;
            case 2:
                Programacion.Imprime();
                break;
            case 3:
                std::cout << "\t INGRESA EL NUEVO MAESTRO" << std::endl;
                std::cin >> nuevoProfesor;
                BasesDatos.CambiaProfe(nuevoProfesor);
                break;
            case 4:
                std::cout << "\t ACTUALIZA LA CLAVE DE PROGRAMACION" << std::endl;
                std::cin >> clave;
                Programacion.CambiaClave(clave);
                break;
            case 5:
                std::cout << "\t HASTA LUEGO"<< std::endl;
        }
    } while (opcionMenu != 5);
    return 0;
}

