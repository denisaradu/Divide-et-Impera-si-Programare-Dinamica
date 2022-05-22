#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fibbo(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibbo(n - 1) + fibbo(n - 2);        
}

int fibnegativ(int n)
{
    if(n < 0)
    {
        n = -n;
        if(n % 2 == 0)  
            return -fibbo(n);
    }
    return fibbo(n);
}

int fibmemo(int n, int memo[])
{
    if(n == 0 || n == 1)
        return n;
    if(memo[n] == 0)
        memo[n] =  fibmemo(n-1, memo) + fibmemo(n-2, memo);
    return memo[n];       
}

int fibmemoneg(int n, int memo[])
{
    if(n < 0)
    {
        n = -n;
        if(n % 2 == 0)  
            return -fibmemo(n, memo);
    }
    return fibmemo(n, memo);
}

int main()
{
    srand(time(0));
    int n, rezultat, *memo;

    n = rand() % 80 - 40;

    printf("Calculam sirul lui Fibonacci pentru n = %d\n", n);
    
    if(n >= 0)
        memo = calloc(n + 1, sizeof(int));
    else
        memo = calloc(-n + 1, sizeof(int));

    clock_t i, d;

    i = clock();
    rezultat = fibnegativ(n);
    d = clock();

    printf("%d %f\n", rezultat, (double)(d - i)/ CLOCKS_PER_SEC);

    i = clock();
    rezultat = fibmemoneg(n, memo);
    d = clock();
    printf("%d %f\n", rezultat, (double)(d - i)/ CLOCKS_PER_SEC);

    free(memo);
}