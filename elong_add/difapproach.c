#include <stdio.h>
#define N 100



struct _Decimal {
    char a[N];   // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;       // наибольшая степень десяти
};


typedef struct _Decimal Decimal;

    /*for(i = 1; i <= power + 1; ++i){
        printf("before: %d, arr: %d ", sum, arr[i - 1]);
        arr[i - 1] = sum % (int)powerf(10, i);
        sum -= arr[i - 1];
        printf("after: %d, arr: %d, num: %d\n", sum, arr[i - 1],
                        5000 % (int)powerf(10, i));
        arr[i - 1] /= (int)powerf(10, i - 1);

        newDecimal.a[i - 1] = arr[i - 1];

        //printf("%d\n", arr[i - 1]);
    }*/

    /*/for(i = 0; i <= power ; ++i){
        printf("before: %d, arr: %d ", sum, arr[i]);
        arr[i] = sum % (int)pow(10, i + 1);
        sum -= arr[i];
        printf("after: %d, arr: %d\n", sum, arr[i]);
        arr[i] /= (int)pow(10, i );

        newDecimal.a[i] = arr[i];

        //printf("%d\n", arr[i - 1]);
    }
    newDecimal.a[i + 1] = '\0';*/
double powerf(int x, int y)
{
    if( y == 0 )
        return 1;
    else if( y > 1 )
        return x * powerf(x, y - 1);
    else 
        return x;
}


#include <math.h>
#include <string.h>
#include <stdlib.h>



Decimal add(Decimal a, Decimal b)
{
    int sumA = 0, sumB = 0, i;
    for(i = 0; i < (int)strlen(a.a); ++i){
        sumA += a.a[i] * pow(10, i);
    }

    for(i = 0; i < (int)strlen(b.a); ++i){
        sumB += b.a[i] * pow(10, i);
    }

    int sum = sumA + sumB, power;
    if(a.n > b.n){
        power = a.n;
    }
    else {
        power = b.n;
    }
    
    // WO
    if(sum >= (int)pow(10, power)){
        ++power;
    }

    // WO


    Decimal newDecimal;
    char arr[100];

    for(i = 0; i <= power ; ++i){
        arr[i] = sum % 10;
        sum /= 10;
        newDecimal.a[i] = arr[i];
    }
    printf("4 :%d\n", i);

    newDecimal.n = power;

    return newDecimal;
}
