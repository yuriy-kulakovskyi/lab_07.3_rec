#ifndef MAIN_H
#define MAIN_H

void smoothElement(int** matrix, int** result, int n, int i, int j, int currentRow, int currentCol, int sum, int count);
void smoothMatrix(int** matrix, int** result, int n, int i, int j);
int sumBelowDiagonal(int** matrix, int n, int i, int j, int sum);
void printMatrix(int** matrix, int n, int i, int j);
void inputMatrix(int** matrix, int n, int i, int j);

#endif //MAIN_H
