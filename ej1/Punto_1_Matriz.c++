#include <iostream>
#include <vector>
#include <string>
using namespace std;


int ** create_matrix(int n){
    int value = 1;

    int ** matrix = new int*[n];
    for (int i = 0; i < n ; i++){
        matrix[i] = new int[n];
        
        for (int j = 0 ; j < n ; j++){
            matrix[i][j] = value;
            value ++ ;
        }

    }
    return matrix;
}

void print_matrix(int ** matrix, int n){
    for (int i = (n*n)-1; i >= 0 ; i--){
        
        cout << "[" + to_string(i/n) + "]["+ to_string(i%n) +"] = " <<matrix[i/n][i%n] << " ";
        
        cout << endl;
    }
}

void deleteMatrix(int** matrix, int n) {
    
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main(){

    int n;
    cout << "Ingrrse el valor N para la matriz:  ";
    cin >> n;

    int ** matrix = create_matrix(n);
    print_matrix(matrix,n);
    deleteMatrix(matrix,n);
}