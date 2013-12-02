/*
 * main.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: jychan
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//// ALL PHYSICAL TESTS

class allTests {
protected:
	int choice;
	string comment;
	string name;
	string id;
public:
	void chooseTest();
	void makeComment();
};

void allTests::chooseTest () {
	cout << "\nWhat test would you like to enter data from? "
			"\n1. Urine test"
			"\n2. Body temperature test"
			"\n3. Pulse rate"
			"\n4. Respiration rate"
			"\n5. Blood pressure";
	cin >> choice;
}

void allTests::makeComment() {
	cout << "\nWould you like to add a comment? (yes/no) ";
	if (cin >> "yes") {
		cout << "\nPlease enter your name: ";
		cin >> name;
		cout << "\nPlease enter your ID: ";
		cin >> id;
		cout << "\nEnter your comment(s): ";
		cin >> comment;
	}
	appendFile(name + id + ": " + "comment");
}

/*
 *
 */

// URINE TESTS

class ut : public allTests {

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
	appendFile("pH: " + string(ph));
	cout << "\nWas there a presence of protein? (yes/no) ";
	cin >> results[0];
	appendFile("protein: " + results[0]);
	cout << "\nWas there a presence of glucose? (yes/no) ";
	cin >> results[1];
	appendFile("glucose: " + results[1]);
	cout << "\nWas there a presence of nitrites? (yes/no) ";
	cin >> results[2];
	appendFile("nitrites: " + results[2]);
	cout << "\nWas there a presence of ketones? (yes/no) ";
	cin >> results[3];
	appendFile("ketones: " + results[3]);
	cout << "\nWas there a presence of bilirubin? (yes/no) ";
	cin >> results[4];
	appendFile("bilirubin: " + results[4]);
	cout << "\nWas there a presence of urobilinogen? (yes/no) ";
	cin >> results[5];
	appendFile("urobilinogen: " + results[5]);
	cout << "\nWas there a presence of red blood cells? (yes/no) ";
	cin >> results[6];
	appendFile("red blood cells: " + results[6]);
	cout << "\nWas there a presence of white blood cells? (yes/no) ";
	cin >> results[7];
	appendFile("white blood cells: " + results[7]);

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
	appendFile("creatinine: " + results[0]);
	cout << "\nWas there a presence of urinary casts? (yes/no) ";
	cin >> results[1];
	appendFile("urinary casts: " + results[1]);
	cout << "\nWas there a presence of crystals? (yes/no) ";
	cin >> results[2];
	appendFile("crystals: " + results[2]);
	cout << "\nWas there a presence of epithelial cells? (yes/no) ";
	cin >> results[3];
	appendFile("epithelial cells: " + results[3]);

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

class bt : public allTests {

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
		status = "suffering from a fever";
	}
	else if (temp < 95) {
		status = "suffering from hypothermia";
	}

	return status;
}

/****
 *
 */

// PULSE RATE

class pr : public allTests {

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
	appendFile("BPM: " + bpm);
	cout << "\nIs the patient an athlete? (yes/no): ";
	cin >> athlete;
	appendFile("Athlete: " + athlete);
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

class rr : public allTests {

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
	appendFile("Number of breaths: " + numBreaths);
	cout << "\nWas there any difficulty breathing noted? (yes/no): ";
	cin >> difficulty;
	appendFile("Difficulty noted: " + difficulty);
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

class bp : public allTests {

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

	appendFile("Blood pressure: " + systolic + "/" + diastolic);
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

/*
 *
 */

// add to file

void appendFile (string sent) {
	ofstream outfile;

	outfile.open("log.txt", ios_base::app);
	outfile << "\n" << sent;
	outfile.close;
}

/*
 *
 */


int main() {

	allTests go;

	go.chooseTest();

	if (go.choice == 1) {
		appendFile("URINE TEST");
		ut urine;
		urine.typeTest();
		if (urine.selection == 1) {
			appendFile("\tRAPID TEST");
			rapid rt;
			rt.getInfo();
			go.makeComment();
			rt.detectAbnormal();
			if (rt.status == "fine") {
				cout << "\nThe patient's rapid urine test did not return any conclusive results.";
				appendFile("\nThe patient's rapid urine test did not return any conclusive results.");
			}
			else {
				cout << "\nThe patient's rapid urine test returned troubling results. The patient may be suffering from: \n--- ";
				appendFile("\nThe patient's rapid urine test returned troubling results. The patient may be suffering from: \n--- ");
			}
		}
		else if (urine.selection == 2) {
			appendFile("\tURINALYSIS");
			urinalysis ua;
			ua.getInfo();
			go.makeComment();
			ua.detectAbnormal();
			if (ua.status == "fine") {
				cout << "\nThe patient's urinalysis test did not return any conclusive results.";
				appendFile("\nThe patient's urinalysis test did not return any conclusive results.");
			}
			else if (ua.status == "problematic") {
				cout << "\nThe patient's urinalysis test returned troubling results.";
				appendFile("\nThe patient's urinalysis test returned troubling results.");
			}
			else {
				cout << "\nThe patient's urinalysis test returned troubling results. The patient may be suffering from: \n--- " << ua.status;
				appendFile("\nThe patient's urinalysis test returned troubling results. The patient may be suffering from: \n--- " + ua.status);
			}
		}
	}
	else if (go.choice == 2) {
		appendFile("BODY TEMPERATURE TEST");
		bt body;
		body.typeTest;
		go.makeComment();
		if (body.selection == (1 | 4 | 5)) {
			appendFile("\tDIRECT TEST");
			body.getStatus(body.measured);
		}
		else if (body.selection == 2) {
			appendFile("\RECTAL TEST");
			rectal bodyt;
			cout << "\n---The patient likely is " << bodyt.getStatus(bodyt.actualTemp());
			appendFile("\n---The patient likely is " + bodyt.getStatus(bodyt.actualTemp()));
		}
		else if (body.selection == 3) {
			appendFile("\AXILLARY TEST");
			axillary bodyte;
			cout << "\n---The patient likely is " << bodyte.getStatus(bodyte.actualTemp());
			appendFile("\n---The patient likely is " + bodyte.getStatus(bodyte.actualTemp()));
		}
	}
	else if (go.choice == 3) {
		appendFile("PULSE RATE TEST");
		pr pulse;
		pulse.getInfo();
		go.makeComment();
		pulse.getStatus();

		if (pulse.getStatus() == "fine") {
			cout << "\nThe patient's pulse rate test did not return any conclusive results.";
			appendFile("\nThe patient's pulse rate test did not return any conclusive results.");
		}
		else if (pulse.getStatus() == "problematic") {
			cout << "\nThe patient's pulse rate test returned troubling results.";
			appendFile("\nThe patient's pulse rate test returned troubling results.");
		}
	}
	else if (go.choice == 4) {
		appendFile("RESPIRATORY RATE TEST");
		rr resp;
		resp.getInfo();
		go.makeComment();
		resp.getStatus();

		if (resp.getStatus() == "fine") {
			cout << "\nThe patient's respiratory rate test did not return any conclusive results.";
			appendFile("\nThe patient's respiratory rate test did not return any conclusive results.");
		}
		else if (resp.getStatus() == "problematic") {
			cout << "\nThe patient's respiratory rate test returned troubling results.";
			appendFile("\nThe patient's respiratory rate test returned troubling results.");
		}
	}
	else if (go.choice == 5) {
		appendFile("BLOOD PRESSURE TEST");
		bp pres;
		pres.getInfo();
		go.makeComment();
		pres.getStatus();

		if (pres.getStatus() == "fine") {
			cout << "\nThe patient's blood pressure test did not return any conclusive results.";
			appendFile("\nThe patient's blood pressure test did not return any conclusive results.");
		}
		else if (pres.getStatus() == "problematic") {
			cout << "\nThe patient's blood pressure test returned troubling results.";
			appendFile("\nThe patient's blood pressure test returned troubling results.");
		}
	}

	return 0;

}
