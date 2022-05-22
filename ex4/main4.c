#include <stdio.h>
#include <stdlib.h>
int cate_tipuri_monede = 4;

int da_rest(int rest, int *monede, int tip_moneda, int *mod_rest)
{
    if(tip_moneda >= cate_tipuri_monede - 1)
    {
        mod_rest[tip_moneda] = rest / monede[tip_moneda]; 
        for(int i = 0; i < cate_tipuri_monede; i++)
            printf("%d de %d ori\n", monede[i], mod_rest[i]);
        printf("\n");    
        return 1;
    }   

    int cate_moduri = 0;
    int val = monede[tip_moneda];
    int i, ce_ramane;

    for(i = 0; i * val <= rest; i++)
    {
        ce_ramane = rest - i * val;
        mod_rest[tip_moneda] = i;
        cate_moduri += da_rest(ce_ramane, monede, tip_moneda + 1, mod_rest);
    }

    return cate_moduri;    
}

int da_rest_memo(int rest, int nr_monede, int *monede)
{
    int i, j;
    int **aux = (int**)malloc(sizeof(int*) * (rest + 1));

    for(i = 0; i <= rest; i++)
    {
        aux[i] = (int*)malloc(sizeof(int) * nr_monede);
    }

    for(i = 0; i <= rest; i++)
    {
        for(j = 0; j < nr_monede; j++)
        {
            if(i == 0)
                aux[i][j] = 1;
            else
            if(j == 0)
            {
                if(i % monede[j] == 0)
                    aux[i][j] = 1;
                else
                    aux[i][j] = 0;
            }
            else
                if (monede[j] > i)
                    aux[i][j] = aux[i][j - 1];
            else
                aux[i][j] = aux[i - monede[j]][j] + aux[i][j - 1];
        }
    }

    return aux[rest][nr_monede-1];
}

int main()
{
    int n;
    int mod_rest[4] = {0};
    int monede[4] = {25, 10, 5, 1};

    printf("Ce rest vreti sa dati?\n");
    scanf("%d", &n);
    printf("Se da rest pentru %d.\n\n", n);

    printf("%d\n", da_rest(n, monede, 0, mod_rest));
    printf("Numar de cate ori se poate da rest, folosind memoizare: ");
    printf("%d", da_rest_memo(n, 4, monede));
     
    return 0;
}

