#include <stdio.h>
#include <stdlib.h>

int main()
{
 
    int lena[512][512];

    char asciiSmall[][2] = { {' ', '0'}, {'.', '1'}, {':', '2'}, {'-', '2'}, {'=', '3'}, {'+', '4'}, {'*', '3'}, {'#', '4'}, {'\%','5'}, {'@', '5'} };

    int greyscaleProportion = 255 / ( sizeof(asciiSmall) / sizeof(asciiSmall[0]) );
    int lenalength[2] = { sizeof(lena[0]) / sizeof(int), sizeof(lena[1]) / sizeof(int) };

    FILE* file = fopen("test.txt", "r");

    //while(!feof(file))
    //{

        char buffer[12];
        fgets(buffer, sizeof(buffer),  file);

        char _registers[3][3];
        int i = 0;
        for(int a = 0; a < 3; a++)
        {
            for (int f = 0; f < 3; i++)
            {
                if(buffer[i] != 32)
                {
                    _registers[a][f] =+ buffer[i];
                    
                    //printf("%c", _registers[a][f]);
                    f++;
                }
                else
                {
                    _registers[a][f] =+ ' ';
                }
            }
        }
       // int s = atoi(buffer);

        printf("%c", _registers[1][1]);

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