#include <stdio.h>
#include <cs50.h>
long ccNumber(void);
int ccLength(long number);
bool creditCardCalc(long number, int length);
char* printCcType(long number, int length);



int main(void)
{
    // Get the credit card number from the function below
    long number = ccNumber();
    // get the length of the credit card
    int length = ccLength(number);
    // check if the credit card itself is valid or not
    if( creditCardCalc(number,length) == true)
    {
        // print the type of the credit card
        printf("%s", printCcType(number,length));
    }
    else
    {
        printf("INVALID\n");
    }
}

long ccNumber(void)
{
    // just a simple input
    long number;
    do
    {
        number = get_long("Enter the credit card number: ");
    }
    while(number < 1);
    return number;
}

int ccLength(long number)
{
    int length = 0;
    // for every digit add +1 to the length when you reach 0 break and return the length
    while(true){
        int digit = number % 10;
        number = number / 10;
        length += 1;
        if(number <= 0)
        {
            break;

        }
    }
    return length;
}


bool creditCardCalc(long number,int length)
{
    int sumOfProductEvenNumbers = 0;
	int sumOfOddNumbers = 0;
    for(int i = 1; i < length+1; i++)
    {
        // if the digit is odd then add it without product!!
        if( i % 2 != 0)
        {
            sumOfOddNumbers += number % 10;
            number = number / 10;
            continue;
        }
        // if the digit is even then multpliy it by 2
        int oneDigit = (number % 10) * 2;
        // if it's the multiplited number is two digits then add both digits to the overall (example 14 = 1 + 4)
        if (oneDigit >= 10)
        {
            sumOfProductEvenNumbers += oneDigit % 10;
            sumOfProductEvenNumbers += oneDigit / 10;
            number = number / 10;
            continue;
        }
        // if it's one digit then just add it!!!!!
        sumOfProductEvenNumbers += oneDigit;
        // get the next digit
        number = number / 10;
    }
    // add both the sum of odd numbers and the sum of even(multiplied by 2) togather
    int sumAllNumbers = sumOfProductEvenNumbers + sumOfOddNumbers;
    // if the number has 0 as his last digit then the cc is valid !!!!!
    if (sumAllNumbers % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

char* printCcType(long number, int length)
{

    // if the length is 15 and start with 34 or 37 then credit card is american express
    if(length == 15  && (number / 10000000000000 == 37 || number / 10000000000000 == 34 ))
    {
        return "AMEX\n";
    }
    // if the cc start with 4 and it's length is 16 then it's a visa
    else if(length == 16 && number / 1000000000000000 == 4 )
    {
        return "VISA\n";

    }
    // if the cc start with 4 and it's length is 14 then it's a visa
    else if ((length == 13 && number / 1000000000000 == 4 ))
    {
        return "VISA\n";

    }
    // anything else is master card because it has lots of diffrent numbers :D
    else if(length == 16  && (number / 100000000000000 == 51 || number / 100000000000000 == 52 ||
    number / 100000000000000 == 53 || number / 100000000000000 == 54 || number / 100000000000000 == 55))
    {
        return "MASTERCARD\n";
    }
    else
    {
        return "INVALID\n";
    }
}

