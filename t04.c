#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap (int A[] , int i , int j) {
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

void printArray (int A[] , int n) {
    for(int i = 0; i < n;i++)
        printf("%d " , A[i]);
    printf("\n");
}

void heapify (int A[] , int i , int n) {
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && A[large] < A[l])
        large = l;

    if (r < n && A[large] < A[r])
        large = r;

    if (large != i) {
        swap(A , large , i);
        heapify(A , large , n);
    }
}

void heapSort (int A[] , int n) {
    for (int i = n / 2 - 1;i >= 0;i--) {
        heapify(A , i , n);
    }

    for (int i = n - 1;i >= 0;i--) {
        swap(A , 0 , i);
        heapify(A , 0 , i);
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
    for (int i = 0;i < 1000;i++)
        heapSort(A , n);
    
    e = clock();
    exe_t = (double) (e - s) / CLK_TCK;

    printf("After Sort \n");
    printArray(A , n);

    printf("\n Execution time : %lf" , exe_t);
}