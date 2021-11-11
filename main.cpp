#include"arbolDerivada.h"

int main()
{
    /*
    ArbolDerivada tree1("z+2");
    tree1.infijoAPrefijo();
    tree1.prefijoAArbol();
    std::cout << std::endl;
    tree1.inorden(tree1.getNodoRaiz());
    tree1.derivarArbol();
    std::cout << std::endl;
    tree1.inorden(tree1.getNodoRaiz());
    std::cout << std::endl;

    ArbolDerivada tree2("1  - y");
    tree2.infijoAPrefijo();
    tree2.prefijoAArbol();
    std::cout << std::endl;
    tree2.inorden(tree2.getNodoRaiz());
    tree2.derivarArbol();
    std::cout << std::endl;
    tree2.inorden(tree2.getNodoRaiz());
    std::cout << std::endl;

    ArbolDerivada tree3("x*4");
    tree3.infijoAPrefijo();
    tree3.prefijoAArbol();
    std::cout << std::endl;
    tree3.inorden(tree3.getNodoRaiz());
    tree3.derivarArbol();
    std::cout << std::endl;
    tree3.inorden(tree3.getNodoRaiz());
    std::cout << std::endl;

    ArbolDerivada tree4("z/ 3");
    tree4.infijoAPrefijo();
    tree4.prefijoAArbol();
    std::cout << std::endl;
    tree4.inorden(tree4.getNodoRaiz());
    tree4.derivarArbol();
    std::cout << std::endl;
    tree4.inorden(tree4.getNodoRaiz());
    std::cout << std::endl;
    */
    /*
    //ArbolDerivada tree5("x ^(x^ 2)");
    //ArbolDerivada tree5("x ^(sIn[X^2])");
    //ArbolDerivada tree5("x ^(x)");
    //ArbolDerivada tree5("((x+1)^3)/(2*x)");
    //ArbolDerivada tree5("x^ (sen[(x + x * 3 - 4) / (x + 5)])");
    //ArbolDerivada tree5("(x^cos[(x + x * 3 - 4) / (x + 5)])");
    //ArbolDerivada tree5("(x^ln[(x + x * 3 - 4) / (x + 5)])");
    ArbolDerivada tree5("(x^exp[(x + x * 3 - 4) / (x + 5)])");
    tree5.infijoAPrefijo();
    tree5.prefijoAArbol();
    std::cout << std::endl;
    tree5.derivarArbol();
    //tree5.inorden(tree5.getNodoRaiz());
    std::cout << std::endl;
    std::cout << tree5.obtenerAgrupacionSubarbol(tree5.getNodoRaiz()) << std::endl;
    tree5.simplificarArbol();
    std::cout << std::endl;
    std::cout << tree5.obtenerAgrupacionSubarbol(tree5.getNodoRaiz()) << std::endl;
    tree5.simplificarArbol();
    std::cout << std::endl;
    std::cout << tree5.obtenerAgrupacionSubarbol(tree5.getNodoRaiz()) << std::endl;
    tree5.simplificarArbol();
    std::cout << std::endl;
    std::cout << tree5.obtenerAgrupacionSubarbol(tree5.getNodoRaiz()) << std::endl;
    tree5.simplificarArbol();
    std::cout << std::endl;
    std::cout << tree5.obtenerAgrupacionSubarbol(tree5.getNodoRaiz()) << std::endl;
    */
    /*
    ArbolDerivada tree5("(x + x * 3 - 4) / (x + 5)");
    tree5.infijoAPrefijo();
    tree5.prefijoAArbol();
    tree5.derivarArbol();
    std::cout << tree5.obtenerAgrupacionSubarbol(tree5.getNodoRaiz()) << std::endl;
    std::cout << std::endl;
    ArbolDerivada arbol;
    arbol.setPrefijo("/ - + x * x 3 4 + x 5");
    arbol.prefijoAArbol();
    arbol.derivarArbol();
    std::cout << std::endl;
    std::cout << arbol.obtenerAgrupacionSubarbol(arbol.getNodoRaiz()) << std::endl;
    std::cout << std::endl;
    ArbolDerivada arbol2;
    arbol2.setSufijo("x x 3 * + 4 - x 5 + /");
    arbol2.sufijoAArbol();
    arbol2.derivarArbol();
    std::cout << std::endl;
    std::cout << arbol2.obtenerAgrupacionSubarbol(arbol2.getNodoRaiz()) << std::endl;
    std::cout << std::endl;
    */
    /*
    std::string seno = "sen[(x + x * 3 - 4) / (x + 5)]";
    int inicio = seno.find("[");
    int final = seno.find("]");
    std::cout << std::endl;
    std::cout << "Cadena: " << seno.substr((inicio + 1), (final - inicio - 1)) << std::endl;
    std::cout << std::endl;
    ArbolDerivada arbol(seno.substr((inicio + 1), (final - inicio - 1)));
    arbol.infijoAPrefijo();
    arbol.prefijoAArbol();
    std::cout << std::endl;
    std::cout << "Inorden: " << std::endl;
    arbol.inorden(arbol.getNodoRaiz());
    std::cout << std::endl;
    std::cout << arbol.obtenerAgrupacionSubarbol(arbol.getNodoRaiz()) << std::endl;
    */
    /*
    std::string expr = "sen[(x + x * 3 - 4) / (x + 5)] + tan[(x + 2) / 8] * ln[x + 2 / (x - 2)] / (3 * x^ 2) - sin[x + 2]";
    expr = "(2* 3 +(6 /2))/ 4";
    std::cout << std::endl;
    ArbolDerivada arbol(expr);
    arbol.infijoAPrefijo();
    arbol.prefijoAArbol();
    std::cout << std::endl;
    std::cout << "Inorden: " << std::endl;
    arbol.inorden(arbol.getNodoRaiz());
    std::cout << std::endl;
    std::cout << arbol.obtenerAgrupacionSubarbol(arbol.getNodoRaiz()) << std::endl;
    */
    /*
    ArbolDerivada arbol("21 + tan[( 6 + 44 * 22 - 1 )] * ( sin[( 6 + 44 * 22 - 1 )] + 4 * cos[x + 2] - 1 ) / sec[2 * x] ^ 2 ^ 4");
    ArbolDerivada arbol2("ln[3 * 2 /2] + sin[x] * cos[2 - 6 *x + 2 ] / exp[2 + 6 * 8 +6]");
    ArbolDerivada arbol3("21 + tan[(6 + 5) * (8 / 2)] * ( sin[3 * 2* x] + 4 * cos[x *  9 + 2 /2] - 1 ) / sec[x * 2 + 7 /2 / 1] ^ 2 ^ 4");
    ArbolDerivada arbol4("21 + tan[(6 + 5) * (8 / 2)] * ( sin[3 * 2* x] + 4 * cos[x *  9 + 2 /2] - 1 ) / sec[x * 2 + 7 /2 / 1] ^ 2 ^ 4");

    arbol.infijoASufijo();
    arbol.sufijoAArbol();
    std::cout << std::endl;
    std::cout << "Inorden: ";
    arbol.inorden(arbol.getNodoRaiz());
    std::cout << std::endl;
    std::cout << "Derivada: ";
    arbol.derivarArbol();
    arbol.inorden(arbol.getNodoRaiz());
    std::cout << std::endl;

    arbol2.infijoAPrefijo();
    arbol2.prefijoAArbol();
    std::cout << std::endl;
    arbol2.inorden(arbol2.getNodoRaiz());
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    arbol3.infijoAPrefijo();
    arbol3.prefijoAArbol();
    std::cout << std::endl;
    std::cout << "Inorden: ";
    arbol3.inorden(arbol3.getNodoRaiz());
    std::cout << std::endl;
    std::cout << "Derivada: ";
    arbol3.derivarArbol();
    arbol3.inorden(arbol3.getNodoRaiz());
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    arbol4.infijoASufijo();
    arbol4.sufijoAArbol();
    std::cout << std::endl;
    std::cout << "Inorden: ";
    arbol4.inorden(arbol4.getNodoRaiz());
    std::cout << std::endl;
    std::cout << "Derivada: ";
    arbol4.derivarArbol();
    arbol4.inorden(arbol4.getNodoRaiz());
    std::cout << std::endl;
    */
    /*
    ArbolDerivada arbol1("x +0");
    ArbolDerivada arbol2("0+x");
    ArbolDerivada arbol3("x- 0");
    ArbolDerivada arbol4("x * 0");
    ArbolDerivada arbol5("0 *x");
    ArbolDerivada arbol6("x * 1");
    ArbolDerivada arbol7("1 *x");
    ArbolDerivada arbol8("0 / x");
    ArbolDerivada arbol9("x^ 0");
    ArbolDerivada arbol10("x^ 1");
    ArbolDerivada arbol11("x - x");
    ArbolDerivada arbol12("x /x");

    arbol1.infijoASufijo();
    arbol2.infijoAPrefijo();
    arbol3.infijoASufijo();
    arbol4.infijoAPrefijo();
    arbol5.infijoASufijo();
    arbol6.infijoAPrefijo();
    arbol7.infijoASufijo();
    arbol8.infijoAPrefijo();
    arbol9.infijoASufijo();
    arbol10.infijoAPrefijo();
    arbol11.infijoASufijo();
    arbol12.infijoAPrefijo();

    arbol1.sufijoAArbol();
    arbol2.prefijoAArbol();
    arbol3.sufijoAArbol();
    arbol4.prefijoAArbol();
    arbol5.sufijoAArbol();
    arbol6.prefijoAArbol();
    arbol7.sufijoAArbol();
    arbol8.prefijoAArbol();
    arbol9.sufijoAArbol();
    arbol10.prefijoAArbol();
    arbol11.sufijoAArbol();
    arbol12.prefijoAArbol();

    arbol1.simplificarArbol();
    arbol2.simplificarArbol();
    arbol3.simplificarArbol();
    arbol4.simplificarArbol();
    arbol5.simplificarArbol();
    arbol6.simplificarArbol();
    arbol7.simplificarArbol();
    arbol8.simplificarArbol();
    arbol9.simplificarArbol();
    arbol10.simplificarArbol();
    arbol11.simplificarArbol();
    arbol12.simplificarArbol();

    std::cout << std::endl;
    arbol1.inorden(arbol1.getNodoRaiz());
    std::cout << std::endl;
    arbol2.inorden(arbol2.getNodoRaiz());
    std::cout << std::endl;
    arbol3.inorden(arbol3.getNodoRaiz());
    std::cout << std::endl;
    arbol4.inorden(arbol4.getNodoRaiz());
    std::cout << std::endl;
    arbol5.inorden(arbol5.getNodoRaiz());
    std::cout << std::endl;
    arbol6.inorden(arbol6.getNodoRaiz());
    std::cout << std::endl;
    arbol7.inorden(arbol7.getNodoRaiz());
    std::cout << std::endl;
    arbol8.inorden(arbol8.getNodoRaiz());
    std::cout << std::endl;
    arbol9.inorden(arbol9.getNodoRaiz());
    std::cout << std::endl;
    arbol10.inorden(arbol10.getNodoRaiz());
    std::cout << std::endl;
    arbol11.inorden(arbol11.getNodoRaiz());
    std::cout << std::endl;
    arbol12.inorden(arbol12.getNodoRaiz());
    std::cout << std::endl;
    */
    system("pause");
    return 0;
}
