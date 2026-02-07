# 5주차 1교시: 단순연결리스트
## Z26. 리스트 연산
### (1) 리스트의 기본 연산
- 삽입 연산
- 삭제 연산
- 탐색 연산

### (2) 배열과 연결리스트
배열은 고정된 길이, 연결리스트는 연결만 해주면되기에 **동적할당**이 가능함


## A1. 배열 리스트

### (1) 배열리스트의 코드 구현
```JAVA
public class MyArrayList {
    private int[] data;    // 데이터를 담을 배열
    private int size;      // 현재 저장된 데이터 개수
    private int capacity;  // 현재 배열의 전체 용량

    public MyArrayList() {
        this.capacity = 5; // 처음엔 작은 크기로 시작
        this.data = new int[capacity];
        this.size = 0;
    }

    // 데이터 추가
    public void add(int value) {
        if (size == capacity) { // 배열이 꽉 찼다면
            grow();             // 크기를 늘림
        }
        data[size++] = value;
    }

    // 배열 크기를 2배로 늘리는 로직 (핵심!)
    private void grow() {
        capacity = capacity * 2;
        int[] newData = new int[capacity];
        
        // 기존 데이터를 새 배열로 복사
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        data = newData; // 기존 배열을 새 배열로 교체
        System.out.println("배열 확장됨! 현재 용량: " + capacity);
    }

    // 특정 인덱스의 데이터 가져오기
    public int get(int index) {
        if (index < 0 || index >= size) throw new IndexOutOfBoundsException();
        return data[index];
    }

    public int size() {
        return size;
    }

    public static void main(String[] args) {
        MyArrayList list = new MyArrayList();
        for (int i = 1; i <= 7; i++) {
            list.add(i * 10);
        }

        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }
    }
}
```

## B2. 연결 리스트
링크필드와 데이터 필드로 구성됨

### (1) 종류
- 단일 연결리스트
- 원형 연결리스트
- 이중 연결리스트
- 이중 원형 연결리스트

### (2) 연결 리스트의 코드 구현
```JAVA
class Node {
    int data;      // 데이터
    Node next;     // 다음 노드를 가리키는 주소값

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class MyLinkedList {
    private Node head; // 리스트의 시작 노드

    // 데이터 추가
    public void add(int data) {
        Node newNode = new Node(data);

        if (head == null) { // 리스트가 비어있으면
            head = newNode;
            return;
        }

        Node temp = head;
        while (temp.next != null) { // 마지막 노드까지 이동
            temp = temp.next;
        }
        temp.next = newNode; // 마지막 노드의 next에 새 노드 연결
    }

    // 전체 리스트 출력
    public void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        MyLinkedList list = new MyLinkedList();
        list.add(10);
        list.add(20);
        list.add(30);

        list.printList(); // 출력: 10 -> 20 -> 30 -> null
    }
}
```


---
# 5주차 2교시: 연결리스트의 응용
## C3. 단어 저장
### (1) 단어들을 저장하고 있는 연결리스트
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단어를 저장할 노드 구조체
typedef struct Node {
    char word[30];       // 단어를 저장할 배열 (최대 29자 + NULL)
    struct Node *next;   // 다음 노드를 가리키는 포인터
} Node;


// 새 단어를 리스트 맨 앞에 추가하는 함수
void addWord(Node **head, char *newWord) {
    // 1. 새 노드 메모리 할당
    Node *newNode = (Node *)malloc(sizeof(Node));
    
    // 2. 단어 복사 및 다음 노드 연결
    strcpy(newNode->word, newWord); // 단어 복사
    newNode->next = *head;          // 현재 head가 가리키던 것을 새 노드의 next로
    
    // 3. head를 새 노드로 변경
    *head = newNode;
}

// 리스트의 모든 단어 출력
void printWords(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("[%s] -> ", curr->word);
        curr = curr->next; // 여기서 '->'를 사용!
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL; // 리스트의 시작점 (초기엔 비어있음)

    addWord(&head, "Apple");
    addWord(&head, "Banana");
    addWord(&head, "Cherry");

    printf("저장된 단어 목록:\n");
    printWords(head);

    // 메모리 해제 로직 (생략 가능하나 실제 구현시 필수)
    return 0;
}
```

## D4. 다항식
### (1) 개요
다항식을 컴퓨터로 처리하기 위한 구조

- 하나의 다항식을 하나의 연결리스트로 표현함

### (2) 코드
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    float coef;         // 계수 (예: 3.5)
    int exp;            // 차수 (예: x^2의 2)
    struct PolyNode* next;
} PolyNode;

// 새로운 항을 차수에 맞춰서 삽입하는 함수
void addTerm(PolyNode** head, float coef, int exp) {
    PolyNode* newNode = (struct PolyNode*)malloc(sizeof(PolyNode));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;

    // 1. 리스트가 비었거나, 새 항의 차수가 제일 높을 때 (맨 앞에 삽입)
    if (*head == NULL || exp > (*head)->exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // 2. 자기 자리를 찾아가기 (차수가 나보다 낮은 놈 바로 앞까지 이동)
        PolyNode* curr = *head;
        while (curr->next != NULL && curr->next->exp > exp) {
            curr = curr->next;
        }
        
        // 차수가 같은 항이 이미 있다면 계수만 더함 (중복 처리)
        if (curr->next != NULL && curr->next->exp == exp) {
            curr->next->coef += coef;
            free(newNode); // 새 노드는 필요 없으니 삭제
        } else {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
}

// 다항식 출력 함수
void printPoly(PolyNode* head) {
    for (PolyNode* curr = head; curr != NULL; curr = curr->next) {
        printf("%.1fx^%d", curr->coef, curr->exp);
        if (curr->next != NULL && curr->next->coef >= 0) printf(" + ");
    }
    printf("\n");
}
```

### (3) 헤더 노드의 개념
헤더 노드 { 길이 - 헤드 - 테일 }

## E5. 방문 연산
방문 프로그램(또는 방문 여부 확인)은 재귀함수 그 자체라기보다는, 재귀함수나 반복문을 써서 그래프/트리를 탐색할 때 "여긴 이미 가봤어!"라고 표시를 남기는 행위를 말합니다. 보통 알고리즘에서 visited 배열을 사용하는 것을 의미해요.

왜 이게 필요한지 아주 쉽게 설명해 드릴게요.

1. 왜 "방문"을 표시해야 할까? (무한 루프 방지)
미로 찾기를 한다고 생각해보세요. 내가 지나온 길을 표시(방문 표시)하지 않으면, 똑같은 길을 계속 뱅글뱅글 돌 수도 있겠죠?

컴퓨터도 똑같습니다. A와 B가 서로 연결되어 있을 때:

A를 방문하고 B로 갑니다.

B에서 다시 연결된 A로 갑니다.

A에서 다시 B로 갑니다... (무한 반복!)

이걸 막으려고 **"나 여기 이미 방문했음"**이라는 체크리스트(visited)를 만드는 겁니다.

2. 어떻게 구현하나? (주로 배열 사용)
보통 노드 번호와 똑같은 크기의 배열을 만들어서 0(안 감) 또는 1(갔음)을 표시합니다.

C
int visited[10] = {0, }; // 모든 노드를 0으로 초기화

void dfs(int v) {
    visited[v] = 1; // 1. 현재 노드(v) 방문 도장 꽝!
    printf("%d 방문 완료\n", v);

    for (int i = 0; i < 연결된노드들; i++) {
        if (visited[i] == 0) { // 2. 아직 안 간 곳이 있다면?
            dfs(i); // 3. 그곳으로 이동 (재귀 호출)
        }
    }
}
3. 재귀함수와의 관계
질문하신 대로 **재귀함수(DFS, 깊이 우선 탐색)**를 쓸 때 이 방문 체크가 단짝처럼 따라다닙니다.

재귀함수: 다음 칸으로 이동하는 방법 (계속 파고들기)

방문 프로그램(visited): 똑같은 곳을 또 가지 않게 막는 안전장치

## F6. 특정 값 탐색
 
요약: 언제 연결 리스트 탐색을 쓰는가?  
데이터의 삽입/삭제가 빈번하게 일어나는 시스템 (예: 주식 체결 대기열)

데이터가 얼마나 들어올지 예측 불가능할 때

중간중간 빈 구간이 아주 많은 데이터를 다룰 때

## G7. 합침과 역순

1. **합침 (Merge)**: "두 기차를 하나로 잇기"  
합침은 두 개의 독립된 연결 리스트를 하나의 리스트로 만드는 과정입니다.

**단순 합침 (Concatenation)**  
가장 쉬운 방법은 **첫 번째 리스트의 꼬리(NULL 앞)**를 **두 번째 리스트의 머리(head)**에 연결해버리는 겁니다.

**방법:** 첫 번째 리스트의 마지막 노드를 찾아서, 그 next에 두 번째 리스트의 시작 주소를 적어줍니다.

**정렬된 합침 (Sorted Merge)**  
실제 알고리즘에서 말하는 '합침'은 주로 이겁니다. 각각 정렬된 두 리스트를 합치면서 결과물도 정렬된 상태로 만드는 거죠.

**방법:** 두 리스트의 맨 앞을 비교해서 더 작은 놈을 먼저 새 기차에 태우고, 그다음 놈을 비교하는 식으로 진행합니다. (마치 카드 게임에서 숫자 낮은 카드부터 내는 것과 비슷해요.)

2. **역순 (Reverse): "화살표 방향 다 바꾸기"**  
역순은 리스트의 내용은 그대로인데, 화살표(next)의 방향만 정반대로 뒤집는 겁니다.  

**방법:** 1. 현재 노드가 가리키는 다음 놈의 주소를 잠깐 딴 데(temp) 적어둡니다. 2. 현재 노드의 화살표(next)를 내 뒤가 아니라 내 앞을 보게 꺾습니다. 3. 이렇게 끝까지 가면, 원래 꼬리였던 놈이 새로운 head가 됩니다.

3. **왜 이걸 하나요? (실제 용도)**  
**합침**: 여러 소스에서 들어온 데이터를 통합할 때 씁니다. 예를 들어, 'A반 성적 리스트'와 'B반 성적 리스트'를 합쳐서 전체 등수를 낼 때 유용하죠.

**역순**: 데이터를 입력받은 순서의 반대로 처리해야 할 때 씁니다. (예: 최신글부터 보여주기, 되돌리기 기능 구현 등)