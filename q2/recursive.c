#include <stdio.h>

char recursive(char str[], char c, int head, int tail)
{
    if(head==tail) {
        if(str[head] > c) {
            return str[head];
        }
        return str[head+1];
    }
    int mid = (tail+head)/2;
    if(str[mid] > c) {
        return recursive(str, c, head, mid);
    } else {
        return recursive(str, c, mid+1, tail);
    }
}

char smallest_character(char str[], char c)
{
    // Get size
    int tail = 0;
    while(str[tail]!='\0') {
        tail++;
    }
    // compare tail
    if(c >= str[tail-1]) {
        return str[0];
    }
    // recursive
    return recursive(str, c, 0, tail-1);
}

int main(int argc, char *argv[])
{
    printf("%c\n",smallest_character(argv[1],argv[2][0]));

    return 0;
}
