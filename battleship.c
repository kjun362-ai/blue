#include <stdio.h>

int main() {

    int playerBoard[5][5] = {0,};
    int cpuBoard[5][5] = {0,};


    int r, c, p_hits = 0, c_hits = 0, placed = 0;
    int c_r = 0, c_c = 0;

    printf("====  당신의 배(2칸)를 배치하세요 ====\n");
    while (placed < 2) {
        printf("%d번째 칸 좌표(행 열): ", placed + 1);
        if (scanf("%d %d", &r, &c) != 2 || r < 0 || r > 4 || c < 0 || c > 4) {
            printf("[오류] 0~4 사이 숫자를 입력하세요.\n");
            while (getchar() != '\n'); continue;
        }
        if (playerBoard[r][c] == 1) printf("[오류] 이미 배가 있습니다.\n");
        else { playerBoard[r][c] = 1; placed++; }
    }
    printf("\n==== 게임 시작! ====\n");

    while (p_hits < 2 && c_hits < 2) {
        printf("\n[컴퓨터의 보드 상태]\n  0 1 2 3 4\n");
        for (int i = 0; i < 5; i++) {
            printf("%d ", i);
            for (int j = 0; j < 5; j++) {
                if (cpuBoard[i][j] == 2) printf("X ");
                else if (cpuBoard[i][j] == 3) printf("O ");
                else printf("~ ");
            }
            printf("\n");
        }

        printf("\n어디를 공격하시겠습니까? (행 열): ");
        if (scanf("%d %d", &r, &c) != 2 || r < 0 || r > 4 || c < 0 || c > 4) {
            printf("좌표 오류! 기회를 날렸습니다.\n");
            while (getchar() != '\n');
        } else {
            if (cpuBoard[r][c] == 1) { printf(">> 명중! \n"); cpuBoard[r][c] = 2; p_hits++; }
            else { printf(">> 꽝! \n"); cpuBoard[r][c] = 3; }
        }
    }


}
