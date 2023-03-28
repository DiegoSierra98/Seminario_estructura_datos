#include <iostream>
#include <string.h>
#define TAM 10

class SolicitudEscolar{
	public:
		std::string Alumno;
		std::string Carrera;
		std::string Preparatoria;
		float Promedio;
		
		SolicitudEscolar(){};
    	friend std::ostream & operator<<(std::ostream &O, SolicitudEscolar &x);
    	friend std::istream & operator>>(std::ostream &O, SolicitudEscolar &x);
    	bool operator==(const SolicitudEscolar &s);
    	bool operator!=(const SolicitudEscolar &s);
    	bool operator<(const SolicitudEscolar &s);
};

bool SolicitudEscolar::operator <(SolicitudEscolar const &s)
{
    return this->Promedio < s.Promedio;
}

bool SolicitudEscolar::operator !=(SolicitudEscolar const &s)
{
    return this->Promedio == s.Promedio;
}

bool SolicitudEscolar::operator ==(SolicitudEscolar const &s)
{
    return this->Promedio == s.Promedio;
}

std::ostream & operator<<(std::ostream &O, SolicitudEscolar &x){
	 O << "\t Nombre_Alumno: " << x.Alumno << std::endl;
	 O << "\t Nombre_Carrera: " << x.Carrera << std::endl;
	 O << "\t Nombre_PreparatoriaPrecedente: " << x.Preparatoria << std::endl;
	 O << "\t Promedio: " << x.Promedio << std::endl;
}
	
std::istream & operator>>(std::istream &O, SolicitudEscolar &x){
	 std::cout<<"\n Nombre Alumno: ";
	 O>>x.Alumno;
	 std::cout<<"\n Nombre_Carrera: ";
	 O>>x.Carrera;
	 std::cout<<"\n PReparatoria Precedente: ";
	 O>>x.Preparatoria;
	 std::cout<<"\n Promedio: ";
	 O>>x.Promedio;
}

template <class T>
class Lista{
private:
    T datos[TAM];
    int ult;
public:
	bool ListaOrdenada;
    Lista():ult(-1){
    	ListaOrdenada = false;
	}
    bool AgregarAlFinal(T);
    bool llena() const;
    bool vacia() const;
    int BusquedaBinaria(T elemento);
    void OrdenamientoPorInsercion();
    void Imprime(int posicion);
};

template <class T>
bool Lista<T>::llena()const{
    return ult==TAM-1;
}

template <class T>
bool Lista<T>::vacia()const{
    return ult==-1;
}

template <class T>
bool Lista<T>::AgregarAlFinal(T elemento){
    if(llena())
    {
        std::cout << "\tNo se puede agregar el registro" << std::endl;
        return false;
    }

    datos[ult + 1] = elemento;
    ult++;
    
    ListaOrdenada = false;

    return true;
}

template<class T>
int Lista<T>::BusquedaBinaria(T elemento){
	int i = 0, j = ult;
	int medio = 0;
	
	while (i <= j)
	{
		medio = (i + j) / 2;
		
		if (elemento == datos[medio])
			return medio;
		
		if (elemento < datos[medio])
			j = medio - 1;
		else
			i = medio + 1;	
	}	
	return -1;
}

template<class T>
void Lista<T>::OrdenamientoPorInsercion(){
	int i = 1;
	int j;
	T aux;
	
	while(i <= ult){
		aux = datos[i];
		j = i;
		
		while(j > 0 && aux < datos[j - 1]){
			datos[j] = datos[j - 1];
			j = j - 1;
		}
		
		if(i != j)
			datos[j] = aux;
		
		i = i + 1;
	}
	
	ListaOrdenada = true;
}

template <class T>
void Lista<T>::Imprime(int posicion){
	std::cout<<datos[posicion]<<std::endl;
}
int Menu(){
    int opcion;

    std::cout<<"\n\n\tSelecciona una opcion:\n\n";
    std::cout<<"\t1. Dar de alta solicitud\n";
    std::cout<<"\t2. Ordenar lista\n";
    std::cout<<"\t3. Buscar solicitud\n";
    std::cout<<"\t4. Salir\n";
    std::cin>> opcion;

    return opcion;
}

int main() {
	int opcionMenu;
	Lista<SolicitudEscolar> ListaEstatica;
	SolicitudEscolar solicitud;
	int posicion;

    do{
        opcionMenu = Menu();

        switch (opcionMenu)
        {
        case 1:
        	std::cin>>solicitud;
            ListaEstatica.AgregarAlFinal(solicitud);
        	std::cout << "\tRegistro agregado exitosamente!" << std::endl;
            break;
        case 2:
        	if(ListaEstatica.vacia())
        		std::cout << "\t No hay elementos por ordenar" << std::endl;
        	else {
        		ListaEstatica.OrdenamientoPorInsercion();	
            	std::cout << "\tOrdenado exitosamente!" << std::endl;	
			}
            break;
        case 3:
        	if (!ListaEstatica.ListaOrdenada)
        	{
        		std::cout << "\tSe debe ordenar la lista primero\n";
			}
			else 
			{
				std::cout << "\tDame el promedio que deseas buscar" << std::endl;
        		std::cin >> solicitud.Promedio; 
            	posicion = ListaEstatica.BusquedaBinaria(solicitud);
            	std::cout << "\tRegistro encontrado en la posicion: " << posicion << std::endl;
            	ListaEstatica.Imprime(posicion);
            	std::cout << "\tBuscado exitosamente!" << std::endl;
			}
            break;
        case 4:
             std::cout<<"\tHasta luego!!!\n";
            break;
        default:
            std::cout<<" Por favor elige otra opcion\n";
            break;
        }
    } while(opcionMenu != 4);
	return 0;
}
