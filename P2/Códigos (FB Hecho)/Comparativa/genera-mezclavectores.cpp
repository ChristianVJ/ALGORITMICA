#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
using namespace std;


//generador de ejemplor para el problema de mezcla de k vectores ordenados. Para obtener k vectores ordenados de forma creciente cada uno con n elementos, genera un vector de tama�o k*n con todos los enteros entre 0 y kn-1 ordenados. Se lanzan entonces k iteraciones de un algoritmo de muestreo aleatorio de tama�o n para obtener los k vectores. Est�n ordeados porque el algoritmo de muestreo mantiene el orden

double uniforme() //Genera un n�mero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

int main(int argc, char * argv[])
{

  if (argc != 3)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << " <num_vect>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);
  int k=atoi(argv[2]);


int **T;
T =  new int * [k];
  assert(T);

 for (int i = 0; i < k; i++)
      T[i]= new int [n];

int N=k*n;
int * aux = new int[N];
  assert(aux);

srand(time(0));
//genero todos los enteros entre 0 y k*n-1
for (int j=0; j<N; j++) aux[j]=j;

//para cada uno de los k vectores se lanza el algoritmo S (sampling) de Knuth
for (int i=0; i<k; i++) {
   int t=0;
   int m=0;
   while (m<n) {
    double u=uniforme();
    if ((N-t)*u >= (n-m)) t++;
    else {
        T[i][m]=aux[t];
	t++;
	m++;
    }
  }
}

delete [] aux;

cout<<"\nNumero de filas: "<<argv[2]<<" numero de columnas "<<argv[1]<<endl;

//Creamos el archivo de texto con los datos generados

std::string name = "mezcla" + std::to_string(n) +"x" + std::to_string(k) + ".txt";
std::ofstream salida(name, std::ios::out);

salida << argv[2] << " "<<argv[1]<<endl; //Filas y columnas


for (int i=0; i<k; i++) {
 for (int j=0; j<n; j++)
   salida << T[i][j] << " ";
 salida << " " << endl;
}

if (salida.is_open()){
  salida.close();
}

}
