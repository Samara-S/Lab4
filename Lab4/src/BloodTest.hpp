#include <iostream>
using namespace std;

//BloodCount will be the base class common to all derived classes

class BloodCount {
	public:
	int RBC;
	int WBC;

	void getRBC ();
	void getWBC ();
	void CheckBC (const int pRBC, const int pWBC);
};

//void getRBC(); will get the patients RBC count

//IgGMarkers looks for signs that the patient has had certain diseases in the past

class IgGMarkers : public BloodCount {

};

//Cholesterol checks on the patients LDL and HDL

class Cholesterol : public BloodCount{

};

class CoagulationMarkers : public BloodCount{

};
