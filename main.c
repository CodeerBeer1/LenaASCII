
#include <stdio.h>
#include <stdlib.h>

int main()
{
 
    int lena[512][512];
    char smallLena[128][128];

    char asciiLarge[] = {" .'`^,:;Il!i><~+fjrxnuvcz0OZmwqpao*#MW&8B@$"};
    char asciiSmall[][2] = { {' ', '0'}, {'.', '1'}, {':', '2'}, {'-', '2'}, {'=', '3'}, {'+', '4'}, {'*', '3'}, {'#', '4'}, {'\%','5'}, {'@', '5'} };

    int greyscaleProportion = 255 / ( sizeof(asciiSmall) / sizeof(asciiSmall[0]) );
    int lenalength[2] = { sizeof(lena[0]) / sizeof(int), sizeof(lena[1]) / sizeof(int) };

    FILE* file = fopen("test.txt", "r");

    //while(!feof(file))
    //{
        char buffer[12];
        fgets(buffer, sizeof(buffer),  file);

        char lenaPiece[3][3];
        int cntr[] = { 0, 0 };

        for(int i = 0; i < sizeof(buffer); i++)
        {
            
            (buffer[i -1] == ' ') ? (cntr[0]++, cntr[1] = 0) : 0;

            (buffer[i] != ' ') ? ( lenaPiece[cntr[0]][cntr[1]] = buffer[i], cntr[1]++) : 0;
            
        }
        
        for(int o = 2; o < 3; o++)
        {
            char str[3];
            for(int u = 1; u < 3; u++)
            {
                str[u] = lenaPiece[o][u];
            }
            printf("%c", lenaPiece[2][0]);
        }
    //}

    /*for(int i = 0; i < lenalength[0]; i++)
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
    }*/

return 0;

}