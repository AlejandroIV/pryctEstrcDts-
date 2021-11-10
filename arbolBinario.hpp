/**
 * @file arbolBinario.hpp
 *
 * Definicion de la clase "ArbolBinario"
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 2.0
 * @date 08/11/2021
 */

template <typename T>
ArbolBinario<T>::~ArbolBinario()
{
    // Llama al metodo "eliminarArbol" para eliminar el arbol completo
    eliminarArbol();
}

template<typename T>
void ArbolBinario<T>::setNodoRaiz(NodoArbol *raiz_)  {  this->raiz_ = raiz_;  }

template<typename T>
typename ArbolBinario<T>::NodoArbol* ArbolBinario<T>::getNodoRaiz()  {  return raiz_;  }
template<typename T>
typename ArbolBinario<T>::NodoArbol** ArbolBinario<T>:: getDireccionNodoRaiz()  {  return &raiz_;  }

template <typename T>
typename ArbolBinario<T>::NodoArbol* ArbolBinario<T>::copiarSubarbol(NodoArbol *subarbolRaizPtr)
{
    // Declaracion de puntero que almacenara la direccion de la raiz del subarbol copia
    NodoArbol *raizCopia = nullptr;

    // Llama al metodo para copiar todo los nodos del subarbol y la direccion de la raiz lo almacena en "raizCopia"
    raizCopia = copiarNodo(subarbolRaizPtr);

    return raizCopia;
}

template <typename T>
typename ArbolBinario<T>::NodoArbol* ArbolBinario<T>::copiarNodo(NodoArbol *nodoActPtr)
{
    // Declara el nodo copia
    NodoArbol *nodo = nullptr;

    // Si el nodo actual no es nulo
    if(nodoActPtr)  {
        // Se copia el dato del nodo actual en el nodo copia
        nodo = new NodoArbol(nodoActPtr->dato);
        // Copia los nodos recursivamente
        nodo->izq = copiarNodo(nodoActPtr->izq);
        nodo->der = copiarNodo(nodoActPtr->der);
    }

    return nodo;
}

template <typename T>
void ArbolBinario<T>::eliminarSubarbol(NodoArbol *subarbolRaizPtr)
{
    // Condicion de paro de recursion
    if(!subarbolRaizPtr)  {
        return;
    }

    // Llama al metodo "eliminarSubarbol" de forma recursiva para eliminar todos los nodos
    eliminarSubarbol(subarbolRaizPtr->izq);
    eliminarSubarbol(subarbolRaizPtr->der);

    // Se iran eliminando las hojas del arbol
    subarbolRaizPtr->izq = nullptr;
    subarbolRaizPtr->der = nullptr;

    // Elimina el nodo padre
    delete subarbolRaizPtr;
}

template <typename T>
void ArbolBinario<T>::eliminarArbol()
{
    // Llama al metodo "eliminarSubarbol" y pasa como arumento a la raiz para eliminar el arbol completo
    eliminarSubarbol(raiz_);
    raiz_ = nullptr;
}

template <typename T>
void ArbolBinario<T>::imprimirNodo(NodoArbol *act)
{
    // Condicion para evitar un error al tratar de imprimir un dato nulo
    if(act)  {
        // Imprime el dato
        std::cout << act->dato;
    }

    // Imprime un espacio (para la visualizacion de los recorridos)
    std::cout << " ";
}

template <typename T>
void ArbolBinario<T>::inorden(NodoArbol *act)
{
    // Condicion de paro de recursion
    if(!act)  {
        return;
    }

    // Llama al metodo "inorden" de forma recursiva para recorrer todos los nodos
    inorden(act->izq);
    imprimirNodo(act);
    inorden(act->der);
}

template <typename T>
void ArbolBinario<T>::preorden(NodoArbol *act)
{
    {
        // Condicion de paro de recursion
        if(!act)  {
            return;
        }

        // Llama al metodo "inorden" de forma recursiva para recorrer todos los nodos
        imprimirNodo(act);
        preorden(act->izq);
        preorden(act->der);
    }
}

template <typename T>
void ArbolBinario<T>::postorden(NodoArbol *act)
{
    // Condicion de paro de recursion
    if(!act)  {
        return;
    }

    // Llama al metodo "inorden" de forma recursiva para recorrer todos los nodos
    postorden(act->izq);
    postorden(act->der);
    imprimirNodo(act);
}
