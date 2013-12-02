//============================================================================
// Name        : Lab4.cpp
// Author      : Samara
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BloodTest.hpp"
#include "main.cpp"
using namespace std;

int main() {
	cout << "BME506 Lab4\n\nSamara Seepersad and Jennifer Chan" << endl;

	int i = 0;
	int option;

	// Samara's Test of Jen's Classes
	typedef rectal Test1[50];
	Test1 admitted1;

	typedef axillary Test2[50];
	Test2 admitted2;

	while (run == 1){
			cout << "Enter 1 to Add Rectal Results\nEnter 2 to enter axillary results\n";
			cin >> option;

			if (option == '1'){
				if (i < 50){
					admitted1[i].getinfo();
					admitted1[i].getstatus();
				}

			} else if (option == '2'){
				if (i < 50){
					admitted2[i].getinfo();
					admitted2[i].getstatus();
				}
			}
	}

	return 0;
}
