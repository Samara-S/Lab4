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

class ut {

private:

protected:
	int selection;

public:
	int typeTest();
	string getStatus();

};

int ut::typeTest() {

	cout << "What type of urine test was it?"
			"\n1. Rapid"
			"\n2. Urinalysis\n";
	cin >> selection;

	cout << "\nWould you like to add a comment? (yes/no) ";
	// comment

	return selection;

}

// urine test: rapid

class rapid : public ut {

private:
	int ph;
	string results[];
	string status = "";

public:
	void getInfo();
	void detectAbnormal();

};

void rapid::getInfo() {

	cout << "\nPlease enter the pH value: ";
	cin >> ph;
	cout << "\nWas there a presence of protein? (yes/no) ";
	cin >> results[0];
	cout << "\nWas there a presence of glucose? (yes/no) ";
	cin >> results[1];
	cout << "\nWas there a presence of nitrites? (yes/no) ";
	cin >> results[2];
	cout << "\nWas there a presence of ketones? (yes/no) ";
	cin >> results[3];
	cout << "\nWas there a presence of bilirubin? (yes/no) ";
	cin >> results[4];
	cout << "\nWas there a presence of urobilinogen? (yes/no) ";
	cin >> results[5];
	cout << "\nWas there a presence of red blood cells? (yes/no) ";
	cin >> results[6];
	cout << "\nWas there a presence of white blood cells? (yes/no) ";
	cin >> results[7];

}

void rapid::detectAbnormal() {

if (ph < 5) {
	if (status == "") {
		status = "kidney stones";
	}
	else {
		status = ", kidney stones";
	}
}
else if (ph > 7) {
	if (status == "") {
		status = "urinary tract infection";
	}
	else {
		status = ", urinary tract infection";
	}
}

if (((results[0] | results[4] | results[5] | results[6]) == "yes")) {
	if (status == "") {
		status = "kidney disease/inflammation";
	}
	else {
		status = ", kidney disease/inflammation";
	}
}
else if (((results[1] | results[3]) == "yes")) {
	if (status == "") {
		status = "diabetes mellitus";
	}
	else {
		status = ", diabetes mellitus";
	}
}
else if (((results[2] | results[7]) == "yes")) {
	if (status == "") {
		status = "bacterial infection";
	}
	else {
		status = ", bacterial infection";
	}
}

if (status == "") {
	status = "fine";
}

}

// urine test: urinalysis

class urinalysis : public ut {

private:
	string results[];
	string status = "";

public:
	void getInfo();
	void detectAbnormal();

};

void urinalysis::getInfo() {

	cout << "\nWas there too little creatinine? (yes/no) ";
	cin >> results[0];
	cout << "\nWas there a presence of urinary casts? (yes/no) ";
	cin >> results[1];
	cout << "\nWas there a presence of crystals? (yes/no) ";
	cin >> results[2];
	cout << "\nWas there a presence of epithelial cells? (yes/no) ";

};

void urinalysis::detectAbnormal() {

if ((results[0] == "yes")) {
	if (status == "") {
		status = "kidneys not filtering properly";
	}
	else {
		status = ", kidneys not filtering properly";
	}
}
else if (results[1]) {
	if (status == "") {
		status = "kidney disease";
	}
	else {
		status = ", kidney disease";
	}
}
else if (((results[2] | results[3]) == "yes")) {
	if (status == "") {
		status = "problematic";
	}
	else {
		status = ", problematic";
	}
}

if (status == "") {
	status = "fine";
}

}

/****
 *
 */

// BODY TEMPERATURE

class bt {

protected:
	int selection;
	double measured;
	string status;

public:
	int typeTest();
	string getStatus(int temp);

};

int bt::typeTest() {

	cout << "What was the obtained temperature in F? ";
	cin >> measured;

	cout << "What type of temperature test was it?"
			"\n1. Oral"
			"\n2. Rectal"
			"\n3. Axillary"
			"\n4. Ear"
			"\n5. Skin\n";
	cin >> selection;

	cout << "\nWould you like to add a comment? (yes/no) ";
	// comment

	return selection;

}

// divide into types

class rectal: public bt {

private:

public:
	double actualTemp() {
		return measured + 0.6;
	}

};

class axillary: public bt {

private:

public:
	double actualTemp() {
		return measured - 0.3;
	}

};

string bt::getStatus(int temp) {
	if ((temp > 97.8) & (temp < 99)) {
		status = "fine";
	}
	else if (temp > 99.6) {
		status = "fever";
	}
	else if (temp < 95) {
		status = "hypothermia";
	}

	return status;
}

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
	string getStatus();
};

void pr::getInfo() {
	cout << "\nPlease enter the number of beats per minute: ";
	cin >> bpm;
	cout << "\nIs the patient an athlete? (yes/no): ";
	cin >> athlete;
	cout << "\nWould you like to add a comment? (yes/no) ";
	// comment
}

string pr::getStatus() {
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
	return status;
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
	string getStatus();
};

void rr::getInfo() {
	cout << "\nPlease enter the number of breaths per minute: ";
	cin >> numBreaths;
	cout << "\nWas there any difficulty breathing noted? (yes/no): ";
	cin >> difficulty;
	cout << "\nWould you like to add a comment? (yes/no) ";
	// comment
}

string rr::getStatus() {

	if ((difficulty == "yes") | (numBreaths > 16)) {
		status = "problematic";
	}
	else {
		status = "fine";
	}

	return status;
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
	string getStatus();
};

void bp::getInfo() {
	cout << "\nPlease enter the systolic pressure in mmHg: ";
	cin >> systolic;
	cout << "\nPlease enter the diastolic pressure in mmHg: ";
	cin >> diastolic;
	cout << "\nWould you like to add a comment? (yes/no) ";
	// comment
}

string bp::getStatus() {
	if ((systolic > 140) & (diastolic > 90)) {
		status = "high blood pressure (hypertension)";
	}
	else if ((systolic > 120) | (diastolic > 80)) {
		status = "prehypertension";
	}
	else {
		status = "normal blood pressure";
	}
	return status;
}



int main() {

	return 0;

}
