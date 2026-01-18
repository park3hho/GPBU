# 2주차 1교시: 배열
## H8. 배열
같은 유형의 변수를 여러개 만드는 경우에 사용함.

**배열의 구조**   
`int grade[10]`  
- `int`: 배열 원소들이 int형이라는 것을 의미
- `grade`: 배열을 사용할 때 사용하는 이름
- `[10]`: 배열의 크기
- 인덱스(첨자): 항상 0부터 시작함

첨자 범위를 벗어나면 생기는 오류 &rarr; `access viloation`

### (1) 배열 ADT
ADT Array
- 객체
  - <인덱스, 값> 쌍의 집합
- 연산
  - `create(size)` ::= size개의 요소를 저장할 수 있는 배열 생성
  - `get(A, i)` ::= 배열 A의 i번째 요소를 반환
  - `set(A, i, V)` ::= 배열 A의 i번쨰 위치에 값 v 저장

#### ㄱ. 1차원 배열
```yaml
int list[6]
list[0] = 100; // set 연산에 해당
value = list[0];  // get 연산에 해당
```

### ㄴ. 2차원 배열
```yaml
int list[3][5]; // **행우선 열우선**
```
행 우선 순위
- A[i][j]의 주소 = 시작주소 + (i*col + j)* 요소 크기

열 우선순위
- A[i][j]의 주소 = 시작주소 + (j*col + i)* 요소 크기

## I9. 구조체
### (1) 개요
구조체(Structure)
- 타입이 다른 데이터를 하나로 묶는 방법

배열(Array)
- 타입이 같은 데이터들을 하나로 묶는 방법

특징
- 구조체 간, 대입은 가능하지만, 비교는 불가능

### (2) 구조체의 필요성
- 학생에 대한 데이터를 하나로 모을 때, `int num; char name[10]; double grade;`를 한번에 묶어버림.

**구조체 선언**
```yaml
  strcut studentTag {
  char name[10];
  int age;
  double gpa;
} // 구조체 구조 생성

struct studentTag s1 {
  strcpy (s.name, "kim"); // buffer overflow로 인해 금지됨 "strcpy"
  s.age = 20; // "."을 이용하여 접근함
  s.gpa = 4.3;
} // 구조체 인스턴스 생성
```
**typedef // 재정의**
```yaml
typedef studentTag {
  char name[10];
  int age;
  double gpa;
} student;

student s;
student s = {"kim", 20, 4.3}; // 초기화
```
예제
```
typedef struct studentTag {
    char name[10];
    int age;
    double gpa;
} student;

int main (void)
{
    student a = {"kim", 20, 4.3};
    student b = {"park", 25, 4.1};
    return 0;
}
```

## J10. 배열의 응용
### (1) 다항식
다항식을 위한 자료구조가 필요함: 배열, 연결리스트

### (2) 다항식 표현 방법
- 다항식의 모든 항을 배열에 저장하는 방법
- 다항식의 0이 아닌 항만을 배열에 저장하는 방법

#### ㄱ. 모든 항을 배열에 저장하는 방법
- 모든 차수에 대한 계수값을 배열로 저장
- 하나의 다항식을 하나의 배열로 표현

**표현법**
```C
#define MAX_DEGREE 101 // 다항식의 최대차수 +1
typedef struct {
  int degree;
  float coef[MAX_DEGREE];
} polynomial;
polynomial a = { 5, {10, 0, 0, 0, 6, 3}};

polynomial ploy_add1(polynomial A, ploynomial B)
{
    ploynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree);
    while (Apos <= A.degree && Bpos <= B.dgree){
        if (degree_a > degree_b) { // A항 > B항
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b) {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++]
            degree_a--; degree_b--;
        }
        else {
            C.coef[Cpos++] = B.coef[Bpos++]
            degree_b--;
        }
    retrun C;
}

void print(polynomial p){
    for (int i = p.degree; i>0; i--)
        print("%3.1fx^%d + ", p.coef[p.degree -i], i);
    print("%3.1f\n", p.coef[p.degree];
}    

int main(void)
{
    polynomial a = { 5, { 3, 6, 0, 0, 0, 10}};
    polynomial b = { 4, { 7, 5, 5, 4, 3}};
    polynomial c;
    print_poly(a);
    print_poly(b);
    c = poly_add1(a,b);
    print_poly(c);
    return 0;
}
```
**다항식의 0이 아닌 항만을 배열에 저장하는 방법**   
10x^5 + 6x + 3 => ((10,5),(6,1),(3,0))
```
# define MAX_TERMS 101
struct{
    float coef;
    int expon;
} terms[MAX_TERMS]
int avail;
```
```C
#define MAX_TERMS 101
struct{
    float coef;
    int expon;
} terms[MAX_TERMS] = {{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}};
int avail = 6;
// 두개의 정수를 비교
char compare(int a, int b)
{
    if(a>b) return '>';
    else if(a==b) return '=';
    else reutrn '<' };

void attach(flaot coef, int expon)
{
    if(avail > MAX_TERMS){
        fprintf(stderr, "Overflow");
        exit(1); // 프로그램 종료
    }
    terms[avail].coef=coef;
    terms[avail++].expon=expon;
}
        
poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
    float tempcoef; 
    *Cs = avail;
    while(As <= Ae && Bs <= Be)
    switch(compare(terms[As].expon, terms[Bs].expon)){
        case '>': // 
            attach(terms[As].coef, terms[As].expon);
            As++;
            break;
        case '=':
            tempcoef = terms[As].coef + terms[Bs].coef;
            if( tempcoef )
                attach(tempcoef, terms[As].expon);
            As++; Bs++
            break;
        case '<':
            attach(terms[Bs].coef, terms[Bs].expon);
            Bs++;
            break;
    }
    for (; As <= Ae; As++)
        attach(terms[As].coef, terms[As].expon;
    for (; Bs <= Be; Bs++)
        attach(terms[Bs].coef, terms[Bs].expon;
    *Ce = avail - 1;
}
void print_poly(int s, int e)
{
    for(int i = s; i < e; i++)
        print("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    print("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main(void)
{
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
    poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
    print_poly(As, Ae);
    print_poly(Bs, Be);
    c = poly_add1(a,b);
    print_poly(Cs, Ce);
    return 0;
}


```
# 2주차 2교시: 집합
## K11. 희소행렬
정의: 대부분의 항이 0으로 된 행렬

### (1) 희소행렬 표현방법
배열을 이용하여 행렬(Matrix)를 표현하는 방법
- 2차원 배열을 이용하여 전체 요소를 저장하는 방법
- 0이 아닌 요소들만 저장하는 방법

### (2) 2차원 배열을 이용하여 배열의 **전체 요소**를 저장
장점: 행렬의 연산들을 간단하게 구현할 수 있음
단점: 대부분의 항이 0인 희소행렬의 경우 많은 메모리 공간이 낭비됨.

```yaml
#include <studio.h>
#define ROWS 3
#define COLS 3

// 행렬 전치 함수 (전치 -> Transpose)
void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS])
{
  for (int r = 0; r<ROWS; r++)
    for (int c = 0; c<COLS; c++)
      B[c][r] = A[r][c]; // A의 전치 결과가 B에 저장됨
}

void matrix_print(int A[ROWS][COLS])
{
    for (int r = 0; r<ROWS; r++ {
    for (int c = 0; c<COLS; c++
    printf("%d", A[ r ][ c ]);
    printf("\n");
  }
}
  
int main(void)
{
  int array1[ROWS][COLS] = {{2,3,0},
                            {8,9,1},
                            {7,0,5}};
  int array2[ROWS][COLS];
  matrix_transpose(array1, array2);
  matrix_print(array1);
  matrix_print(array2);
  return 0;
}
```
### (3) 0이 아닌 요소들만 저장하는 방법
- 희소행렬의 경우 메모리 공간 절약
- 각종 행렬 연산들의 구현이 복잡해짐

행 열 값을 저장함.
A = {x, y, v}

```
#include <stdio.h>

#define ROWS 3       // 입력받을 행렬의 세로 크기
#define COLS 3       // 입력받을 행렬의 가로 크기
#define MAX_TERMS 10 // 0이 아닌 원소를 저장할 최대 공간

// (행, 열, 값)을 하나로 묶는 구조체
typedef struct {
    int row;
    int col;
    int value;
} Term;

int main() {
    Term sparse[MAX_TERMS];
    int val;
    int k = 1; // 1번 칸부터 데이터 저장 (0번은 요약 정보용)

    printf("%d x %d 행렬의 원소들을 입력하세요:\n", ROWS, COLS);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // 1. 숫자를 하나씩 입력받음
            scanf("%d", &val);

            // 2. 0이 아닌 경우에만 구조체 배열에 저장
            if (val != 0) {
                sparse[k].row = i;      // 행 번호 저장
                sparse[k].col = j;      // 열 번호 저장
                sparse[k].value = val;  // 실제 값 저장
                k++; // 다음 저장을 위해 인덱스 1 증가
            }
        }
    }

    // 3. 0번 인덱스에 전체 정보 저장 (표지판 역할)
    sparse[0].row = ROWS;
    sparse[0].col = COLS;
    sparse[0].value = k - 1; // 총 저장된 원소의 개수

    // 4. 저장된 결과 출력해서 확인하기
    printf("\n--- 희소행렬 저장 결과 ---\n");
    printf("인덱스\t행\t열\t값\n");
    for (int i = 0; i <= sparse[0].value; i++) {
        printf("[%d]\t%d\t%d\t%d\n", i, sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0;
}
```

## L12. 포인터
**정의**: 다른 변수의 **주소를 가지고 있는 변수**
```yaml
char a = 'A';
char *p;
p = &a;
```
`*`: 역참조 
```c
*p = 'B' // 이러면 'A' 에서 'B'로 바뀜.
```

`&`: 변수의 주소 추출 
`*`: 포인터가 가르키는 곳의 주소 추출

32비트 컴퓨터에서는 포인터 자체의 크기는 4바이트  
64비티 컴퓨터에서는 8바이트

### (1) 함수의 매개변수로 포인터 사용하기
```c
#include <stdio.h>
void swap(int *px, int *py)
{
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}
```

### (2) 배열과 포인터
A[0] = A
A[1] = A + 1
A[2] = A + 2

### 예제
```c
#include <stdio.h>
#define SIZE 6
void get_integers(int list[])
{
  printf("정수 입력");
  for(int i = 0; i < SIZE; ++i) {
    scanf("%d",&list[i]);                                 
  }
}
```

## M13. 동적 메모리 할당
정의: 프로그램의 실행 도중에 메모리를 할당받는 것
- 필요한 만큼만 할당을 받고 또 필요한 때에 사용하고 반납
- 메모리를 매우 효율적으로 사용가능

코드
```c
main()
{
  int *pi;
  pi = (int *)malloc(sizeof(int));
  ...
  ...
  ...
  free(pi);
}
```
```c
// MALLOC.C: malloc을 이용하여 정수 10개 저장할 수 있는 동적 메모리를 할당하고 free를 사용하여 메모리를 반납함.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE 10
int main(void)
{
    int *p;
    p = (int *)malloc(SIZE * sizeof(int));
    if (p == NULL) {
        fprintf
        (stderr, "메모리가 부족해서 할당할 수 없습니다.");
        exit(1);
        }
    for (int i = 0; i < SIZE; i++)
        p[i] = i;
    for (int i = 0; i < SIZE; i++)
        printf("%d", p[i]);
    free(p);
    return 0; 
} 
```

