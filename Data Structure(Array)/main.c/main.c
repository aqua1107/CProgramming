#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int capacity = 10;  // 현재 방 크기
    int size = 0;      // 현재 들어온 손님 수c

    // 1. 초기 방 계약 (10개)
    arr = (int*)malloc(sizeof(int) * capacity);

    for (int i = 0; i < 100; i++) {
        // ★ 핵심: 방이 꽉 찼는지 검사
        if (size == capacity) {
            printf("[알림] 방이 꽉 찼습니다 (%d개). 이사 갑니다!\n", capacity);

            // 2. 더 큰 방 계약 (보통 2배씩 늘림)
            capacity *= 2;

            // 3. realloc: 기존 데이터를 들고 큰 방으로 이사함
            // (기존 방은 알아서 free 해주고, 새 방 주소를 리턴함)
            int *new_arr = (int*)realloc(arr, sizeof(int) * capacity);

            if (new_arr == NULL) {
                printf("메모리 부족으로 이사 실패!\n");
                free(arr); // 기존 방이라도 빼고 종료
                return 1;
            }
            arr = new_arr; // 새 주소 갱신
        }

        // 데이터 입주
        arr[size] = i;
        size++;
    }

    // 결과 확인
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n[성공] 총 %d명 입주 완료. 최종 방 크기: %d\n", size, capacity);

    free(arr);
    return 0;
}
