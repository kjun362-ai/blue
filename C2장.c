#include <stdio.h>

int main() {

    int n, i;
    char c = '*';

    scanf("%d", &n);

        for (int a = 0;a < n; a++) {// n = 3

            // a = 1
            for ( i = 0;i <= a; i++) {

                printf("%c", c);
            }
            printf("\n");

            if (a == n-1) {// 3

                for (i = a-1 ;i > 0; i--) {

                     for (int v = i;v >= 0; v--) {
                         printf("%c", c);
                     }printf("\n");
                    }
                printf("*");
            }

        }

    return 0;
}




