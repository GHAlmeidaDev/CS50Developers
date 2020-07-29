#include <stdio.h>

#include <cs50.h>

#include <math.h>

int main(void)

{

    int sum = 0;

    long ccNum = 0L;

    while (ccNum < 1L || ccNum > 9999999999999999L)

    {

       ccNum = get_long("Please Input CC Number: "); 

    }

    // Copy to be used throughout the process.

    long temp = ccNum;

    // Keep track of the amount and position of each digit using variable 'count'.

    int count = 0;

    while (temp > 0L)

    {

        temp = temp / 10L;

        count++;

    }

    // Validate number of digits

    if (count != 13 && count != 15 && count != 16)

    {

        printf("INVALID\n");

        return 0;

    }

    // Reset value of variable 'temp' and apply calculations that will isolate the first two digits. 

    // Store the results in a variable 'brand'.

    temp = ccNum;

    while (temp > 100L)

    {

        temp = temp / 10L;

    }

    int brand = temp;

    // Credit card company from ID digits and length.

    if (brand > 50 && brand < 56 && count == 16)

    {

        printf("MASTERCARD\n") ;

    }

    else if ((brand == 34 || brand == 37) && (count == 15)) 

    {

        printf("AMEX\n") ;

    }

    else if ((brand / 10 == 4) && (count == 13 || count == 16))

    {

        printf("VISA\n") ;

    }

     else if (sum % 10 != 0)

    {

        printf("INVALID\n");

        return 0; 

    }

    else

    {

        printf("INVALID\n");

    }

    // Checksum.

    

    temp = ccNum;

    for (int i = 1; i <= count; i++)

    {

        int digit = temp % 10L;

        if (i % 2 == 0)

        {

            digit *= 2;

            if (digit > 9)

            {

                digit -= 9;

            }

        }

        sum += digit;

        temp /= 10L;

    }

}