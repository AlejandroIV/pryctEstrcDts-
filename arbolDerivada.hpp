/**
 * @file arbolDerivada.hpp
 *
 * Definicion de la clase "ArbolDerivada"
 *
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 08/11/2021
 */

// Funcion que regresara "True" en caso de que "x" sea un operador
inline bool esOperador(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%');
}

// Funcion que regresara "True" en caso de que "x" sea digito de un numero o una letra
inline bool esDigitoOLetra(char x)
{
    return ((x >= 48 && x <= 57) || (x >= 65 && x <= 90) || (x >= 97 && x <= 122));
}

// Funcion que regresara "True" en caso de que "x" sea una letra minuscula (para las variables)
inline bool esVariable(std::string x)
{
    return (x == "x" || x == "y" || x == "z");
}

// Funcion que regresara "True" en caso de que "x" sea un corchete
inline bool esCorchete(char x)
{
    return (x == '[' || x == ']');
}

// Funcion que regresa el caracter "x" en minuscula
char lowerChar(char x)
{
    if(x >= 65 && x <= 90)  {
        x += 32;
        return x;
    }
    else  {
        return x;
    }
}

// Funcion que regresara un numero asociado a la precedencia de los operadores
int precedencia(char x)
{
    // '^' tiene mayor precedencia que '*' y '/' tiene mayor precedencia que '+' y '-'
    if(x == '+' || x == '-')  return 0;
    if(x == '*' || x == '/')  return 1;
    if(x == '^')  return 2;
    return -1;
}

// Funcion que regresara un numero asociado a la asociacion de los operadores
int asociacion(char x)
{
    // Si la asociacion es der-izq
    if(x == '^')  return -1;
    // Si la asociacion es izq-der
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%')  return 1;
    return 0;
}

// Funcion que regresara "True" en caso de que en la cadena se identifique una variable
bool tieneVariable(std::string x)
{
    std::string aux = "";
    for(int i = 0; i <= x.length(); i++)  {
        aux += x[i];
        if(esVariable(aux))  {
            return true;
        }
        aux = "";
    }
    return false;
}

ArbolDerivada::~ArbolDerivada()
{
    // Llama al metodo "eliminarArbol" para eliminar el arbol completo
    eliminarArbol();

    // Vacia las cadenas
    infijo = "";
    prefijo = "";
    infijo = "";
}

void ArbolDerivada::infijoAPrefijo()
{
    // Pila que contendra los operadores
    std::stack<char> P;
    // Vacia (en caso de tener algo) la cadena del atributo "prefijo"
    prefijo = "";

    // Bucle que se repetira hasta que llegue al principio de la cadena "infijo"
    for(int i = infijo.length(); i >= 0; i--)  {
        // Condicional que se saltara los espacios
        if(infijo[i] == ' ')  {
            continue;
        }

        // Si el siguiente caracter es un parentesis que cierra
        if(infijo[i] == ')')  {
            // Entra a la pila "P"
            P.push(infijo[i]);
        }
        // Si el siguiente caracter es un parentesis que abre
        else if(infijo[i] == '(')  {
            // Saca los operadores de la pila "P" y los concatena con "prefijo" hasta encontrar ')'
            while(!P.empty() && P.top() != ')')  {
                prefijo += ' ';
                prefijo += P.top();
                P.pop();
            }
            // Elimina el parentesis ')' que queda
            P.pop();
        }
        // Si lo que sigue es un operando lo concatena con "prefijo"
        else if(!esOperador(infijo[i]))  {
            prefijo += ' ';
            // No admite mayusculas
            prefijo += lowerChar(infijo[i]);
            // Si el que se acaba de concatenar con "prefijo" es un corchete que cierra
            if(infijo[i] == ']')  {
                // Concatena con "prefijo" la expresion dentro de los corchetes
                while(infijo[i] != '[')  {
                    i--;
                    // No admite mayusculas
                    prefijo += lowerChar(infijo[i]);
                }
            }
            // En caso de que el numero tenga mas de un digito o el termino sea una funcion trascendente
            while(esDigitoOLetra(infijo[i - 1]) && infijo[i - 1] != ' ')  {
                i--;
                // No admite mayusculas
                prefijo += lowerChar(infijo[i]);
            }
        }
        // Si el siguiente caracter es un operador
        else  {
            // Mientras al frente de la pila "P" haya un operador de mayor precedencia y no este vacia
            while(!P.empty() && precedencia(P.top()) > precedencia(infijo[i]))  {
                // Concatena el frente de la pila "P" con "prefijo" y saca ese nodo de la pila
                prefijo += ' ';
                prefijo += P.top();
                P.pop();
            }
            /* Si la pila "P" esta vacia o tiene un parentesis al frente, o el operador al frente de la pila
               es de menor precedencia que "infijo[i]" */
            if(P.empty() || precedencia(P.top()) < precedencia(infijo[i]))  {
                // "infijo[i]" entra a la pila
                P.push(infijo[i]);
            }
            // Si al frente de la pila "P" hay un operador de igual precedencia
            else  {
                // Si la asociacion es der-izq
                if(asociacion(infijo[i]) < 0)  {
                    // Concatena el operador al frente de la pila "P" con "prefijo" y saca ese nodo de la pila
                    prefijo += ' ';
                    prefijo += P.top();
                    P.pop();
                }
                // El nuevo operador entra a la pila
                P.push(infijo[i]);
            }
        }
    }

    // Termina de vaciar la pila "P"
    while(!P.empty())  {
        prefijo += ' ';
        prefijo += P.top();
        P.pop();
    }

    // Invirte la cadena "prefijo"
    std::string auxTmp(prefijo);
    int tamanho = prefijo.length();
    prefijo = "";
    for(int y = (tamanho - 1); y >= 0; y--)  {
        if(esOperador(auxTmp[y]) || esDigitoOLetra(auxTmp[y]) || esCorchete(auxTmp[y]) || auxTmp[y] == ' ' || auxTmp[y] == '(' || auxTmp[y] == ')')  {
            prefijo += auxTmp[y];
        }
    }

    // Elimina el espacio al final de "prefijo"
    prefijo = prefijo.substr(0, (tamanho - 1));
}

void ArbolDerivada::infijoASufijo()
{
    // Pila que contendra los operadores
    std::stack<char> P;
    // Vacia (en caso de tener algo) la cadena del atributo "sufijo"
    sufijo = "";

    // Bucle que se repetira hasta que llegue al final de la cadena "infijo"
    for(int i = 0; i < infijo.length(); i++)  {
        // Condicional que se saltara los espacios
        if(infijo[i] == ' ')  {
            continue;
        }

        // Si el siguiente caracter es un parentesis que abre
        if(infijo[i] == '(')  {
            // Entra a la pila "P"
            P.push(infijo[i]);
        }
        // Si el siguiente caracter es un parentesis que cierra
        else if(infijo[i] == ')')  {
            // Saca los operadores de la pila "P" y los concatena con "sufijo" hasta encontrar '('
            while(!P.empty() && P.top() != '(')  {
                sufijo += ' ';
                sufijo += P.top();
                P.pop();
            }
            // Elimina el parentesis '(' que queda
            P.pop();
        }
        // Si el siguiente caracter es un operando lo concatena con "sufijo"
        else if(!esOperador(infijo[i]))  {
            sufijo += ' ';
            // No admite mayusculas
            sufijo += lowerChar(infijo[i]);
            // En caso de que el numero tenga mas de un digito o el termino sea una funcion trascendente
            while((esDigitoOLetra(infijo[i + 1]) || esCorchete(infijo[i + 1])) && infijo[i + 1] != ' ')  {
                // Si el que se va a concatenar con "sufijo" es un corchete que abre
                if(infijo[i + 1] == '[')  {
                    // Concatena con "sufijo" la expresion dentro de los corchetes
                    while(infijo[i + 1] != ']')  {
                        i++;
                        // No admite mayusculas
                        sufijo += lowerChar(infijo[i]);
                    }
                }
                i++;
                // No admite mayusculas
                sufijo += lowerChar(infijo[i]);
            }
        }
        // Si el siguiente caracter es un operador
        else  {
            // Mientras al frente de la pila "P" haya un operador de mayor precedencia y no este vacia
            while(!P.empty() && precedencia(P.top()) > precedencia(infijo[i]))  {
                // Concatena el frente de la pila "P" con "sufijo" y saca ese nodo de la pila
                sufijo += ' ';
                sufijo += P.top();
                P.pop();
            }
            /* Si la pila "P" esta vacia o tiene un parentesis al frente, o el operador al frente de la pila
               es de menor precedencia que "infijo[i]" */
            if(P.empty() || precedencia(P.top()) < precedencia (infijo[i]))  {
                // "infijo[i]" entra a la pila
                P.push(infijo[i]);
            }
            // Si al frente de la pila "P" hay un operador de igual precedencia
            else  {
                // Si la asociacion es izq-der
                if(asociacion(infijo[i]) > 0)  {
                    // Concatena el operador al frente de la pila "P" con "sufijo" y saca ese nodo de la pila
                    sufijo += ' ';
                    sufijo += P.top();
                    P.pop();
                }
                // El nuevo operador entra a la pila
                P.push(infijo[i]);
            }
        }
    }

    // Termina de vaciar la pila "P"
    while(!P.empty())  {
        sufijo += ' ';
        sufijo += P.top();
        P.pop();
    }

    // Elimina el espacio al principio de "sufijo"
    sufijo = sufijo.substr(1);
}

void ArbolDerivada::prefijoAArbol()
{
    // Pila que contendra los operadores de la expresion (definido en el heap)
    std::stack<NodoArbol> *P = new std::stack<NodoArbol>();
    // Contador de caracteres para los numeros de mas de un digito o las funciones trascendentes
    int auxContChar = 1;
    // Vacia el arbol en caso de tener algo
    eliminarArbol();

    // Bucle que recorrera la cadena "prefijo" de derecha a izquierda
    for(int i = (prefijo.length() - 1); i >= 0; i--)  {
        // Condicional que se saltara los espacios
        if(prefijo[i] == ' ')  {
            continue;
        }

        // Si el siguiente caracter es un operando
        if(!esOperador(prefijo[i]))  {
            // En caso de que el siguiente caracter sea un corchete que cierra entonces aumenta "auxContChar" hasta encontrar el corchete que abre
            if(prefijo[i] == ']')  {
                while(prefijo[i - auxContChar] != '[')  {
                    auxContChar++;
                }
            }
            // En caso de que el numero tenga mas de un digito o sea una funcion trascendente
            while((esDigitoOLetra(prefijo[i - auxContChar]) || esCorchete(prefijo[i - auxContChar])) && prefijo[i - auxContChar] != ' ')  {
                auxContChar++;
            }
            // Si hay un numero con mas de un digito o una funcion trascendente
            if(auxContChar != 1)  {
                // Ingresa el nodo a la pila el operando (numero de mas de un digito o funcion trascendente) a la pila "P"
                P->push(NodoArbol(std::string(prefijo.substr((i - auxContChar + 1), auxContChar))));
                // Actualiza "i"
                i -= auxContChar;
            }
            // Pero si el numero solo tiene un digito
            else{
                // El operando (un digito o letra) entra a la pila "P"
                P->push(NodoArbol(std::string(1, prefijo[i])));
            }

            // Reinicia contador
            auxContChar = 1;
        }
        // Si el siguiente caracter es un operador
        else  {
            // Extrae dos elementos de la pila "P"
            NodoArbol *A = new NodoArbol(P->top());
            P->pop();
            NodoArbol *B = new NodoArbol(P->top());
            P->pop();
            // Crea el nodo que contendra el operador y sus hijos seran los operandos
            std::string operador;
            operador = prefijo[i];
            NodoArbol *C = new NodoArbol(operador);
            C->izq = A;
            C->der = B;
            P->push(*C);
        }
    }

    // Se almacena la raiz del arbol resultante en "raiz_"
    setNodoRaiz(&P->top());
}

void ArbolDerivada::sufijoAArbol()
{
    // Pila que contendra los operadores de la expresion (definido en el heap)
    std::stack<NodoArbol> *P = new std::stack<NodoArbol>();
    // Contador de caracteres para los numeros de mas de un digito o las funciones trascendentes
    int auxContChar = 1;
    // Vacia el arbol en caso de tener algo
    eliminarArbol();

    // Bucle que recorrera la cadena "sufijo" de izquierda a derecha
    for(int i = 0; i < sufijo.length(); i++)  {
        // Condicional que se saltara los espacios
        if(sufijo[i] == ' ')  {
            continue;
        }

        // Si el siguiente caracter es un operando
        if(!esOperador(sufijo[i]))  {
            // En caso de que el numero tenga mas de un digito o sea una funcion trascendente
            while((esDigitoOLetra(sufijo[i + auxContChar]) || esCorchete(sufijo[i + auxContChar])) && sufijo[i + auxContChar] != ' ')  {
                // En caso de que el siguiente caracter sea un corchete que abre entonces aumenta "auxContChar" hasta encontrar el corchete que cierra
                if(sufijo[i + auxContChar] == '[')  {
                    while(sufijo[i + auxContChar] != ']')  {
                        auxContChar++;
                    }
                }
                auxContChar++;
            }
            // Si hay un numero con mas de un digito o una funcion trascendente
            if(auxContChar != 1)  {
                // Ingresa el nodo a la pila el operando (numero de mas de un digito o funcion trascendente) a la pila "P"
                P->push(NodoArbol(std::string(sufijo.substr(i, auxContChar))));
                // Actualiza "i"
                i += auxContChar;
            }
            // Pero si el numero solo tiene un digito
            else{
                // El operando (un digito o letra) entra a la pila "P"
                P->push(NodoArbol(std::string(1, sufijo[i])));
            }

            // Reinicia contador
            auxContChar = 1;
        }
        // Si el siguiente caracter es un operador
        else  {
            // Extrae dos elementos de la pila "P"
            NodoArbol *A = new NodoArbol(P->top());
            P->pop();
            NodoArbol *B = new NodoArbol(P->top());
            P->pop();
            // Crea el nodo que contendra el operador y sus hijos seran los operandos
            std::string operador;
            operador = sufijo[i];
            NodoArbol *C = new NodoArbol(operador);
            C->izq = B;
            C->der = A;
            P->push(*C);
        }
    }

    // Se almacena la raiz del arbol resultante en "raiz_"
    setNodoRaiz(&P->top());
}

void ArbolDerivada::derivarArbol()
{
    // Llama al metodo para calcular la derivada de todos los nodos del arbol
    derivarNodo(getNodoRaiz());
}

void ArbolDerivada::derivarNodo(NodoArbol *nodoActPtr)
{
    // Como se deben comparar dos cadenas entonces hay que usar comillas dobles "", en caso de comparar caracteres se usan comillas simples ''
    // Si el nodo es un signo mas
    if(nodoActPtr->dato == "+")  {
        derivarNodo(nodoActPtr->izq);
        derivarNodo(nodoActPtr->der);
    }

    // Si el nodo es un signo menos
    else if(nodoActPtr->dato == "-")  {
        derivarNodo(nodoActPtr->izq);
        derivarNodo(nodoActPtr->der);
    }

    // Si el nodo es un signo producto
    else if(nodoActPtr->dato == "*")  {
        // Crea copias de los hijos del nodo "nodoActPtr"
        NodoArbol *f = copiarSubarbol(nodoActPtr->izq);
        NodoArbol *g = copiarSubarbol(nodoActPtr->der);

        // Crea dos nodos para los terminos de la suma
        NodoArbol *l = new NodoArbol(std::string("*"));
        NodoArbol *r = new NodoArbol(std::string("*"));

        // Cambia el signo producto por mas
        nodoActPtr->dato = "+";

        // Aplica la regla de derivacion
        l->izq = f;
        derivarNodo(f);
        l->der = nodoActPtr->der;
        r->izq = nodoActPtr->izq;
        r->der = g;
        derivarNodo(g);
        nodoActPtr->izq = l;
        nodoActPtr->der = r;
    }

    // Si el nodo es un signo cociente
    else if(nodoActPtr->dato == "/")  {
        // Crea copias de los hijos del nodo "nodoActPtr"
        NodoArbol *f = copiarSubarbol(nodoActPtr->izq);
        NodoArbol *g = copiarSubarbol(nodoActPtr->der);
        NodoArbol *gDenominador = copiarSubarbol(nodoActPtr->der);

        // Crea dos nodos para los terminos de la resta del numerador y crea el nodo de la resta
        NodoArbol *lNum = new NodoArbol(std::string("*"));
        NodoArbol *rNum = new NodoArbol(std::string("*"));
        NodoArbol *restaNum = new NodoArbol(std::string("-"));

        // Crea los dos nodos del denominador
        NodoArbol *denCuadr = new NodoArbol("^");
        NodoArbol *potencia = new NodoArbol("2");

        // Aplica la regla de derivacion
        lNum->izq = f;
        derivarNodo(f);
        lNum->der = nodoActPtr->der;
        rNum->izq = nodoActPtr->izq;
        rNum->der = g;
        derivarNodo(g);
        restaNum->izq = lNum;
        restaNum->der = rNum;
        denCuadr->izq = gDenominador;
        denCuadr->der = potencia;
        nodoActPtr->izq = restaNum;
        nodoActPtr->der = denCuadr;
    }

    // Si el nodo es un signo potencia
    else if(nodoActPtr->dato == "^")  {
        // Si "g" es un numero
        if(!tieneVariable(nodoActPtr->der->dato))  {
            // Crea copias de los hijos del nodo "nodoActPtr"
            NodoArbol *f = copiarSubarbol(nodoActPtr->izq);
            NodoArbol *g = copiarSubarbol(nodoActPtr->der);

            // Crea los nodos para la resta de la potencia
            NodoArbol *res = new NodoArbol(std::string("-"));
            NodoArbol *uno = new NodoArbol(std::string("1"));

            // Crea el nodo para la potencia
            NodoArbol *pot = new NodoArbol(std::string("^"));

            // Crea el nodo para el otro producto
            NodoArbol *prod = new NodoArbol(std::string("*"));

            // Cambia el signo potencia por producto
            nodoActPtr->dato = "*";

            // Aplica la regla de derivacion
            res->izq = g;
            res->der = uno;
            pot->izq = nodoActPtr->izq;
            pot->der = res;
            prod->izq = pot;
            prod->der = f;
            derivarNodo(f);
            nodoActPtr->izq = nodoActPtr->der;
            nodoActPtr->der = prod;
        }
        // Si "g" es una funcion trascendente
        else  {
            // Crea copias de los hijos del nodo "nodoActPtr"
            NodoArbol *f = copiarSubarbol(nodoActPtr->izq);
            NodoArbol *g = copiarSubarbol(nodoActPtr->der);

            // Crea dos nodos para los terminos del producto
            NodoArbol *l = new NodoArbol(std::string("^"));
            NodoArbol *r = new NodoArbol(std::string("*"));

            // Crea el nodo que contendra el logaritno
            NodoArbol *ln = new NodoArbol(std::string("ln[" + this->obtenerAgrupacionSubarbol(f) + "]"));

            // Cambia el signo potencia por producto
            nodoActPtr->dato = "*";

            // Aplica la regla de derivacion
            l->izq = nodoActPtr->izq;
            l->der = nodoActPtr->der;
            r->izq = g;
            r->der = ln;
            derivarNodo(r);
            nodoActPtr->izq = l;
            nodoActPtr->der = r;
        }
    }

    // Si el nodo no es un simbolo de operador (numeros, variables o funciones trascendentes)
    else  {
        // Deriva las hojas del arbol de sintaxis
        // Si el nodo es una variable
        if(esVariable(nodoActPtr->dato))  {
            nodoActPtr->dato = std::string("1");
            return;
        }

        // Si el nodo es una funcion seno
        else if(nodoActPtr->dato.substr(0, 3) == "sen" || nodoActPtr->dato.substr(0, 3) == "sin")  {
            // Crea el nodo que contendra la derivada de la funcion seno
            NodoArbol *derSin = new NodoArbol("cos" + nodoActPtr->dato.substr(3));

            // Crea un arbol de sintaxis con el argumento para poder derivarlo
            int inicio = nodoActPtr->dato.find("[");
            int final = nodoActPtr->dato.find("]");
            ArbolDerivada *arbolAux = new ArbolDerivada(nodoActPtr->dato.substr((inicio + 1), (final - inicio - 1)));
            arbolAux->infijoASufijo();
            arbolAux->sufijoAArbol();
            arbolAux->derivarArbol();

            // Cambia el nodo por el signo producto
            nodoActPtr->dato = "*";

            // Aplica la regla de derivacion
            nodoActPtr->izq = derSin;
            nodoActPtr->der = arbolAux->getNodoRaiz();
        }

        // Si el nodo es una funcion coseno
        else if(nodoActPtr->dato.substr(0, 3) == "cos")  {
            // Crea los nodos que contendran la derivada de la funcion coseno
            NodoArbol *derCos = new NodoArbol("sin" + nodoActPtr->dato.substr(3));
            NodoArbol *cero = new NodoArbol("0");
            NodoArbol *res = new NodoArbol("-");

            // Crea un arbol de sintaxis con el argumento para poder derivarlo
            int inicio = nodoActPtr->dato.find("[");
            int final = nodoActPtr->dato.find("]");
            ArbolDerivada *arbolAux = new ArbolDerivada(nodoActPtr->dato.substr((inicio + 1), (final - inicio - 1)));
            arbolAux->infijoAPrefijo();
            arbolAux->prefijoAArbol();
            arbolAux->derivarArbol();

            // Cambia el nodo por el signo producto
            nodoActPtr->dato = "*";

            // Aplica la regla de derivacion
            res->izq = cero;
            res->der = derCos;
            nodoActPtr->izq = res;
            nodoActPtr->der = arbolAux->getNodoRaiz();
        }

        // Si el nodo es una funcion exponencial natural
        else if(nodoActPtr->dato.substr(0, 3) == "exp")  {
            // Crea el nodo que contendra la derivada de la funcion exponencial natural
            NodoArbol *derExp = new NodoArbol(nodoActPtr->dato);

            // Crea un arbol de sintaxis con el argumento para poder derivarlo
            int inicio = nodoActPtr->dato.find("[");
            int final = nodoActPtr->dato.find("]");
            ArbolDerivada *arbolAux = new ArbolDerivada(nodoActPtr->dato.substr((inicio + 1), (final - inicio - 1)));
            arbolAux->infijoASufijo();
            arbolAux->sufijoAArbol();
            arbolAux->derivarArbol();

            // Cambia el nodo por el signo producto
            nodoActPtr->dato = "*";

            // Aplica la regla de derivacion
            nodoActPtr->izq = derExp;
            nodoActPtr->der = arbolAux->getNodoRaiz();
        }

        // Si el nodo es una funcion logaritmo natural
        else if(nodoActPtr->dato.substr(0, 2) == "ln")  {
            // Crea un arbol de sintaxis con el argumento
            int inicio = nodoActPtr->dato.find("[");
            int final = nodoActPtr->dato.find("]");
            ArbolDerivada *den = new ArbolDerivada(nodoActPtr->dato.substr((inicio + 1), (final - inicio - 1)));
            den->infijoAPrefijo();
            den->prefijoAArbol();

            // Crea un arbol de sintaxis con el argumento para poder derivarlo
            ArbolDerivada *arbolAux = new ArbolDerivada(nodoActPtr->dato.substr((inicio + 1), (final - inicio - 1)));
            arbolAux->infijoASufijo();
            arbolAux->sufijoAArbol();
            arbolAux->derivarArbol();

            // Cambia el nodo por el signo cociente
            nodoActPtr->dato = "/";

            // Aplica la regla de derivacion
            nodoActPtr->izq = arbolAux->getNodoRaiz();
            nodoActPtr->der = den->getNodoRaiz();
        }

        // Si el nodo es un numero
        else  {
            nodoActPtr->dato = std::string("0");
        }
    }
}

std::string ArbolDerivada::obtenerAgrupacionSubarbol(NodoArbol *nodoPtr)
{
    // Crea un arbol copia para la agrupacion en el heap
    ArbolDerivada *arbolAgrupado = new ArbolDerivada();
    arbolAgrupado->setNodoRaiz(copiarSubarbol(nodoPtr));

    // Llama al metodo para que vaya agrupando los terminos del arbol copia
    agruparTerminos(arbolAgrupado->getDireccionNodoRaiz());

    return arbolAgrupado->getNodoRaiz()->dato;
}

void ArbolDerivada::agruparTerminos(NodoArbol **nodoActPtr)
{
    // Condicion de paro de recursion (solo admite nodos padre)
    if(!(*nodoActPtr)->izq && !(*nodoActPtr)->der)  {
        return;
    }

    // Variable auxiliar que contendra los terminos agrupados
    std::string exprAgrupAux = "(";

    // Llama al metodo "agruparTerminos" de forma recursiva para recorrer todos los nodos
    agruparTerminos(&(*nodoActPtr)->izq);
    // Si el nodo derecho es padre
    if((*nodoActPtr)->der->izq && (*nodoActPtr)->der->der)  {
        agruparTerminos(&(*nodoActPtr)->der);
    }

    // Si el nodo derecho no es padre agrupa los terminos
    exprAgrupAux += (*nodoActPtr)->izq->dato + (*nodoActPtr)->dato + (*nodoActPtr)->der->dato + ")";
    // Elimina el nodo y crea uno nuevo con los terminos agrupadas
    eliminarSubarbol(*nodoActPtr);
    NodoArbol *nuevoActPtr = new NodoArbol(std::string(exprAgrupAux));
    // Reemplaza el "nodoActPtr" por "nuevoActPtr"
    *nodoActPtr = nuevoActPtr;
}
