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

	if (IgGRatio>=0 && IgGRatio<=1){
			cout << "IgG Ratio Normal";
		} else {
			cout << "IgG Ratio Abnormal";
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
	cout << "What is the Total Cholesterol?\n";
	cin >> TotalCholesterol;
	cout << "What is the LDL?\n";
	cin >> LDL;
	cout << "What is the HDL?\n";
	cin >> HDL;
	cout << "Any comments?";
	cin >> DLcomment;
}

Cholesterol::checkDL(){
	if(TotalCholesterol>=0 && TotalCholesterol<=239){
		cout << "Total Cholesterol Normal\n";
	} else {
		cout << "Total Cholesterol Abnormal\n";
	}

	if (LDL>=0 && LDL<=159){
		cout << "LDL Normal";
	} else {
		cout << "LDL Abnormal";
	}

	if (HDL>=0 && HDL<=59){
			cout << "HDL Normal";
		} else {
			cout << "HDL Abnormal";
		}
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
	cout << "What is the C Protein?\n";
	cin >> proteinC;
	cout << "What is the S Protein?\n";
	cin >> proteinS;
	cout << "What is the Prothrombin?\n";
	cin >> PTT;
	cout << "What is the Homocysteine?\n";
	cin >> Homocysteine;
	cout << "Any comments?";
	cin >> CMcomment;
}

CoagulationMarkers::checkCM(){
	if(proteinC>=0.6 && proteinC<=3.6){
		cout << "C Protein Normal\n";
	} else {
		cout << "C Protein Abnormal\n";
	}

	if (proteinS>=1.2 && proteinS<=7.2){
		cout << "S Protein Normal";
	} else {
		cout << "S Protein Abnormal";
	}

	if (PTT>=10 && PTT<=15){
			cout << "Prothrombim Normal";
		} else {
			cout << "Prothrombin Abnormal";
		}
	if (Homocysteine>=0.9 && Homocysteine<=1.2){
				cout << "Homocysteine Normal";
			} else {
				cout << "Homocysteine Abnormal";
			}
}
