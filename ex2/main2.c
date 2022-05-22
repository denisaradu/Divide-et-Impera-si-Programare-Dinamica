#include <stdio.h>
#include <math.h>
#define err 0.00001

float logaritm(float n, float s, float d)
{
    float x = (s + d) / 2;

    if((n - pow(10, x) < err) && (pow(10, x) - n < err))
        return x;
    else
    {
        if(pow(10, x) < n)
        {
            return logaritm(n, x, d);
        }
        else
        {
            return logaritm(n, s, x);
        }
    }    
}

float logaritm10(float n)
{
    if(n < 1.0)
    {
        return -logaritm(1/n, 0, 1/n);
    }
    else
        return logaritm(n, 0, n);
}

int main()
{
    float n;

    printf("Introduceti valoarea pentru care cautati logaritmul zecimal.\n");
    scanf("%f", &n);

    printf("%f\n", logaritm10(n));

    return 0;
}