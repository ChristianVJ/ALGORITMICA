#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std::chrono;
high_resolution_clock::time_point tantes, tdespues;
duration<double> transcurrido;

using namespace std;

void print(vector<vector<int>>v)
{
	for(int i = 0; i < v.size(); i++)
	{

		for (int j =0; j < v.at(0).size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

}

vector<vector<int>> merge(const vector<vector<int>> v1, const vector<vector<int>> v2){

	int i = 0,j = 0;
	int p;
	int cont=0;

	vector<vector<int>> vector_resultado; // "matriz" donde almacenar el merge

	vector_resultado.resize(1); //redimensionamos a una fila
	vector_resultado[0].resize(v1.at(0).size() + v2.at(0).size()); //tamaño v1 + tamaño v2


	//Meter números ordenados en el vector ordenado

	while(i < v1.at(0).size() && j < v2.at(0).size()){
		if(v1.at(0).at(i) < v2.at(0).at(j)){
			vector_resultado[0][cont] = v1.at(0).at(i);
			i++;
		}
		else{
			vector_resultado[0][cont] = v2.at(0).at(j);
			j++;
		}
		cont++;
	}

	//Terminar de introducir elementos

	if (i>=v1.at(0).size()){
		for(p=j; p < v2.at(0).size(); p++){
			vector_resultado[0][cont] = v2.at(0).at(p);
			cont++;
		}
	}

	if (j>=v2.at(0).size()){
		for(p=i; p < v1.at(0).size(); p++){
			vector_resultado[0][cont] = v1.at(0).at(p);
			cont++;
		}
	}

	return vector_resultado;
}


vector<vector<int>> dyv(vector<vector<int>> &vectores){

    // Caso base, el tamaño de la matriz es 1
    if (vectores.size() <= 1)
        return vectores;
  
    // En otro caso:

    int mitad = 0;

    // Calculamos la mitad de la matriz en filas

   	if(vectores.size()%2 == 0) mitad = vectores.size()/2; // Es una cantidad de filas par
   	else mitad = (vectores.size()/2) +1; // Es una cantidad de filas impar

    // Creamos las matrices de ambas mitades 

    vector<vector<int>> up;

    up.resize(mitad); // Filas que tendrá la nueva matriz
    for(int i = 0; i < mitad; i++) up[i].resize(vectores.at(0).size());

    vector<vector<int>> down;

    down.resize(vectores.size() - mitad); // Filas que tendrá la nueva matriz
    for(int i = 0; i < vectores.size() - mitad; i++) down[i].resize(vectores.at(0).size());

    // Rellenamos las nuevas matrices con los elementos de cada mitad
    for (int i = 0; i < mitad; i++)
		for (int j = 0; j < vectores.at(i).size(); j++)
			up[i][j] = vectores[i][j];

    for (int i = mitad; i < vectores.size(); i++)
		for (int j = 0; j < vectores.at(i).size(); j++)
			down[i - mitad][j] = vectores[i][j];

    // Llamada recursiva que divide la matrices creadas hasta llegar al caso base (un vector)
    up = dyv(up);
    down = dyv(down);

    // Almacenamos en un vector 
    vector<vector<int>>resultado;
    resultado.resize(1); 
    
    resultado = merge(up, down); // Mezclamos y ordenamos los vectores

    return resultado;
}


int main(int argc, char const *argv[]){

	if (argc != 2){
		cerr << "Formato " << argv[0] << "<ruta_del_archivo_de_entrada>" << endl;
		return -1;
    }

	int n; //Tamaño vectores
	int k = n;

	int num = 0;
	string ruta=argv[1];
	ifstream archivo(ruta);

	cout<<ruta<<endl;

	archivo >> k;
        archivo >> n;

        cout<< "\nK vectores "<<k << " de n elementos "<<n<<endl;

	vector<vector<int>> vector_sol;
	vector<vector<int>> vector_entrada;

	vector_sol.resize(k);
	vector_entrada.resize(k);

	for(int i = 0; i < k; i++){
		vector_sol[i].resize(n);
		vector_entrada[i].resize(n);
	}


	for(int i = 0; i < k; i++){
		for (int j = 0 ; j < n; j++){
		   archivo >> num;
		   vector_entrada[i][j] = num;
		}
	}


	tantes = high_resolution_clock::now();
	//////////////////////////////////////////
	vector_sol = dyv(vector_entrada);
	//////////////////////////////////////////
	tdespues = high_resolution_clock::now();
	transcurrido = duration_cast<duration<double>>(tdespues - tantes);
	cout <<  n << " "<< transcurrido.count() << endl;
	

	/*for (int i=0; i < vector_sol.at(0).size(); i++) cout << vector_sol[0][i] << " ";
	cout << endl;*/

}
