#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray (int A[] , int n) {
    for(int i = 0; i < n;i++)
        printf("%d " , A[i]);
    printf("\n");
}

void merge (int A[] , int lb , int ub , int mid) {
    int i = lb , j = mid + 1;
    int k = lb;
    int B[ub + 1];

    while (i <= mid && j <= ub) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        }
        else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        B[k] = A[i];
        i++; k++;
    }

    while (j <= ub) {
        B[k] = A[j];
        j++; k++;
    }

    for(i = lb;i <= ub;i++) {
        A[i] = B[i];
    }
}

void mergeSort (int A[] , int lb , int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;

        mergeSort(A , lb , mid);
        mergeSort(A , mid + 1 , ub);
        merge(A , lb , ub , mid);
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
    for (int i = 0;i < 10000;i++)
        mergeSort(A , 0 , n - 1);
    
    e = clock();
    exe_t = (double) (e - s) / CLK_TCK;

    printf("After Sort \n");
    printArray(A , n);

    printf("\n Execution time : %lf" , exe_t);
}