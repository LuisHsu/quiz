#include <stdio.h>
#include <string.h>
#include <limits.h>

char smallest_character(char str[],char c)
{

    for(unsigned int i=0; str[i]!='\0'; ++i) {
        if(str[i]>c) {
            return str[i];
        }
    }
    return c;

}

int main(int argc, char *argv[])
{

    printf("%c\n",smallest_character(argv[1],argv[2][0]));

    return 0;
}
