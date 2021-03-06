
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

int twoRomanLietals(int firstLiteral, int secondLiteral){
  int value = 0;

  int sum = firstLiteral + secondLiteral;
  switch (sum) {
  case 4:
    value = sum;
    break;
  case 9:
    value = sum;
    break;
  case 40:
    value = sum;
    break;
  case 90:
    value = sum;
    break;
  case 900:
    value = sum;
    break;
  }

  return value;

}

void eraseElementsFromAnArray(char* string, int start, int end){
  char tmp[100001];

  int i, j;
  for(i = 0; i < start; ++i){
    tmp[i] = string[i];
  }

  for(j = end + 1; j < (int)strlen(string); ++i, ++j){
    tmp[i] = string[j];
  }

  strcpy(string, tmp);
  return;
}


int rightHand(char* string){
  char tmpString[100001];
  int valueOfTheCouple = 0;

  int i;
  for(i = 0; i < (int)strlen(string) - 1; ++i){
    // Get rid of this couple and keep in mind number they represent
    valueOfTheCouple = twoRomanLietals(romanLiteral(string[i]), romanLiteral(string[i + 1]));
    if(valueOfTheCouple){
      eraseElementsFromAnArray(string, i, i + 1);
    }
  }

  return valueOfTheCouple;
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

  int doubleValue = rightHand(msg);
  int tmp = rightHand(msg);
  while (tmp) {
    tmp = rightHand(msg);
    doubleValue += tmp;
  }
  reverse(msg, strlen(msg));

  int arabic = romanToArabic(msg);

  printf("%d\n", arabic);
  return 0;
}

