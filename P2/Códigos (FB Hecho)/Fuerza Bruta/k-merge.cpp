#include <vector>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <chrono>

using namespace std::chrono;
using namespace std;

void inicializar(vector<vector<int> > &conjunto_vectores, int n) {
    srand(0);

    int num_vectores = n;//(1+rand())%10;
    int tam_vector;

    for (int i = 0 ; i < num_vectores; i++) {
        tam_vector = 5;//(1+rand())%100;

        vector <int> v(tam_vector);
        generate(v.begin(), v.end(), []() {
            return rand() % 1000;
        });

        conjunto_vectores.push_back(v);
    }

    for(int t = 0; t < num_vectores; t++) {
        sort (conjunto_vectores[t].begin(), conjunto_vectores[t].end());
    }
}

vector<int> SortedMerge(vector<int> a, vector<int> b) {

    int i = 0,j = 0;

    vector <int> out_array;
    out_array.resize(a.size() + b.size());

    while((i < a.size()) && (j < b.size())) {

        if(a[i] >= b[j]) {
            out_array[i+j] = b[j];
            j++;

        } else {
            out_array[i+j] = a[i];
            i++;
        }
    }

    while(i < a.size()) {
        //copy the reminder
        out_array[i+j] = a[i];
        i++;
    }

    while( j < b.size()) {
        out_array[i+j] = b[j];
        j++;
    }

    return out_array;
}


vector<int>  mergeKVectors(vector<vector<int> > &arr) {
    int last = arr.size()-1;

    // Repetir hasta que nos quede un unico vector
    while (last != 0) {
        int i = 0, j = last;

        // (i, j) forms a pair
        while (i < j) {
            
            vector<int> aux = SortedMerge(arr.at(i), arr.at(j));

            arr.at(i) = aux;

            // pasamos al siguiente par de vectores
            i++, j--;

            // Si todos los vectores estan fusionados, actualizamos last
            if (i >= j)
                last = j;
        }
    }

    return arr.at(0);
}




int main(int argc, char * argv[]) {
    vector<vector<int> > conjunto_vectores;
    int n = atoi(argv[1]);

    inicializar(conjunto_vectores,n);

    /*cerr << "INI" << endl;
    cout << "Conjunto de vectores: \n";
    for(vector<int> i: conjunto_vectores) {
        cout << " ---> ";
        for(int j :i ) {
            cout << setw(4) << j ;
        }
        cout << endl << endl;
    }*/

    high_resolution_clock::time_point tantes, tdespues;
    duration<double> transcurrido;
    tantes = high_resolution_clock::now();

    vector<int> test = mergeKVectors(conjunto_vectores);

    tdespues = high_resolution_clock::now();
    transcurrido = duration_cast<duration<double>>(tdespues - tantes);
    cout << n <<" "<< transcurrido.count()<< endl;

   /* cout << "\nResultado: "<< endl;
    cout << " ---> ";

    for(int i: test) {
        cout << setw(4) << i;
    }
    cout << endl;*/
}