/**
 * @file leerArchivo.hpp
 *
 * @brief Contiene la definicion de la clase "Archivo"
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 4.0
 * @date 12/11/2021
 */

Archivo::Archivo(std::string nombreArch)
{
    // Abre el archivo
    archivo.open(nombreArch, std::ios::in);

    // Comprueba si se abrio correctamente el archivo
    if(!archivo.is_open())  {
        std::cout << "No fue posible abrir el archivo" << std::endl;
        exit(1);
    }

    // Inicializa las demas variables de clase
    expresion = "";
}

void Archivo::extraerExpresion()
{
    // Extrae la expresion que esta en la primera linea del documento
    getline(archivo, expresion);

    // Se posiciona al inicio del archivo
    archivo.clear();
    archivo.seekg(0, archivo.beg);

    // Cierra el archivo
    archivo.close();
}

std::string Archivo::getExpresion()
{
    // Regresa la cadena almacenada en el atributo "expresion"
    return expresion;
}
