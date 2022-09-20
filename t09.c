#include<stdio.h>
#define max 10
int s[10];
int v[10];
int sum;

int isPromising (int i , int w , int total) {
    return ((w + total) >= sum && (w == sum || w + s[i + 1] <= sum));
}

void subSet (int i , int w , int total) {
    if (isPromising(i , w , total)) {
        if (w == sum) {
            for(int j = 0;j <= i;j++)
                if (v[j] == 1)
                    printf(" %d " , s[j]);
            printf("\n");
        }
        else {
            v[i + 1] = 1;
            subSet (i + 1 , w + s[i + 1] , total - s[i + 1]);
            v[i + 1] = 0;
            subSet (i + 1 , w , total - s[i + 1]);
        }
    }
}

void main () {
    int n;
    printf("Enter size : ");
    scanf("%d" , &n);

    int total = 0;
    printf("Enter set elements : ");
    for(int i = 0;i < n;i++) {
        scanf("%d" , &s[i]);
        total += s[i];
    }

    printf("Enter sum : ");
    scanf("%d" , &sum);

    for(int i = 0;i < n - 1;i++) {
        for(int j = 0;j < n - i - 1;j++) {
            if (s[j] > s[j + 1]) {
                int t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }

    printf("After sorting \n");
    for(int i = 0;i < n;i++) {
        v[i] = 0;
        printf("%d " , s[i]);
    }
    printf("\n");

    subSet(-1 , 0 , total);
}