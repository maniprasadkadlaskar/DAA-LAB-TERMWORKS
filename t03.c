#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray (int A[] , int n) {
    for(int i = 0; i < n;i++)
        printf("%d " , A[i]);
    printf("\n");
}

void insertionSort (int A[] , int n) {
    for (int i = 1;i < n;i++) {
        int temp = A[i] , j = i - 1;

        while (j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = temp;
    }
}

void main () {
    int n;
    printf("Enter size : ");
    scanf("%d" , &n);

    int A[n];
    for(int i = 0;i < n;i++) {
        A[i] = rand() % 100;
    }

    printf("Before Sort \n");
    printArray(A , n);

    clock_t s , e;
    double exe_t;

    s = clock();
    for (int i = 0;i < 100000;i++)
        insertionSort(A , n);
    
    e = clock();
    exe_t = (double) (e - s) / CLK_TCK;

    printf("After Sort \n");
    printArray(A , n);

    printf("\n Execution time : %lf" , exe_t);
}