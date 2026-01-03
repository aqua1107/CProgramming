#include <stdio.h>

// 윈도우에서 파이썬이 이 함수를 찾을 수 있게 '간판'을 다는 문법입니다 (__declspec)
__declspec(dllexport) int is_prime(int n) {
    if (n < 2) return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}