#include <iostream>
#include <string>
using namespace std;

//BloodTest classes done by Samara Seepersad (500 396 756)

//BloodCount will be the base class common to all derived classes

class BloodCount {
	private:
	int RBC;
	int WBC;
	int platelets;
	int BCcomment;

	void getBC ();
	void CheckBC ();
};

//void getBC(); will get the patients RBC and WBC count
BloodCount::getBC(){
	cout << "What is the Red Blood Cell Count?\n";
	cin >> RBC;
	cout << "What is the White Blood Cell Count?\n";
	cin >> WBC;
	cout << "What is the Platelets Count?\n";
	cin >> platelets;
	cout << "Any comments";
	cin >> BCcomment;
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

	if (platelets>=140000 && platelets<=450000){
			cout << "Platelets Normal";
		} else {
			cout << "Platelets Abnormal";
		}
}
//IgGMarkers looks for signs that the patient has had certain diseases in the past

class IgGMarkers : public BloodCount {
public:
	int IgGSerum;
	int IgGCSF;
	int IgGRatio;
	string IgGcomment;

	void getIgG();
	void CheckIgG();
};

//Functions for IgG
IgGMarkers::getIgG():getBC(){
	cout << "What is the Serum IgG?\n";
	cin >> IgGSerum;
	cout << "What is the CSF IgG?\n";
	cin >> IgGCSF;
	cout << "What is the IgG Ratio?\n";
	cin >> IgGRatio;
	cout << "Any comments?";
	cin >> IgGcomment;
}

IgGMarkers::CheckIgG(){
	if(IgGSerum>=0.2 && IgG<=4.2){
		cout << "IgG Serum Normal\n";
	} else {
		cout << "IgG Serum Abnormal\n";
	}

	if (IgGCSF>=4.5 && IgGCSF<=10){
		cout << "IgG CSF Normal";
	} else {
		cout << "IgG CSF Abnormal";
	}

	if (platelets>=140000 && platelets<=450000){
			cout << "Platelets Normal";
		} else {
			cout << "Platelets Abnormal";
		}
}


//Cholesterol checks on the patients LDL and HDL

class Cholesterol : public BloodCount{
public:
	int TotalCholesterol;
	int LDL;
	int HDL;
	string DLcomment;

	void getDL();
	void checkDL();
};

Cholesterol::getDL():getBC(){
	//Similar to getIgG
}

Cholesterol::checkDL(){
	//Similar to checkBC but for IgGs
}

//CoagulationMarkers to Proteins and other coagulants
class CoagulationMarkers : public BloodCount{
public:
	int proteinC;
	int proteinS;
	int PTT;
	int Homocysteine;
	string CMcomment;

	void getCM();
	void checkCM();
};

CoagulationMarkers::getCM():getBC(){
	//Similar to getIgG() but for CMs
}

CoagulationMarkers::checkCM(){
	//Similar to check BC but for CMs
}
