#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
int** generate_matrix(int, int);
void display_matrix(int**, int);
int* create_array(int**, int);
void display_array(int*, int);
void sort_descending(int*, int);
void delete_matrix(int**, int);

int main() {
    int n = 5;
    int** matrix;
    int* array;
    matrix = generate_matrix(n, n);
    cout << "Matrix:\n";
    display_matrix(matrix, n);
    array = create_array(matrix, n);
    cout << "Array:\n";
    display_array(array, n);
    sort_descending(array, n);
    cout << "Sorted array:\n";
    display_array(array, n);
    delete_matrix(matrix, n);
    delete[] array;
    return 0;
}

int** generate_matrix(int rows, int columns) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[columns];
    }
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; ++j) {
            arr[i][j] = rand()% 19 - 9;
        }
    }
    return arr;
}

void display_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout <<"\n";
    }
}

int* create_array(int** matrix, int size) {
    int k = 0;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] > 0) {
            array[k] = matrix[i][i];
            k++;
        }
    }
    return array;
}

void display_array(int* arr, int length) {
    int i = 0;
    while(arr[i] != 0 && i < length) {
        cout << arr[i] << " ";
        i++;
    }
    cout << "\n";
}

void sort_descending(int* arr, int length) {
    int temp_num;
    int i = 0, j;
    while(i < length - 1 && arr[i] != 0) {
        j = 0;
        while (j < length - 1 - i && arr[j] != 0) {
            if (arr[j+1] > arr[j]) {
                temp_num = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp_num;
            }
            j++;
        }
        i++;
    }
}

void delete_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
