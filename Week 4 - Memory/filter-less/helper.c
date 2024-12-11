#include <math.h>
#include <stdio.h>

#include "helpers.h"

typedef struct
{
    int x;
    int y;
} PIXEL;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int avg = round((image[y][x].rgbtRed + image[y][x].rgbtGreen + image[y][x].rgbtBlue) / 3.0f);

            image[y][x].rgbtRed = avg;
            image[y][x].rgbtGreen = avg;
            image[y][x].rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int originalRed = image[y][x].rgbtRed;
            int originalGreen = image[y][x].rgbtGreen;
            int originalBlue = image[y][x].rgbtBlue;

            image[y][x].rgbtRed = fmin(255, round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue));
            image[y][x].rgbtGreen = fmin(255, round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue));
            image[y][x].rgbtBlue = fmin(255, round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue));
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            RGBTRIPLE temp = image[y][x];
            image[y][x] = image[y][width - x - 1];
            image[y][width - x - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image during the scope of the function to work with.
    RGBTRIPLE copy[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            copy[y][x] = image[y][x];
        }
    }

    // Modifying the image it self with the help of the copy
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Keep count of the number of pixel kept for the average
            float counter = 0.0;

            // Get the pixels around the current one
            // In clockwise order: top left -> left -> current
            PIXEL pixels[9];

            pixels[0].x = x - 1;
            pixels[0].y = y - 1;
            pixels[1].x = x;
            pixels[1].y = y - 1;
            pixels[2].x = x + 1;
            pixels[2].y = y - 1;
            pixels[3].x = x + 1;
            pixels[3].y = y;
            pixels[4].x = x + 1;
            pixels[4].y = y + 1;
            pixels[5].x = x;
            pixels[5].y = y + 1;
            pixels[6].x = x - 1;
            pixels[6].y = y + 1;
            pixels[7].x = x - 1;
            pixels[7].y = y;
            pixels[8].x = x;
            pixels[8].y = y;

            // Start averaging
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;

            for (int i = 0; i < 9; i++)
            {
                // If the pixel does not exists
                // Do not break the loop, just pass
                if (pixels[i].y < 0 || pixels[i].y > (height - 1) || pixels[i].x < 0 || pixels[i].x > (width - 1))
                {
                    continue;
                }

                totalRed += copy[pixels[i].y][pixels[i].x].rgbtRed;
                totalGreen += copy[pixels[i].y][pixels[i].x].rgbtGreen;
                totalBlue += copy[pixels[i].y][pixels[i].x].rgbtBlue;

                counter++;
            }

            // Make average
            int avgRed = round(totalRed / counter);
            int avgGreen = round(totalGreen / counter);
            int avgBlue = round(totalBlue / counter);

            // Assign to the image
            image[y][x].rgbtRed = avgRed;
            image[y][x].rgbtGreen = avgGreen;
            image[y][x].rgbtBlue = avgBlue;
        }
    }
}
