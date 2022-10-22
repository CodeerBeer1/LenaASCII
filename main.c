#include <stdio.h>
#include "lenaArray.h"

int main()
{
 
    char asciiLarge[] = {" .'`^,:;Il!i><~+fjrxnuvcz0OZmwqpao*#MW&8B@$"};
    char asciiSmall[][2] = { {' ', '0'}, {'.', '1'}, {':', '2'}, {'-', '2'}, {'=', '3'}, {'+', '4'}, {'*', '3'}, {'#', '4'}, {'\%','5'}, {'@', '5'} };

    int greyscaleProportion = 255 / ( sizeof(asciiSmall) / sizeof(asciiSmall[0]) );
    int lenalength[2] = { sizeof(lena[0]) / sizeof(int), sizeof(lena[1]) / sizeof(int) };

    for(int i = 0; i < lenalength[0]; i++)
    {
        for(int o = 0; o < lenalength[1]; o++)
        {
            int c = (lena[i][(lenalength[0] -1) - o]) / greyscaleProportion;
            char buffer[10];
            
            sprintf(buffer,  "\033[0;3%cm", asciiSmall[c][1]);
            printf(buffer);
            printf("%c", asciiSmall[c][0]);
            printf("\033[0m");
            
        }
        printf("\n");
    }

return 0;

}