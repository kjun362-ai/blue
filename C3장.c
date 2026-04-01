#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    char playerBoard[SIZE][SIZE];
    char computerBoard[SIZE][SIZE];
    char playerView[SIZE][SIZE]; // 플레이어가 보는 컴퓨터의 바다 (가려진 판)

    // 선박의 식별자(문자)를 저장할 포인터 변수들
    char s1 = '4', s2 = '3', s3 = '2';
    char *ships[3] = {&s1, &s2, &s3};
    int shipSizes[3] = {4, 3, 2};

    // 보드 초기화 ('~'는 바다를 의미)
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            playerBoard[i][j] = computerBoard[i][j] = playerView[i][j] = '~';
        }
    }

    srand(time(NULL)); // 난수 초기화
    for(int i = 0; i < 3; i++) {
        int x, y, dir;
        printf("\n크기 %d인 배를 배치합니다. (현재 문자: %c)\n", shipSizes[i], *ships[i]);
        printf("좌표(행 열)와 방향(0:가로, 1:세로) 입력: ");
        scanf("%d %d %d", &x, &y, &dir);

        // 배치 가능 여부 체크 (경계 및 중복)
        int possible = 1;
        for(int j = 0; j < shipSizes[i]; j++) {
            int nx = x + (dir == 1 ? j : 0);
            int ny = y + (dir == 0 ? j : 0);

            if(nx >= SIZE || ny >= SIZE || playerBoard[nx][ny] != '~') {
                possible = 0; break;
            }
        }

        if(possible) {
            for(int j = 0; j < shipSizes[i]; j++) {
                int nx = x + (dir == 1 ? j : 0);
                int ny = y + (dir == 0 ? j : 0);
                playerBoard[nx][ny] = *ships[i]; // 포인터가 가리키는 문자 저장
            }
        } else {
            printf("잘못된 공간이거나 배가 겹칩니다! 다시 입력하세요.\n");
            i--; // 재입력을 위해 인덱스 감소
        }
        int playerHits = 0, computerHits = 0;
        int totalShipCells = 4 + 3 + 2;

        // 게임 루프: 모든 배가 파괴될 때까지
        for (; playerHits < totalShipCells && computerHits < totalShipCells; ) {
            // 1. 플레이어 차례
            int ax, ay;
            printf("\n공격 좌표 입력(행 열): ");
            scanf("%d %d", &ax, &ay);

            if (computerBoard[ax][ay] != '~' && computerBoard[ax][ay] != 'X') {
                printf("명중!\n");
                computerBoard[ax][ay] = 'X'; // 명중 표시
                playerHits++;
            } else {
                printf("풍덩!\n");
            }

            // 2. 컴퓨터 차례 (이중 for문을 이용한 공격 시뮬레이션 예시)
            int attacked = 0;
            for (int i = 0; i < 1 && !attacked; i++) { // 공격 기회 한 번
                for (int j = 0; j < 1; j++) {
                    int cx = rand() % SIZE;
                    int cy = rand() % SIZE;

                    printf("컴퓨터가 (%d, %d)를 공격합니다.\n", cx, cy);
                    if (playerBoard[cx][cy] != '~' && playerBoard[cx][cy] != 'X') {
                        printf("컴퓨터 명중!\n");
                        playerBoard[cx][cy] = 'X';
                        computerHits++;
                    } else {
                        printf("컴퓨터 빗나감!\n");
                    }
                    attacked = 1; // 한 번 수행 후 탈출
                }
            }

            // 현재 상황 출력 (보드 띄우기)
            // ... (중략: playerView와 playerBoard를 화면에 출력하는 코드)
        }

        if (playerHits == totalShipCells) printf("플레이어 승리!\n");
        else printf("컴퓨터 승리!\n");
    }
    int playerHits = 0, computerHits = 0;
    int totalShipCells = 4 + 3 + 2;

    // 게임 루프: 모든 배가 파괴될 때까지
    for (; playerHits < totalShipCells && computerHits < totalShipCells; ) {
        // 1. 플레이어 차례
        int ax, ay;
        printf("\n공격 좌표 입력(행 열): ");
        scanf("%d %d", &ax, &ay);

        if (computerBoard[ax][ay] != '~' && computerBoard[ax][ay] != 'X') {
            printf("명중!\n");
            computerBoard[ax][ay] = 'X'; // 명중 표시
            playerHits++;
        } else {
            printf("풍덩!\n");
        }

        // 2. 컴퓨터 차례 (이중 for문을 이용한 공격 시뮬레이션 예시)
        int attacked = 0;
        for (int i = 0; i < 1 && !attacked; i++) { // 공격 기회 한 번
            for (int j = 0; j < 1; j++) {
                int cx = rand() % SIZE;
                int cy = rand() % SIZE;

                printf("컴퓨터가 (%d, %d)를 공격합니다.\n", cx, cy);
                if (playerBoard[cx][cy] != '~' && playerBoard[cx][cy] != 'X') {
                    printf("컴퓨터 명중!\n");
                    playerBoard[cx][cy] = 'X';
                    computerHits++;
                } else {
                    printf("컴퓨터 빗나감!\n");
                }
                attacked = 1; // 한 번 수행 후 탈출
            }
        }

        // 현재 상황 출력 (보드 띄우기)
        // ... (중략: playerView와 playerBoard를 화면에 출력하는 코드)
    }

    if (playerHits == totalShipCells) printf("플레이어 승리!\n");
    else printf("컴퓨터 승리!\n");
}