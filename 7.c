#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main () 
{
    int n,temp ;

    FILE *fp;
    fp  = fopen ("data.txt", "w");

    printf("Enter N: ");
    scanf("%d",&n);

    srand(time(NULL));

    for(int i = 0; i<n; i++)
    {
        temp = rand() %1000 ;
        fprintf(fp, "%d\n", temp);
    }
    fclose(fp);
}

