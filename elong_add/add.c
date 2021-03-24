#define N 100
#include <stdio.h>


double power(int x, int y)
{
    if( y == 0 )
        return 1;
    else if( y > 1 )
        return x * power(x, y - 1);
    else 
        return x;
}

struct _Decimal {
    char a[N];   // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;       // наибольшая степень десяти
};


typedef struct _Decimal Decimal;


Decimal add(Decimal a, Decimal b)
{
  #include <string.h> 
  #include <stdbool.h>
  Decimal newDecimal;
  int lenFirst = strlen(a.a), 
        lenSecond = strlen(b.a), next = 0, len;
  bool aIsBigger = lenFirst > lenSecond;

  if(aIsBigger){
    len = lenFirst;
  }
  else {
    len = lenSecond;
  }


  int i;
  for (i = 0; i < len; ++i) {

    /*printf("a: %c, b: %c, next: %d\n", a.a[i] + 48, 
                          b.a[i] + 48, next);*/

    int tmp = next + a.a[i] + b.a[i];
    if(tmp >= 10){
      newDecimal.a[i] = tmp % 10;
      next = tmp/ 10;
    }
    else{
      newDecimal.a[i] = tmp;
      next = 0;
    }
    //printf("NewDec: %c\n", newDecimal.a[i]);
  }


  if(aIsBigger){
    // DO some
    for(i = len; i < lenFirst; ++i){
      int tmp = next + a.a[i];
      if(tmp >= 10){
        newDecimal.a[i] = tmp % 10;
        next = tmp / 10;
      }
      else{
        newDecimal.a[i] = tmp;
        next = 0;
      }
    }
  }
  else if(lenFirst < lenSecond){
    // do something else
    for(i = len; i < lenSecond; ++i){
      int tmp = next + b.a[i];
      if(tmp >= 10){
        newDecimal.a[i] = tmp % 10;
        next = tmp / 10;
      }
      else{
        newDecimal.a[i] = tmp;
        next = 0;
      }
    }
  }
  

  newDecimal.a[i + 1] = '\0';

  int biggerPow;
  if(a.n > b.n){
    biggerPow = a.n;
  }
  else{
    biggerPow = b.n;
  }
  newDecimal.n = biggerPow;


  /*int final = 0;
  printf("len: %li\n", strlen(newDecimal.a));
  for(i = 0; i < strlen(newDecimal.a); ++i){
    printf("Num: %c\n", newDecimal.a[i]);
    final += (newDecimal.a[i] - 48) * power(10, i);
  }

  printf("Final: %d\n", final);

  Decimal finalDecimal = {{final}, 0};*/


  return newDecimal;
}
