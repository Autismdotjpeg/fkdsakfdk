#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void add_zeroes(char x[], int needed_size)
{
  int i;
  for (i = 0; i < needed_size; ++i) {
    x[i] = '0';
  }
  x[i] = '\0';
}

void same_length(char a[], char b[], char x[], 
														int lenA, int lenB)
{
	int needed_size;
	if(lenA > lenB)
	{
		needed_size = lenA - lenB;
		add_zeroes(x, needed_size);
		strcat(x, b);
		strcpy(b, x);
	}
	else if(lenB > lenA)
	{
		needed_size = lenB - lenA;
		add_zeroes(x, needed_size);
		strcat(x, a);
		strcpy(a, x);
	}
}

void different_cases(char a, char b, char *next, char x[], int i)
{
	int sum = a + b; 			// 96(0 + 0), 97(0 + 1)(1 + 0), 98(1 + 1)
	if(sum == 96){
		if(*next == '1'){
			//printf("96NEXT %c\n", *next);
			x[i] = '1';
			*next = '0';
		}
		else{
			//printf("96\n %c", *next);
			x[i] = '0';
		}
	}
	else if(sum == 97){
		if(*next == '1'){
			//printf("97NEXT\n %c", *next);
			x[i] = '0';
		}
		else{
			//printf("97\n %c", *next);
			x[i] = '1';
		}
	}
	else{
		if(*next == '1'){
			//printf("98NEXT %c\n", *next);
			x[i] = '1';
		}
		else {
			x[i] = '0';
			//printf("98 %c\n", *next);
			*next = '1';
		}
	}
}

void sum(char a[], char b[], int size, char x[])
{
	int i;
	char next = '0';
	for (i = size - 1; i >= 0; --i) {
		different_cases(a[i], b[i], &next, x, i);
	}
	x[size] = '\0';
	if(next == '1'){
		strcpy(a, "1");
		strcat(a, x);
		strcpy(x, a);
	}
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
	scanf("%s %s", a, b);
  int lenA = strlen(a), lenB = strlen(b);
  if(check_if_all_zeroes(a, b, lenA, lenB))
  {
    printf("0");
    return 0;
  }
	same_length(a, b, x, lenA, lenB);
	//printf("\n\n\n%s %s\n\n\n", a, b);
	sum(a, b, strlen(a), x);
	printf("%s\n", x);
}
