#include <iostream>
#include <string.h>

//using namespace std;
class Empleado{
private:
    int ClaveEmpleado;
    char Nombre[100];
    char Domicilio [100];
    float Sueldo;
    char ReportaA [100];
public:
    //Constructor por default
    Empleado();
    Empleado(char nombre[100], int claveEmpleado, char domicilio[100], float sueldo, char reportaA[100]);
    void Imprime();
    void CambiaDomicilio(char nuevoDomicilio[]);
    void CambiaReportaA(char nuevoSuperior[]);
    void ActualizarSueldo(float porcentajeAumento);
    bool ValidaClave(int clave);
};

Empleado::Empleado(){
    ClaveEmpleado = 123456;
    strcpy(Nombre, "Empleado default");
    strcpy(Domicilio, "Domicilio default");
    Sueldo = 7000;
    strcpy(ReportaA, "Empleado default 2");
}

//Constructor por parametros
Empleado::Empleado(char *nombre, int claveEmpleado, char *domicilio, float sueldo, char *reportaA) {
    ClaveEmpleado = claveEmpleado;
    strcpy(Nombre, nombre);
    strcpy(Domicilio, domicilio);
    Sueldo = sueldo;
    strcpy(ReportaA, reportaA);
}

void Empleado::Imprime() {
    std::cout << "\n\tDATOS DEL EMPLEADO" << std::endl;
    std::cout << "\tClave: " << ClaveEmpleado << std::endl;
    std::cout << "\tNombre: " << Nombre << std::endl;
    std::cout << "\tDomicilio: " << Domicilio << std::endl;
    std::cout << "\tSueldo: " << Sueldo << std::endl;
    std::cout << "\tReporta a: " << ReportaA << std::endl << std::endl;
}

void Empleado::CambiaDomicilio(char *nuevoDomicilio) {
    strcpy(Domicilio, nuevoDomicilio);
}

void Empleado::CambiaReportaA(char *nuevoSuperior) {
    strcpy(ReportaA, nuevoSuperior);
}

void Empleado::ActualizarSueldo(float porcentajeAumento) {
    int cantidadDeAumento;

    cantidadDeAumento = (Sueldo * porcentajeAumento) / 100;

    Sueldo = Sueldo + cantidadDeAumento;
}

bool Empleado::ValidaClave(int clave) {
    if (ClaveEmpleado == clave)
        return  true;

    return false;
}

int Menu(){
    int opcion = 0;

    do {
        std::cout << "\tSELECCIONA UNA OPCION" << std::endl;
        std::cout << "\t1. Imprimir los datos de un empleado" << std::endl;
        std::cout << "\t2. Actualizar el domicilio de un empleado" << std::endl;
        std::cout << "\t3. Actualizar el sueldo de un empleado" << std::endl;
        std::cout << "\t4. Actualizar el superior de un empleado" << std::endl;
        std::cout << "\t5. Salir" << std::endl;
        std::cin >> opcion;

        if (opcion < 1 || opcion > 5)
            std::cout << "\t SELECCIONA UNA OPCION VALIDA" << std::endl;

    } while (opcion < 1 || opcion > 5);

    return opcion;
}

int main()
{
    Empleado empleadoDefault;
    Empleado jefePlanta("Girasol", 123, "Javier Mina", 8000, "Bugambilia");
    Empleado jefePersonal("Alexa", 456, "Jose Maria", 10000, "ANA");

    int opcionMenu;
    int claveEmpleado;
    char nuevoDomicilio[100];
    char nuevoSuperior[100];
    float porcentajeAumento;

    do {
        opcionMenu = Menu();

        switch (opcionMenu) {
            case 1:
                std::cout << "\t INGRESA LA CLAVE DEL EMPLEADO" << std::endl;
                std::cin >> claveEmpleado;

                if (jefePlanta.ValidaClave(claveEmpleado) == true)
                    jefePlanta.Imprime();
                else if(jefePersonal.ValidaClave(claveEmpleado) == true)
                    jefePersonal.Imprime();
                else
                    std::cout << "\t No hay empleados con esa clave" << std::endl;
                break;
            case 2:
                std::cout << "\t INGRESA LA CLAVE DEL EMPLEADO" << std::endl;
                std::cin >> claveEmpleado;

                if (jefePlanta.ValidaClave(claveEmpleado) == true){
                    std::cout << "\t INGRESA EL NUEVO DOMICILIO" << std::endl;
                    std::cin >> nuevoDomicilio;
                    jefePlanta.CambiaDomicilio(nuevoDomicilio);
                }

                else if(jefePersonal.ValidaClave(claveEmpleado)){
                    std::cout << "\t INGRESA EL NUEVO DOMICILIO" << std::endl;
                    std::cin >> nuevoDomicilio;
                    jefePersonal.CambiaDomicilio(nuevoDomicilio);
                }

                else
                    std::cout << "\t No hay empleados con esa clave" << std::endl;
                break;
            case 3:
                std::cout << "\t INGRESA LA CLAVE DEL EMPLEADO" << std::endl;
                std::cin >> claveEmpleado;

                if (jefePlanta.ValidaClave(claveEmpleado) == true){
                    std::cout << "\t INGRESA EL PORCENTAJE A AUMENTAR" << std::endl;
                    std::cin >> porcentajeAumento;
                    jefePlanta.ActualizarSueldo(porcentajeAumento);
                }

                else if(jefePersonal.ValidaClave(claveEmpleado)){
                    std::cout << "\t INGRESA EL PORCENTAJE A AUMENTAR" << std::endl;
                    std::cin >> porcentajeAumento;
                    jefePersonal.ActualizarSueldo(porcentajeAumento);
                }
                else
                    std::cout << "\t No hay empleados con esa clave" << std::endl;
                break;
            case 4:
                std::cout << "\t INGRESA LA CLAVE DEL EMPLEADO" << std::endl;
                std::cin >> claveEmpleado;
                if (jefePlanta.ValidaClave(claveEmpleado) == true){
                    std::cout << "\t Nueva persona a la que le reporta" << std::endl;
                    std::cin >> nuevoSuperior;
                    jefePlanta.CambiaReportaA(nuevoSuperior);
                }
                else if(jefePersonal.ValidaClave(claveEmpleado)){
                    std::cout << "\t Nueva persona a la que le reporta" << std::endl;
                    std::cin >> nuevoSuperior;
                    jefePersonal.CambiaReportaA(nuevoSuperior);
                }
                else
                    std::cout << "\t No hay empleados con esa clave" << std::endl;
                break;
        }
    } while (opcionMenu != 5);
    return 0;
}

