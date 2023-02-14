#include <iostream>
#include <string.h>

class Mamifero {
public:
    char Dieta [100];
    char FechaNacimiento [50];
    char LugarNacimiento[100];
    char Raza [100];
    void ImprimirDieta();
    void ImprimirDatosNacimiento();
    void ImprimirRaza();
};

void Mamifero::ImprimirDieta() {
    std::cout << "\t Dieta: " << Dieta << std::endl;
}

void Mamifero::ImprimirDatosNacimiento() {
    std::cout << "\t Fecha de nacimiento: " << FechaNacimiento << std::endl;
    std::cout << "\t Lugar de nacimiento: " << LugarNacimiento << std::endl;
}

void Mamifero::ImprimirRaza() {
    std::cout << "\t Raza: " << Raza << std::endl;
}

class Felino : public Mamifero {
private:
    char Circo[100];
public:
    Felino();
    void ImprimirCirco();
    void CambiarCirco(char nuevoCirco[]);
};

Felino::Felino() {
    strcpy(Dieta, "Carnivoro");
    strcpy(LugarNacimiento, "Chiapas");
    strcpy(FechaNacimiento, "12/12/22");
    strcpy(Raza, "Tigre");
    strcpy(Circo, "Atayde hermanos");
}

void Felino::ImprimirCirco () {
    std::cout << "\t Circo en el que actua: " << Circo << std::endl;
}

void Felino::CambiarCirco(char *nuevoCirco){
    strcpy(Circo, nuevoCirco);
}

class GatoDomestico : public Felino{
private:
    char Duenio [100];
public:
    GatoDomestico();
    void MostrarDuenio();
    void CambiarDuenio(char nuevoDuenio[]);
};
GatoDomestico::GatoDomestico(){
    strcpy(Dieta, "Croquetas");
    strcpy(LugarNacimiento, "Hoenn");
    strcpy(FechaNacimiento, "17/12/20");
    strcpy(Raza, "Egipcio");
    strcpy(Duenio, "Lionel");
}

void GatoDomestico::MostrarDuenio() {
    std::cout << "\t Dueño: " << Duenio << std::endl;
}
void GatoDomestico::CambiarDuenio(char *nuevoDuenio) {
    strcpy(Duenio, nuevoDuenio);
    std::cout << "\t Nuevo Dueño: " << nuevoDuenio << std::endl;
}

int Menu(){
    int opcion = 0;

    do {
        std::cout << "\tSELECCIONA UNA OPCION" << std::endl;
        std::cout << "\t1. Imprimir la dieta de Minino y de EstrellaCirco." << std::endl;
        std::cout << "\t2. Imprimir el anio y lugar de nacimiento de Minino y de EstrellaCirco." << std::endl;
        std::cout << "\t3. Cambiar el nombre del duenioo de Minino." << std::endl;
        std::cout << "\t4. Imprimir la raza de Minino y de EstrellaCirco." << std::endl;
        std::cout << "\t5. Cambiar el nombre del circo en el que actua EstrellaCirco." << std::endl;
        std::cout << "\t6. Mostrar duenioo de Minino" << std::endl;
        std::cout << "\t7. Mostrar nuevo circo" << std::endl;
        std::cout << "\t8. SALIR" << std::endl;
        std::cin >> opcion;

        if (opcion < 1 || opcion > 8)
            std::cout << "\t SELECCIONA UNA OPCION VALIDA" << std::endl;

    } while (opcion < 1 || opcion > 8);

    return opcion;
}

int main() {

    GatoDomestico Minino;
    Felino EstrellaCirco;

    int opcionMenu;
    int clave;

    char nuevoDuenio[100];

    do {
        opcionMenu = Menu();

        switch (opcionMenu) {
            case 1:
                std::cout << "\t Dieta Minino" << std::endl;Minino.ImprimirDieta();
                std::cout << "\t Dieta Felino" << std::endl;EstrellaCirco.ImprimirDieta();
                break;
            case 2:
                std::cout << "\t Datos Nacimiento Minino" << std::endl;Minino.ImprimirDatosNacimiento();
                std::cout << "\t Datos Nacimiento EstrellaCirco" << std::endl;EstrellaCirco.ImprimirDatosNacimiento();
                break;
            case 3:
                std::cout << "\t INGRESA EL NUEVO DUeño" << std::endl;
                std::cin >> nuevoDuenio;
                Minino.CambiarDuenio(nuevoDuenio);
                break;
            case 4:
                std::cout << "\t Raza de Minino" << std::endl;Minino.ImprimirRaza();
                std::cout << "\t Raza de Felino" << std::endl;EstrellaCirco.ImprimirRaza();
                break;
            case 5:
                std::cout << "\t INGRESA EL NUEVO CIRCO" << std::endl;
                std::cin >> nuevoDuenio;
                EstrellaCirco.CambiarCirco(nuevoDuenio);
                break;
            case 6:
                Minino.MostrarDuenio();
                break;
            case 7:
                EstrellaCirco.ImprimirCirco();
                break;
            case 8:
                std::cout << "\t Hasta luego" << std::endl;
        }

    } while (opcionMenu != 8);
    return 0;
}

