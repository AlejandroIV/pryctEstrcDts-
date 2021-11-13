/**
 * @file arbolDerivada.h
 *
 * @brief Contiene la declaracion de la clase "ArbolDerivada"
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 08/11/2021
 */

#pragma once

#include"arbolBinario.h"
#include<stack>
#include<string>

/**
 * @brief La clase "ArbolDerivada" es para construir objetos que pueden formar un arbol de expresiones algebraicas y calcular su derivada
 */
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
         * @brief Asigna un valor al atributo "infijo"
         * @param infijo Expresion algebraica en notacion infijo
         */
        void setInfijo(const std::string &infijo);

        /**
         * @brief Asigna un valor al atributo "prefijo"
         * @param prefijo Expresion algebraica en notacion prefijo
         */
        void setPrefijo(const std::string &prefijo);

        /**
         * @brief Asigna un valor al atributo "sufijo"
         * @param sufijo Expresion algebraica en notacion sufijo
         */
        void setSufijo(const std::string &sufijo);

        /**
         * @brief Convierte la expresion en notacion infijo almacenada en el objeto a notacion prefijo y lo almacena en el atributo "prefijo"
         */
        void infijoAPrefijo();

        /**
         * @brief Convierte la expresion en notacion infijo almacenada en el objeto a notacion sufijo y lo almacena en el atributo "sufijo"
         */
        void infijoASufijo();

        /**
         * @brief Crea el arbol de expresiones algebraicas a partir de una expresion algebraica en notacion prefijo
         */
        void prefijoAArbol();

        /**
         * @brief Crea el arbol de expresiones algebraicas a partir de una expresion algebraica en notacion sufijo
         */
        void sufijoAArbol();

        /**
         * @brief Calcula la derivada del arbol de expresiones algebraicas
         */
        void derivarArbol();

        /**
         * @brief Calcula la derivada de los nodos recursivamente
         * @param nodoActPtr Nodo del arbol de expresiones algebraicas que se desea derivar
         */
        void derivarNodo(NodoArbol *nodoActPtr);

        /**
         * @brief Regresa una cadena con los terminos del arbol de expresiones algebraicas agrupados entre parentesis
         * @param nodoActPtr Nodo del arbol de expresiones algebraicas que se desea agrupar
         * @return Cadena con la expresion algebraica agrupada entre parentesis
         */
        std::string obtenerAgrupacionSubarbol(NodoArbol *nodoPtr);

        /**
         * @brief Recorrera los nodos de un subarbol de expresiones algebraicas recursivamente y agrupara los terminos entre parentesis
         * @param nodoActPtr Puntero a nodo del arbol de expresiones algebraicas
         */
        void agruparTerminos(NodoArbol **nodoActPtr);

        /**
         * @brief Simplifica el arbol de expresiones algebraicas
         */
        void simplificarArbol();

        /**
         * @brief Simplifica los nodos recursivamente
         * @param nodoActPtr Puntero a nodo del arbol de expresiones algebraicas
         */
        void simplificarNodo(NodoArbol **nodoActPtr);
};

#include"arbolDerivada.hpp"
