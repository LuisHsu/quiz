#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // generate
    char gcmd[strlen(argv[2])+20];
    sprintf(gcmd,"./generator %s",argv[2]);
    system(gcmd);
    printf("Test data generated!\n");
    // initialize
    FILE *fin=fopen("test.txt","r");
    double timeSum=0,start=0,interval=0,times[atoi(argv[2])];
    int testCount=0,min=INT_MAX,max=0;
    char testData[162];
    while(fgets(testData,162,fin)!=NULL) {
        printf("Start test %d ...\n",testCount);
        // prepare
        char command[strlen(argv[1])+162];
        sprintf(command,"./%s %s",argv[1],testData);
        // execute
        FILE *pexec;
        start=clock();
        if((pexec=popen(command,"r"))==NULL) {
            printf("Test %d error\n",testCount);
            continue;
        }
        // time
        interval=(double)(clock()-start)*1000000/(double)CLOCKS_PER_SEC;
        pclose(pexec);
        timeSum+=interval;
        times[testCount]=interval;
        min=(((int) interval)<min) ? interval : min;
        max=(((int) interval)>max) ? interval : max;
        printf("Test %d finished\n",testCount);
        testCount++;

    }
    // Frequency
    int freq[max+1-min];
    for(int i=0; i<=(max-min); ++i) {
        freq[i]=0;
    }
    for(int i=0; i<testCount; ++i) {
        freq[((int)times[i])-min]=freq[((int)times[i])-min]+1;
    }
    printf("=== RESULT ===\n");
    printf("Test count: %d\n",testCount);
    printf("Average time: %lf micro seconds\n",timeSum/testCount);
    FILE *fq=fopen("time_freq.txt","w");
    for(int i=0; i<=(max-min); ++i) {
        fprintf(fq,"%d %d\n",i+min,freq[i]);
    }
    fclose(fq);
    fclose(fin);
    system("rm test.txt");

    return 0;
}
