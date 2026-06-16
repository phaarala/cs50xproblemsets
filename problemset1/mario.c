#include <cs50.h>
#include <stdio.h>

void print_row(int height);

int main(void)
{
    // Prompt user for height (int)
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print pyramid of that height
    print_row(height);
}

// Given a height from user input, produce a row of spaces and bricks based on the number of row
// being iterated on
void print_row(int height)
{
    for (int row = 1; row < height + 1; row++)
    {
        // print spaces
        for (int i = height - row; i > 0; i--)
        {
            printf(" ");
        }

        // print left bricks
        for (int i = 1; i < row + 1; i++)
        {
            printf("#");
        }

        // print 2 spaces
        printf("  ");

        // print right bricks
        for (int i = 1; i < row + 1; i++)
        {
            printf("#");
        }

        printf("\n");
    }
}
