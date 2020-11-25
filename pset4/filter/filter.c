#include "helpers.h"
#include <stdio.h>
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int averageColor = 0;
    for(int column = 0; column < height; column++)
    {
        for(int row = 0; row < width; row++)
        {
            averageColor = round((image[column][row].rgbtRed + image[column][row].rgbtGreen + image[column][row].rgbtBlue) / 3.0 );
            image[column][row].rgbtRed = averageColor;
            image[column][row].rgbtGreen = averageColor;
            image[column][row].rgbtBlue = averageColor;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed;
    int originalGreen;
    int originalBlue;
    for(int column = 0; column < height; column++)
    {
        for(int row = 0; row < width; row++)
        {
            originalRed = image[column][row].rgbtRed;
            originalGreen = image[column][row].rgbtGreen;
            originalBlue = image[column][row].rgbtBlue;
            if( round( (0.393 * originalRed) + (0.769 * originalGreen) +(0.189 * originalBlue) ) > 255 )
            {
                image[column][row].rgbtRed = 255;
            }
            else
            {
               image[column][row].rgbtRed = round( (0.393 * originalRed) + (0.769 * originalGreen) +(0.189 * originalBlue) );
            }
            if(round( (0.349 * originalRed) +(0.686 * originalGreen) +(0.168 * originalBlue)) > 255)
            {
                image[column][row].rgbtGreen = 255;
            }
            else
            {
                image[column][row].rgbtGreen = round( (0.349 * originalRed) +(0.686 * originalGreen) +(0.168 * originalBlue));
            }
            if( round((0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue)) > 255)
            {
                image[column][row].rgbtBlue  = 255;
            }
            else
            {
                image[column][row].rgbtBlue  =round((0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue));
            }


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE relfection[height][width];
    int reflectedRow = width-1;

    for(int column = 0; column < height; column++)
    {
        for(int row = 0; row < width; row++, reflectedRow--)
        {
            relfection[column][row].rgbtRed = image[column][reflectedRow].rgbtRed;
            relfection[column][row].rgbtGreen = image[column][reflectedRow].rgbtGreen;
            relfection[column][row].rgbtBlue = image[column][reflectedRow].rgbtBlue;


        }
        reflectedRow = width-1;
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = relfection[i][j].rgbtRed;
            image[i][j].rgbtGreen = relfection[i][j].rgbtGreen;
            image[i][j].rgbtBlue = relfection[i][j].rgbtBlue;


        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE BluredImage[height][width];
    int avgRed = 0;
    int avgGreen = 0;
    int avgBlue = 0;
    double numberOfPixels = 0.0;
    for(int column = 0; column < height; column++)
    {
        for(int row = 0; row < width; row++)
        {
                avgRed += image[column][row].rgbtRed;
                avgGreen += image[column][row].rgbtGreen;
                avgBlue += image[column][row].rgbtBlue;
                numberOfPixels++;
            if(column-1 >= 0 && row-1 >= 0)
            {
                avgRed += image[column-1][row-1].rgbtRed;
                avgGreen += image[column-1][row-1].rgbtGreen;
                avgBlue += image[column-1][row-1].rgbtBlue;
                numberOfPixels++;
            }
            if(row-1 >= 0)
            {
                avgRed += image[column][row-1].rgbtRed;
                avgGreen += image[column][row-1].rgbtGreen;
                avgBlue += image[column][row-1].rgbtBlue;
                numberOfPixels++;
            }
            if(column-1 >= 0)
            {
                avgRed += image[column-1][row].rgbtRed;
                avgGreen += image[column-1][row].rgbtGreen;
                avgBlue += image[column-1][row].rgbtBlue;
                numberOfPixels++;
            }
            if(column-1 >= 0 && row+1 < width)
            {
                avgRed += image[column-1][row+1].rgbtRed;
                avgGreen += image[column-1][row+1].rgbtGreen;
                avgBlue += image[column-1][row+1].rgbtBlue;
                numberOfPixels++;
            }
            if(row+1 < width)
            {
                avgRed += image[column][row+1].rgbtRed;
                avgGreen += image[column][row+1].rgbtGreen;
                avgBlue += image[column][row+1].rgbtBlue;
                numberOfPixels++;
            }
            if(column+1 < width && row-1 >= 0)
            {
                avgRed += image[column+1][row-1].rgbtRed;
                avgGreen += image[column+1][row-1].rgbtGreen;
                avgBlue += image[column+1][row-1].rgbtBlue;
                numberOfPixels++;
            }
            if(column+1 < width)
            {
                avgRed += image[column+1][row].rgbtRed;
                avgGreen += image[column+1][row].rgbtGreen;
                avgBlue += image[column+1][row].rgbtBlue;
                numberOfPixels++;
            }
            if(column+1 < width && row+1 < width)
            {
                avgRed += image[column+1][row+1].rgbtRed;
                avgGreen += image[column+1][row+1].rgbtGreen;
                avgBlue += image[column+1][row+1].rgbtBlue;
                numberOfPixels++;
            }
            BluredImage[column][row].rgbtRed = round(avgRed / numberOfPixels);
            BluredImage[column][row].rgbtGreen = round(avgGreen / numberOfPixels);
            BluredImage[column][row].rgbtBlue = round(avgBlue / numberOfPixels);
            numberOfPixels = 0.0;
            avgRed = 0;
            avgGreen = 0;
            avgBlue = 0;
        }

    }
<<<<<<< HEAD:pset4/filter/filter.c
	
=======
>>>>>>> 27dd34eef7540237bc4fcc9ef28a34d778cc79c9:pset4/filter.c
    // Output
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = BluredImage[i][j].rgbtRed;
            image[i][j].rgbtGreen = BluredImage[i][j].rgbtGreen;
            image[i][j].rgbtBlue = BluredImage[i][j].rgbtBlue;
        }
    }
    return;
}