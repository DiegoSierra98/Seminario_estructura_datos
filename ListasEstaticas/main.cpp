#include <iostream>
#include <string.h>
#define TAM 50

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
    GatoDomestico(char raza[], char duenio[], char dieta[], 
    char lugarNacimiento[],
    char fechaNacimiento[]);
    void MostrarDuenio();
    void CambiarDuenio(char nuevoDuenio[]);
    bool operator==(const GatoDomestico &g);

    friend std::ostream& operator << (std::ostream &o,const GatoDomestico &g);
};

GatoDomestico::GatoDomestico(){
    strcpy(Dieta, "Croquetas");
    strcpy(LugarNacimiento, "Hoenn");
    strcpy(FechaNacimiento, "17/12/20");
    strcpy(Raza, "Egipcio");
    strcpy(Duenio, "Lionel");
}

GatoDomestico::GatoDomestico(char *raza, char *duenio, char *dieta, char *lugarNacimiento, char *fechaNacimiento)
{
    strcpy(Raza, raza);
    strcpy(Duenio, duenio);
    strcpy(Dieta, dieta);
    strcpy(LugarNacimiento, lugarNacimiento);
    strcpy(FechaNacimiento, fechaNacimiento);
}

bool GatoDomestico::operator ==(GatoDomestico const &g)
{
    return strcmp(this->Duenio, g.Duenio) == 0 && strcmp(this->Raza, g.Raza) == 0;
}

std::ostream& operator << (std::ostream &o,const GatoDomestico &g)
{
    o << "\t Raza: " << g.Raza << std::endl;
    o << "\t Duenio: " << g.Duenio << std::endl;
    o << "\t Dieta: " << g.Dieta << std::endl;
    o << "\t Fecha de nacimiento: " << g.FechaNacimiento << std::endl;
    o << "\t Lugar de nacimiento: " << g.LugarNacimiento << std::endl;
    return o;
}

void GatoDomestico::MostrarDuenio() {
    std::cout << "\t Dueño: " << Duenio << std::endl;
}
void GatoDomestico::CambiarDuenio(char *nuevoDuenio) {
    strcpy(Duenio, nuevoDuenio);
    std::cout << "\t Nuevo Dueño: " << nuevoDuenio << std::endl;
}

//plantillas
template <class T>
class Lista{
private:
    T datos[TAM];
    int ult;
public:
    Lista():ult(-1){}
    bool agrega(T);
    bool vacia()const;
    bool llena()const;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
    int buscar(T);
};

template<class T>
bool Lista<T>::agrega(T elemento)
{
    if(llena())
    {
        std::cout << "\tNo se puede agregar el registro" << std::endl;
        return false;
    }

    datos[ult + 1] = elemento;
    ult++;

    return true;
}

template <class T>
int Lista<T>::buscar(T elem){

    int i=0;

    while(i <= ult)
    {
        if(elem == datos[i]){
            return i;
        }
        i++;
    }
    return -1;
}

template <class T>
void Lista<T>::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            std::cout<<datos[i]<<std::endl;
        }
    }
}

template <class T>
bool Lista<T>::vacia()const{
    return ult==-1;
}

template <class T>
bool Lista<T>::llena()const{
    return ult==TAM-1;
}

template <class T>
bool Lista<T>::inserta(T elem, int pos){

    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }

    int i = ult+1;

    while(i > pos) 
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template <class T>
bool Lista<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }

    int i=pos;

    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template <class T>
T Lista<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template <class T>
int Lista<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}
template <class T>
int Lista<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

int Menu(){
    int opcion;

    std::cout<<"\n\n\tSelecciona una opcion:\n\n";
    std::cout<<"\t1. Agregar al final\n";
    std::cout<<"\t2. Buscar\n";
    std::cout<<"\t3. Eliminar\n";
    std::cout<<"\t4. Inserta en posicion\n";
    std::cout<<"\t5. Mostrar lista\n";
    std::cout<<"\t6. Salir\n\n";
    std::cin>> opcion;

    return opcion;
}

GatoDomestico NuevoGatoDomestico()
{
    char raza[100], duenio[100], dieta[100], fechaNacimiento[50], lugarNacimiento[100];

    std::cout << "\t INGRESA LA RAZA: " << std::endl;
    std::cin >> raza;
    std::cout << "\t INGRESA EL NOMBRE DEL DUENIO" << std::endl;
    std::cin >> duenio;
    std::cout << "\t INGRESA LA DIETA ALIMENTICIA" << std::endl;
    std::cin >> dieta;
    std::cout << "\t INGRESA LA FECHA DE NACIMIENTO" << std::endl;
    std::cin >> fechaNacimiento;
    std::cout << "\t INGRESA EL LUGAR DE NACIMIENTO" << std::endl;
    std::cin >> lugarNacimiento;

    GatoDomestico gato =  GatoDomestico(raza, duenio, dieta, lugarNacimiento, fechaNacimiento);

    return gato;
}

GatoDomestico BuscarGatoDomestico()
{
    char raza[100], duenio[100];

    std::cout << "\t INGRESA LA RAZA: " << std::endl;
    std::cin >> raza;
    std::cout << "\t INGRESA EL NOMBRE DEL DUENIO" << std::endl;
    std::cin >> duenio;

    GatoDomestico gato =  GatoDomestico(raza, duenio, "", "", "");

    return gato;
}

int main()
{
    int opcionMenu;
    bool respuesta;
    int posicion;

    Lista<GatoDomestico> ListaEstatica;
    GatoDomestico gatoDomestico;

    do{
        opcionMenu = Menu();

        switch (opcionMenu)
        {
        case 1:
            gatoDomestico = NuevoGatoDomestico();
            respuesta = ListaEstatica.agrega(gatoDomestico);
            if (respuesta)
                std::cout << "\tRegistro agregado exitosamente!" << std::endl;
            break;
        case 2:
            gatoDomestico = BuscarGatoDomestico();
            posicion = ListaEstatica.buscar(gatoDomestico);
            std :: cout << "POSICION" << posicion << std::endl;
            if (ListaEstatica.vacia())
                std::cout << "\t---La lista esta vacia---";
            else if (posicion == -1)
                std::cout << "\t---El elemento no existe en la lista---";
            else 
                std:: cout << "\t El elemento se encuentra en la posicion " << posicion << " de la lista" << std::endl;
            break;
        case 3:
            gatoDomestico = BuscarGatoDomestico();
            posicion = ListaEstatica.buscar(gatoDomestico);
            if (ListaEstatica.vacia())
                std::cout << "\t---La lista esta vacia---";
            else if (posicion == -1)
                std::cout << "\t---El elemento no existe en la lista---";
            else 
                ListaEstatica.elimina(posicion);
            break;
        case 4:
            gatoDomestico = NuevoGatoDomestico();
            std::cout << "\tIngresa la posicion en la que deseas insertar" << std::endl;
            std::cin >> posicion;
            respuesta = ListaEstatica.inserta(gatoDomestico, posicion);
            break;
        case 5:
            ListaEstatica.imprime();
            break;
        case 6:
            std::cout<<"\tHasta luego!!!\n";
            break;
        default:
            std::cout<<" Por favor elige otra opcion\n";
            break;
        }

    } while (opcionMenu != 6);

    return 0;
}
