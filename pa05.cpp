/// @file pa05.cpp
/// @author Dr. Brodersen <david.brodersen@csn.edu>
/// @date 10/11/22
/// @note I pledge my word of honor that I have abided by the
/// the CSN Academic Integrity Policy while completing this assignment.
///
/// @brief This program outputs a series of numbers starting with a user
///        supplied integer a_0 such that
///        a_n+1 = a_n / 2 if a_n is even and
///        a_n+1 = 3 * a_n + 1 if a_n is odd
///
///        The total number of iterations is tracked as is the largest value
///        and the position of the largest value.
///
/// @note People who helped me:
///
/// @note This is but one possible solution to the assignment.
///       Programming techniques and commands in this solution
///       are aligned with the current and previous chapters,
///       labs, and lectures, which may result in a trade-off
///       between efficient coding and what student are
///       currently able to understand.

// include header files
#include <iostream>
#include <iomanip>
#include <string>

// set namespace
using namespace std;


/// -------------------------------------------------------------------------
/// Main entry-point for this application
///
/// @returns Exit-code for the process - 0 for success, else an error code.
/// -------------------------------------------------------------------------
int main() {

    // Constant definition(s)
    const int col_1 = 15;           // set the width of column 1
    const int col_2 =  5;           // set the width of column 2

    // Variable declarations(s)
    int exitState;                  // tracks the exit code for the process
    exitState = EXIT_SUCCESS;       // set state to successful run
    int current;                    // current value in sequence (LCV)
    int startValue = 0;             // save the origional
    unsigned largest;               // largest value in sequence
    unsigned pos;                   // position of largest value
    unsigned count;                 // sequence cycle length (k)
    string messageOut;              // error message

    // process every number in the input stream
    // cin is the input phase
    while (cin >> current && current != 0) {
        // set exitState in case there was a failure in the
        // last iteration
        exitState = EXIT_SUCCESS;

        /* ***** Processing/Output ************************************* */
        // insure the number is positive
        if (current < 0) {
            current *= -1;
            exitState = EXIT_FAILURE;
            messageOut = "\n*** Negative number entered, using: ";

            // save the original value for error messages
            startValue = current;
        }

        // insure the number is less than 65535
        if (current > 65535) {
            current = 65535;
            exitState = EXIT_FAILURE;
            messageOut = "\n*** Input exceeds 65535, using: ";

            // save the original value for error messages
            startValue = current;
        }

        // initialize aggregate variables
        largest = static_cast<unsigned>(current);
        pos     = 0;
        count   = 0;

        // display error message if any
        if (exitState == EXIT_FAILURE) {
            cout << messageOut << startValue << endl;
        }

        // display sequence starting value
        cout << current;

        // generate and print the sequence
        while (current > 1) {
            // track largest value
            if (static_cast<unsigned>(current) > largest) {
                largest = static_cast<unsigned>(current);
                pos     = count;
            }

            // count numbers in sequence
            ++count;

            // compute next number in sequence (update LCV)
            current = (static_cast<bool>(current % 2)) ?
            (current * 3 + 1) :
            (current / 2);

            cout << ' ' << current;
        }

        // display sequence summary
        cout << left << '\n' << setw(col_1) << "Iterations: "
        << right << setw(col_2) << count
        << left << '\n' << setw(col_1) << "Largest: "
        << right << setw(col_2) << largest
        << left << '\n' << setw(col_1) << "Position: "
        << right << setw(col_2) << pos << '\n' << endl;
    }

    return exitState;
}

// EOF: pa05.cpp