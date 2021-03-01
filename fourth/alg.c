#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



void reverse(char* string, int n) {

	char temp;
	int i, j;

	// swapping string[i] and string[j] until i<j
	for (i = 0, j = n - 1; i < j; ++i, --j) {
		temp = string[j];
		string[j] = string[i];
		string[i] = temp;
	}

}


void add_zeroes(char x[], int needed_size)
{
  int i;
  for (i = 0; i < needed_size; ++i) {
    x[i] = 48;
  }
  x[i] = '\0';
  //printf("zero%s\n", x);
}

void sum(char x[], char c[], int size)
{
  int i, temp;
  bool next = 0;
  for (i = size - 1; i >= 0; --i) {
    temp = c[i] + x[i];
    //printf("%d\n", temp);
    if(temp == 96)        // 0 + 0
    {
      //printf("IF96\n");
      if(next )       // got 1
      {
        //printf("A\n");
        next = 0;
        c[i] = 49;
        continue;
      }
      else{
        c[i] = 48;
        continue;
      }
    }
    if(temp == 97)
    {
      //printf("IF97\n");
      if(next )
      {
        next = 1;
        c[i] = 48;
        continue;
      }
      else {
        c[i] = 49;
        continue;
      }
    }
    if(temp == 98)    // 1 + 1
    {
      //printf("IF98\n");
      if(next )
      {
        //printf("B\n");
        c[i] = 49;
        next = 1;
        continue;
      }
      else{
        c[i] = 48;
        next = 1;
        continue;
      }
    }
  }
  if(next) 
  {
    printf("1");
  }
  printf("%s\n", c);
  /*if(next) 
  {
    printf("1\n");
  }
  else {
    printf("\n");
  }*/
}


bool check_if_all_zeroes(char a[], char b[], int sizeA, int sizeB)
{
  int i;
  bool zero = 1;
  for (i = 0; i < sizeA && zero ; ++i ) {
   if (a[i] == 48) {
    continue;
   } 
   else {
    zero = 0;
    return zero;
   }
  }

  for (i = 0; i < sizeB && zero ; ++i ) {
   if (b[i] == 48) {
    continue;
   } 
   else {
    zero = 0;
    return zero;
   }
  }
   return zero;
}
int main()
{
  char a[1100], b[1100], x[1100];
  //int size;
  //bool a_is_bigger = 0;
  scanf("%s %s", a, b);
  int lenA = strlen(a), lenB = strlen(b);
  //reverse_string(a, lenA);
  //reverse_string(b, lenB);
  //printf("%d %d\n", lenA, lenB);
  if(check_if_all_zeroes(a, b, lenA, lenB))
  {
    printf("0");
    return 0;
  }
  if(lenA < lenB)
  {
    int size = lenB - lenA;
    add_zeroes(x,  size);
    //printf("zero: %s\n", x);
    strcat(x, a);
    //printf("%s\n%s\n\n\n", a, b);
    //printf("cantatenaited string %s\n", x);
    //reverse(a, lenB);
    //reverse(b, lenB);
    sum(x, b, lenB);
  }
  else if(lenA > lenB)
  {
    int size = lenA - lenB;
    //a_is_bigger = 1;
    //printf("A IS BIGGER\n");
    add_zeroes(x, size);
    //printf("zero%s\n", x);
    strcat(x, b);
    //printf("cantatenaited string %s\n", x);
    //printf("%s", b);
    //printf("%s\n%s\n\n\n", a, b);
    //reverse(a, lenA);
    //reverse(b, lenA);
    sum(x, a, lenA);
  }
  else{
    //reverse(a, lenA);
    //reverse(b, lenA);
    sum(b, a, lenA);
  }
  //printf("%s\n%s\n\n\n", a, b);
  return 0;
}
