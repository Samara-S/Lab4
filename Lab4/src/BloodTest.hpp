#include <iostream>
using namespace std;

//BloodCount will be the base class common to all derived classes

class BloodCount {
	public:
	int RBC;
	int WBC;

	void getRBC ();
	void getWBC ();
	void CheckBC ();
};

//void getRBC(); will get the patients RBC count
BloodCount::getRBC(){
	cout << "What is the Red Blood Cell Count?\n";
	cin >> RBC;
}
//void getWBC() will get the patients WBC count
BloodCount::getWBC(){
	cout << "What is the White Blood Cell Count?\n";
	cin >> WBC;
}
//void CheckBC() will check if they're in normal ranges
BloodCount::CheckBC(){
	if(RBC>=4000000 && RBC<=6000000){
		cout << "RBC Normal\n";
	} else {
		cout << "RBC Abnormal\n";
	}

	if (WBC>=4500 && WBC<=10000){
		cout << "WBC Normal";
	} else {
		cout << "WBC Abnormal";
	}
}
//IgGMarkers looks for signs that the patient has had certain diseases in the past

class IgGMarkers : public BloodCount {

};

//Cholesterol checks on the patients LDL and HDL

class Cholesterol : public BloodCount{

};

class CoagulationMarkers : public BloodCount{

};
