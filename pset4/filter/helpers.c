#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            float grayscale = (round(red) + round(green) + round(blue)) / 3;
            grayscale = round(grayscale);

            image[i][j].rgbtRed = grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtBlue = grayscale;
        }
    }
}

//check50 cs50/problems/2020/x/filter/less
//./filter -g images/yard.bmp out.bmp


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = round((0.349 * originalRed) + (0.686 * originalGreen) + (0.168 * originalBlue));
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round((0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

//./filter -s images/yard.bmp out.bmp

// Reflect image horizontally

void swap(RGBTRIPLE *x, RGBTRIPLE *y);
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {

            swap(&image[i][j], &image[i][width - j - 1]);
        }
    }
}

void swap(RGBTRIPLE *x, RGBTRIPLE *y)
{
    RGBTRIPLE temp = *x;
    *x = *y;
    *y = temp;
}

//./filter -r images/tower.bmp out.bmp


// Blur image


void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //temporary array where the blur will happen

    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //Iterate over every column and row
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Initializing variables to do the later calculations
            int countRed = 0;
            int countGreen = 0;
            int countBlue = 0;

            float counter = 0;


            //CORNERS

            //top right pixel

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                countRed += temp[i - 1][j - 1].rgbtRed;
                countGreen += temp[i - 1][j - 1].rgbtGreen;
                countBlue += temp[i - 1][j - 1].rgbtBlue;
                counter ++;
            }

            //top left pixel
            if (i - 1 >= 0 && j >= 0)
            {
                countRed += temp[i - 1][j].rgbtRed;
                countGreen += temp[i - 1][j].rgbtGreen;
                countBlue += temp[i - 1][j].rgbtBlue;
                counter ++;
            }


            //bottom right pixel
            if (i >= 0 && j >= 0)
            {
                countRed += temp[i][j].rgbtRed;
                countGreen += temp[i][j].rgbtGreen;
                countBlue += temp[i][j].rgbtBlue;
                counter ++;
            }

            //bottom left pixel

            if (i >= 0 && j - 1 >= 0)
            {
                countRed += temp[i][j - 1].rgbtRed;
                countGreen += temp[i][j - 1].rgbtGreen;
                countBlue += temp[i][j - 1].rgbtBlue;
                counter ++;
            }
            //EDGES
            //Bottom
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                countRed += temp[i][j + 1].rgbtRed;
                countGreen += temp[i][j + 1].rgbtGreen;
                countBlue += temp[i][j + 1].rgbtBlue;
                counter++;
            }
            //Top
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                countRed += temp[i - 1][j + 1].rgbtRed;
                countGreen += temp[i - 1][j + 1].rgbtGreen;
                countBlue += temp[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            //Left
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                countRed += temp[i + 1][j].rgbtRed;
                countGreen += temp[i + 1][j].rgbtGreen;
                countBlue += temp[i + 1][j].rgbtBlue;
                counter++;
            }
            //Right
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                countRed += temp[i + 1][j - 1].rgbtRed;
                countGreen += temp[i + 1][j - 1].rgbtGreen;
                countBlue += temp[i + 1][j - 1].rgbtBlue;
                counter++;
            }

            //Middle pixel
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                countRed += temp[i + 1][j + 1].rgbtRed;
                countGreen += temp[i + 1][j + 1].rgbtGreen;
                countBlue += temp[i + 1][j + 1].rgbtBlue;
                counter++;
            }
            //find average colour value
            image[i][j].rgbtRed = round(countRed / counter);
            image[i][j].rgbtGreen = round(countGreen / counter);
            image[i][j].rgbtBlue = round(countBlue / counter);
        }

    }
//./filter -b images/tower.bmp out.bmp

    return;

}




