#include <stdio.h>

int sum(int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            result += i;
        }
    }
    return result;
}

int main() {
    int n = 100;
    int result = sum(n);
    printf("Sum of even numbers up to %d is %d\n", n, result);
    return 0;
}
