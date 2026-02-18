#include <stdio.h>

int main() {
    int arr[100];
    int count = 0;
    int num;
    int sum = 0;

    while (1) {
        printf("숫자 입력 (종료: -1) : ");
        scanf("%d", &num);

        if (num == -1)
            break;

        arr[count] = num;
        sum += arr[count];
        count++;

        printf("현재까지의 합: %d\n", sum);
    }

    return 0;
}
