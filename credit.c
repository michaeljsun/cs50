#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void)
{   
    long long number;
    do
    {
        printf("Number: ");
        scanf("%lli", &number);
    } while (number < 0);
   
    long long n = number, m = number / 10, l = number;   // m is the number without the last digit

    int count = 0;
    while (n != 0)
    {
        n /= 10;        // n = n/10
        ++count;
    }
    
    int amex = number / pow(10, count - 2);
    int master = number / pow(10, count - 2);
    int visa = number / pow(10, count - 1);

    // printf("%i\n", count);
    // printf("%i\n", amex);
    // printf("%i\n", master);
    // printf("%i\n", visa);

    int a, b, c = 0, d, e = 0, f;

    // Multiply every other digit by 2, starting with the number’s second-to-last digit,
    // and then add those products’ digits together
    
    while (m != 0)
    {
        a = m % 10 * 2;
        m /= 100;        // m = m/100
        while (a != 0)
        {
            b = a % 10;
            c = c + b;
            a /= 10;    // a = a/10
        }
    }

    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    while (l != 0)
    {
        d = l % 10;
        e = e + d;
        l /= 100;        // l = l/100
    }

    // If the total’s last digit is 0 (or, put more formally, 
    // if the total modulo 10 is congruent to 0), the number is valid!
    f = (c + e) % 10;

    // printf("%i\n", c);
    // printf("%i\n", e);
    // printf("%i\n", c + e);
    // printf("%i\n", f);

    if (f == 0)
    {   
        if ((count == 15 && amex == 34) || (count == 15 && amex == 37))
        {
            printf("AMEX\n"); 
        }     
                
        else if ((count == 16 && master == 51) || (count == 16 && master == 52) || (count == 16 
                 && master == 53) || (count == 16 && master == 54) || (count == 16 && master == 55))
        {
            printf("MASTERCARD\n");
        }          
                
        else if ((count == 13 && visa == 4) || (count == 16 && visa == 4))
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