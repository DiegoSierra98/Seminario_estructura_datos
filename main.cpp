#include <iostream>

class ConstanciaEscolar{
private:
    std::string nombreAlumno;
    std::string nombreCarrera;
    int materiaAprobada;
    float promedioGeneral;
public:
    ConstanciaEscolar(){};
    friend std::ostream & operator<<(std::ostream &O, ConstanciaEscolar &x){
            O<<"\tNombre del alumno: "<<x.nombreAlumno<<std::endl;
            O<<"\tNombre de la Carrera: "<<x.nombreCarrera<<std::endl;
            O<<"\tMaterias Aprobadas: "<<x.materiaAprobada<<std::endl;
            O<<"\tPromedio General: "<<x.promedioGeneral<<std::endl;
            return O;
    }

    friend std::istream & operator>>(std::istream &O, ConstanciaEscolar &x){
            std::cout<<"Nombre del alumno: ";
            O>>x.nombreAlumno;
            std::cout<<"Nombre de la Carrera: ";
            O>>x.nombreCarrera;
        	std::cout<<"Materias Aprobadas: ";
        	O>>x.materiaAprobada;
        	std::cout<<"Promedio General: ";
        	O>>x.promedioGeneral;
            return O;
    }
};

template<class T>
class Cola;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class Cola<T>;
};

template<class T>
class Cola{
private:
    node<T>* lista;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
public:
    Cola():lista(nullptr){};
    bool vacia()const;
    void imprimir()const;
    void Enqueue(T elem);
    void Dequeue();
    T Front();
};

template<class T>
T Cola<T>::Front(){
    if(!vacia()){
       return primero()->data;
    }
}

template<class T>
void Cola<T>::Dequeue(){
    eliminar(primero());
}

template<class T>
void Cola<T>::Enqueue(T elem){
    insertar(ultimo(),elem);
}

template<class T>
void Cola<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> ";
        aux=aux->sig;
    }
}

template<class T>
bool Cola<T>::eliminar(node<T>* pos){
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
void Cola<T>::insertar(node<T>* pos, T elem){
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
node<T>* Cola<T>::anterior(node<T>* pos)const{
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
node<T>* Cola<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* Cola<T>::ultimo()const{
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
bool Cola<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

int Menu(){
    int opcion = 0;

    std::cout << "\n\t------DIRECCION ESCOLAR------" << std::endl;
    std::cout << "\tSelecciona una opcion" << std::endl;
    std::cout << "\t1. Dar de alta solicitud" << std::endl;
    std::cout << "\t2. Elaborar constancia" << std::endl;
    std::cout << "\t3. Salir" << std::endl;
    std::cout << std::endl;
    std::cin >> opcion;

    return opcion;
}


int main()
{
    Cola<ConstanciaEscolar> ColaConstanciasEscolares;
    ConstanciaEscolar Solicitud;

    int OpcionMenu;

    do{
        OpcionMenu = Menu();

        switch (OpcionMenu)
        {
        case 1:
				std::cin >> Solicitud;
        		ColaConstanciasEscolares.Enqueue(Solicitud);
        	break;
        case 2:
        	if (ColaConstanciasEscolares.vacia())
        		std::cout << "\tNo hay solicitudes pendientes" << std::endl << std::endl;
			else
			{
                std::cout << "\t------CONSTANCIA ACADEMICA----" << std::endl << std::endl;
				Solicitud = ColaConstanciasEscolares.Front();
			    std::cout << Solicitud << std::endl << std::endl;
			    ColaConstanciasEscolares.Dequeue();
			}
		    break;
		case 3:
            std::cout <<"\tHasta luego!" << std::endl;
            break;
        default:
            std::cout <<" Por favor elige otra opcion\n";
            break;
        }
	} while (OpcionMenu != 3);

    return 0;
}
