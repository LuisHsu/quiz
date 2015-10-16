#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxSubArray(int A[],int n)
{
    int max=INT_MIN;
    int cons=0;
    for(int i=1; i<n; ++i) {
        int sum=A[i]+A[i-1];
        int max_plus_a = cons ? (max+A[i]) : INT_MIN;
        if(sum>max) {
            max=sum;
            cons=1;
        } else {
            cons=0;
        }
        if(max_plus_a>max) {
            max=max_plus_a;
            cons=1;
        }
    }
    return max;
}

int main(int argc,char *argv[])
{
    int array[argc-1];
    for(int i=0; i<argc-1; ++i) {
        array[i]=atoi(argv[i+1]);
    }
    printf("%d\n",maxSubArray(array,9));
    return 0;
}
