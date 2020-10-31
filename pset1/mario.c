#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter a positive number:\n");
    }
    while(height < 1 || height > 8);
    int counter = 0;
    for(int i = 0;i < height;i++)
    {
        for(int j = height-1; j > counter; j--)
        {
           printf(" ");
        }
        for(int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for(int h = 0; h <= i;h++)
        {
            printf("#");
        }
        counter++;
        printf("\n");
    }

}