# 3주차 1교시: 스택의 구현
## N14. 스택 연산
### (1) 개요
**후입선출**: LIFO
- 가장 최근에 들어온 데이터가 가장 먼저 나감

함수를 호출하게 되면 복귀를 해야함. 복귀 주소가 최근에 저장된 것부터 가져와야함. 그렇기 때문에 함수의 경우 스택을 굉장히 많이 사용함,

스택 구조
- 스택 상단(Top): 최상위 데이터
- 요소(Element): 
- 스택 하단(Bottom): 

#### ㄱ. 시스템 스택을 이용한 함수 호출 예제(복귀 주소)
```yaml
int main(void){
  func1();
  return 0;
}
  
void func1(){
  func2();
}

void func2(){
  return;
}
```
- 위의 구조는 `main` 함수가 `func1`을, `func1` 함수가 `func2` 함수를 부르는 구조. 하지만 실행되는 순서는 `func2` &rarr; `func1` &rarr; `main이` 됨.

#### ㄴ. 보안 이슈
- 컴퓨터의 주기억장치에도 스택 영역이 존재
- 스택 영역의 주소는 위에서 아래로 감소하면서 증가
- `strcoy`와 같은 함수를 사용하면 **버퍼 오버플로우** 공격이 가능함
- 버퍼 오버플로우 공격이란 함수 호출의 복귀 주소를 변경하여 공격자가 원하는 코드를 실행하는 공격 기법
- 이를 해결하기 위해 `strncpy`와 같은 함수를 사용해야하고 이를 **시큐어 코딩**이라고 함.

#### ㄷ. 스택의 ADT (추상 데이터 타입)
객체: 0개 이상의 원소를 가지는 유한 선형 리스트

**연산**
- `create(size)` ::=
  - 최대크기가 size인 공백 스택을 생성
- `is_full(s)` ::=
  - if(스택의 원소수 == size) return TRUE;
  - else return FALSE;
  - **포화상태를 확인**
- `is_empty(s)` ::=
  - if(스택의 원소수 == 0) return TRUE;
  - else return FALSE;
  - **공백 상태를 확인**

- `push`
  - 스택에 아이템을 집어 넣는 것
- `pop`
  - 스택의 맨 위의 원소를 제거해서 반환함.
- `peek`
  - 스택의 맨 위의 원소를 제거하지 않고 반환.

## O15. 배열 스택
### (1) 배열을 이용한 스택 구현
1차원 배열 `stack[]`
- 스택에서 최근에 입력되었던 자료를 가르키는 `top` 변수
- 가장 먼저 들어온 요소는 `stack[0]`에 저장
- 가장 최근에 들어온 요소는 `stck[top]`에 저장
- 스택이 공백상태이면 `top`은 -1
- 스택이 공백상태이면 `top`은 0

### (2) is_empty, is_full의 구현
```pseudo
is empty(S): // Pseudo Code

if top == -1
  then return TRUE
  else return FALSE 
```

### (3) push, pop 연산
```yaml

push(S, x) // 선 증가
if is_full(S)
  then error
"overflow"
  else top = top + 1
    stack[top]
```
```yaml

pop(S, x) // 후감소
if is_full(S)
  then error
"underflow"
  else top = top - 1
    stack[top]
```

### (4) 전역변수로 구현하는 방법
```
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

// 공백상태 검출 함수
int is_empty()
{
    return (top == -1);
}

// 포화 상태 검출 함수
int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(element item)
{
    if (is_full()){
        fprintf(stderr, "OVERFLOW")
        return;
        }
   } else stack[++top] = item; // 선 증가
}

// 삭제 함수
element pop()
{
    if(is_empty()) {
        fprintf(stderr, "스택 공백 에러 \n"
        exit(1);
    }
    else return stack[top--] // 후 감소
}
```
```
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

// 공백상태 검출 함수
int is_empty()
{
    return (top == 0);
}

// 포화 상태 검출 함수
int is_full()
{
    return (top == MAX_STACK_SIZE);
}

// 삽입 함수
void push(element item)
{
    if (is_full()){
        fprintf(stderr, "OVERFLOW")
        return;
        }
   } else stack[top++] = item; // 후 증가
}

// 삭제 함수
element pop()
{
    if(is_empty()) {
        fprintf(stderr, "스택 공백 에러 \n"
        exit(1);
    }
    else return stack[--top] // 선 감소
}
```

### (5) 구조체 배열 사용
```yaml
#define MAX_STACK_SIZE 100 //preprocessor
typedef int element;
tpyedef struct {
  element data[MAX_STACK_SIZE];
  int top;
} StackType

// 스택 초기화 함수
void init_stack(StackType *s)
{
  s -> top = -1; // s -> top = 0;
}

// 공백상태 검출 함수
int is_empty(StackType *s)
{
    return (s-> top == -1);
}

// 포화 상태 검출 함수
int is_full()
{
    return (s -> top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(element item)
{
    if (is_full()){
        fprintf(stderr, "OVERFLOW")
        return;
        }
   } 
   else s->data[++(s->top)] = item; // 선 증가
}

// 삭제 함수
element pop()
{
    if(is_empty()) {
        fprintf(stderr, "스택 공백 에러 \n"
        exit(1);
    } 
    else return s->data[(s->top)--] = item; // 후 감소
}
```

## P16. 동적 스택
### (1) 개요
**malloc ()**
- `malloc()`을 호출해서 실행 시간에 메모리를 할당 받아 스택을 생성함.

**realloc()**
- `realloc()`을 호출하여 스택 배열을 **동적으로 확장**함.


### (2) 예제 프로그램
```yaml
tpyedef int elemet;
typedef struct{
  element *data; // data는 포인터로 정의됨
  int capacity; // 현재 크기
  int top;
}StackType;

int main (void)
{
  StackType *s;
  s = (StackType *)malloc(sizeof(StackType));
  init_stack(s); // s->top = -1; s->capacity=1;
  push(s,1); // 포화상태면 realloc
  push(s,2);
  push(s,3);
  printf("%d\n", pop(s)); // LIFO
  printf("%d\n", pop(s));
  printf("%d\n", pop(s));
  free(s); // Memory Leakage
}

void push(StackType *s, element item)
{
  if (is_full(s)){
      s->capacity *= 2;
      s->data=(element *)realloc(s->data, s->capacity *sizeof(element));
      }
  s-> data[++(s->top)]=item; // 선증가            
  } 
}

```

--- 
# 3주차 2교시: 스택의 응용
## Q17. 괄호 검사
### (1) 개요
괄호 종류(포함 관계)
- 대괄호 []
- 중괄호 {}
- 소괄호 ()

괄호의 조건
- 왼쪽 갈호의 개수와 오른쪽 괄호의 개수가 같아야함
- 같은 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 함
- 괄호 사이에는 포함 관계만 존재함 (대괄호>중괄호>소괄호)

### (2) 알고리즘의 개요
- 문자열에 있는 괄호를 차례대로 조사하면서 왼쪽 괄호를 만나면 스택에 삽입하고, 오른쪽 괄호를 만나면 스택에서 top 괄호를 삭제한 후 오른쪽 괄호와 짝이 맞는지 검사함.

### (3) 프로그램
```yaml
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element; // 괄호를 저장해야 하므로 char 타입
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 기본 스택 함수들
void init_stack(StackType *s) { s->top = -1; }
int is_empty(StackType *s) { return (s->top == -1); }
int is_full(StackType *s) { return (s->top == (MAX_STACK_SIZE - 1)); }

void push(StackType *s, element item) {
    if (is_full(s)) return;
    s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if (is_empty(s)) exit(1);
    return s->data[(s->top)--];
}

// 핵심: 괄호 검사 함수
int check_matching(const char *in) {
    StackType s;
    char ch, open_ch;
    int n = strlen(in);
    init_stack(&s);

    for (int i = 0; i < n; i++) {
        ch = in[i];
        switch (ch) {
            case '(': case '[': case '{':
                push(&s, ch);
                break;
            case ')': case ']': case '}':
                if (is_empty(&s)) return 0; // 오른쪽 괄호는 있는데 스택이 비었음
                else {
                    open_ch = pop(&s);
                    // 짝이 맞는지 검사
                    if ((open_ch == '(' && ch != ')') ||
                        (open_ch == '[' && ch != ']') ||
                        (open_ch == '{' && ch != '}')) {
                        return 0; // 짝 불일치
                    }
                    break;
                }
        }
    }
    return is_empty(&s); // 마지막에 스택이 비어있어야 성공 (1 반환)
}

int main() {
    char *p = "{ A[(i+1)] = 0; }";
    if (check_matching(p)) printf("%s : 성공\n", p);
    else printf("%s : 실패\n", p);

    return 0;
}
```

## R18. 수식 계산
### (1) 개요
- 전위, 중위, 후위 표현

스택이 사용되는 경우
- 중위표기식에서 후위표기식으로
- 후위표기식에서 계산으로

#### ㄱ. 후위표기식의 계산법
1. 수식을 왼쪽에서 오른쪽으로 스캔
2. 피연산자면 스택에 저장
3. 연산자이면 필요한 만큼 피연산자를 스택에서 꺼내 연산을 실행
4. 이후 연산의 결과를 다시 스택에 저장

#### ㄴ. 후위표기식 프로그램
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// --- [1] 스택 데이터 타입 및 구조체 정의 ---
typedef char element; 
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// --- [2] 스택 기본 연산 함수들 ---
void init_stack(StackType *s) { 
    s->top = -1; // 스택 초기화: top을 -1로 설정
}

int is_empty(StackType *s) { 
    return (s->top == -1); // 비어있으면 1(참) 반환
}

int is_full(StackType *s) { 
    return (s->top == (MAX_STACK_SIZE - 1)); // 가득 찼으면 1(참) 반환
}

void push(StackType *s, element item) {
    if (is_full(s)) return;
    s->data[++(s->top)] = item; // top을 먼저 증가시키고 데이터 삽입
}

element pop(StackType *s) {
    if (is_empty(s)) exit(1);
    return s->data[(s->top)--]; // 데이터를 반환한 후 top을 감소
}

element peek(StackType *s) {
    if (is_empty(s)) exit(1);
    return s->data[s->top]; // top 위치의 데이터를 확인만 함
}

// --- [3] 연산자 우선순위 판단 함수 ---
int prec(char op) {
    switch (op) {
        case '(': case ')': return 0;   // 괄호가 가장 낮음 (벽 역할)
        case '+': case '-': return 1;   // 덧셈, 뺄셈
        case '*': case '/': return 2;   // 곱셈, 나눗셈 (가장 높음)
    }
    return -1;
}

// --- [4] 중위 -> 후위 변환 핵심 함수 ---
void infix_to_postfix(char exp[]) {
    StackType s;
    init_stack(&s); // 지역 변수로 스택 생성 및 초기화
    int n = strlen(exp);

    for (int i = 0; i < n; i++) {
        char ch = exp[i];

        // 숫자면 바로 출력
        if (ch >= '0' && ch <= '9') {
            printf("%c", ch);
        }
        // 왼쪽 괄호면 스택에 보관
        else if (ch == '(') {
            push(&s, ch);
        }
        // 오른쪽 괄호면 '('가 나올 때까지 스택에서 꺼내 출력
        else if (ch == ')') {
            while (peek(&s) != '(') {
                printf("%c", pop(&s));
            }
            pop(&s); // '(' 자체는 출력하지 않고 버림
        }
        // 연산자면 우선순위 비교 후 처리
        else {
            // 스택에 나보다 강한(우선순위 높은) 놈이 있다면 먼저 내보냄
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                printf("%c", pop(&s));
            }
            push(&s, ch); // 나보다 약한 놈들만 남았을 때 내가 들어감
        }
    }
    // 스택에 남아있는 모든 연산자 털어내기
    while (!is_empty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");
}

// --- [5] 프로그램 실행부 ---
int main() {
    char *exp = "(2+3)*4-5/1"; 
    printf("중위 표기식: %s\n", exp);
    printf("후위 표기식: ");
    infix_to_postfix(exp); // 호출 결과: 23+4*51/- 
    return 0;
}
```

## S19. 미로 탐색
### (1) 개요
**정의**: 현재의 위치에서 가능한 방향을 스택에 저장해놓았다 막다른 길을 만나면 스택에서 다음 탐색 위치를 꺼냄

### (2) 미로 탐색 알고리즘
스택 s와 출구위치 x, 현재 생쥐의 위치를 초기화
```
while (현재의 위치가 출구가 아니면)
    do 현재의 위치를 방문한 것으로 표기
        if (현재의 위치의 위, 아래, 왼쪽, 오른쪽 위치가 아직 방문되지 않았고 갈 수 있으면) 
            then (그 위치들을 스택에 push)
        if (is_empty(s))
            then 실패
            else 스택에서 하나의 위치를 꺼내어 현재 위치로 설정한다.
성공;
```

### (3) 미로 탐색 프로그램
```
// 구조체 배열 사용 스택 코드 추가
// ...
typedef struct {
    short r;
    short c;
} element

element here = {1,0}, entry = {1,0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
{1,1},
{1,1}
};

// 위치를 스택에 삽입
void push_loc(StackType *s, int r, int c)
{
    if (r < 0 || c < 0) return; // 경계를 벗어남
    if (maze[r][c] != '1' && maze[r][c] != '.'){
    // 벽이 아니고 방문하지 않았다면,    
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s,tmp)
    }
}
// 미로를 화면에 출력
void maze_print(char maze_print[MAZE_SIZE][MAZE_SIZE])
{
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++){
            printf("%c",maze[r][c]);
        }
        printf("\n")
    }

}

int main(void)
{
    int r, c;
    StackType s;
    init_stack(&s);
    here=entry;
    while(maze[here.r][here.c]!= 'x'){
        r = here.r;
        c = here.c;
        maze[r][c] = ',' // 방문 표시
        maze_print(maze);
        push_loc(&, r-1, c); // 위
        push_loc(&, r+1, c); // 아래
        push_loc(&, r, c-1); // 좌
        push_loc(&, r, c+1); // 우 
        if (is_empty(&s)){
            pritnf("실패\n");
            return;
        }
        else
            here = pop(&s); // 하나 꺼냄
    }
    printf("성공")
    return 0
}
```