#include <stdio.h>
#define err 0.00001

float radical(float n, float s, float d)
{
    float x = (s + d) / 2;

    if((x * x - n < err) && (n - x * x < err))
        return x;
    else
    {
        if(x * x < n)
        {
            return radical(n, x, d);
        }
        else
        {
            return radical(n, s, x);
        }
    }    
}

float radical3(float n, float s, float d)
{
    float x = (s + d) / 2;

    if((x * x * x - n < err) && (n - x * x * x < err))
        return x;
    else
    {
        if(x * x * x < n)
        {
            return radical3(n, x, d);
        }
        else
        {
            return radical3(n, s, x);
        }
    }    
}

int main()
{
    float n;

    printf("Introduceti valoarea pentru care cautati radacina patrata.\n");
    scanf("%f", &n);

    printf("%f\n", radical(n, 0, n));

    printf("Introduceti valoarea pentru care cautati radacina cubica.\n");
    scanf("%f", &n);

    printf("%f\n", radical3(n, 0, n));

    return 0;
}