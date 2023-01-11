
#include <stdio.h>
#include <stdlib.h>

int lena[512][512];

int GenerateLena(int start, int end)
{

    FILE* fileToWrite;
    fileToWrite = fopen("mylena.txt", "w");

    char ascii[][2] = { {' ', '0'}, {'.', '1'}, {':', '2'}, {'-', '2'}, {'=', '3'}, {'+', '4'}, {'*', '3'}, {'#', '4'}, {'\%','5'}, {'@', '5'} };

    int greyscaleProportion = 255 / ( sizeof(ascii) / sizeof(ascii[0]) );
    int lenalength[2] = { sizeof(lena[0]) / sizeof(int), sizeof(lena[1]) / sizeof(int) };
    int avg;

    for(int i = start; i < end; i++)
    {
        for(int o = end; o > start; o--)
        {
            avg += lena[i][o];

            // The image gets mirrored by substracting the total 'x-axis' length with the image starting point.
            int c = (lena[i][o]) / greyscaleProportion;

            // Combines the color code and the corresponding number character into one buffer using sprintf().
            char buffer[10];

            sprintf(buffer, "\033[0;3%cm", ascii[c][1]);
            printf(buffer);
            printf("%c", ascii[c][0]);
            printf("\033[0m");

            // Writes the character to the file where it has to be written into.
            putc(ascii[c][0], fileToWrite);
            
        }
        printf("\n");
        putc('\n', fileToWrite);
    }

    // Returns the calculated average grayscale value.
    return avg / ((end - start) * (end - start));
}

int main()
{

    // Opens the lena.txt file.
    FILE* lenaFile = fopen("lena.txt", "r");

    while(!feof(lenaFile))
    {
        // The significant values are stored in an array.
        int data[3] = {0};

        // i is used for the buffer to be independent of the loop.
        int i = 0;
        char buffer[12] = {0};
        fgets(buffer, sizeof(buffer), lenaFile);
        for (int y = 0; y < 3; y++)
        {
            // A piece of data gets read into _register. 
            // [4] for the last null-character.
            char _register[4] = {0};
            for(int u = 0; u < 4; u++)
            {
                if(buffer[i] != '\t')
                {
                    _register[u] = buffer[i];
                    i++;
                }

                else
                {
                    i++;
                    break;
                }
            }
            data[y] = atoi(_register);
        }

        // Constructing the main lena array using the values.
        lena[data[0]][data[1]] = data[2];
    }

int avg = GenerateLena(100, 400);

printf("%d", avg);

return 0;

}