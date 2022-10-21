#include <stdio.h>
#include "lenaArray.h"

int main()
{
 
    char asciiLarge[] = {" .'`^,:;Il!i><~+fjrxnuvcz0OZmwqpao*#MW&8B@$"};
    char asciiSmall[] = {" .:-=+*#\%@"};
    int greyscaleProportion = 255 /  sizeof(asciiSmall);
    int lenalength[2] = { sizeof(lena[0]) / sizeof(int), sizeof(lena[1]) / sizeof(int) };

    for(int i = 0; i < lenalength[1]; i++)
    {
        for(int o = 0; o < lenalength[0]; o++)
        {
            int c = (lena[i][511 - o]) / greyscaleProportion;
            printf("%c", asciiSmall[c]);
        }
        printf("\n");
    }

return 0;

}