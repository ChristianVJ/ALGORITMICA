#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <fstream>
//#include <algorithm>
#include <vector>
#include <chrono>


using namespace std::chrono;
high_resolution_clock::time_point tantes, tdespues;
duration<double> transcurrido;

//generador de ejemplor para el problema de mezcla de k vectores ordenados. Para obtener k vectores ordenados de forma creciente cada uno con n elementos, genera un vector de tamaño k*n con todos los enteros entre 0 y kn-1 ordenados. Se lanzan entonces k iteraciones de un algoritmo de muestreo aleatorio de tamaño n para obtener los k vectores. Están ordeados porque el algoritmo de muestreo mantiene el orden

double uniforme() //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C. 
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}


int main(int argc, char * argv[])
{

        if (argc != 2)
        {
                cerr << "Formato " << argv[0] << "<ruta_del_archivo_de_entrada>" << endl;
                return -1;
        }


        int n;
        int k=n;
        int a=0;
        int num;
        string ruta=argv[1];
        ifstream archivo(ruta);

//Leemos k y n

        archivo >> k;
        archivo >> n;

int **T;
T =  new int * [k];
  assert(T);

 for (int i = 0; i < k; i++)
      T[i]= new int [n];

        for (int j=0; j<k; j++) { //Recorremos los k vectores
                //Leemos los datos del vector k-esimo
                for (int i=0; i<n; i++) {
                        archivo >> a;
                        T[j][i]=a;
                }
}

tantes = high_resolution_clock::now();
////////////////////////////////////////////////////////////

int numero;
vector<int> res;

// Matriz en un vector

for (int i=0; i<k; i++) {
 for (int j=0; j<n; j++){
  numero = T[i][j];
  res.push_back(numero);
  }
}

if (k>=2){
// Burbuja

 for(int i=0;i<res.size()-1;i++)
    for (int j=i+1; j<res.size(); j++)
      if(res.at(i) > res.at(j)){
        numero=res.at(i);
        res.at(i) = res.at(j);
        res.at(j) = numero;
      }
}

////////////////////////////////////////////////////////////
tdespues = high_resolution_clock::now();
transcurrido = duration_cast<duration<double>>(tdespues - tantes);
cout <<  n << " "<< transcurrido.count() << endl;

}
