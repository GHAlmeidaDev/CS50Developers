

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: \n");
    }
    while (h < 0 || h > 8);
     
// This loop determines which row it's on
for (int i = 0; i < h; i++)
{
    //This loop prints the necessary number of spaces first
    for (int s = h - 2 - i; s >= 0; s--)
        {
            printf(" ");
        }
    //This loop prints the necessary number of hashes on the left
    for (int hash = 1; hash <= i + 1; hash++)
        {
            printf("#");
        }
    //Prints the space in the middle
    printf("  ");
        {
    //Loop that prints the hashes on the right side
    for (int hash = 1; hash <= i + 1; hash++)
        {
            printf("#");
        }
        }
        printf("\n");
    }
}