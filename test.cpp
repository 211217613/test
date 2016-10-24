//============================================================================
// Name        : starprinter.cpp
// Author      : Joel Vazquez
// Version     :
// Copyright   : Dis ma Shit
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void printEverything (const unsigned int);
void printIncrementing(const unsigned int);
void printDecrementing(const unsigned int);

int main()
{ //int main()

	unsigned int amount; //The amount to increment/decrement

	// **************************************************
	//Add a check to make sure that the input is even
	//Quit the program if they don't enter an even number
	// **************************************************
	cout << "How many stars would you like to print? (even numbers only)\n";
	cin >> amount;

	if ( (amount%2) == 0 ){
		cout << "Even." << endl;
	} else {
		cout << "Exiting program";
	}


	//call our function
	printEverything(amount);


	return 0;
} //int main()

/**
 * parameter: amount - Amount to increment/decrement
 * Description: This function will print the number of stars supplied by
 * 		incrementing amounts first, and then by decrementing amounts
 **/
void printEverything (const unsigned int amount)
{ //void printEverything (const unsigned int amount)

	// **********************************
	//Don't add any code to this function
	// **********************************

	//Call the incrementing function
	// printIncrementing(amount);
	//Call the decrementing function
	printDecrementing(amount);

	return;
} //void printEverything (const unsigned int amount)

/**
 * parameter: count - Maximum number of stars to print to
 * Description: This function takes in the user-defined maximum number of stars
 *		to print in a line. It will print 2 stars in the first line, and an
 *		additional 2 stars each subsequent line until it reaches the maximum
 *		number of stars to print.
 **/

void printIncrementing(const unsigned int count)  
{ 
  // count  is 6
  // **
  // ****
  // ****** 
    //this code prints out *'s in vertical and horizontal lines that equal the length of the 
	// something that increments by two temp * 2  
	string stars; 
	for (unsigned int i = 0; i <= count; i++) {
		stars += "**";
		cout << stars  << endl;
    
    // 6
    // Even.
    // **
    // **
    // **
	}
} //void printIncrementing(const unsigned int count)

/**
 * EXTRA CREDIT ONLY!
 * parameter: count - Maximum number of stars to print from
 * Description: This function takes in the user-defined maximum number of stars
 *		to print in a line. It will print the maximum number of stars in the
 *		first line, and 2 less stars each subsequent line until it reaches the
 *		minimum number (2) of stars to print.
 **/
void printDecrementing(const unsigned int count)
{ //void printDecrementing(const unsigned int count)
	string stars;
  for (unsigned int idx = 0; idx < count; idx++ ){
  	    stars += "**";
  }

  for (unsigned int index = count; index <= 0; index--){
  	stars -= stars;
  	cout << "adfsdf"<< endl;
  }
  
	// cout << "Testing" << endl;


	// ********************************************************
	//EXTRA CREDIT
	//Add your code here if you are working on the EXTRA CREDIT
	// ********************************************************

} //void printDecrementing(const unsigned int count)
