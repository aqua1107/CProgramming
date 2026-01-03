#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL; // 첫 번째 노드 (기관차)
    Node* tail = NULL; // 마지막 노드 (꼬리) - ★여기가 핵심!

    int n = 100; // 만들 노드 개수

    printf("[생성] %d개의 노드를 자동으로 연결합니다...\n", n);

    for (int i = 0; i < n; i++) {
        // 1. 새 노드(객차) 생성 (Malloc)
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = i;      // 데이터 입력 (0, 1, 2...)
        new_node->next = NULL;   // 일단 뒤는 끊어둠

        // 2. 연결하기 (Link)
        if (head == NULL) {
            // (A) 리스트가 비어있을 때 (첫 번째 노드인 경우)
            head = new_node; // 네가 대장(Head)이다.
            tail = new_node; // 동시에 네가 꼬리(Tail)다.
        }
        else {
            // (B) 이미 노드가 있을 때 (이어 붙이기)
            tail->next = new_node; // 1. 현재 꼬리 뒤에 새 녀석을 붙임
            tail = new_node;       // 2. "이제부터 네가 꼬리야"라고 꼬리표 옮김
        }
    }

    // 3. 확인 (순회)
    printf("[완료] 연결 리스트 출력:\n");
    Node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");

    // 4. 해제 (생략 가능하지만, 습관을 위해!)
    curr = head;
    while (curr != NULL) {
        Node* temp = curr->next;
        free(curr);
        curr = temp;
    }

    return 0;
}