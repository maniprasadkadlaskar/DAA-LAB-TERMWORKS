#include<stdio.h>

int min (int a , int b) {
    return (a < b) ? a : b;
}

void printArray (int n , int D[][n]) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            printf("%d " , D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void floyd (int n , int D[][n]) {
    printf("D[%d] : \n" , 0);
    printArray(n , D);
    
    for (int k = 0;k < n;k++) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                D[i][j] = min(D[i][j] , (D[k][j] + D[i][k]));
            }
        }
        printf("D[%d] : \n" , k + 1);
        printArray(n , D);
    }
}

void main () {
    int n;
    printf("Enter size : ");
    scanf("%d" , &n);

    int D[n][n];
    printf("Enter weights \n");
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            scanf("%d" , &D[i][j]);
        }
    }

    floyd(n , D);
}