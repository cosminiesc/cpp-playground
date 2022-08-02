#include <iostream>
#include<string>

bool isArmstrongNumber(int number)
{
	int copyNumber = number, currentDigit = 0, numberDigits = 0, sumArmstrong=0;

	/* - getting the number of digits - first method (scrolling through the digits of the number)
	while (copyNumber)
	{
		numberDigits++;
		copyNumber/=10;
	}*/

	//getting the number of digits - second method (mathematical formula)
	int numbersDigits = int(log10(number) + 1);
	
	while (copyNumber)
	{
		currentDigit = copyNumber%10;
		
		sumArmstrong += pow(currentDigit, numbersDigits);
		
		copyNumber /= 10;
		
	}

	if (sumArmstrong == number)
	{
		return true;
	}

	return false;
}

void printIsArmstrong(int number)
{
	if (isArmstrongNumber(number))
	{
		std::cout << "Armstrong" << std::endl;
	}
	else
	{
		std::cout << "NOT Armstrong" << std::endl;
	}
}

int main(int argc, char *argv[])
{
	// What is this program expected to do?
	// - Shows whether an argument is an armstrong number.
	// (what?)
	// -	An Armstrong number is a number that is equal to the sum of cubes of its digits.
	//		For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
	//		Let's try to understand why 153 is an Armstrong number:
	//			1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
	//
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  03_armstrong.exe 1		=> Output: Armstrong
	//		  03_armstrong.exe 2		=> Output: NOT Armstrong
	//		  03_armstrong.exe 			=> Output: No program arguments found.
	//		  03_armstrong.exe ABC		=> Undefined output (do whatever).
	//		  03_armstrong.exe 153		=> Output: Armstrong
	//		  03_armstrong.exe 154		=> Output: NOT Armstrong
	//

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		std::cout << "No program arguments found." << std::endl;
		return 1;
	}

	// Get the first argument
    // TODO: read number / cast to integer
	std::string argumentAsString = argv[1];
	const char* argumentAsCharArray = argumentAsString.c_str();
	for (int i = 0; i < strlen(argumentAsCharArray); i++)
	{
		if (isdigit(argumentAsCharArray[i]) == false)
		{
			printf("NAN\n");
			printf("Do you want to try from console?[Y/N]\n");
			std::string option="";
			std::cin >> option;
			if (option == "Y")
			{
				double readNumber = 0;
				bool isInCatch = false;
				std::cout << "Hello! We are in console" << std::endl << "Please insert an integer number!" << std::endl;
				try
				{
					std::cin >>  readNumber;
				}
				catch (int readNumber)
				{
	
					readNumber = NULL;
				}
			
				if (readNumber == NULL)
				{
					std::cout << "It is not a valid number";
					return 0;
				}
				else
				{
					printIsArmstrong((int)readNumber);
					return 0;
				}
 
			}
			else if (option == "N")
			{
				return 0;
			}
			else
			{
				std::cout << "Invalid option";
				return 0;
			}
			
		}
	}
	
	int number = stoi(argumentAsString);
    printIsArmstrong(number);

	return 0;
}