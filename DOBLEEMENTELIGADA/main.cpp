#include <iostream>

/// Clase socio
class SocioClub
{
public:
    int NumeroSocio;
    std::string NombreSocio;
    std::string Domicilio;
    int AnioIngreso;

    SocioClub(){};
    friend std::ostream &operator<<(std::ostream &O, SocioClub &x);
    friend std::istream &operator>>(std::ostream &O, SocioClub &x);
    bool operator==(const SocioClub &s);
    bool operator!=(const SocioClub &s);
    bool operator<(const SocioClub &s);
};

std::ostream &operator<<(std::ostream &O, SocioClub &x)
{
    O << "\t Nombre_Socio: " << x.NombreSocio << std::endl;
    O << "\t Numero_Socio: " << x.NumeroSocio << std::endl;
    O << "\t Domicilio: " << x.Domicilio << std::endl;
    O << "\t Anio de ingreso: " << x.AnioIngreso << std::endl;

    return O;
}

std::istream &operator>>(std::istream &O, SocioClub &x)
{
    std::cout << "\n Nombre Socio: ";
    O.ignore();
    std::getline(O, x.NombreSocio);
    std::cout << "\n Numero de Socio: ";
    O >> x.NumeroSocio;
    std::cout << "\n Domicilio: ";
    O.ignore();
    std::getline(O, x.Domicilio);
    std::cout << "\n Anio Ingreso: ";
    O >> x.AnioIngreso;

    return O;
};

bool SocioClub::operator!=(const SocioClub &s)
{
    if (this->NombreSocio.compare(s.NombreSocio) == 0 && this->Domicilio.compare(s.Domicilio) == 0)
    {
        return false;
    }

    return true;
}

bool SocioClub::operator==(const SocioClub &s)
{
    return this->NumeroSocio == s.NumeroSocio;
}

/// Template lista doblemente ligada
template <class T>
class LDLLSE;

template <class T>
class nodo
{
private:
    T data;
    nodo<T> *sig;
    nodo<T> *ant;

public:
    nodo() : sig(nullptr), ant(nullptr){};
    friend class LDLLSE<T>;
};

template <class T>
class LDLLSE
{
private:
    nodo<T> *ancla;

public:
    LDLLSE() : ancla(nullptr){};
    bool vacia() const;
    nodo<T> *primero() const;
    nodo<T> *ultimo() const;
    nodo<T> *anterior(nodo<T> *) const;
    nodo<T> *siguiente(nodo<T> *) const;
    nodo<T> *localiza(T) const;
    T recupera(nodo<T> *) const;
    void imprime() const;
    void anula();
    void inserta(nodo<T> *pos, T elem);
    void elimina(nodo<T> *pos);
    //nuevos metodos
    bool numeroSocioExiste(T elem);
    int contarSocios();
};

template <class T>
void LDLLSE<T>::inserta(nodo<T> *pos, T elem)
{
    nodo<T>* aux = new nodo<T>;
    aux->data = elem;

    if (pos == nullptr)
    {
        aux->ant = nullptr;
        aux->sig = ancla;

        if (ancla != nullptr)
        {
            ancla->ant = aux;
        }

        ancla = aux;
    }
    else
    {
        aux->ant = pos;
        aux->sig = pos->sig;

        if (pos->sig != nullptr)
        {
            pos->sig->ant = aux;
        }

        pos->sig = aux;
    }
}

template <class T>
void LDLLSE<T>::elimina(nodo<T> *pos)
{
    if (vacia() || pos == nullptr)
    {
        return;
    }

    if (pos->ant != nullptr)
    {
        pos->ant->sig = pos->sig;
    }
    if (pos->sig != nullptr)
    {
        pos->sig->ant = pos->ant;
    }
    if (pos == ancla)
    {
        ancla = ancla->sig;
    }

    delete pos;
}

template <class T>
nodo<T> *LDLLSE<T>::primero() const
{
    return ancla;
}

template <class T>
nodo<T> *LDLLSE<T>::ultimo() const
{
    if (vacia())
    {
        return ancla;
    }
    else
    {
        nodo<T> *aux = ancla;
        while (aux->sig != nullptr)
        {
            aux = aux->sig;
        }
        return aux;
    }
}

template <class T>
nodo<T> *LDLLSE<T>::anterior(nodo<T> *pos) const
{
    if (vacia() || pos == nullptr)
    {
        return nullptr;
    }
    else
    {
        return pos->ant;
    }
}

template <class T>
nodo<T> *LDLLSE<T>::siguiente(nodo<T> *pos) const
{
    if (vacia() || pos == nullptr)
    {
        return nullptr;
    }
    else
    {
        return pos->sig;
    }
}

template <class T>
nodo<T> *LDLLSE<T>::localiza(T elem) const
{
    nodo<T> *aux = ancla;
    while (aux != nullptr && aux->data != elem)
    {
        aux = aux->sig;
    }
    return aux;
}

template <class T>
T LDLLSE<T>::recupera(nodo<T> *pos) const
{
    if (vacia() || pos == nullptr)
    {
    }
    else
    {
        return pos->data;
    }
}

template <class T>
bool LDLLSE<T>::vacia() const
{
    if (ancla == nullptr)
    {
        return true;
    }
    return false;
}

template <class T>
void LDLLSE<T>::imprime() const
{
    if (!vacia())
    {
        nodo<T> *aux = ancla;
        while (aux != nullptr)
        {
            std::cout << aux->data << std::endl;
            aux = aux->sig;
        }
    }
}

template <class T>
void LDLLSE<T>::anula()
{
    nodo<T> *aux;
    while (ancla != nullptr)
    {
        aux = ancla;
        ancla = aux->sig;
        delete aux;
    }
}

//nuevos metodos
template <class T>
bool LDLLSE<T>::numeroSocioExiste(T elem)
{
    bool numeroExiste = false;

    nodo<T> *aux = ancla;
    while (aux != nullptr)
    {
        if (aux->data == elem)
        {
            numeroExiste = true;
            break;
        }
        aux = aux->sig;
    }

    return numeroExiste;
}

template <class T>
int LDLLSE<T>::contarSocios()
{
    int sociosRegistrados = 0;

    nodo<T> *aux = ancla;
    while (aux != nullptr)
    {
        sociosRegistrados++;
        aux = aux->sig;
    }

    return sociosRegistrados;
}

int Menu()
{
    int opcion;

    std::cout << "\n\n\tSelecciona una opcion:\n\n";
    std::cout << "\t1. Registrar un nuevo socio\n";
    std::cout << "\t2. Dar de baja un socio\n";
    std::cout << "\t3. Reporte con los datos de todos los socios\n";
    std::cout << "\t4. Buscar por nombre y domicilio a un socio del club\n";
    std::cout << "\t5. Calcular e imprimir todos los socios registrados\n";
    std::cout << "\t6. Salir\n";
    std::cin >> opcion;

    return opcion;
}

int main()
{
    int opcionMenu;

    LDLLSE<SocioClub> listaSocios;
    SocioClub socioClub;
    nodo<SocioClub>* nodoPosicion;

    do
    {
        opcionMenu = Menu();
        switch (opcionMenu)
        {
        case 1:
            std::cin >> socioClub;

            if (listaSocios.numeroSocioExiste(socioClub))
            {
                std::cout << "\n\tALERTA! Ya existe un socio con el numero: " << socioClub.NumeroSocio << std::endl;
            }
            else
            {
                listaSocios.inserta(listaSocios.ultimo(), socioClub);
                std::cout << "\n\tRegistro agregado exitosamente!" << std::endl;
            }
            
            break;
        case 2:
            std::cin.ignore();
            std::cout << "\tNombre del socio" << std::endl;
            std::getline(std::cin, socioClub.NombreSocio);
            std::cout << "\tDomicilio del socio" << std::endl;
            std::getline(std::cin, socioClub.Domicilio);

            nodoPosicion = listaSocios.localiza(socioClub);

            if (nodoPosicion != nullptr)
            {
                listaSocios.elimina(nodoPosicion);
                std::cout << "\tEl socio " << socioClub.NombreSocio << " ha sido eliminado" << std::endl;
            }
            else
            {
                std::cout << "\tEl socio que deseas eliminar no existe" << std::endl;
            }
            break;
        case 3:
            if (listaSocios.vacia())
            {
                std::cout << "\tNo hay socios registrados" << std::endl;
            }
            else 
            {
                listaSocios.imprime();
            }
            break;
        case 4:
            std::cin.ignore();
            std::cout << "\tNombre del socio" << std::endl;
            std::getline(std::cin, socioClub.NombreSocio);
            std::cout << "\tDomicilio del socio" << std::endl;
            std::getline(std::cin, socioClub.Domicilio);

            nodoPosicion = listaSocios.localiza(socioClub);

            if (nodoPosicion != nullptr)
            {
                socioClub = listaSocios.recupera(nodoPosicion);
                std::cout << "\n\t SOCIO ENCONTRADO" << std::endl << std::endl;
                std::cout << socioClub << std::endl;
            }
            else
            {
                std::cout << "\tEl socio que buscas no existe" << std::endl;
            }
            break;
        case 5:
            std::cout << "Existen " << listaSocios.contarSocios() << " socios registrados" << std::endl;
            break;
        case 6:
            std::cout << "Hasta luego!" << std::endl;
            break;
        default:
            std::cout << " Por favor elige otra opcion\n";
            break;
        }
    } while (opcionMenu != 6);
    
    return 0;
}