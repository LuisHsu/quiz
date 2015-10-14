#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cmp(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b) ;
}

char smallest_character(char str[],char c)
{
    for(unsigned int i=0; str[i]!='\0'; ++i) {
        if(str[i]>c) {
            return str[i];
        }
    }
    return str[0];
}

int main(int argc, char *argv[])
{
    FILE *fout=fopen("test.txt","w");

    srand(time(NULL));
    char characters[26] = "abcdefghijklmnopqrstuvwxyz";

    for(int i=0; i<atoi(argv[1]); ++i) {
        int size = rand() % 80;
        char outp[size+2];
        // generate
        for(int j=0; j<=size; ++j) {
            outp[j] = characters[rand()%26];
        }
        outp[size+1] = '\0';
        // sort
        qsort((void *)outp, size+1, sizeof(char), cmp);
        // remove repeat
        int rsize=0;
        char routp[size+2];
        for(int j=0; j<=size;) {
            if(rand()%5) {
                char last=outp[j];
                while((j<=size)&&(outp[j]==last)) {
                    j++;
                }
                routp[rsize]=last;
                rsize++;
            } else {
                routp[rsize]=outp[j];
                rsize++;
                j++;
            }
        }
        routp[rsize]='\0';
        char c=characters[rand()%26];
        fprintf(fout,"%s %c %c\n",routp,c,smallest_character(routp,c));
    }
    fclose(fout);
    return 0;
}
