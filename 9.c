#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* to_hex(int64_t val)
{
    int count = 0 ;
    char  HEX_DIGITS[] = "0123456789abcdef" ;
    char* s = malloc( sizeof(char)*10 ) ;
    if(val < 0)
    {
        int64_t a =1 ;
        val += (a << 32) ;
    }
    
    while(1)
    {
        char d[2] = { HEX_DIGITS[ val & 0xf ], NULL } ;
        char temp[10] = {NULL} ;

        strcat(temp,d);
        strcat(temp,s);

        strcpy(s,temp);

        val = val >> 4 ;
        count++ ; 

        if(val == 0 || count == 8)
        {
            break;
        }
    }
    char f[] = "0x" ;
    strcat(f,s);
    strcpy(s,f);

    return s;
}

main()
{
    int val ;
    printf("Input DEC Number : ");
    scanf("%d", &val);
    char* ans = to_hex(val) ;
    printf("%s\n",ans);
    
    return 0;
}