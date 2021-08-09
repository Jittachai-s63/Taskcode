#include <stdio.h>
#include <stdlib.h>
#include "qsort.c"

int main()
{
    int ch, f_line = 0, i, count ;
    char* line;
    FILE *fp;
    ssize_t read , len = 0 ;

    fp = fopen("data.txt","r");

    while( (ch = fgetc(fp)) != EOF ) 
    {
        if( ch == '\n')
            f_line++;
        
    } 

    fclose(fp);
    //printf("%d",f_line);

    int arr[f_line] ;
    fp = fopen("data.txt","r");

    int round=0;
    while ( (read = getline(&line, &len, fp)) != -1)
    {
        arr[round] = atoi(line) ;
        round++;
    }

    fclose(fp);

    quicksort(arr , 0, f_line-1);

    fp=fopen("data_sorted.txt","w");
    for(int i=0 ; i < f_line ; i++)
    {
        //printf("%d ",arr[i]);
        fprintf(fp,"%d\n",arr[i]);
    }
    fclose(fp);
    return 0;

}