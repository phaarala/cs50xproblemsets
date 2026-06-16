#include <cs50.h>
#include <stdio.h>

// American Express
// 15 digits, starts with 34 or 37

// MasterCard
// 16 digits, starts with 51 - 55

// Visa
// 13 or 16 digits, starts with 4

// Checksum
// Mult every other digit by 2 (starting with 2nd to last digit)
// Add those products together
// Add to the sum of the digits not multiplied by 2
// If last digit is 0, it is a valid credit card

bool checksum(long card_number);
int card_length(long card_number);

int main(void)
{
    long card_number = get_long("Number: ");

    if (checksum(card_number) == true)
    {
        // AMEX
        if (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }

        // MASTERCARD
        else if (card_number / 100000000000000 >= 51 && card_number / 100000000000000 <= 55)
        {
            printf("MASTERCARD\n");
        }

        // VISA
        else if (card_number / 1000000000000000 == 4 || card_number / 1000000000000 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool checksum(long card_number)
{
    int sum_1 = 0;
    int sum_2 = 0;
    int sum_3 = 0;
    for (int digit = 1; digit <= 16; digit++)
    {
        if (card_number == 0)
        {
            break;
        }

        if (digit % 2 != 0)
        {
            sum_2 = sum_2 + card_number % 10;
            card_number = card_number / 10;
        }
        else
        {
            int product = (card_number % 10) * 2;
            if (product >= 10)
            {
                product = (product % 10) + (product / 10);
            }

            sum_1 = sum_1 + product;
            card_number = card_number / 10;
        }

        sum_3 = sum_1 + sum_2;
    }
    if (sum_3 % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
