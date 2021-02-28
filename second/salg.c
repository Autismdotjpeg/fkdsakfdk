#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double power(int x, int y)
{
    if( y == 0 )
        return 1;
    else if( y > 1 )
        return x * power(x, y - 1);
    else 
        return x;
}

unsigned long long intconvert(unsigned long long int val)
{
    unsigned long long int newval = 0;
    char arr[100];
    sprintf(arr, "%llu", val);
    int i, len = strlen(arr);
    for(i = 0; i < len ; ++i){
        newval += (arr[i] - 48) * power(3, len - 1 - i);
    }
    return newval;
}


int main()
{
    unsigned long long int i;
    scanf("%llu", &i);
    //if(argc > 0){
        //sscanf(argv[1], "%llu", &i);
        i = intconvert(i);
        printf("%llu\n", i);
    //}
    return 0;
}
