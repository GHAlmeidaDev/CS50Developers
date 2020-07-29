#include "helpers.h"
#include "math.h"
#include "string.h"

void edges(int height, int width, RGBTRIPLE image[height][width])
{   
    // sobel filters 
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0 ,0}, {1, 2, 1}};

    // creates copied image to story the original image and extra lines/columes
    // of black pixels to loop through
    RGBTRIPLE temp[height + 2][width + 2];
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || j == 0 || i == height + 1 || j == width + 1)
            {
                temp[i][j].rgbtRed = 0;
                temp[i][j].rgbtGreen = 0;
                temp[i][j].rgbtBlue = 0;
            }
            else
            {
                temp[i][j] = image[i - 1][j - 1];
            }
        }
    }
    // second copied image with extra black pixels to store the result
    RGBTRIPLE temp2[height + 2][width + 2];
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            temp2[i][j] = temp[i][j];
        }
    }

    //calculation based on the copied image
    for (int i = 1; i < height + 1; i++)
    {   
        // varibles to stroy Gx Gy for each color channels
        float blueGx = 0.0, redGx = 0.0, greenGx = 0.0;
        float blueGy = 0.0, redGy = 0.0, greenGy = 0.0;

        for (int j = 1; j < width + 1; j++)
        {
            for (int k = -1; k < 2; k++)
            {   
                for (int h = -1; h < 2; h++)
                {
                    //calculate the Gx for each R G B channel by using temp
                    blueGx += temp[i + k][j + h].rgbtBlue * Gx[k + 1][h + 1];
                    redGx += temp[i  + k][j + h].rgbtRed * Gx[k + 1][h + 1];
                    greenGx += temp[i + k][j + h].rgbtGreen * Gx[k + 1][h + 1];
                    //calculate the Gy for each R G B channel by using temp
                    blueGy += temp[i + k][j + h].rgbtBlue * Gy[k + 1][h + 1];
                    redGy += temp[i + k][j + h].rgbtRed * Gy[k + 1][h + 1];
                    greenGy += temp[i + k][j + h].rgbtGreen * Gy[k + 1][h + 1];
                }
            }
            //store result for each pixels (i, j) in temp2
            temp2[i][j].rgbtRed = maxCheck(round(sqrt(redGx * redGx + redGy * redGy)));
            temp2[i][j].rgbtBlue = maxCheck(round(sqrt(blueGx * blueGx + blueGy * blueGy)));
            temp2[i][j].rgbtGreen = maxCheck(round(sqrt(greenGx * greenGx + greenGy * greenGy)));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp2[i + 1][j + 1];
        }
    }
}

// cap rgb value to 255
int maxCheck(int a)
{
    if (a > 255)
    {
        a = 255;
    }
    return a;
}