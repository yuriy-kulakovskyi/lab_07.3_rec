#include <iostream>
#include <iomanip>
#include "../include/main.h"

using namespace std;

int main() {
  int n;
  cout << "Введіть розмірність матриці (n x n): ";
  cin >> n;

  int** matrix = new int*[n];
  int** result = new int*[n];
  for (int i = 0; i < n; ++i) {
    matrix[i] = new int[n];
    result[i] = new int[n];
  }

  cout << "Введіть елементи матриці:\n";
  inputMatrix(matrix, n, 0, 0);

  smoothMatrix(matrix, result, n, 0, 0);

  cout << "Згладжена матриця:\n";
  printMatrix(result, n, 0, 0);

  int sum = sumBelowDiagonal(result, n, 1, 0, 0);
  cout << "Сума модулів елементів нижче головної діагоналі: " << sum << endl;

  for (int i = 0; i < n; ++i) {
    delete[] matrix[i];
    delete[] result[i];
  }
  delete[] matrix;
  delete[] result;

  return 0;
}
