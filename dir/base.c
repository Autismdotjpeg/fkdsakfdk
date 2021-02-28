#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char empty[100] = "";
    char text[10000];
    FILE *ifp, *ofp;
    ifp = fopen("./dir/input.txt", "r");
    ofp = fopen("./dir/output.txt", "w");
    while( !feof(ifp) )
    {
        char line = getc(ifp);
        char fuck[128] = {line};
        if(line != 10){
            strcat(text, fuck);
        }
        else{
            unsigned long long int val;
            sscanf(text, "%llu", &val);
            fprintf(ofp, "%llu\n", val);
            strcpy(text, empty);
        }
    }
    fclose(ifp);
    fclose(ofp);
    return 0;
}
