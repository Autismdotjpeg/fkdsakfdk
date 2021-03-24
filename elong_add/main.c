#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define N 100



struct _Decimal {
    char a[N];   // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;       // наибольшая степень десяти
};


typedef struct _Decimal Decimal;


Decimal add(Decimal first, Decimal second)
{
  #include <string.h>
  Decimal newDecimal;
  //printf("a: %s, n: %d", newDecimal.a, newDecimal.n);
  int lenFirst = strlen(first.a);
  int lenSecond = strlen(second.a);
  int len; 
  //printf("lena: %d, lenb: %d", lenFirst, lenSecond);

  //printf("lenA: %d, lenB: %d, dif:%d\n", lenFirst, lenSecond, dif);

  if(lenFirst > lenSecond) // first is bigger
  {
    len = lenFirst;
  }
  else 
  {
    len = lenSecond;
  }

  int i, next = 0;
  for(i = 0; i < len - 1; ++i)
  {
    //printf("?, %c, %c, next: %d\n", first.a[i] + 48, second.a[i] + 48, next);
    //newDecimal.a[i] = first.a[i] + second.a[i] + 48;
    //newDecimal.a[i] = first.a[i] + second.a[i] ;
    int tmp = next + first.a[i] + second.a[i];
    if(tmp >= 10){
      //newDecimal.a[i] = tmp % 10 ;
      newDecimal.a[i] = tmp % 10 + 48;
      next = tmp / 10;
      //printf("a: %sn", newDecimal.a);
    }
    else{
      newDecimal.a[i] = tmp;
      next = 0;
      //printf("a: %sn", newDecimal.a);
    }
  }
  //printf("a: %s, n: %d\n", newDecimal.a, newDecimal.n);
  if(lenFirst > lenSecond)
  {
    for(i = len; i < lenFirst + 1; ++i)
    {
      //printf("!");
      if(!(next == 0)){
        //newDecimal.a[i] = next + first.a[i] ;
        newDecimal.a[i] = next + first.a[i] + 48;
        next = 0;
      }
      else{
        //newDecimal.a[i] = first.a[i] ;
        newDecimal.a[i] = first.a[i] + 48;
      }
      //newDecimal.a[i] = first.a[i];
    }
  }
  else if(lenFirst < lenSecond)
  {
    for(i = len ; i < lenSecond + 1; ++i)
    {
      if(!(next == 0)){
        //newDecimal.a[i] = second.a[i] ;
        newDecimal.a[i] = second.a[i] + 48;
        next = 0;
      }
      else{
        //newDecimal.a[i] = second.a[i] ;
        newDecimal.a[i] = second.a[i] + 48;
      }
      //newDecimal.a[i] = second.a[i];
    }
  }
  newDecimal.a[i + 1] = '\0';
  int biggerPow;
  if(first.n > second.n)
  {
    biggerPow = first.n;
  }
  else 
  {
    biggerPow = second.n;
  }
  newDecimal.n = biggerPow;
  return newDecimal;
}



Decimal zero = {{0}, 0};    // представление 0 в виде структуры



int main()
{
    Decimal a = {{7, 4, 1}, 2};  // set number 147
    //Decimal a = {{8, 4, 1}, 2};  // set number 147
    Decimal b = {{3, 1}, 1};     // set number 13
    Decimal res;
    
    res = add(a, b);             // res = a+b = 147+13 = 160
    //print(d);                    // print 160
    //printf("\n");statements

    printf("a: %s, n: %d\n", res.a, res.n);
    
    return 0;
}


