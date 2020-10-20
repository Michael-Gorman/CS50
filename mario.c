#include <stdio.h>
#include <cs50.h>

int get_pyramid_height(void);
void build_pyramid(int i);


int main(void)
{
    int i = get_pyramid_height();
   {
       build_pyramid(i);   
   }
}




// Defined Functions Below:

// Prompt user for integer between 1 and 8:
int get_pyramid_height(void)
{
   int n;
   
   // use 'do while' to get an initail input then continue into the wjile loop: 
   do
   {
        n = get_int("How tall is the Pyramid?\n");  
   }
   //set the conditions for the do while loop
    while (n < 1  ||  8 < n);
        
    // return the value of n:
    return n;
}



//build the pyramid:
void build_pyramid(int i)
{
    // interate through the columns with a for loop using y as the integer.
    for (int y = 1; y <= i; y++)
    {
        
        // while iterating through the collumns print each line. print the spaces which are equal to the i - y to offset the hashes
        for (int n = i - y; n > 0; n --)
        {
            printf(" ");
        }
          
        // print the hashes on each line increasing the number with the lines.
        for (int x = 0; x < y; x++)
        {
            printf("#");
        }
         
        //jump to the next line.
        printf("\n");
    }
}
