/**
 * @file arbolBinario.h
 *
 * Declaracion de la clase "ArbolBinario" que es para la construccion de objetos
 * que pueden formar un arbol binario
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 2.0
 * @date 08/11/2021
 */

#pragma once

#include<iostream>

template<typename T>
class ArbolBinario
{
    protected:
        // Clase para la construccion de objetos que se usaran como nodos del arbol
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
                */
                NodoArbol(const T &dato) : dato(dato), izq(nullptr), der(nullptr)  {  }

                /**
                * @brief Constructor copia de la clase "NodoArbol"
                */
                NodoArbol(const NodoArbol &otro) : dato(otro.dato), izq(otro.izq), der(otro.der)  {  }
        };

    private:
        NodoArbol *raiz_;

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
         * @brief Metodo que asigna un valor al atributo "raiz_"
         * @param raiz_ Nodo raiz de un arbol binario
         */
        void setNodoRaiz(NodoArbol *raiz_);

        /**
         * @brief Metodo que regresa el atributo "raiz_"
         * @return Nodo raiz del arbol
         */
        NodoArbol* getNodoRaiz();

        /**
         * @brief Metodo que regresa la direccion del atributo "raiz_"
         * @return Puntero a nodo raiz del arbol
         */
        NodoArbol** getDireccionNodoRaiz();

        /**
         * @brief Metodo que regresa el nodo raiz del subarbol que es copia de otro
         * @param subarbolRaizPtr Nodo raiz del subarbol que se desea copiar
         * @return Nodo raiz del subarbol copia
         */
        NodoArbol* copiarSubarbol(NodoArbol *subarbolRaizPtr);

        /**
         * @brief Metodo que recorre un subarbol para realizar las copias de los nodos de un subarbol recursivamente
         * @param nodoActPtr Nodo del arbol
         * @return Nodo copiado
         */
        NodoArbol* copiarNodo(NodoArbol *nodoActPtr);

        /**
         * @brief Metodo que elimina todo un subarbol completo
         * @param subarbolRaizPtr Nodo raiz del subarbol que se desea eliminar
         */
        void eliminarSubarbol(NodoArbol *subarbolRaizPtr);

        /**
         * @brief Metodo que elimina todo el arbol completo
         */
        void eliminarArbol();

        /**
         * @brief Metodo que imprime el contenido de un nodo
         * @param act Nodo del arbol
         */
        void imprimirNodo(NodoArbol *act);

        /**
         * @brief Metodo que imprime el recorrido inorden del arbol binario
         * @param act Nodo del arbol
         */
        void inorden(NodoArbol *act);

        /**
         * @brief Metodo que imprime el recorrido preorden del arbol binario
         * @param act Nodo del arbol
         */
        void preorden(NodoArbol *act);

        /**
         * @brief Metodo que imprime el recorrido postorden del arbol binario
         * @param act Nodo del arbol
         */
        void postorden(NodoArbol *act);
};

#include"arbolBinario.hpp"
