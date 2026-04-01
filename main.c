#include <stdio.h>

 int main() {
    int a = 10;
    int b = 20;
    int *ptr = &b;
     char c = 'dkdid'; //<- 1바이트 즉 한 글자만 헤당하므로 맨 마지막 d가 변수 c에 들어감
     char *ppr= "안녕하세요"; //<- 안녕하세요를 1바이트 안에 저장할 수 없으므로 "안"의 주소를 저장 (%p로 주소를 출력하던가, %s로 문자열 전체를 출력가능)

    printf("%p\n", ptr);
    printf("%d\n", *ptr);
    printf("%p\n", ppr);
     printf("%s\n", ppr);
   printf("%c\n", c);

    return 0;
}