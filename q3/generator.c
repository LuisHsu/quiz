#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    FILE *fout=fopen("test.txt","w");

    srand(time(NULL));

    for(int i=0; i<atoi(argv[1]); ++i) {
        int size = rand() % 40;
        int dataArr[400];
        for(int j=0; j<=400; ++j) {
            dataArr[j] = 0;
        }
        // generate
        for(int j=0; j<=size; ++j) {
            int data = rand()%30+1;
            if((j!=0)&&(j!=2)&&((j%3)!=0)) {
                if(!(rand()%3)) {
                    dataArr[j]=0;
                } else {
                    dataArr[j]=data;
                }
            } else {
                dataArr[j]=data;
            }
            fprintf(fout,"%d ",dataArr[j]);
        }
        fprintf(fout,"\n");
    }
    fclose(fout);
    return 0;
}
