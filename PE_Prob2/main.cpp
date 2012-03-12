//****************************
// Chris Engstrom            *
// Project Euler - Problem 2 *
//***********************************************************
// By considering the terms in the Fibonacci sequence whose *
//  values do not exceed four million, find the sum of the  *
//  even-valued terms.                                      *
//***********************************************************

#include <iostream>

using namespace std;

// GLOBAL VARIABLES //
int sumEvenNums = 0,        // Sum of even Fibonacci numbers
    nMinusTwoValue = 0,     // Fib value from two calculations ago
    nMinusOneValue = 1,     // Fib value from one calculation ago
    currentValue = 0;       // Current Fib value

// FUNCTION PROTOTYPES //
int fibonacci(int numberLimit);

int main() {

    int fibLimit = 0;		// Limit set by user

    // Introduce the program and ask the user for the limit
    cout << "This program adds up the even valued terms of the Fibonacci sequence up to a certain number." << endl << endl
         << "What Fibonacci number limit would you like to use? ";

    // Get the limit from the user
    cin >> fibLimit;

    // Report the results
    cout << "Sum of even Fibonacci numbers that are less than " << fibLimit << ": " << fibonacci(fibLimit) << endl;

    return 0;
}

//*******************************************************************************
// FUNCTION: int fibonacci(int numberLimit)                                     *
//  int numberLimit - Function will calculate one Fib number past this number   *
//                      and then stop recursing                                 *
//                                                                              *
// RETURNS - The sum of the even Fib numbers that are less than the numberLimit *
//*******************************************************************************
int fibonacci(int numberLimit)
{
    // Calculate the next/current Fib number from the last two Fib numbers
    currentValue = nMinusOneValue + nMinusTwoValue;

    // If we have hit or passed our numberLimit, quit recursing and return the sum
    if(currentValue > numberLimit)
        return sumEvenNums;
    else {  // Continue recursing
        // Add even numbers to our sum
        if(!(currentValue % 2))
            sumEvenNums += currentValue;

        // Update our previous Fib number values
        nMinusTwoValue = nMinusOneValue;
        nMinusOneValue = currentValue;

        // Recursively call the function to keep adding even Fib numbers
        fibonacci(numberLimit);
    }
}