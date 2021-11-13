/**
 * @file main.cpp
 *
 * @brief Funcion main que extrae una expresion algebraica de un documento en notacion infijo, prefijo o sufijo, crea el arbol de expresiones algebraicas y calcula su derivada
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 2.0
 * @date 12/11/2021
 */

#include"leerArchivo.h"

int main()
{
    // Pide el nombre del archivo
    std::string nombreArchivo = "";
    std::cout << "Ingresa el nombre del archivo que contiene la expresion algebraica (con extension): ";
    std::cin >> nombreArchivo;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    // Abre el archivo y extrae la expresion algebraica del archivo
    Archivo archivoIn(nombreArchivo);
    archivoIn.extraerExpresion();

    system("clear");

    unsigned short int opcion = 0;
    std::cout << "En cual notacion esta escrita la expresion almacenada en el archivo?" << std::endl;
    std::cout << "1 - Infijo" << std::endl;
    std::cout << "2 - Prefijo" << std::endl;
    std::cout << "3 - Sufijo" << std::endl;
    do  {
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        // Si la opcion es valida
        if(opcion > 0 && opcion < 4)  {
            break;
        }
        // Si la opcion es invalida
        else  {
            std::cout << "\nOpcion invalida\n" << std::endl;
        }
    }  while(opcion < 1 || opcion > 3);

    system("clear");

    // Arreglo booleano auxiliar para representar las notaciones disponibles
    bool auxNotacion[3] = {false, false, false};

    // Crea el objeto que contendra el arbol de expresiones algebraicas con la notacion de entrada
    ArbolDerivada arbol;
    switch(opcion)  {
        // Si la notacion de la expresion algebraica es infijo
        case 1:
            arbol.setInfijo(archivoIn.getExpresion());
            auxNotacion[0] = true;
            break;

        // Si la notacion de la expresion algebraica es prefijo
        case 2:
            arbol.setPrefijo(archivoIn.getExpresion());
            auxNotacion[1] = true;
            break;

        // Si la notacion de la expresion algebraica es sufijo
        case 3:
            arbol.setSufijo(archivoIn.getExpresion());
            auxNotacion[2] = true;
            break;
    }

    // Arreglo booleano auxiliar para saber si ya se creo el arbol de expresiones algebraicas y si ya se derivo
    bool creadoYDerivado[2] = {false, false};
    // Llevara el conteo de las derivadas
    unsigned short int contDerivadas = 0;

    do  {
        std::cout << "\nArbol de expresiones: ";
        if(!creadoYDerivado[0])  {
            std::cout << "no creado";
        }
        else if(creadoYDerivado[1])  {
            std::cout << contDerivadas << " derivada";
        }
        else if(creadoYDerivado[0])  {
            std::cout << "creado";
        }

        std::cout << "\n\nElija una de las siguientes opciones\n" << std::endl;
        // Si aun no se ha creado el arbol de expresiones algebraicas
        if(!creadoYDerivado[0])  {
            std::cout << "1 - Crear el arbol de expresiones algebraicas" << std::endl;
        }
        // Si ya se creo el arbol de expresiones
        else  {
            std::cout << "2 - Imprimir expresion almacenada en el arbol en notacion infijo" << std::endl;
            std::cout << "3 - Imprimir expresion almacenada en el arbol en notacion prefijo" << std::endl;
            std::cout << "4 - Imprimir expresion almacenada en el arbol en notacion sufijo" << std::endl;
            std::cout << "5 - Simplificar expresion almacenada en el arbol" << std::endl;
            std::cout << "6 - Calcular la derivada de la expresion almacenada en el arbol" << std::endl;
        }
        // Si ya se creo el arbol de expresiones algebraicas y ya se derivo
        if(creadoYDerivado[0] && creadoYDerivado[1])  {
            std::cout << "7 - Crear el arbol de expresiones algebraicas con la expresion inicial de entrada" << std::endl;
        }
        std::cout << "0 - Salir" << std::endl;

        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        switch(opcion)  {
            // Crea el arbol de expresiones algebraicas
            case 1:
                // Condicional para evitar crear otro arbol
                if(creadoYDerivado[0])  {
                    system("clear");
                    continue;
                }
                creadoYDerivado[0] = true;
                // Si la entrada fue una expresion algebraica en notacion infijo
                if(auxNotacion[0])  {
                    arbol.infijoAPrefijo();
                    arbol.prefijoAArbol();
                }
                // Si la entrada fue una expresion algebraica en notacion prefijo
                else if(auxNotacion[1])  {
                    arbol.prefijoAArbol();
                }
                // Si la entrada fue una expresion algebraica en notacion sufijo
                else if(auxNotacion[2])  {
                    arbol.sufijoAArbol();
                }
                std::cout << "\nArbol creado" << std::endl;
                std::cout << "\nPresione Enter para continuar";
                while(std::cin.get() != '\n');
                system("clear");
                break;

            // Recorre el arbol en inorden
            case 2:
                // Condicional para evitar errores
                if(!creadoYDerivado[0])  {
                    system("clear");
                    continue;
                }
                std::cout << "\nInfijo: " << arbol.obtenerAgrupacionSubarbol(arbol.getNodoRaiz()) << std::endl;
                std::cout << "\nPresione Enter para continuar";
                while(std::cin.get() != '\n');
                system("clear");
                break;

            // Recorre el arbol en preorden
            case 3:
                // Condicional para evitar errores
                if(!creadoYDerivado[0])  {
                    system("clear");
                    continue;
                }
                std::cout << "\nPrefijo: ";
                arbol.preorden(arbol.getNodoRaiz());
                std::cout << "\nPresione Enter para continuar";
                while(std::cin.get() != '\n');
                system("clear");
                break;

            // Recorre el arbol en postorden
            case 4:
                // Condicional para evitar errores
                if(!creadoYDerivado[0])  {
                    system("clear");
                    continue;
                }
                std::cout << "\nSufijo: ";
                arbol.postorden(arbol.getNodoRaiz());
                std::cout << "\nPresione Enter para continuar";
                while(std::cin.get() != '\n');
                system("clear");
                break;

            // Simplifica la expresion
            case 5:
                // Condicional para evitar errores
                if(!creadoYDerivado[0])  {
                    system("clear");
                    continue;
                }
                for(int i = 0; i < 10; i++)  {
                    arbol.simplificarArbol();
                }
                std::cout << "\nArbol simplificado" << std::endl;
                std::cout << "\nPresione Enter para continuar";
                while(std::cin.get() != '\n');
                system("clear");
                break;

            // Calcula la derivada
            case 6:
                // Condicional para evitar errores
                if(!creadoYDerivado[0])  {
                    system("clear");
                    continue;
                }
                creadoYDerivado[1] = true;
                arbol.derivarArbol();
                contDerivadas++;
                std::cout << "\nArbol derivado" << std::endl;
                std::cout << "\nPresione Enter para continuar";
                while(std::cin.get() != '\n');
                system("clear");
                break;

            // Vuelve a crear arbol con la expresion de entrada
            case 7:
                // Condicional para evitar errores
                if(!creadoYDerivado[1])  {
                    system("clear");
                    continue;
                }
                // Si la entrada fue una expresion algebraica en notacion infijo
                if(auxNotacion[0])  {
                    arbol.infijoAPrefijo();
                    arbol.prefijoAArbol();
                }
                // Si la entrada fue una expresion algebraica en notacion prefijo
                else if(auxNotacion[1])  {
                    arbol.prefijoAArbol();
                }
                // Si la entrada fue una expresion algebraica en notacion sufijo
                else if(auxNotacion[2])  {
                    arbol.sufijoAArbol();
                }
                contDerivadas = 0;
                creadoYDerivado[1] = false;
                std::cout << "\nArbol creado nuevamente" << std::endl;
                std::cout << "\nPresione Enter para continuar";
                while(std::cin.get() != '\n');
                system("clear");
                break;
        }
    }  while(opcion > 0 && opcion < 8);

    system("pause");
    return 0;
}
