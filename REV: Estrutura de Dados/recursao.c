#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int potencia(int base, int exp)
{
    if (exp == 1)
    {
        return base;
    }

    return base * potencia(base, exp - 1);
}

int fat(int n)
{
    int total = 1;
    if (n == 1)
    {
        return n;
    }
    else
    {
        return n * fat(n - 1);
    }
}

int main()
{
    int v = potencia(2, 4);
    printf("%i\n", v);

    int f = fat(2);
    printf("%i", f);

    return 0;
}