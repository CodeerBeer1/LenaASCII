#include <stdio.h>
#include <stdlib.h>

int lena[512][512];

int printLena(int start, int end)
{

    FILE* fileToWrite;
    fileToWrite = fopen("mylena.txt", "w");

    char ascii[][2] = { {' ', '0'}, {'.', '1'}, {':', '2'}, {'-', '2'}, {'=', '3'}, {'+', '4'}, {'*', '3'}, {'#', '4'}, {'\%','5'}, {'@', '5'} };

    int greyscaleProportion = 255 / ( sizeof(ascii) / sizeof(ascii[0]) );
    int lenalength[2] = { sizeof(lena[0]) / sizeof(int), sizeof(lena[1]) / sizeof(int) };
    int avg;

    for(int i = start; i < end; i++)
    {
        for(int o = start; o < end; o++)
        {
            avg += lena[i][o];
            int c = (lena[i][(lenalength[0] -1) - o]) / greyscaleProportion;
            char buffer[10];
            sprintf(buffer,  "\033[0;3%cm", ascii[c][1]);
            printf(buffer);
            printf("%c", ascii[c][0]);
            printf("\033[0m");

            putc(ascii[c][0], fileToWrite);
            
        }
        printf("\n");
        putc('\n', fileToWrite);
    }

    return avg / ((end - start) * (end - start));
}

int main()
{

    FILE* lenaFile = fopen("lena.txt", "r");

    while(!feof(lenaFile))
    {
        int data[3];
        int i = 0;
        char buffer[12];
        fgets(buffer, sizeof(buffer), lenaFile);
        for (int y = 0; y < 3; y++)
        {
            // [4] for the last nul-character.
            char _register[4];
            for(int u = 0; u < 3; u++)
            {
                _register[u] = buffer[i];
                i++;
            }
            int s = atoi(_register);
            data[y] = s;
            i++;
        }
        lena[data[0]][data[1]] = data[2];
    }

int avg = printLena(100, 400);

printf("%d", avg);

return 0;

}