#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    int fileNum = 0;
    char fileName[50];
    FILE *input = fopen(argv[1], "r");
    if(input == NULL){return 1;}

    int bytes[512];
    while(1)
    {
        for(int i = 0; i < 512; i++)
        {
            fread(&bytes[i], sizeof(BYTE), 1, input);
        }
        OUTER:;
        if(feof(input) != 0){return 0;}
        if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] <= 0xef && bytes[3] >= 0xe0))
        {
            if(fileNum == 0 || fileNum < 10)
            {
                sprintf(fileName, "00%d.jpg", fileNum);
            }
            else
            {
                sprintf(fileName, "0%d.jpg", fileNum);
            }
            FILE *output = fopen(fileName, "w");
            while(1)
            {
                for(int i = 0; i < 512; i++)
                {
                    fwrite(&bytes[i], sizeof(BYTE), 1, output);
                }
                for(int i = 0; i < 512; i++)
                {
                    bytes[i] = 0;
                    fread(&bytes[i], sizeof(BYTE), 1, input);
                }
                if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] <= 0xef && bytes[3] >= 0xe0))
                {
                    fileNum++;
                    fclose(output);
                    goto OUTER;
                }
                else
                {
                    if(feof(input) != 0){return 0;}
                }
            }
        }
    }
}
