#include <iostream>
#include "math_tools.h"
#include "classes.h"
#include "display_tools.h"
#include "tools.h"
#include "sel.h"


int main()
{
    vector<Matrix> localKs;
    vector<Vector> localbs;
    Matrix K;
    Vector b;
    Vector T;

    
    cout << "IMPLEMENTACI"<<char(224)<<"N DEL M"<<char(144)<<"TODO DE LOS ELEMENTOS FINITOS\n"
         << "\t- ECUACIONES DE NAVIER-STOKES\n" << "\t- 1 DIMENSI"<<char(224)<<"N\n"
         << "\t- FUNCIONES DE FORMA LINEALES\n" << "\t- PESOS DE GALERKIN\n"
         << "*********************************************************************************\n\n";

    mesh m;
    leerMallayCondiciones(m);
   
    crearSistemasLocales(m,localKs,localbs);
    
    zeroes(K,m.getSize(NODES)*2);
    zeroes(b,m.getSize(NODES)*2);
    ensamblaje(m,localKs,localbs,K,b);
    

    
    applyDirichlet(m,K,b);
    //MOSTRAR MATRIZ K
    showMatrix(K);
/*
    zeroes(T,b.size());

    calculate(K,b,T);

    cout << "La respuesta es: " << endl;
    
    showVector(T);*/

    return 0;
}
