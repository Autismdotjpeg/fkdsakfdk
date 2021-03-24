#include "difapproach.c"
#include <stdio.h>



  int main(){
    Decimal a = {{8, 1, 4, 8, 5, 8, 2, 5, 3, 1}, 9};  // set number 147
    Decimal b = {{7, 2, 2, 7, 0, 1, 1, 7, 8}, 8};     // set number 13
    Decimal res;
    
    res = add(a, b);             // res = a+b = 147+13 = 160


    int i;
    for(i = 0; i < 10; ++i){
      printf("%d", res.a[i]);
    }
    printf("\n");
    //printf("%s\n", res.a);

    printf("%d\n", res.n);
    
    return 0;
}


