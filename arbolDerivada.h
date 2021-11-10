/**
 * @file arbolDerivada.h
 *
 * Declaracion de la clase "ArbolDerivada" que es para la construccion de objetos
 * que pueden formar un arbol de sintaxis y calcular su derivada
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 08/11/2021
 */

#pragma once

#include"arbolBinario.h"
#include<stack>
#include<string>

class ArbolDerivada : public ArbolBinario<std::string>
{
    private:
        std::string infijo;  // Expresion algebraica en notacion infijo
        std::string prefijo;  // Expresion algebraica en notacion prefijo
        std::string sufijo;  // Expresion algebraica en notacion sufijo

    public:
        /**
        * @brief Constructor de la clase "ArbolDerivada" por defecto
        */
        ArbolDerivada() : ArbolBinario(), infijo(""), prefijo(""), sufijo("")  {  }

        /**
        * @brief Constructor de la clase "ArbolDerivada" que inicializara los atributos
        * @param infijo Expresion algebraica en notacion infijo
        */
        ArbolDerivada(const std::string &infijo) : ArbolBinario(), infijo(infijo), prefijo(""), sufijo("")  {  }

        /**
         * @brief Destructor de la clase "ArbolDerivada"
         */
        ~ArbolDerivada();

        /**
         * @brief Metodo que convierte la expresion en notacion infijo almacenada en el objeto
         * a notacion prefijo y lo almacena en el atributo "prefijo"
         */
        void infijoAPrefijo();

        /**
         * @brief Metodo que convierte la expresion en notacion infijo almacenada en el objeto
         * a notacion sufijo y lo almacena en el atributo "sufijo"
         */
        void infijoASufijo();

        /**
         * @brief Metodo que crea el arbol binario a partir de una expresion algebraica en notacion prefijo
         */
        void prefijoAArbol();

        /**
         * @brief Metodo que crea el arbol binario a partir de una expresion algebraica en notacion sufijo
         */
        void sufijoAArbol();

        /**
         * @brief Metodo que calcula la derivada del arbol de sintaxis
         */
        void derivarArbol();

        /**
         * @brief Metodo que calcula la derivada de un nodo recursivamente
         * @param nodoActPtr Nodo del arbol de sintaxis que se desea derivar
         */
        void derivarNodo(NodoArbol *nodoActPtr);

        /**
         * @param Metodo que regresa una cadena con los terminos del arbol de sintaxis agrupados entre parentesis
         * @param nodoActPtr Nodo del arbol de sintaxis que se desea agrupar
         * @return Cadena con la expresion agrupada entre parentesis
         */
        std::string obtenerAgrupacionSubarbol(NodoArbol *nodoPtr);

        /**
         * @brief Metodo que recorrera los nodos de un subarbol de sintaxis recursivamente y agrupara los terminos entre parentesis
         * @param nodoActPtr Nodo del arbol de sintaxis
         */
        void agruparTerminos(NodoArbol **nodoActPtr);
};

#include"arbolDerivada.hpp"
