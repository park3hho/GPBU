#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* temp;
    Node* newNode;
    int num;
    int sum = 0;

    while (1) {
        printf("숫자 입력 (종료: -1) : ");
        scanf("%d", &num);

        if (num == -1)
            break;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        sum += num;
        printf("현재까지의 합: %d\n", sum);
    }

    return 0;
}
