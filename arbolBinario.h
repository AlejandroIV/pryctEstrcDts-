/**
 * @file arbolBinario.h
 *
 * @brief Contiene la declaracion de la clase "ArbolBinario"
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 2.0
 * @date 08/11/2021
 */

#pragma once

#include<iostream>

/**
 * @brief La clase "ArbolBinario" es para construir objetos que pueden formar un arbol binario
 */
template<typename T>
class ArbolBinario
{
    protected:
        /**
         * @brief La clase "NodoArbol" es para construir objetos que se usaran como nodos de los arboles formados por la clase "ArbolBinario"
         */
        class NodoArbol
        {
            public:
                T dato;  // Dato almacenado en el nodo
                NodoArbol *izq;  // Apuntador al nodo hijo izq
                NodoArbol *der;  // Apuntador al nodo hijo der

                /**
                * @brief Constructor de la clase "NodoArbol" por defecto
                */
                NodoArbol() : dato(NULL), izq(nullptr), der(nullptr)  {  }

                /**
                * @brief Constructor de la clase "NodoArbol" que inicializara los atributos
                * @param dato Dato que se desea almacenar en el nodo
                */
                NodoArbol(const T &dato) : dato(dato), izq(nullptr), der(nullptr)  {  }

                /**
                * @brief Constructor copia de la clase "NodoArbol"
                * @param otro Nodo que se desea copiar
                */
                NodoArbol(const NodoArbol &otro) : dato(otro.dato), izq(otro.izq), der(otro.der)  {  }
        };

    private:
        NodoArbol *raiz_;  // Nodo raiz del arbol

    public:
        /**
        * @brief Constructor de la clase "ArbolBinario" por defecto
        */
        ArbolBinario() : raiz_(nullptr)  {  }

        /**
         * @brief Destructor de la clase "ArbolBinario"
         */
        ~ArbolBinario();

        /**
         * @brief Asigna un valor al atributo "raiz_"
         * @param raiz_ Nodo de un arbol binario
         */
        void setNodoRaiz(NodoArbol *raiz_);

        /**
         * @brief Regresa el atributo "raiz_"
         * @return Nodo raiz del arbol
         */
        NodoArbol* getNodoRaiz();

        /**
         * @brief Regresa la direccion del atributo "raiz_"
         * @return Puntero a nodo raiz del arbol
         */
        NodoArbol** getDireccionNodoRaiz();

        /**
         * @brief Regresa el nodo raiz del subarbol que es copia de otro
         * @param subarbolRaizPtr Nodo raiz del subarbol que se desea copiar
         * @return Nodo raiz del subarbol copia
         */
        NodoArbol* copiarSubarbol(NodoArbol *subarbolRaizPtr);

        /**
         * @brief Recorre un subarbol para realizar las copias de los nodos de un subarbol recursivamente
         * @param nodoActPtr Nodo del arbol
         * @return Nodo copiado
         */
        NodoArbol* copiarNodo(NodoArbol *nodoActPtr);

        /**
         * @brief Elimina todo un subarbol completo
         * @param subarbolRaizPtr Nodo raiz del subarbol que se desea eliminar
         */
        void eliminarSubarbol(NodoArbol *subarbolRaizPtr);

        /**
         * @brief Elimina todo el arbol completo
         */
        void eliminarArbol();

        /**
         * @brief Imprime el contenido de un nodo
         * @param act Nodo del arbol
         */
        void imprimirNodo(NodoArbol *act);

        /**
         * @brief Imprime el recorrido inorden del arbol binario
         * @param act Nodo del arbol
         */
        void inorden(NodoArbol *act);

        /**
         * @brief Imprime el recorrido preorden del arbol binario
         * @param act Nodo del arbol
         */
        void preorden(NodoArbol *act);

        /**
         * @brief Imprime el recorrido postorden del arbol binario
         * @param act Nodo del arbol
         */
        void postorden(NodoArbol *act);
};

#include"arbolBinario.hpp"
