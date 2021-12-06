#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
double rand_double(int, int);
double** generate_matrix(int, int);
void display_matrix(double**, int, int);
void find_min_column(double**, int, int);

int main() {
    int m, n;
    double **matrix;
    srand(time(NULL));
    cout << "Enter the number of rows in the matrix: ";
    cin >> m;
    cout << "Enter the number of columns in the matrix: ";
    cin >> n;
    matrix = generate_matrix(m, n);
    cout << "Generated matrix:\n";
    display_matrix(matrix, m, n);
    find_min_column(matrix, m, n);
    cout << "Swapped matrix:\n";
    display_matrix(matrix, m, n);
    return 0;
}

double rand_double(int min, int max) {
    double fraction, rnd_max, result;
    rnd_max = rand()%(max + 1);
    fraction = (double)rnd_max / max;
    result = min + rand()%(max-min) + fraction;
    return result;
}

double** generate_matrix(int rows, int columns) {
    double **matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rand_double(0, 10);
        }
    }
    return matrix;
}

void display_matrix(double** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << setw(8) << matrix[i][j];
        }
        cout << "\n";
    }
}

void find_min_column(double **matrix, int rows, int columns)  {
    double temp_num;
    int index;
    for (int j = 0; j < columns; j++) {
        temp_num = matrix[0][j];
        index = 0;
        for (int i = 0; i < rows; i++) {
            if (temp_num > matrix[i][j]) {
                temp_num = matrix[i][j];
                index = i;
            }
        }
        matrix[index][j] = matrix[0][j];
        matrix[0][j] = temp_num;
    }
}