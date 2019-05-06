/* 
 * File:   main.cpp
 * Author: darwin
 *
 * Created on 5 de mayo de 2019, 08:48 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int alt_d[60];
int alt_i[60];
int fe[60];
int numeros[60];
int max(int a, int b) {
    if (a > b) {
        return a;
    } else if (a < b) {
        return b;
    } else {
        return a;
    }
}

void actualizarAltura(int i) {
    if (numeros[i * 2 + 1] == 0 && numeros[i * 2 + 2] == 0) {
        alt_i[i] = 0;
        alt_d[i] = 0;
    } else if (numeros[i * 2 + 1] == 0 && numeros[i * 2 + 2] != 0) {
        alt_i[i] = 0;
        alt_d[i] = max(alt_i[i * 2 + 2], alt_d[i * 2 + 2]) + 1;
    } else if (numeros[i * 2 + 1] != 0 && numeros[i * 2 + 2] == 0) {
        alt_i[i] = max(alt_i[i * 2 + 1], alt_d[i * 2 + 1]) + 1;
        alt_d[i] = 0;
    } else if (numeros[i * 2 + 1] != 0 && numeros[i * 2 + 2] != 0) {
        alt_i[i] = max(alt_i[i * 2 + 1], alt_d[i * 2 + 1]) + 1;
        alt_d[i] = max(alt_i[i * 2 + 2], alt_d[i * 2 + 2]) + 1;
    }
    fe[i] = alt_d[i] - alt_i[i];
}

int rotarSimpleIzq(int i) {
    int aux = numeros[i * 2 + 1];
    int posaux = i * 2 + 1;
    numeros[i * 2 + 1] = numeros[posaux * 2 + 2];
    numeros[i * 2 + 2] = numeros[i];
    actualizarAltura(i);
    actualizarAltura(posaux);
    return aux;
}

int rotarSimpleDer(int i) {
    int aux = numeros[i * 2 + 2];
    int posaux = i * 2 + 2;
    numeros[i * 2 + 2] = numeros[posaux * 2 + 1];
    numeros[i * 2 + 1] = numeros[i];
    actualizarAltura(i);
    actualizarAltura(posaux);
    return aux;
}

int rotarDobreDer(int i) {
    numeros[i * 2 + 2] = rotarSimpleIzq(i * 2 + 2);
    return rotarSimpleDer(i);
}

int rotarDobreIzq(int i) {
    numeros[i * 2 + 1] = rotarSimpleDer(i * 2 + 1);
    return rotarSimpleIzq(i);
}

int balancear(int i) {
    if ((alt_i[i] - alt_d[i]) == 2) {
        if (alt_i[i * 2 + 1] >= alt_d[i * 2 + 1]) {
            numeros[i] = rotarSimpleIzq(i);
        } else {
            numeros[i] = rotarDobreIzq(i);
        }
    }
    if ((alt_d[i] - alt_i[i]) == 2) {
        if (alt_d[i * 2 + 2] >= alt_i[i * 2 + 2]) {
            numeros[i] = rotarSimpleDer(i);
        } else {
            numeros[i] = rotarDobreDer(i);
        }
    }
    return numeros[i];
}

int inserta(int i, int nuevo) {
    if (numeros[i] == 0) {
        numeros[i] = nuevo;
    } else {
        if (nuevo < numeros[i]) {
            inserta(i * 2 + 1, nuevo);
        } else if (nuevo > numeros[i]) {
            inserta(i * 2 + 2, nuevo);
        }
    }
    actualizarAltura(i);
    numeros[i] = balancear(i);
    return numeros[i];
}
int raiz = 0;

void insertame(int nuevo) {
    if (numeros[raiz] == 0) {
        numeros[raiz] = nuevo;
    } else {
        numeros[raiz] = inserta(raiz, nuevo);
    }
}

void preOrden(int i) {
    if (numeros[i] != 0) {
        preOrden(i * 2 + 1);
        cout << numeros[i] << "->";        
        preOrden(i * 2 + 2);
    }
}

void preOrdenGraf(int i) {
    if (numeros[i] != 0) {
        cout << numeros[i] << "[label= \"<C0>|" << numeros[i] << "|<C1>\"];\n";
        if(numeros[i*2+1]!=0){
            cout << numeros[i] << ":C0->" << numeros[i*2+1] << ";\n";
        }
        if(numeros[i*2+2]!=0){
            cout << numeros[i] << ":C1->" << numeros[i*2+2] << ";\n";
        }
        preOrdenGraf(i * 2 + 1);
        preOrdenGraf(i * 2 + 2);
    }
}

void graficarAVL() {
    cout << "digraph G {\n";
    cout << "rankdir=TB;\n";
    cout << "node [shape = record, style=filled, fillcolor= lightsalmon];\n";
    preOrdenGraf(raiz);
    cout << "}\n";
}

void graficarvector() {
    cout << "digraph G {\n";
    cout << "rankdir=TB;\n";
    cout << "node [shape = record, style=filled, fillcolor= lightsalmon];\n";
    cout << "vector[label= \"";
    for(int i = 0; i < 60; i++){
        cout << numeros[i] << "|";
    }
    cout << "\"];\n";
    cout << "}\n";
}

bool buscar(int i, int valor) {
    if (numeros[i] != 0) {
        if (numeros[i] == valor) {
            return true;
        } else {
            if (valor < numeros[i]) {
                return buscar(i * 2 + 1, valor);
            } else if (valor > numeros[i]) {
                return buscar(i * 2 + 2, valor);
            }
        }
    }
    return false;
}

int main(int argc, char** argv) {
    int entrada[] = {5, 10, 96, 30, 2, 63, 85, 47, 20, 3, 4, 19};
    for (int i = 0; i < 12; i++) {
        insertame(entrada[i]);
    }
    
    cout<<"RECORRIDO EN ORDEN"<<endl;
    preOrden(raiz);
    cout<<"IMAGEN AVL"<<endl;
    graficarAVL();
    cout<<"IMAGEN VECTOR"<<endl;
    graficarvector();    
    return 0;
}
