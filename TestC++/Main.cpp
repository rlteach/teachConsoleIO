#include <iostream>		//for cin/cout
#include <algorithm>	//for transform
#include <stdio.h>		//for printf(). scanf()
#include <string>		//for strings
#include <ctime>		//To Access time
#include <conio.h>

//http://tinyurl.com/y9pmf2y5


void	WaitForExit(int vSeconds=1);	//Header, with default variable


std::string&	MakeLower(std::string& vIn) {		//Convert a string to lower case
	std::string tLower = vIn;
	std::transform(tLower.begin(), tLower.end(), tLower.begin(), ::tolower);
	return	vIn;
}

void	WaitForExit(int vSeconds) {
	std::cout << "\nWill exit in " << vSeconds << " second(s)\n";
	clock_t tEndTime = vSeconds * 1000 + clock();		//Calculate when time will run out
	while (clock() != tEndTime)  {  //Wait until time expires
		if (_kbhit()) break;		//Early exit if key hit
	}
	
}

int main(int argc, char**argv) {
	std::cout << "Please type your name:" << std::flush;		//Flush will print this but not need newline
	std::string	tName;			//Make up a blank string
	std::cin >> tName;			//Get User input into string

	if (MakeLower(tName) == "richard") {		//Turn it to lower case
		std::cout << "You are:" << tName << " my master\n";		//Output a special message + user string
	}
	else {
		std::cout << "You are:" << tName << "\n";		//Output a normal message + user string
	}
	WaitForExit(10);					//Wait for exit
	return	0;
}
