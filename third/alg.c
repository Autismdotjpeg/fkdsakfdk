#include <stdio.h>
#include <string.h>

typedef unsigned long long int ulli;

double power(int x, int y)
{
    if( y == 0 )
        return 1;
    else if( y > 1 )
        return x * power(x, y - 1);
    else 
        return x;
}

ulli convert_base_27(char* argv)
{
    ulli z = 0;
    char arr[1000];
    strcpy(arr, argv);
    int len = strlen(arr), i;
    for(i = 0; i < len; ++i)
    {
        ulli temp = arr[i];
        if(temp < 58)         // This is a number
            z += (temp - 48) * power(27, len - 1 - i);  
        else if( temp > 64 && temp < 91 ) // Upper case letter
            z += (temp - 55) * power(27, len - 1 - i);
        else
            z += (temp - 87) * power(27, len - 1 - i);

    }
    return z;
}

ulli convert_base_16(char* argv)
{
    ulli y = 0;
    char arr[1000];
    strcpy(arr, argv);
    int len = strlen(arr), i;
    for(i = 0; i < len; ++i)
    {
        ulli temp = arr[i];
        if(temp < 58)         // This is a number
            y += (temp - 48) * power(16, len - 1 - i);  
        else if( temp > 64 && temp < 16 ) // Upper case letter
            y += (temp - 55) * power(16, len - 1 - i);
        else
            y += (temp - 87) * power(16, len - 1 - i);

    }
    return y;
}

int main(int argc, char* argv[])
{
    if(argc > 0){
        ulli y, z;
        double x;
        char hex[1000];
        //sscanf(argv[1], "%llu", &z);
        z = convert_base_27(argv[1]);
        scanf("%lf %s", &x, hex);
        y = convert_base_16(hex);
        //printf("%lf\n%llu\n%llu\n\n%lf\n", x, y, z, x + y + z);
        printf("%0.3lf\n", x + y + z);
    }
    return 0;
}
