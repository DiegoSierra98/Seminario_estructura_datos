#include <iostream>
#define TAM 4

class ConstanciaEscolar{
private:
    std::string nombreAlumno;
    std::string nombreCarrera;
    int materiaAprobada;
    float promedioGeneral;
public:
    ConstanciaEscolar(){};
    friend std::ostream & operator<<(std::ostream &O, ConstanciaEscolar &x){
            O<<"\n Nombre: "<<x.nombreAlumno<<std::endl;
            O<<"\n Nombre de la Carrera: "<<x.nombreCarrera<<std::endl;
            O<<"\n Materias Aprobadas: "<<x.materiaAprobada<<std::endl;
            O<<"\n Promedio General: "<<x.promedioGeneral<<std::endl;
            return O;
    }
    friend std::istream & operator>>(std::istream &O, ConstanciaEscolar &x){
            std::cout<<"\n Nombre: ";
            O>>x.nombreAlumno;
            std::cout<<"\n Nombre de la Carrera: ";
            O>>x.nombreCarrera;
        	std::cout<<"\n Materias Aprobadas: ";
        	O>>x.materiaAprobada;
        	std::cout<<"\n Promedio General: ";
        	O>>x.promedioGeneral;
            return O;
    }
};

//plantillas
template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Cola():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool  Queue(T&);
    bool Dequeue();
    T Front()const;
};

template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T& elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}

template<class T>
void Cola<T>::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            ConstanciaEscolar x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
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

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}
int Menu(){
    int opcion;

    std::cout<<"\n\n\tSelecciona una opcion:\n\n";
    std::cout<<"\t1. Dar de alta una solicitud\n";
    std::cout<<"\t2. Elaborar una constancia\n";
    std::cout<<"\t3. SALIR\n";
    std::cin>> opcion;

    return opcion;
    
}
int main()
{
    Cola<ConstanciaEscolar> MiCola;
    ConstanciaEscolar x;
    
    int opcionMenu;
    do{
        opcionMenu = Menu();

        switch (opcionMenu)
        {
        case 1:
        	if (MiCola.llena())
        	{
        		std::cout << "\t No se pueden procesar mas solicitudes\n";
			}
			else
			{
				std::cin>>x;
        		MiCola.Queue(x);
			}
        	break;
        case 2:
        	if (MiCola.vacia())
        	{
        		std::
				cout << "\t No hay solicitudes pendientes\n";
			}
			else
			{
				x=MiCola.Front();
			    std::cout<<x<<std::endl;
			    MiCola.Dequeue();
			}
		    break;
		case 3:
            std::cout<<"\tHasta luego!!!\n";
            break;
        default:
            std::cout<<" Por favor elige otra opcion\n";
            break;
        }
	} while (opcionMenu != 3);

    return 0;
}
