#include <stdio.h>

#include <string.h>

#include <stdlib.h>


void reverse(char * string, int len) {
  char temp;
  int i, j;

  for (i = 0, j = len - 1; i < j; ++i, --j) {
    temp = string[j];
    string[j] = string[i];
    string[i] = temp;
  }
  return;
}

int romanLiteral(char literal) {
  int value = 0;
  switch (literal) {
  case 'I':
    value = 1;
    break;
  case 'V':
    value = 5;
    break;
  case 'X':
    value = 10;
    break;
  case 'L':
    value = 50;
    break;
  case 'C':
    value = 100;
    break;
  case 'D':
    value = 500;
    break;
  case 'M':
    value = 1000;
    break;
  }
  return value;
}

int romanToArabic(char * string) {
  int arabic = 0;

  int i;
  for (i = 0; i < (int) strlen(string); i += 2) {
    int first = romanLiteral(string[i]), second = 0;
    if (i + 1 < (int) strlen(string)) {
      second = romanLiteral(string[i + 1]);
      //printf("i + 1 < strlen, first: %d, second: %d\n", first, second);
    }
    if (first <= second) {
      arabic += (first + second);
      //printf("first <= second\n");
    } else {
      arabic += abs(second - first);
      //printf("else: first <= second\n");
    }

  }
  return arabic;
}

int main() {
  char msg[100001];
  scanf("%s", msg);
  reverse(msg, strlen(msg));

  int arabic = romanToArabic(msg);

  printf("%d\n", arabic);
  return 0;
}
