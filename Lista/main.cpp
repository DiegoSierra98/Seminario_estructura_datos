#include <iostream>
class SocioClub{
public:
    int NumeroSocio;
    std::string NombreSocio;
    std::string Domicilio;
    int AnioIngreso;

    SocioClub(){};
    friend std::ostream & operator<<(std::ostream &O, SocioClub &x);
    friend std::istream & operator>>(std::ostream &O, SocioClub &x);
    bool operator==(const SocioClub &s);
    bool operator!=(const SocioClub &s);
    bool operator<(const SocioClub &s);
};
std::ostream & operator<<(std::ostream &O, SocioClub &x){
    O << "\t Nombre_Socio: " << x.NombreSocio << std::endl;
    O << "\t Numero_Socio: " << x.NumeroSocio << std::endl;
    O << "\t Domicilio: " << x.Domicilio << std::endl;
    O << "\t Anio de ingreso: " << x.AnioIngreso << std::endl;

    return O;
}

std::istream & operator>>(std::istream &O, SocioClub &x){
    std::cout<<"\n Nombre Socio: ";
    O>>x.NombreSocio;
    std::cout<<"\n Numero de Socio: ";
    O>>x.NumeroSocio;
    std::cout<<"\n Domicilio: ";
    O>>x.Domicilio;
    std::cout<<"\n Anio Ingreso: ";
    O>>x.AnioIngreso;

    return O;
};

bool SocioClub::operator==(const SocioClub &s) {
    return this->NombreSocio.compare(s.NombreSocio) == 0 &&
    this->Domicilio.compare(s.Domicilio) == 0;
}
bool SocioClub::operator!=(const SocioClub &s) {
    return this->NumeroSocio != s.NumeroSocio;
}
bool SocioClub::operator<(const SocioClub &s) {
    return this->NumeroSocio < s.NumeroSocio;
}


template<class T>
class LSLSE;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class LSLSE<T>;
};

template<class T>
class LSLSE{
private:
    node<T>* lista;
public:
    LSLSE():lista(nullptr){};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    //Nuevos metodos para cumplir con requisitos de tarea
    void insertarAlPrincipio(T elem);
    bool insertarEnOrden(T elem);
    node<T>* buscar(T elem);
    void imprimirNodo(node<T>* pos);
    int contarElementos();
};

template<class T>
void LSLSE<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> ";
        aux=aux->sig;
    }
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

//Implementacion de nuevos metodos

/// Esta funcion se usa para insertar al principio de la lista
/// cuando el nuevo valor es el menor de todos
/// \tparam T
/// \param elem
template<class T>
void LSLSE<T>::insertarAlPrincipio(T elem) {
    node<T>* aux= new node<T>;
    aux->data=elem;

    aux->sig=lista;
    lista=aux;
}

/// Este metodo inserta al final de la lista,
/// al principio de la lista
/// o en una posicion especifica dependiendo del valor a insertar
/// si el valor de comparacion ya esta en la lista no se inserta el registro
/// para evitar duplicados
/// \tparam T
/// \param elem
template<class T>
bool LSLSE<T>::insertarEnOrden(T elem){

    bool insercionExitosa = true;

    if(vacia()){
        insertar(ultimo(), elem);
        return insercionExitosa;
    }

    node<T>* actual = ultimo();
    node<T>* primerNodo = primero();

    while(actual != nullptr){

        //Validar si el numero de socio ya existe en la lista
        if(!(actual->data != elem)){
            insercionExitosa = false;
            break;
        }

        if(actual->data < elem){
            insertar(actual, elem);
            break;
        }
        actual = anterior(actual);
    }

    if(actual == nullptr){
        insertarAlPrincipio(elem);
    }

    return insercionExitosa;
}

/// Busca elemento en la lista
/// \tparam T
/// \param elem
/// \return
template<class T>
node<T>* LSLSE<T>::buscar(T elem) {
    node<T>* actual = ultimo();
    while(actual != nullptr){

        if(actual->data == elem)
            break;

        actual = anterior(actual);
    }
    return actual;
}

/// Imprime un nodo de la lista
/// \tparam T
/// \param nodo
template<class T>
void LSLSE<T>::imprimirNodo(node<T>* nodo){
    std::cout<<nodo->data<<"-> ";
}

/// Calcula y regresa la cantidad de elementos en la lista
/// \tparam T 
/// \return 
template<class T>
int LSLSE<T>::contarElementos() {
    int cantidadDeElementos = 0;

    node<T>* aux=lista;
    while(aux!=nullptr){
        cantidadDeElementos++;
        aux=aux->sig;
    }

    return cantidadDeElementos;
}

int Menu(){
    int opcion;

    std::cout<<"\n\n\tSelecciona una opcion:\n\n";
    std::cout<<"\t1. Registrar un nuevo socio\n";
    std::cout<<"\t2. Dar de baja un socio\n";
    std::cout<<"\t3. Reporte con los datos de todos los socios\n";
    std::cout<<"\t4. Buscar por nombre y domicilio a un socio del club\n";
    std::cout<<"\t5. Calcular e imprimir todos los socios registrados\n";
    std::cout<<"\t6. Salir\n";
    std::cin>> opcion;

    return opcion;
}

int main() {
    int opcionMenu;
    bool resultadoInsercion;

    LSLSE<SocioClub> listaSocios;
    SocioClub socioClub;
    node<SocioClub>* nodoSocio;

    do{
        opcionMenu = Menu();
        switch (opcionMenu)
        {
            case 1:
                std::cin>>socioClub;
                resultadoInsercion = listaSocios.insertarEnOrden(socioClub);

                if (resultadoInsercion)
                    std::cout << "\tRegistro agregado exitosamente!" << std::endl;
                else 
                    std::cout << "\t El numero de socio " << socioClub.NumeroSocio 
                    << " ya ha sido asignado, intenta con otro." << std::endl;
                break;
            case 2:
                std::cout << "\tNombre del socio" << std::endl;
                std::cin >> socioClub.NombreSocio;
                std::cout << "\tDomicilio del socio" << std::endl;
                std::cin >> socioClub.Domicilio;

                nodoSocio = listaSocios.buscar(socioClub);

                if (nodoSocio != nullptr){
                    listaSocios.eliminar(nodoSocio);
                    std::cout << "\tEl socio " << socioClub.NombreSocio << " ha sido eliminado" << std::endl;
                }
                else{
                    std::cout << "\tEl socio que deseas eliminar no existe" << std::endl;
                }
                break;
            case 3:
                listaSocios.imprimir();
                break;
            case 4:
                std::cout << "\tNombre del socio" << std::endl;
                std::cin >> socioClub.NombreSocio;
                std::cout << "\tDomicilio del socio" << std::endl;
                std::cin >> socioClub.Domicilio;

                nodoSocio = listaSocios.buscar(socioClub);

                if (nodoSocio != nullptr){
                    listaSocios.imprimirNodo(nodoSocio);
                }
                else{
                    std::cout << "\tEl socio que buscas no existe" << std::endl;
                }
                break;
            case 5:
                std::cout << "Existen " << listaSocios.contarElementos() << " socios registrados" << std::endl;
                break;
            case 6:
                std::cout << "Hasta luego!" << std::endl;
                break;
            default:
                std::cout<<" Por favor elige otra opcion\n";
                break;
        }
    } while(opcionMenu != 6);
    return 0;
}
