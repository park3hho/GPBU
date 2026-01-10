#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num01, num02;

    printf("첫번째 정수를 입력하세요: ");
    // &는 따옴표 밖에 있어야 하며, 형식 지정자(%d)와 쉼표(,)로 구분됩니다.
    scanf("%d", &num01);

    printf("두번째 정수를 입력하세요: ");
    scanf("%d", &num02);

    // 출력할 때는 주소(&)가 아니라 변수 이름만 사용하여 '값'을 더합니다.
    printf("입력하신 두 정수의 합은 %d입니다.\n", num01 + num02);

    return 0;
}