# 4주차 1교시: 큐의 구현
## T20. 큐 연산
### (1) 큐 개요
**정의**: FIFO 구조

### (2) 큐 ADT
객체: 0개 이상으로 구성된 선형 리스트

연산
- 최대 크기 정하기(max_size)
- 큐 초기화
- 공백, 포화상태 확인
- 객체 추가 및 반환
- 맨 앞의 객체를 확인

### (3) 큐의 응용
- 시뮬레이션의 대기열
  - 공항에서의 비행기, 은행에서의 대기열
- 컴퓨터와 프린터 간의 버퍼링(스풀링)

## U21. 선형 큐
### (1) 개요
**배열**을 선형으로 사용하여 큐를 구현
- 삽입을 계속하기 위해 요소들을 이동시킴.

### (2) 예제 프로그램
```java
class LinearQueue {
    private int[] queue;
    private int front;
    private int rear;
    private int capacity;

    public LinearQueue(int capacity) {
        this.capacity = capacity;
        queue = new int[capacity];
        front = 0;
        rear = -1;
    }

    // 큐가 비었는지 확인
    public boolean isEmpty() {
        return front > rear;
    }

    // 큐가 가득 찼는지 확인
    public boolean isFull() {
        return rear == capacity - 1;
    }

    // 삽입 (enqueue)
    public void enqueue(int data) {
        if (isFull()) {
            System.out.println("큐가 가득 찼습니다.");
            return;
        }
        queue[++rear] = data;
    }

    // 삭제 (dequeue)
    public int dequeue() {
        if (isEmpty()) {
            System.out.println("큐가 비어 있습니다.");
            return -1;
        }
        return queue[front++];
    }

    // 맨 앞 요소 확인
    public int peek() {
        if (isEmpty()) {
            System.out.println("큐가 비어 있습니다.");
            return -1;
        }
        return queue[front];
    }

    // 큐 출력
    public void printQueue() {
        if (isEmpty()) {
            System.out.println("큐가 비어 있습니다.");
            return;
        }
        for (int i = front; i <= rear; i++) {
            System.out.print(queue[i] + " ");
        }
        System.out.println();
    }
}
```

## V22. 원형 큐
### (1)  개요
큐의 전단과 후단을 연결한다. (반환 시마다 rear의 위치를 옮김)
- 

### (2) 공백상태와 포화상태
front == rear
front == (rear+1) % M

### (3) 예제 프로그램
```java
class CircularQueue {
    private int[] queue;
    private int front;
    private int rear;
    private int capacity;

    public CircularQueue(int capacity) {
        this.capacity = capacity;
        queue = new int[capacity];
        front = 0;
        rear = 0;
    }

    // 큐가 비었는지 확인
    public boolean isEmpty() {
        return front == rear;
    }

    // 큐가 가득 찼는지 확인
    public boolean isFull() {
        return (rear + 1) % capacity == front;
    }

    // 삽입 (enqueue)
    public void enqueue(int data) {
        if (isFull()) {
            System.out.println("큐가 가득 찼습니다.");
            return;
        }
        queue[rear] = data;
        rear = (rear + 1) % capacity;
    }

    // 삭제 (dequeue)
    public int dequeue() {
        if (isEmpty()) {
            System.out.println("큐가 비어 있습니다.");
            return -1;
        }
        int data = queue[front];
        front = (front + 1) % capacity;
        return data;
    }

    // 맨 앞 요소 확인
    public int peek() {
        if (isEmpty()) {
            System.out.println("큐가 비어 있습니다.");
            return -1;
        }
        return queue[front];
    }

    // 큐 출력 (논리적 순서)
    public void printQueue() {
        if (isEmpty()) {
            System.out.println("큐가 비어 있습니다.");
            return;
        }

        int i = front;
        while (i != rear) {
            System.out.print(queue[i] + " ");
            i = (i + 1) % capacity;
        }
        System.out.println();
    }
}
```


---
# 4주차 2교시: 큐의 응용
## W23. 버퍼
기다리고 있는 것

### (1) 예제 프로그램
```
public class CircularBuffer<T> {
    private Object[] buffer;
    private int capacity;
    private int front;  // 읽기 위치
    private int rear;   // 쓰기 위치
    private int size;   // 현재 저장된 요소 수

    public CircularBuffer(int capacity) {
        this.capacity = capacity;
        buffer = new Object[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    // 버퍼가 비었는지
    public boolean isEmpty() {
        return size == 0;
    }

    // 버퍼가 가득 찼는지
    public boolean isFull() {
        return size == capacity;
    }

    // 데이터 추가
    public void write(T data) {
        if (isFull()) {
            System.out.println("버퍼가 가득 찼습니다. 덮어쓰기 가능");
            // 원하면 덮어쓰기 가능: front = (front + 1) % capacity;
            return;
        }
        buffer[rear] = data;
        rear = (rear + 1) % capacity;
        size++;
    }

    // 데이터 읽기
    @SuppressWarnings("unchecked")
    public T read() {
        if (isEmpty()) {
            System.out.println("버퍼가 비어 있습니다.");
            return null;
        }
        T data = (T) buffer[front];
        front = (front + 1) % capacity;
        size--;
        return data;
    }

    // 현재 버퍼 상태 출력
    public void printBuffer() {
        if (isEmpty()) {
            System.out.println("버퍼 비어 있음");
            return;
        }

        int i = front;
        System.out.print("Buffer: ");
        for (int count = 0; count < size; count++) {
            System.out.print(buffer[i] + " ");
            i = (i + 1) % capacity;
        }
        System.out.println();
    }
}
```

## X24. 덱
### (1) 개요
Double-ended queue 의 줄임말로 큐의 전단과 후단 모두 삽입과 삭제가 가능한 큐

### (2) 의사코드
- 생성과 초기화
- 공백과 포화 조회
- 앞에, 요소 추가 및 반환
- 뒤에, 요소 추가 및 반환
- peek
 
### (3) 예제 프로그램
```java
public class MyDeque<T> {
    private Object[] deque;
    private int capacity;
    private int front;
    private int rear;
    private int size;

    public MyDeque(int capacity) {
        this.capacity = capacity;
        deque = new Object[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }

    // 앞쪽 삽입
    public void addFirst(T data) {
        if (isFull()) {
            System.out.println("Deque가 가득 찼습니다.");
            return;
        }
        front = (front - 1 + capacity) % capacity;
        deque[front] = data;
        size++;
    }

    // 뒤쪽 삽입
    public void addLast(T data) {
        if (isFull()) {
            System.out.println("Deque가 가득 찼습니다.");
            return;
        }
        deque[rear] = data;
        rear = (rear + 1) % capacity;
        size++;
    }

    // 앞쪽 삭제
    @SuppressWarnings("unchecked")
    public T removeFirst() {
        if (isEmpty()) {
            System.out.println("Deque가 비어 있습니다.");
            return null;
        }
        T data = (T) deque[front];
        front = (front + 1) % capacity;
        size--;
        return data;
    }

    // 뒤쪽 삭제
    @SuppressWarnings("unchecked")
    public T removeLast() {
        if (isEmpty()) {
            System.out.println("Deque가 비어 있습니다.");
            return null;
        }
        rear = (rear - 1 + capacity) % capacity;
        T data = (T) deque[rear];
        size--;
        return data;
    }

    // 덱 상태 출력
    public void printDeque() {
        if (isEmpty()) {
            System.out.println("Deque 비어 있음");
            return;
        }
        int i = front;
        System.out.print("Deque: ");
        for (int count = 0; count < size; count++) {
            System.out.print(deque[i] + " ");
            i = (i + 1) % capacity;
        }
        System.out.println();
    }
}

```

## Y25. 시뮬레이션
### (1) 큐잉모델
고객에 대한 서비스를 수행하는 서버와 서비스를 받는 고객으로 이루어짐
- 고객이 기다리는 평균시간을 계산


