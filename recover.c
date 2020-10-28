#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Check for single command line arg as file name
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    //check if file can be opened
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 1;
    }

    //Create variables that can be used to collect the image data
    FILE *img;
    char filename[8];
    unsigned char *buffer = malloc(512);
    int counter = 0;


    //start a while loop
    while (fread(buffer, 512, 1, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if the counter is greater than zero
            if (counter > 0)
            {
                //close the last image that we looped through
                fclose(img);
            }

            //creat filename of jpeg
            sprintf(filename, "%03d.jpg", counter);

            //open new image file and assign to img
            img = fopen(filename, "w");

            //check if file has been created
            if (img == NULL)
            {
                fclose(file);
                fprintf(stderr, "could not create output file JPG %s", filename);
                return 3;
            }

            counter++;
        }

        //if jpg found; write to file
        if (counter > 0)
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    //close files and free allocated space
    fclose(img);
    fclose(file);
    free(buffer);
    return 0;
}
