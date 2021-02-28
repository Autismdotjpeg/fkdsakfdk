#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void reverse_string(char oldarr[], char newarr[], char empty[])
{
    strcpy(newarr, empty);
    int i, j = 0;
    for(i = strlen(oldarr) - 1; i >= 0; --i)
    {
        newarr[j] = oldarr[i];
        ++j;
    }
    newarr[j] = '\0';
}

void foo(unsigned long long int *val, char arr[], 
            char empty[], char newarr[])
{
    strcpy(arr, empty);
    unsigned long long int base = *val;
    int reminder = INT_MAX;
    while(base != 0) {
        reminder = base % 8;
        base /= 8;
        char rem[100] = {reminder + 48};
        strcat(arr, rem);
    }
    reverse_string(arr, newarr, empty);
}

int main()
{
    char empty[100] = "";
    char text[10000], newarr[1000];
    //FILE *ifp, *ofp;
    //ifp = fopen("./input.txt", "r");
    //ofp = fopen("./output.txt", "w");
    //while( !feof(ifp) )
    //{
        //char line = getc(ifp);
        //char A[128] = {line};
        //if(line != 10){
            //strcat(text, A);
        //}
        //else{
            unsigned long long int val;
            scanf("%llu", &val);
            //sscanf(text, "%llu", &val);
            
            foo(&val, text, empty, newarr);

            printf("%s\n", newarr);

            //fprintf(ofp, "%s\n", newarr);
            strcpy(text, empty);
        //}
    //}
    //fclose(ifp);
    //fclose(ofp);
    return 0;
}
