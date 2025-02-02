#include <stdio.h>

#include <iostream>
#include <string>

void printOddOrEven(int number)
{
	if (number % 2 == 0)
	{
		printf("EVEN\n");
	}
	else
	{
		printf("ODD\n");
	}
}

int main(int argc, char* argv[])
{

	// What is this program expected to do?
// - Shows whether an argument is an ODD or EVEN number.
// How to launch it?
// - Execute the binary and pass a parameter to it?
// - E.g. Open CMD in bin/Debug or bin/Release
//		  02_odd_even.exe 1		=> Output: ODD
//		  02_odd_even.exe 2		=> Output: EVEN
//		  02_odd_even.exe 		=> Output: No program arguments found.
//		  02_odd_even.exe ABC   => Undefined output (do whatever).
//		

	if (argc <= 1)
	{
		printf("No program arguments found.\n");
		return 0;
	}

	std::string argumentAsString = argv[1];
	bool isValid = true;
	const char* argumentAsCharArray = argumentAsString.c_str();

	for (int i = 0; i < strlen(argumentAsCharArray); i++)
	{
		if (isdigit(argumentAsCharArray[i])==false)
		{
			printf("NAN");
			isValid = false;
			break;
		}
	}

		if (isValid)
		{
			int number = stoi(argumentAsString);
			printOddOrEven(number);
		}

	return 0;
}