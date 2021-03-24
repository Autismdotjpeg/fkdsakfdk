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


ulli convert_to_base_16(char* argv)
{
    ulli y = 0;
    char arr[1000001];
    strcpy(arr, argv);
    int len = strlen(arr), i;
    for(i = 0; i < len; ++i)
    {
        ulli temp = arr[i];
        if(temp < 58)         // This is a number
            y += (temp - 48) * power(16, len - 1 - i);  
        else if( temp > 64 && temp < 91 ) // Upper case letter
            y += (temp - 55) * power(16, len - 1 - i);
        else
            y += (temp - 87) * power(16, len - 1 - i);

    }
    return y;
}

void reverse(char* string, int len) {

	char temp;
	int i, j;

	// swapping string[i] and string[j] until i<j
	for (i = 0, j = len - 1; i < j; ++i, --j) {
		temp = string[j];
		string[j] = string[i];
		string[i] = temp;
	}

}

void convert_to_base_2(ulli x)
{
    char bin[100000];
    //char arr[1000000];
    //sprintf(arr, "%lli", x);

    int rem, i = 0;
    ulli tmp = x;
    while(!(tmp == 0 || tmp == 1))
    {
        // Do something    
        rem = tmp % 2;
        //printf("tmp: %lli, rem: %d\n", tmp, rem);
        tmp /= 2;
        bin[i] = rem + 48;
        ++i;
    }
    if(tmp == 1)
    {
        bin[i] = '1';
    }
    bin[i + 1] = '\0';
    
    int len = strlen(bin);
    reverse(bin, len);


    printf("%s\n", bin);

}

int main()
{
  char hexNum[1000001];
  scanf("%s", hexNum);
  ulli x = convert_to_base_16(hexNum);

  //printf("ulli: %lli, string: %s\n", x, hexNum);

  convert_to_base_2(x);
  return 0;
}


