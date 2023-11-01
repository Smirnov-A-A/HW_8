/*1. Придумать эллипсис со своим механизмом конроля вводимых параметров*/

#include <stdio.h>
#include <stdarg.h>

//Функция суммирует произвольное количество чисел типа int
//признак конца параметров функции - символ 'x'
int sum(int num1, ...) {

    int sum = 0;
    int a = num1;

    va_list p;
    va_start (p, num1);

    while (a != 'x') {
        sum += a;
        a = va_arg(p, int);
    }
    va_end(p);
    return sum;
}

int main () {

    int res = sum(1, 2, 3, 4, -1, -3, 'x');
    printf("sum = %d\n", res);

    return 0;
}
