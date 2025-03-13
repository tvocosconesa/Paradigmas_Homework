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
    for (int i = 0; i < n ; i++){
        
    }
}

void deleteMatrix(int** matrix, int n) {
    
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

main(){

    int n;
    cout << "Ingrrse el valor N para la matriz";
    cin >> n;

    int ** matrix = create_matrix(n);

    deleteMatrix(matrix,n);
}