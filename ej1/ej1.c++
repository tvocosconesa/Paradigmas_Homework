#include "ej1.h"


int ** create_matrix(int n){ 
    int value = 1;

    int ** matrix = new int*[n];   // creo la matriz
    for (int i = 0; i < n ; i++){
        matrix[i] = new int[n];
        
        for (int j = 0 ; j < n ; j++){          //inserto los valores en la matriz
            matrix[i][j] = value;
            value ++ ;
        }

    }
    return matrix;
}

void print_matrix(int ** matrix, int n){
    for (int i = (n*n)-1; i >= 0 ; i--){          // recorro la matriz de atras para adelante 
        
        cout << '[' << i/n << "][" << i%n << "] = " << matrix[i/n][i%n] << endl; // imprimo cada valor
    }
}

void delete_matrix(int** matrix, int n) {
    
    for (int i = 0; i < n; i++) {   // borro los arrays de la matriz
        delete[] matrix[i];
    }
    delete[] matrix;                // borro la matriz 
}

int main(){

    int n;
    cout << "Insert a value n for the nxn Matrix:  ";
    cin >> n;

    int ** matrix = create_matrix(n);
    print_matrix(matrix,n);
    delete_matrix(matrix,n);
}