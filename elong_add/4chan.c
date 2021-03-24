#include <stdio.h>
#include <math.h>

int main()
{
  char arr[100];
  int sum = 35162, power = 4;

  int i;
  for(i = 0; i <= power ; ++i){
      printf("before: %d, arr: %d ", sum, arr[i]);
      arr[i] = sum % (int)pow(10, i + 1);
      sum -= arr[i];
      printf("after: %d, arr: %d\n", sum, arr[i]);
      arr[i] /= (int)pow(10, i );
  }

  return 0;
}


/*I am feeling so retarded, what am I doing wrong?
I have two numbers sum and power, let's say that sum is 35162, and power being digits - 1, so in this case 4.
I want to convert int sum in reverse order to the char array, code works fine until it hits 35000, what am I doing wrong, I don't fucking understand*/
