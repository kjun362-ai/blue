#include<stdio.h>


int main() {

    int a, b, c, d;
    char n;


    printf("부호를 입력하세요:");
    scanf("%c", &n);

    if (n == '+') {
        printf("연산 할 4개까지의 수를 입력하세요:");
        scanf("%d %d %d %d", &a, &b, &c, &d);

        printf("%d", a+ b+ c+d);
    }
            if (n == '-') {
                printf("연산 할 4개까지의 수를 입력하세요:");
                scanf("%d %d %d %d", &a, &b, &c, &d);

                printf("%d", a - b - c -d);
            }
                if (n == '*') {
                    printf("연산 할 4개까지의 수를 입력하세요:");
                    scanf("%d %d %d %d", &a, &b, &c, &d);

                    printf("%d", a* b*c*d);
                }
                    if (n == '/') {
                        printf("연산 할 4개까지의 수를 입력하세요:");
                        scanf("%d %d %d %d", &a, &b, &c, &d);

                        printf("%d", a/b/c/d);
                    }










    return 0;


}