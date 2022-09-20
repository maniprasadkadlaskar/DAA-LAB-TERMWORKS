#include<stdio.h>

void dijkstras (int s , int n , int D[][n]) {
    int visited[n] , dist[n];

    for (int i = 0;i < n;i++) {
        visited[i] = 0;
        dist[i] = 999;
    }

    int count = 0;
    dist[s] = 0;
    int u;

    while (count < n) {
        
        int min = 999;
        for (int j = 0;j < n;j++) {
            if (visited[j] == 0 && min > dist[j]) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;
        count++;

        for(int j = 0;j < n;j++) {
            if(visited[j] == 0 && (dist[u] + D[u][j]) < dist[j]) {
                dist[j] = dist[u] + D[u][j];
            }
        }
    }

    for(int i = 0;i < n;i++) {
        printf("%d -> %d = %d \n" , s , i , dist[i]);
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

    dijkstras(0 , n , D);
}