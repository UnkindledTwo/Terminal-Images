#include <iostream>
#include "Colors.h"
#include <fstream>
#include <string>

using namespace std;

int main(){
	string fileStr;
	cout << "Enter the path of the file you want to read" << endl;
	cin >> fileStr;
	cout << endl;
	string line;
	string wholeFile = "";
	ifstream fileToRead(fileStr);

	while(getline(fileToRead, line)){
		wholeFile.append(line);
	}
	
	for(int i = 0; i < wholeFile.length(); i+=2){
		string toWriteBg;
			switch(wholeFile[i])
			{
				case 'R':
					toWriteBg = BBRed;
					break;
				case 'B':
					toWriteBg = BBBlack;
					break;
				case 'G':
					toWriteBg = BBGreen;
					break;
				case 'Y':
					toWriteBg = BBYellow;
					break;
				case 'M':
					toWriteBg = BBMagenta;
					break;
				case 'C':
					toWriteBg = BBCyan;
					break;
				case 'W':
					toWriteBg = BBWhite;
					break;
				
				case 'r':
					toWriteBg = BRed;
					break;
				case 'b':
					toWriteBg = BBlack;
					break;
				case 'g':
					toWriteBg = BGreen;
					break;
				case 'y':
					toWriteBg = BYellow;
					break;
				case 'm':
					toWriteBg = BMagenta;
					break;
				case 'c':
					toWriteBg = BCyan;
					break;
				case 'w':
					toWriteBg = BWhite;
					break;
				case 'n':
					toWriteBg = ANSI_COLOR_RESET "\n";
					break;
			}
			cout << toWriteBg << wholeFile[i+1];
	}


	cout << ANSI_COLOR_RESET << endl;

	return 0;
}
