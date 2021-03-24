#include <stdio.h>
#include <string.h>


void reverse(char* string, int lenOfTheString) {
	char temp;
	int i, j;

	// swapping string[i] and string[j] until i<j
	for (i = 0, j = lenOfTheString - 1; i < j; ++i, --j) {
		temp = string[j];
		string[j] = string[i];
		string[i] = temp;
	}
}

void isBigger(char msg[], int start, int end)
{
	int i;
	for(i = start; i < end; ++i){
		if(msg[i] <)
	}
}

int main()
{
  char msg[4002];
  scanf("%s", msg);

  reverse(msg, strlen(msg));

  printf("%s\n", msg);
  return 0;
}
