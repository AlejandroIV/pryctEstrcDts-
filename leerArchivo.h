/**
 * @file leerArchivo.h
 *
 * @brief Contiene la declaracion de la clase "Archivo"
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 4.0
 * @date 12/11/2021
 */

#pragma once

#include"arbolDerivada.h"
#include<fstream>

/**
 * @brief La clase "Archivo" es para construir objetos que pueden abrir archivos y extraer una expresion algebraica del documento
 */
class Archivo
{
    private:
        std::ifstream archivo;  // Archivo
        std::string expresion;  // Cadena que contendra la expresion algebraica

    public:
    /**
     * @brief Constructor de la clase "Archivo" que abrira el archivo con el nombre "nombreAch"
     * @param nombreArch Nombre del archivo
     */
    Archivo(std::string nombreArch);

    /**
     * @brief Metodo que extrae la expresion del documento y lo almacena en el atributo "expresion"
     */
    void extraerExpresion();

    /**
     * @brief Metodo que regresa la cadena "expresion"
     * @return Expresion extraida del documento
     */
    std::string getExpresion();
};

#include"leerArchivo.hpp"
