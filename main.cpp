#include <iostream>
#include "Nodo.h"
#include "NodoNexoDoble.h"
using namespace std;

void InsertarSimpleAlFinal(Nodo * &head, int datoAgregar) {
Nodo* nuevo = new Nodo(datoAgregar);
    // caso que no tenemos ni un nodo que por ahora es lo normal pq lo creamos vacio entonces si o si entra aqui en la primera pasada
    if (head == nullptr) {
        head = nuevo;
    }else {
        //caso que tenemos ya elementos en la lista entonces empezamos en la primera caja
        //usamos un aux(actual) para movernos en la lista pero no mover la cabeza original
        Nodo* actual = head;
        while (actual -> siguiente != nullptr) {
            actual =  actual -> siguiente;
        }
        actual -> siguiente = nuevo;
    }
}

void EliminacionSimple(Nodo * &head, int datoEliminar) {
    if (head == nullptr) {return;}
    Nodo* actual = head;
    Nodo* anterior = nullptr;
    while (actual != nullptr && actual -> dato != datoEliminar) {
            anterior = actual;
            actual = actual -> siguiente;
    }
    if (actual == nullptr) {
        cout<<"No se encontro el dato a eliminar";
        return;
    }if (anterior == nullptr) {
        head = actual -> siguiente;
        delete actual;
        cout<<"el dato se elimino de la lista"<<endl;
        return;
    }
    anterior -> siguiente = actual -> siguiente;
    delete actual;
    cout<<"EL dato se elimino de la lista"<<endl;

}
void BusquedaNexoSimple(Nodo* &head, int datoBusqueda) {
    if (head == nullptr) {cout<<"La lista esta vacia"<<endl; return;}
    Nodo* actual = head;
    while(actual != nullptr && actual -> dato != datoBusqueda){
        actual = actual -> siguiente;
    }
    if (actual == nullptr) {
        cout<<"No se encontro el dato";
        return;
    }else {
        cout<<"dato encontrado";
        return;
    }
}
void insertarDobleAlFinal(NodoNexoDoble * &head, int datoAgregar) {
    NodoNexoDoble* Nuevo = new NodoNexoDoble(datoAgregar);
    if (head == nullptr) {
        head = Nuevo;
    }else {
       NodoNexoDoble* actual = head;
        NodoNexoDoble* anterior = nullptr;
        while (actual -> siguiente != nullptr) {
            anterior = actual;
            actual = actual -> siguiente;
        }
        Nuevo -> anterior = actual;
        actual -> siguiente = Nuevo;
    }

}

void eliminacionNexoDoble(NodoNexoDoble * &head, int datoEliminar) {
    if (head == nullptr) {cout<<"La lista esta vacia"<<endl; return;}
    NodoNexoDoble* actual = head;
    NodoNexoDoble* anterior = nullptr;

    while (actual != nullptr && actual -> dato != datoEliminar) {
        anterior = actual;
        actual = actual -> siguiente;
    }
    if (actual == nullptr) {
        cout<<"No se encontro el dato";
        return;
    }
    //si el anterior es nulo es la cabeza lo que queremos eliminar
    if (anterior == nullptr) {
        head = actual->siguiente;

        if (head != nullptr) {
            head->anterior = nullptr;
        }

        delete actual;
        cout << "El dato se elimino de la lista" << endl;
        return;
    }

    anterior -> siguiente = actual -> siguiente;

    if (actual -> siguiente != nullptr) {
        actual -> siguiente -> anterior = anterior;
    }
    delete actual;
    cout<<"El dato se elimino de la lista"<<endl;
}

void busquedaNexoDoble(NodoNexoDoble * &head, int datoBusqueda) {
    if (head == nullptr) {cout<<"La lista esta vacia"; return;}
    NodoNexoDoble* actual = head;
    while(actual != nullptr && actual -> dato != datoBusqueda){
        actual = actual -> siguiente;
    }
    if (actual == nullptr) {
        cout<<"No se encontro el dato";
        return;
    }else {
        cout<<"dato encontrado";
        return;
    }
}

void insertarSimpleCircular(Nodo* & head,int datoAgregar) {
    Nodo* nuevo = new Nodo(datoAgregar);
    nuevo ->siguiente = nuevo;
    if (head == nullptr) {
        head = nuevo;
    }else {
        Nodo* actual = head;
        while (actual -> siguiente != head) {
                actual = actual -> siguiente;
        }
        actual -> siguiente = nuevo;
        actual -> siguiente -> siguiente = head;
    }
}
void eliminarSimpleCircular(Nodo* & head, int datoEliminar) {
    if (head == nullptr) {cout<<"La lista esta vacia"; return;}
    Nodo* actual = head;
    Nodo* anterior = nullptr;
    while (actual ->  siguiente != head && actual -> dato != datoEliminar) {
        anterior = actual;
        actual = actual -> siguiente;
    }

    if (actual -> siguiente == head && actual -> dato != datoEliminar) {
        cout<<"No se encontro el dato";
        return;
    }
    //caso 1 de esta condicional que este solo la cabeza no usamos actual pq o si no funcionaria
    //dado que bueno el actual es cabeza pero imagina no pasa lo mejor q seria q no entre al while entonces
    // en el que estamos parados ejem es el ultimo q si apunta a la cabeza su sig pero ahi la cagariamos
    // pq en verdad no estariamos borrando bien para este caso que queremos hacer q es q solo exista la cabeza
    if (head -> siguiente == head && head -> dato == datoEliminar) {
        delete head;
        head = nullptr;
        return;
    }
    // otro caso cuando queremos eliminar cabeza pero hay mas nodos
    if (head -> dato == datoEliminar) {
        Nodo * ultimo = head;
        while (ultimo -> siguiente != head) {
            ultimo = ultimo -> siguiente;
        }
        Nodo* viejoHead = head;
        head = head->siguiente;
        ultimo->siguiente = head;
        delete viejoHead;
        return;
    }
    anterior -> siguiente = actual -> siguiente;
    delete actual;

}

void busquedaSimpleCircular(Nodo* & head, int datoBusqueda) {
    if (head == nullptr) {cout<<"La lista esta vacia"; return;}
    Nodo* actual = head;
    while (actual -> siguiente != head && actual -> dato != datoBusqueda) {
        actual = actual -> siguiente;
    }
    if (actual->dato == datoBusqueda) {
        cout << "Dato encontrado";
    } else {
        cout << "No se encontro el dato";
    }
}
void insercionDobleCircular(NodoNexoDoble* & head, int datoAgregar) {
    NodoNexoDoble* nuevo = new NodoNexoDoble(datoAgregar);

    // Lista vacía
    if (head == nullptr) {
        head = nuevo;
        head->siguiente = head;
        head->anterior = head;
        return;
    }

    NodoNexoDoble* ultimo = head->anterior;   // En doble circular, el último es head->anterior

    // Conectar nuevo entre ultimo y head
    nuevo->siguiente = head;
    nuevo->anterior = ultimo;

    ultimo->siguiente = nuevo;
    head->anterior = nuevo;
}
void busquedaDobleCircular(NodoNexoDoble*& head, int datoBusqueda) {
    if (head == nullptr) {
        cout << "La lista esta vacia";
        return;
    }

    NodoNexoDoble* actual = head;

    // Revisar la cabeza primero
    if (actual->dato == datoBusqueda) {
        cout << "Dato encontrado";
        return;
    }

    actual = actual->siguiente;

    while (actual != head && actual->dato != datoBusqueda) {
        actual = actual->siguiente;
    }

    if (actual->dato == datoBusqueda) {
        cout << "Dato encontrado";
    } else {
        cout << "No se encontro el dato";
    }
}
void eliminarDobleCircular(NodoNexoDoble*& head, int datoEliminar) {
    if (head == nullptr) {
        cout << "La lista esta vacia";
        return;
    }

    NodoNexoDoble* actual = head;

    // Revisar la cabeza primero
    if (actual->dato == datoEliminar) {
        // Caso: solo un nodo
        if (head->siguiente == head) {
            delete head;
            head = nullptr;
            return;
        }

        // Caso: borrar head con más de un nodo
        NodoNexoDoble* viejoHead = head;
        head = head->siguiente;

        // Reconectar circular doble
        viejoHead->anterior->siguiente = head;
        head->anterior = viejoHead->anterior;

        delete viejoHead;
        return;
    }

    // Avanzar desde el segundo
    actual = actual->siguiente;

    while (actual != head && actual->dato != datoEliminar) {
        actual = actual->siguiente;
    }

    // No encontrado
    if (actual == head) {
        cout << "No se encontro el dato";
        return;
    }

    // Borrar nodo del medio o el último
    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;

    delete actual;
}



int main() {
    //simple
Nodo * XD = nullptr;
    //doble
    NodoNexoDoble * DX = nullptr;
    //simple circular
    Nodo * XXD = nullptr;
    //doble circular
    NodoNexoDoble* DXX = nullptr;

//lista nexo simple
InsertarSimpleAlFinal(XD, 1);
    InsertarSimpleAlFinal(XD, 2);
    InsertarSimpleAlFinal(XD, 3);
    InsertarSimpleAlFinal(XD, 4);
    InsertarSimpleAlFinal(XD, 5);
    InsertarSimpleAlFinal(XD, 6);

    //eliminacion en nexo simple
    EliminacionSimple(XD,4);

    //buscar dato en nexo simple
    BusquedaNexoSimple(XD,3);

//lista nexo doble
    //insercion
    insertarDobleAlFinal(DX,4);
    insertarDobleAlFinal(DX,5);
    insertarDobleAlFinal(DX,3);
    //busqueda
    busquedaNexoDoble(DX,5);
    //eliminacion
    eliminacionNexoDoble(DX,5);

//lista nexo simple circular
    //insertar
insertarSimpleCircular(XXD,2);
    insertarSimpleCircular(XXD,3);
    insertarSimpleCircular(XXD,4);
    insertarSimpleCircular(XXD,5);
    //busqueda
    busquedaSimpleCircular(XXD,4);

    //eliminacion
    eliminarSimpleCircular(XXD,4);

//lista nexo doble circular
    //insercion
    insercionDobleCircular(DXX,2);
    insercionDobleCircular(DXX,3);
    insercionDobleCircular(DXX,4);
    insercionDobleCircular(DXX,5);
    //busqueda
    busquedaDobleCircular(DXX,4);
    //eliminacion
    eliminarDobleCircular(DXX,5);

    return 0;
}