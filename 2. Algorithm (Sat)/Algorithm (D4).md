# 4주차 1교시: 유용한 알고리즘 - 정렬 알고리즘 1
## O15. 정렬 알고리즘의 개요
정의: N개의 숫자가 입력으로 주어졌을 때, 사용자가 지정한 기준에 맞게 정렬하여 출력하는 알고리즘
- 정렬 알고리즘은 컴퓨터 분야에서 가장 깊이 연구된 분야 중 하나.
- 정렬 알고리즘은 다양하며, 각각 시간 복잡도도 다양함

### (1) 내부정렬과 외부정렬로 분류함
내부정렬: 
- 입력의 크기가 주기억장치의 공간보다 크지 않은 경우에 수행되는 정렬

외부정렬:
- 입력의 크기가 주기억장치 공간보다 큰 경우에 수행되는 정렬
- 이때에는 보조기억 장치에 있는 입력을 여러 번에 나누어 주기억장치에 읽어 들인 후, 정렬하여 보조기억 장치에 다시 저장하는 과정을 반복해야함.

### (2) 비교정렬 알고리즘
- **원소들의 순서**에만 의존하는 알고리즘
- 비교정렬 알고리즘은 시간의 복잡도가 **$O(N \log_2 N)$**보다 나은 성능을 낼 수 없음

### (3) 비-비교정렬 알고리즘
- 시간 복잡도에 대한 제약이 없음
- 원소들의 특성이나 종류에 따라 비교정렬 알고리즘보다 느릴 수 있음
- 기수정렬

### (4) 정렬 알고리즘의 기초 연산
- 판별, 비교, 교환

## P16. 선택 정렬 알고리즘 
오름차순 정렬 기준
- 오른쪽 값을 전부 보고, 가장 낮은 값과 위치를 바꿈

시간복잡도
- $O(n^2)$

특징
- 대중적임, 입력 순서에 영향을 받지 않음

```java
public class SelectionSort {

    public static void selectionSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            // i 이후 구간에서 최소값 찾기
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            // 최소값을 현재 위치 i와 교환
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11};

        selectionSort(arr);

        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
```
## Q17. 삽입 정렬 알고리즘 
 삽입 정렬 알고리즘 동작
- 정렬된 왼쪽 보고, 자신의 위치를 찾아감

시간복잡도
- $O(n^2)$

특징
- 정렬이 잘 되어있으면 $O(n)$으로 나옴

```java
public class InsertionSort {

    public static void insertionSort(int[] arr) {
        int n = arr.length;

        for (int i = 1; i < n; i++) {
            int key = arr[i];      // 삽입할 값
            int j = i - 1;

            // key보다 큰 값들을 오른쪽으로 이동
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            // 올바른 위치에 key 삽입
            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11};

        insertionSort(arr);

        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
```

## R18. 버블 정렬 알고리즘
- 오른쪽 놈이랑 비교해서 자리 바꿈, 한줄 처리한 걸 **pass**라고 함.

시간복잡도
- $O(n^2)$

```java
public class BubbleSort {

    public static void bubbleSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            boolean swapped = false;

            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            // 이미 정렬된 경우
            if (!swapped) break;
        }
    }
}
```

---
# 4주차 2교시: 유용한 알고리즘 - 정렬 알고리즘 2
## R18. 쉘 정렬 알고리즘
버블 정렬: 작은 수가 배열의 앞부분으로 이동이 느림  
삽입 정렬: 가장 작은 숫자가 배열의 마지막 원소일 때 마지막에 모든 원소들이 모두 오른쪽으로 이동해야함.  

얘는 걔네 둘을 보완한 알고리즘임.

- 배열 뒷부분의 작은 숫자를 앞부분으로 빠르게 이동시키고, 앞부분의 큰 숫자를 뒷부분으로 빠르게 이동시키는 알고리즘
- **원소들을 일정한 크기로 나누고 각각 삽입정렬을 실행함.**
- 마지막에는 반드시 크기 1로 하여 전체 삽입정렬을 실행함.

시간 복잡도
- $O(n^2)$

간격에 굉장히 의존적임 
- Hibbard 간격 이용하면 좋음 $O(n^{1.5})$
- 평균은 $O(n^{1.25})$

특징
- 입력이 크면 안됨
- 임베디드 시스템에서 자주 씀

```java
public class ShellSort {

    public static void shellSort(int[] arr) {
        int n = arr.length;

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j = i;

                while (j >= gap && arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
        }
    }
}
```

## S19. 기수 정렬 알고리즘
- 비교정렬 알고리즘은 $O(N \log_2 N)$ 이상의 성능을 못냄.

정의: 전체 값에 대한 비교정렬이 아니라 숫자를 부분적으로 비교하는 정렬 방법

- 기수란, 기(radix)는 특정 진수를 나타내는 숫자들
  - 10진수의 기: 0-9
  - 2진수의 기: 0, 1
- 기수 정렬 알고리즘은 **제한적인 범위 내**에 있는 숫자에 대해서 각 자릿수 별로 정렬하는 알고리즘임
- **자릿수로 비교한다잉**

시간복잡도
- $O(d*(n + k))$ &rarr; $O(n)$ (k, r < n)

특징
- LSD (Least) RL
- MSD (Most) LR

```java
import java.util.ArrayList;
import java.util.List;

public class RadixSort {

    public static void radixSort(int[] arr) {
        int max = getMax(arr);

        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSort(arr, exp);
        }
    }

    private static int getMax(int[] arr) {
        int max = arr[0];
        for (int num : arr) {
            if (num > max) max = num;
        }
        return max;
    }

    private static void countingSort(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n];
        int[] count = new int[10];

        // 자릿수 기준 카운트
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        // 누적 합
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // 안정 정렬을 위해 뒤에서부터
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // 결과 복사
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}
```

## T20. 외부 정렬 알고리즘
보조기억장치A의 전체 덩어리를 주기억장치에서 쪼개고 보조기억장치 B에 쓰면서 정렬함

- 보조기억장치에서 읽고 쓰는 것을 최소화하는 것이 중요함.

시간 복잡도
- k =  $2^kM = M$
-  $O(log_2({n/m}))$