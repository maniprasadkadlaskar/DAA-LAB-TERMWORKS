#include<stdio.h>

void prims (int n , int D[][n]) {
    int visited[n];

    for (int i = 0;i < n;i++) {
        visited[i] = 0;
    }

    int minCost = 0;
    int ne = 0;
    visited[0] = 1;

    while (ne < n - 1) {
        int min = 999;
        int u , v;

        for (int i = 0;i < n;i++) {
            if (visited[i] == 1) {
                for (int j = 0;j < n;j++) {
                    if (visited[j] == 0 && min > D[i][j]) {
                        min = D[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d = %d \n" , u , v , min);
        minCost += min;
        visited[v] = 1;
        ne++;
    }

    printf("Minimum cost : %d" , minCost);
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

    prims(n , D);
}    