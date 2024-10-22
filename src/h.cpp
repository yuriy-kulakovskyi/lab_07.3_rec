#include "../include/main.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

void smoothElement(int** matrix, int** result, int n, int i, int j, int currentRow, int currentCol, int sum, int count) {
  if (currentRow > i + 1 || currentCol > j + 1) {
    result[i][j] = sum / count;
    return;
  }

  if (currentRow >= 0 && currentRow < n && currentCol >= 0 && currentCol < n) {
    sum += matrix[currentRow][currentCol];
    count++;
  }

  if (currentCol < j + 1) {
    smoothElement(matrix, result, n, i, j, currentRow, currentCol + 1, sum, count);
  } else {
    smoothElement(matrix, result, n, i, j, currentRow + 1, j - 1, sum, count);
  }
}

void smoothMatrix(int** matrix, int** result, int n, int i, int j) {
  if (i >= n) {
    return;
  }
  if (j >= n) {
    smoothMatrix(matrix, result, n, i + 1, 0);
  } else {
    smoothElement(matrix, result, n, i, j, 0, 0, 0, 0);
    smoothMatrix(matrix, result, n, i, j + 1);
  }
}

int sumBelowDiagonal(int** matrix, int n, int i, int j, int sum) {
  if (i >= n) {
    return sum;
  }
  if (j >= i) {
    return sumBelowDiagonal(matrix, n, i + 1, 0, sum);
  } else {
    sum += abs(matrix[i][j]);
    return sumBelowDiagonal(matrix, n, i, j + 1, sum);
  }
}

void printMatrix(int** matrix, int n, int i, int j) {
  if (i == n) return;

  cout << setw(4) << matrix[i][j];

  if (j + 1 < n) {
    printMatrix(matrix, n, i, j + 1);
  } else {
    cout << endl;
    printMatrix(matrix, n, i + 1, 0);
  }
}

void inputMatrix(int** matrix, int n, int i, int j) {
  if (i >= n) return;
  if (j >= n) {
    inputMatrix(matrix, n, i + 1, 0);
  } else {
    cin >> matrix[i][j];
    inputMatrix(matrix, n, i, j + 1);
  }
}