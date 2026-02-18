# 6주차 1교시: 원형연결리스트
## H8. 원형의 삽입과 삭제
### (1) 개요
> **원형연결리스트**: 마지막 노드의 링크가 첫번째 노드를 가리키는 리스트
- 한 노드에서 다른 모든 노드로의 접근 가능

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insert(Node* head, int data) {
    Node* newNode = createNode(data);

    // 리스트가 비어있는 경우
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return head;
    }

    Node* temp = head;

    // 마지막 노드 찾기
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

void printList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head로 돌아감)\n");
}

Node* delete(Node* head, int key) {
    if (head == NULL) return NULL;

    Node *curr = head, *prev = NULL;

    // head가 삭제될 경우
    if (head->data == key) {
        while (curr->next != head)
            curr = curr->next;

        if (curr == head) {
            free(head);
            return NULL;
        }

        curr->next = head->next;
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    prev = head;
    curr = head->next;

    while (curr != head) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

int main() {
    Node* head = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);

    printf("원형 연결 리스트:\n");
    printList(head);

    head = delete(head, 20);

    printf("20 삭제 후:\n");
    printList(head);

    return 0;
}


```

## J10. 연결리스트 스택
**정의**: 연결리스트 스택은 선형 자료구조인 스택(Stack)을 연결리스트 형태로 구현한 구조를 의미한다. 스택은 후입선출(LIFO, Last In First Out)의 특징을 가지며, 가장 마지막에 삽입된 데이터가 가장 먼저 삭제되는 방식으로 동작한다. 연결리스트를 이용한 스택은 각 데이터를 노드 단위로 생성하여 포인터를 통해 연결함으로써, 스택의 크기를 미리 정할 필요 없이 동적으로 데이터를 저장할 수 있다는 특징을 가진다.  
**용도**: 연결리스트로 구현된 스택은 데이터의 삽입과 삭제가 빈번하게 발생하는 상황에서 효율적으로 사용될 수 있다. 특히 재귀 호출의 처리, 함수 호출 과정의 관리, 수식 계산, 괄호 검사, 되돌리기(Undo) 기능과 같은 작업에서 활용된다. 배열 기반 스택과 달리 저장 공간의 크기를 사전에 설정할 필요가 없기 때문에, 데이터의 개수가 예측되지 않는 환경에서도 유연하게 사용할 수 있다는 장점을 가진다.

```c
#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

// Push 함수
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop 함수
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// 출력 함수
void display() {
    Node* current = top;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    printf("Pop: %d\n", pop());
    display();

    return 0;
}

```

---

# 6주차 2교시: 이중연결리스트
## K11. 이중의 삽입과 삭제
> 하나의 노드가 선행노드와 후행노드에 대한 두개읜 링크를 가지는 리스트

```c
#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

// 노드 생성 함수
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 맨 앞에 삽입
void insertFront(int value) {
    Node* newNode = createNode(value);

    if (head != NULL) {
        head->prev = newNode;
        newNode->next = head;
    }
    head = newNode;
}

// 맨 뒤에 삽입
void insertEnd(int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// 노드 삭제
void deleteNode(int value) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
            return;
        }
        temp = temp->next;
    }
}

// 리스트 출력 (정방향)
void displayForward() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 리스트 출력 (역방향)
void displayBackward() {
    Node* temp = head;

    if (temp == NULL)
        return;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    printf("정방향 출력: ");
    displayForward();

    printf("역방향 출력: ");
    displayBackward();

    deleteNode(20);

    printf("삭제 후 정방향 출력: ");
    displayForward();

    return 0;
}
```

## M13. 연결리스트 큐
**정의**: 연결리스트 큐는 선형 자료구조인 큐(Queue)를 연결리스트 형태로 구현한 구조를 의미한다. 큐는 선입선출(FIFO, First In First Out)의 특징을 가지며, 먼저 삽입된 데이터가 먼저 삭제되는 방식으로 동작한다. 연결리스트를 이용한 큐는 각 데이터를 노드(Node) 단위로 생성하여 포인터를 통해 연결하는 방식으로 구성되며, 데이터의 삽입은 큐의 뒤쪽(Rear)에서 이루어지고 삭제는 앞쪽(Front)에서 이루어진다.



