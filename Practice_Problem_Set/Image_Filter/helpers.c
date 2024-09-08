#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i=0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            float R = image[i][j].rgbtRed;
            float G = image[i][j].rgbtGreen;
            float B = image[i][j].rgbtBlue;
            float rem  = fmod((double)(R+G+B),3.0);
            if ((rem*10)/3 > 5.0)
            {
                average = (R+G+B)/3 + 1;
            }
            else
            {
                average = (R+G+B)/3;
            }

            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            float R = image[i][j].rgbtRed;
            float G = image[i][j].rgbtGreen;
            float B = image[i][j].rgbtBlue;
            float sepiaRed = .393 * R + .769 * G + .189 * B;
            int SR = (int)sepiaRed;
            if ((sepiaRed - (float)SR) > 0.5)
            {
                SR = SR+1;
            }
            if (SR > 255)
            {
                SR = 255;
            }
            float sepiaGreen = .349 * R + .686 * G + .168 * B;
            int SG = (float)sepiaGreen;
            if ((sepiaGreen - (float)SG) > 0.5)
            {
                SG = SG+1;
            }
            if (SG > 255)
            {
                SG = 255;
            }
            float sepiaBlue = .272 * R + .534 * G + .131 * B;
            int SB = (float)sepiaBlue;
            if ((sepiaBlue - (float)SB) > 0.5)
            {
                SB = SB+1;
            }
            if (SB > 255)
            {
                SB = 255;
            }
            if (SB > 255)
            {
                SB = 255;
            }
            image[i][j].rgbtRed = SR;
            image[i][j].rgbtGreen = SG;
            image[i][j].rgbtBlue = SB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int mid = width/2;
    for (int i=0; i < height; i++)
    {
        for (int j=0, k=width-1; j < mid; j++ , k--)
        {
            // int tempR = image[i][j].rgbtRed;
            // image[i][j].rgbtRed = image[i][k].rgbtRed;
            // image[i][k].rgbtRed = tempR;

            // int tempG = image[i][j].rgbtGreen;
            // image[i][j].rgbtGreen = image[i][k].rgbtGreen;
            // image[i][k].rgbtGreen = tempG;

            // int tempB = image[i][j].rgbtBlue;
            // image[i][j].rgbtBlue = image[i][k].rgbtBlue;
            // image[i][k].rgbtBlue = tempB;
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <  width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int radius = 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <  width; j++)
        {
            float R,G,B;
            R = G = B = 0;
            int count = 0;
            for(int m = -radius; m <= radius; m++)
            {
                for (int n = -radius; n <= radius; n++)
                {
                    int mi = i + m;
                    int ni = j +n;

                    if (mi >= 0 && mi < height && ni >= 0 && ni < width)
                    {
                        R = R + copy[mi][ni].rgbtRed;
                        G = G + copy[mi][ni].rgbtGreen;
                        B = B + copy[mi][ni].rgbtBlue;
                        count++;
                    }
                }
            }

            int AR = R/count;
            if ((R/(float)count)-AR >= 0.5)
            {
                AR = AR + 1;
            }
            int AG = G/count;
            if ((G/(float)count)-AG >= 0.5)
            {
                AG = AG + 1;
            }
            int AB = B/count;
            if ((B/(float)count)-AB >= 0.5)
            {
                AB = AB + 1;
            }

            image[i][j].rgbtRed = AR;
            image[i][j].rgbtGreen = AG;
            image[i][j].rgbtBlue = AB;
        }
    }

    return;
}
