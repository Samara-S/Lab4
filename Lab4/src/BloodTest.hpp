#include <iostream>
using namespace std;

//BloodCount will be the base class common to all derived classes

class BloodCount {
	private:
	int RBC;
	int WBC;

	void getBC ();
	void CheckBC ();
};

//void getBC(); will get the patients RBC and WBC count
BloodCount::getBC(){
	cout << "What is the Red Blood Cell Count?\n";
	cin >> RBC;
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
public:
	int IgGSerum;
	int IgGCSF;
	int IgGRatio;

	void getIgG();
	void CheckIgG();
};

//Functions for IgG
IgGMarkers::getSerum():getBC(){
	cout << "What is the Serum IgG?\n";
	cin >> IgGSerum;
	cout << "What is the CSF IgG?\n";
	cin >> IgGCSF;
	cout << "What is the IgG Ratio?\n";
	cin >> IgGRatio;
}

IgGMarkers::CheckIgG(){
	//Like the CheckBC it will check if the IgG values are in normal ranges
}


//Cholesterol checks on the patients LDL and HDL

class Cholesterol : public BloodCount{
public:
	int LDL;
	int HDL;

	void getDL();
	void checkDL();
};

Cholesterol::getDL():getBC(){
	//Similar to getIgG
}

Cholesterol::checkDL(){
	//Similar to checkBC
}

//CoagulationMarkers to
class CoagulationMarkers : public BloodCount{

};
