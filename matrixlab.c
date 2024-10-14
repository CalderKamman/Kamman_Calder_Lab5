// Name: Calder Kamman
// KUID: 3123207

#include <stdio.h>
#define SIZE 5

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void trasposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int result[SIZE][SIZE]);

int main() {
    int m1[SIZE][SIZE];
    int m2[SIZE][SIZE];
    int result[SIZE][SIZE];
    int choice;

    printf("Enter elements for Matrix 1 (size %dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m1[i][j]);
        }
    }

    printf("\nEnter elements for Matrix 2 (size %dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m2[i][j]);
        }
    }

    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Multiply Matrices\n");
        printf("3. Transpose Matrix 1\n");
        printf("4. Transpose Matrix 2\n");
        printf("5. Print Matrix 1\n");
        printf("6. Print Matrix 2\n");
        printf("7. Exit\n");
        printf("Enter your choices: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMatrices(m1,m2,result);
                printf("\nSum of matrices:\n");
                printMatrix(result);
                break;
            case 2:
                multiplyMatrices(m1,m2,result);
                printf("\nProduct of matrices:\n");
                printMatrix(result);
                break;
            case 3:
                trasposeMatrix(m1,result);
                printf("\nTranspose of Matrix 1:\n");
                printMatrix(result);
                break;
            case 4:
                trasposeMatrix(m2,result);
                printf("\nTranspose of Matrix 2:\n");
                printMatrix(result);
                break;
            case 5:
                printf("\nMatrix 1:\n");
                printMatrix(m1);
                break;
            case 6:
                printf("\nMatrix 2:\n");
                printMatrix(m2);
                break;
            case 7:
                printf("Existing the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }  
    }
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) { 
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = m[i][j];
        }
    }
}

void printMatrix(int m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", m[i][j]);
        }
    }
}