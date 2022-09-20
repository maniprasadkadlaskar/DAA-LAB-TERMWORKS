#include<stdio.h>
#include<stdlib.h>

int count = 0;
int v[10];

int isPlace (int k) {
    for(int i = 1;i < k;i++) {
        if (v[i] == v[k] || abs(v[i] - v[k]) == abs(i - k)) {
            return 0;
        }
    }
    return 1;
}

void printSol (int n) {
    count++;

    printf("Solution - %d \n" , count);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if (v[i] == j) {
                printf(" Q ");
            }
            else {
                printf(" _ ");
            }
        }
        printf("\n");
    }

    printf("\n");
}

void nQueen (int n) {
    int k = 1;
    v[k] = 0;

    while (k > 0) {
        v[k] += 1;
        while (v[k] <= n && isPlace(k) == 0) {
            v[k]++;
        }

        if(v[k] <= n) {
            if(k == n) {
                printSol(n);
            }
            else {
                k++;
                v[k] = 0;
            }
        }
        else {
            k--;
        }
    }

}

void main () {
    int n;
    printf("Enter queens : ");
    scanf("%d" , &n);

    nQueen (n);
}