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

int partition (int A[] , int lb , int ub) {
    int pivot = lb , i = lb , j = ub;

    while (i < j) {
        while (A[pivot] >= A[i]) {
            i++;
        }

        while (A[pivot] < A[j]) {
            j--;
        }

        if (i < j)
            swap(A , i , j);
    }
    swap(A , pivot , j);

    return j;
}

void quickSort (int A[] , int lb , int ub) {
    if (lb < ub) {
        int pivot = partition(A , lb , ub);

        quickSort(A , lb , pivot - 1);
        quickSort(A , pivot + 1 , ub);
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
    for (int i = 0;i < 1000000;i++)
        quickSort(A , 0 , n - 1);
    
    e = clock();
    exe_t = (double) (e - s) / CLK_TCK;

    printf("After Sort \n");
    printArray(A , n);

    printf("\n Execution time : %lf" , exe_t);
}