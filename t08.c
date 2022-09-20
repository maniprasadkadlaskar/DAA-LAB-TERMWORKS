#include<stdio.h>

int max (int a , int b) {
    return (a > b) ? a : b;
}

void main () {
    int n;
    printf("Enter size : ");
    scanf("%d" , &n);

    int w[n + 1] , v[n + 1];

    printf("Enter weights : \n");
    for(int i = 1;i <= n;i++) {
        scanf("%d" , &w[i]);
    }

    printf("Enter values : \n");
    for(int i = 1;i <= n;i++) {
        scanf("%d" , &v[i]);
    }

    int c;
    printf("Enter capacity : ");
    scanf("%d" , &c);

    int M[n + 1][c + 1];

    for(int i = 0;i < n + 1;i++) {
        for(int j = 0;j < c + 1;j++) {
            M[i][j] = 0;
        }
    }

    for(int i = 1;i < n + 1;i++) {
        for(int j = 1;j < c + 1;j++) {
            if (j - w[i] < 0) {
                M[i][j] = M[i - 1][j];
            }
            else {
                M[i][j] = max (M[i - 1][j] , (v[i] + M[i - 1][j - w[i]]));
            }
        }
    }

    printf("Maximum profit : %d \n" , M[n][c]);

    int i = n;
    int j = c;
    int item[n + 1];

    while (j > 0 && i > 0) {
        if (M[i][j] != M[i - 1][j]) {
            item[i] = 1;
            j = j - w[i];
        }
        else {
            item[i] = 0;
        }
        i = i - 1;
    }

    printf("Items \n");
    for(i = 1;i < n + 1;i++) {
        if (item[i] == 1)
            printf("%d \n" , i);
    }
}