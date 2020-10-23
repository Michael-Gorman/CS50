// This file includes the fucntions which are used to apply filters to images.

#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Initalize rgbgray which will get assigned later
    float rgbgray;

    //starting on row one, iterate through the rows
    for (int i = 0; i < height; i++)
    {
        //iterate through the pixels of each row i
        for (int j = 0; j < width; j++)
        {
            // average the values of rgb and assign that value to rgbgray
            rgbgray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = rgbgray;
            image[i][j].rgbtGreen = rgbgray;
            image[i][j].rgbtBlue = rgbgray;
        }
    }

    return;
}


//With sepia the is a chance of "overflow", the following function is designed to stop the value of each colour from exceeding 255
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Initailize the sepia variable which will be assigned later
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;

    //starting on row one, iterate through the rows of the image
    for (int i = 0; i < height; i++)
    {
        //iterate through the pixels of each row i
        for (int j = 0; j < width; j++)
        {
            sepiaRed = limit(round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue)));
            sepiaGreen = limit(round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue)));
            sepiaBlue = limit(round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue)));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //initiate a temorary array which will be used to swap pixel positions
    // array has three positions to accomodate rgbtRed, rgbtGreen and, rgbtBlue
    int temp[3];

    //starting on row one, iterate through the rows of the image
    for (int i = 0; i < height; i++)
    {
        //iterate through the pixels of each row, stopping half way
        for (int j = 0; j < (width / 2); j++)
        {
            temp[0] = image[i][j].rgbtRed;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtBlue = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //initiate variables for the sum of each rgb colour for the surrounding pixels of each pixel
    int sumRed;
    int sumGreen;
    int sumBlue;

    //initaiate a counter to count how many pixels were around that pixel and used for the sum
    //make counter a float so the output is a float and can be rounded properly
    float counter;

    //Create a temp table of colours to hold the new values so can still use the origonal values in the calculation
    RGBTRIPLE temp[height][width];

    //iterate through the rows of the image
    for (int i = 0; i < height; i++)
    {
        //iterate through the pixels of each row
        for (int j = 0; j < width; j++)
        {
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;
            counter = 0.00;

            //iterate left and right by one pixel of the current pixel (h for horizontal)
            for (int h = -1; h < 2; h++)
            {
                //check to see if all these are in the image and not beyond the edge.
                if (j + h < 0 || j + h > width - 1)
                {
                    continue;
                }

                //iterate up and down by one pixel from the current pixel (v for vertical)
                for (int v = -1; v < 2; v++)
                {
                    //check to see if all these are in the image and not beyond the edge.
                    if (i + v < 0 || i + v > height - 1)
                    {
                        continue;
                    }
                    //get the sum of each colour by adding the value of each one to the prevois sum as you iterate through pixels
                    sumRed += image[i + v][j + h].rgbtRed;
                    sumGreen += image[i + v][j + h].rgbtGreen;
                    sumBlue += image[i + v][j + h].rgbtBlue;
                    counter++;
                }
            }

            //devide sum of each colour by counter to get average
            //the resulting average will likely be a float so needs to be rounded using round function
            //add the average of each to the temp table.
            temp[i][j].rgbtRed = round(sumRed / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtBlue = round(sumBlue / counter);

        }
    }

    //iterate through image again and copy values from temp table to origonal
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }

    }

    return;
}
