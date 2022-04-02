#include <random>
#include <iostream>
#include <cmath>
#include <math.h>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int cant_elem = 20000;
    int dim = 100;
    int** set = new int*[cant_elem];
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

    uniform_real_distribution<> dis(1, 100);

    for (int i = 0; i < cant_elem; i++) {
        set[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            set[i][j] = dis(gen);
        }
    }

    int result[600];
    for (int i = 0; i < 600; i++) {
        result[i] = 0;
    }

    int suma = 0;
    for (int i = 0; i < cant_elem; i++) {
        suma = 0;
        for (int j = 0; j < dim; j++) {
            suma += pow(set[0][j] - set[i][j], 2);
        }
        result[int(sqrt(suma))]++;
    }
    
    for (int i = 0; i < 600; i++) {
        cout << i << ' ' << result[i] << endl;
    }
    ofstream file;
    string nombre = "100Dim";
    string direccion = "D://Programacion//EDA//";
    direccion.append(nombre);
    direccion.append(".csv");
    file.open(direccion, ios::out);

    for (int i = 0; i < 600; i++) {
        if (result[i] != 0) {
            file << i << "," << result[i]<<",\n";
        }
    }
    file.close();   //Se cierra el file
    /*
    int dist[100];
    for (int i = 0; i < 20000; i++) {
        dist[i] = sqrt(pow(*set[0] - *set[i], 2));
    }
    cout << *set[0] << ' ' << *set[105] << '\n';
    cout << dist[105];*/
}