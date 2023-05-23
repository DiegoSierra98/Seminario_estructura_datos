#include <iostream>

template <class T>
class Arbol {
private:
    struct Nodo {
        T elem;
        Nodo* izq;
        Nodo* der;

        Nodo(T elemento) : elem(elemento), izq(nullptr), der(nullptr) {}
    };

    Nodo* arbol;

public:
    Arbol() : arbol(nullptr) {}

    void inicializa() {
        arbol = nullptr;
    }

    bool vacio() {
        return (arbol == nullptr);
    }

    T recupera(Nodo* pos) {
        if (arbol == nullptr || pos == nullptr) {
            throw std::runtime_error("Insuficiencia de datos");
        }
        return pos->elem;
    }

    void inserta(T elem) {
        inserta(arbol, elem);
    }

    Nodo* localiza(T elem) {
        return localiza(elem, arbol);
    }

    Nodo* menor() {
        return menor(arbol);
    }

    Nodo* mayor() {
        return mayor(arbol);
    }

    bool es_hoja(Nodo* pos) {
        return (pos != nullptr && pos->izq == nullptr && pos->der == nullptr);
    }

    void recorrido_preorder() {
        recorrido_preorder(arbol);
    }

    void recorrido_inorder() {
        recorrido_inorder(arbol);
    }

    void recorrido_postorder() {
        recorrido_postorder(arbol);
    }

    void elimina(Nodo* pos) {
        elimina(pos, arbol);
    }

    int altura() {
        return altura(arbol);
    }

    int fact_eq() {
        return fact_eq(arbol);
    }

    void balanceo() {
        balanceo(arbol);
    }

private:
    void inserta(Nodo*& arbol, T elem) {
        if (arbol == nullptr) {
            Nodo* aux = new Nodo(elem);
            arbol = aux;
        } else {
            if (elem < arbol->elem) {
                inserta(arbol->izq, elem);
            } else {
                inserta(arbol->der, elem);
            }
        }
    }

    Nodo* localiza(T elem, Nodo* arbol) {
        if (arbol == nullptr) {
            return nullptr;
        }
        if (elem == arbol->elem) {
            return arbol;
        }
        if (elem < arbol->elem) {
            return localiza(elem, arbol->izq);
        } else {
            return localiza(elem, arbol->der);
        }
    }

    Nodo* menor(Nodo* arbol) {
        if (arbol == nullptr) {
            return nullptr;
        }
        if (arbol->izq == nullptr) {
            return arbol;
        }
        return menor(arbol->izq);
    }

    Nodo* mayor(Nodo* arbol) {
        if (arbol == nullptr) {
            return nullptr;
        }
        if (arbol->der == nullptr) {
            return arbol;
        }
        return mayor(arbol->der);
    }

    void recorrido_preorder(Nodo* arbol) {
        if (arbol == nullptr) {
            return;
        }
        std::cout << arbol->elem << " ";
        recorrido_preorder(arbol->izq);
        recorrido_preorder(arbol->der);
    }

    void recorrido_inorder(Nodo* arbol) {
        if (arbol == nullptr) {
            return;
        }
        recorrido_inorder(arbol->izq);
        std::cout << arbol->elem << " ";
        recorrido_inorder(arbol->der);
    }

    void recorrido_postorder(Nodo* arbol) {
        if (arbol == nullptr) {
            return;
        }
        recorrido_postorder(arbol->izq);
        recorrido_postorder(arbol->der);
        std::cout << arbol->elem << " ";
    }

    void elimina(Nodo* pos, Nodo*& arbol) {
        if (arbol == nullptr || pos == nullptr) {
            throw std::runtime_error("Insuficiencia de datos");
        }
        if (es_hoja(pos)) {
            delete arbol;
            arbol = nullptr;
        } else if (arbol->izq != nullptr) {
            Nodo* pos_reemplazo = mayor(arbol->izq);
            arbol->elem = pos_reemplazo->elem;
            elimina(pos_reemplazo, arbol->izq);
        } else {
            Nodo* pos_reemplazo = menor(arbol->der);
            arbol->elem = pos_reemplazo->elem;
            elimina(pos_reemplazo, arbol->der);
        }
    }

    int altura(Nodo* arbol) {
        if (arbol == nullptr) {
            return 0;
        }
        int alt_izq = altura(arbol->izq);
        int alt_der = altura(arbol->der);
        return (alt_izq > alt_der) ? alt_izq + 1 : alt_der + 1;
    }

    int fact_eq(Nodo* arbol) {
        if (arbol == nullptr) {
            return 0;
        }
        return altura(arbol->der) - altura(arbol->izq);
    }

    void balanceo(Nodo*& arbol) {
        if (fact_eq(arbol) < -1) {
            if (fact_eq(arbol->izq) == -1) {
                rot_sim_der(arbol);
            } else {
                rot_dob_der(arbol);
            }
        } else if (fact_eq(arbol) > 1) {
            if (fact_eq(arbol->der) == 1) {
                rot_sim_izq(arbol);
            } else {
                rot_dob_izq(arbol);
            }
        }
    }

    void rot_sim_der(Nodo*& arbol) {
        Nodo* aux1 = arbol->izq;
        Nodo* aux2 = aux1->der;
        arbol->izq = aux2;
        aux1->der = arbol;
        arbol = aux1;
    }

    void rot_sim_izq(Nodo*& arbol) {
        Nodo* aux1 = arbol->der;
        Nodo* aux2 = aux1->izq;
        arbol->der = aux2;
        aux1->izq = arbol;
        arbol = aux1;
    }

    void rot_dob_der(Nodo*& arbol) {
        Nodo* aux1 = arbol->izq;
        Nodo* aux2 = aux1->der;
        Nodo* aux3 = aux2->izq;
        Nodo* aux4 = aux2->der;
        arbol->izq = aux4;
        aux1->der = aux3;
        aux2->izq = aux1;
        arbol = aux2;
    }

    void rot_dob_izq(Nodo*& arbol) {
        Nodo* aux1 = arbol->der;
        Nodo* aux2 = aux1->izq;
        Nodo* aux3 = aux2->der;
        Nodo* aux4 = aux2->izq;
        arbol->der = aux4;
        aux1->izq = aux3;
        aux2->der = aux1;
        arbol = aux2;
    }
};

int main() {
    class arbol;
    return 0;
}
