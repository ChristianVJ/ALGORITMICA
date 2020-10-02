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
		if (k<1 || n<1){
			cout << "tamaño incorrecto" << endl;
			return -1;
		}

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


int numero;
vector<int> res;

// Matriz en un vector
tantes = high_resolution_clock::now();
////////////////////////////////////////////////////////////

	for (int j=0; j<n; j++){
	  numero = T[0][j];
	  res.push_back(numero);
	  }
if (k>1){
	for (int fil=1; fil < k; fil ++){
		int i=0, j=0;
		vector<int> aux;

		while(i < res.size() && j < n){
			if(res.at(i) < T[fil][j]){
				aux.push_back(res.at(i));
				i++;
			}
			else{
				aux.push_back(T[fil][j]);
				j++;
			}
		}
	
		if (i>=res.size()){
			for(int p=j; p < n; p++){
				aux.push_back(T[fil][p]);
			}
		}

		if (j>=n){
			for(int p=i; p < res.size(); p++){
				aux.push_back(res.at(p));
			}
		}
		res = aux;
	}
}

////////////////////////////////////////////////////////////
tdespues = high_resolution_clock::now();
//for (int i=0; i < res.size(); i++)
	//cout << res.at(i) << " ";
transcurrido = duration_cast<duration<double>>(tdespues - tantes);
cout <<  n <<"x"<< k <<" "<< transcurrido.count() << endl;

}
