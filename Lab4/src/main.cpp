/*
 * main.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: jychan
 */

#include <iostream>
#include <string>
using namespace std;

// URINE TESTS

// urine test: rapid

// urine test: urinalysis

// urine test: urine culture

// urine test: 24-hour sample

// urine test: pregnancy test

// urine test: drug test

/****
 *
 */

// BODY TEMPERATURE

class bt {

private:
	int selection;
	double temp;

public:
	void getInfo();
	void getStatus();

};

void bt::getInfo() {

	cout << "What was the obtained temperature? ";
	cin >> temp;

	cout << "How was the blood temperature test taken?"
			"\n1. Orally"
			"\n2. Rectally"
			"\n3. Axillary"
			"\n4. Through the ear"
			"\n5. On the skin\n";
	cin >> selection;

	switch (selection) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}

}

// divide into types

class btTypes {

private:

public:
	bt direct;
	bt rectally;
	bt axillary;

};

/****
 *
 */

// PULSE RATE

class pr {

private:
	int bpm;
	string athlete;
	string status;

public:
	void getInfo();
	void getStatus();
};

void pr::getInfo() {
	cout << "\nPlease enter the number of beats per minute: ";
	cin >> bpm;
	cout << "\nIs the patient an athlete? (yes/no): ";
	cin >> athlete;
	cout << "\nWould you like to add a comment? (yes/no) ";
	// comment
}

void pr::getStatus() {
	if (athlete == "yes") {
		if ((bpm < 40) | (bpm > 100)) {
			status = "problematic";
		}
		else status = "fine";
	}
	else if (athlete == "no") {
		if ((bpm < 100) | (bpm > 60)) {
			status = "fine";
		}
		else status = "problematic";
	}
}



/****
 *
 */

// RESPIRATORY RATE

class rr {

private:
	int numBreaths;
	string status;
	string difficulty;

public:
	void getInfo();
	void getStatus();
};

void rr::getInfo() {
	cout << "\nPlease enter the number of breaths per minute: ";
	cin >> numBreaths;
	cout << "\nWas there any difficulty breathing noted? (yes/no): ";
	cin >> difficulty;
	cout << "\nWould you like to add a comment? (yes/no) ";
	// comment
}

void rr::getStatus() {
	if ((difficulty == "yes") | (numBreaths > 16)) {
		status = "problematic";
	}
	else status = "fine";
}


/****
 *
 */

// BLOOD PRESSURE

class bp {

private:
	int systolic;
	int diastolic;
	string status;

public:
	void getInfo();
	void getStatus();
};

void bp::getInfo() {
	cout << "\nPlease enter the systolic pressure in mmHg: ";
	cin >> systolic;
	cout << "\nPlease enter the diastolic pressure in mmHg: ";
	cin >> diastolic;
	cout << "\nWould you like to add a comment? (yes/no) ";
	// comment
}

void bp::getStatus() {
	if ((systolic > 140) & (diastolic > 90)) {
		status = "high blood pressure (hypertension)";
	}
	else if ((systolic > 120) | (diastolic > 80)) {
		status = "prehypertension";
	}
	else {
		status = "normal blood pressure";
	}
}



int main() {

return 0;

}
