#include "std_lib_facilities.h"
#include "canonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
	double diff = (compareOperand - toOperand);
	if (abs(diff) > maxError){
		cout << name << " er forskjellig fra " << toOperand << endl;
	}
	else{
		cout << name << " er tilnaermet lik " << toOperand << endl;
	}
}

void playTargetPractice(){
	int lives=10;
	double winTolerance = 10.0;
	double theta;
	double absVel;

	double distanceToTarget=randomWithLimits(100, 1000);
	cout << distanceToTarget;
	while (lives>0){
		theta=degToRad(getUserInputTheta());
		absVel=getUserInputAbsoluteVelocity();
		vector<double> velVec=getVelocityVector(theta, absVel);
		double dist=targetPractice(distanceToTarget, velVec[0], velVec[1]);
		int ja = abs(static_cast<int>(dist));
		cout << ja << "\t" << dist;
		if (abs(static_cast<int>(dist))<winTolerance){
			cout << "Gratulerer, du vant! Du brukte " << (10-lives) << " forsøk!\n";
			break;
		}
		else{
			lives-=1;
			cout << "Beklager, den landet " << dist;
			if (dist>0){
				cout << " for langt.\n";
			}
			else {
				cout << " for kort.\n";
			}
		}
		cout << "Kula var oppe i ";
		printTime(flightTime(absVel));
		cout << ".\n";

	}
}

int main()
{
	// Her følger en rekke gamle tester for programmet:
	double acclX = 0.0;
	vector<double> t = {0.0, 2.5, 5.0};
	vector<double> initVel{50.0, 25.0};
	vector<double> initPos{0.0, 0.0};
	cout << "\tT=0\tT=2.5\tT=5"  << endl;
	cout << "acclX\t" << acclX << "\t" << acclX << "\t" << acclX << endl;
	cout << "acclY\t" << acclY() << "\t" << acclY() << "\t" << acclY() << endl;
	cout << "velX\t" << initVel[0] << "\t" << initVel[0] << "\t" << initVel[0] << endl;
	cout << "velY\t" << velY(t[0], initVel[1]) << "\t" << velY(t[1], initVel[1]) << "\t" << velY(t[2], initVel[1]) << endl;
	cout << "posX\t" << posX(initPos[0], initVel[0], t[0]) << "\t" << posX(initPos[0], initVel[0], t[1]) << "\t" << posX(initPos[0], initVel[0], t[2]) << endl;
	cout << "posY\t" << posY(initPos[1], initVel[1], t[0]) << "\t" << posY(initPos[1], initVel[1], t[1]) << "\t" << posY(initPos[1], initVel[1], t[2]) << endl;
	printTime(1024);
	cout << flightTime(initVel[1]) << endl;
	testDeviation(posX(0.0, 50.0, 5.0), 250.0, 0.0001, "posX(0.0, 50.0, 5.0)");

	cout << degToRad(93.0) << endl;

	double userVel = getUserInputAbsoluteVelocity();
	
	double userTheta = degToRad(getUserInputTheta());

	vector<double> velocityVector = getVelocityVector(userTheta, userVel);

	cout << userTheta << "\t" << velocityVector[0] << velocityVector[1] << endl;

	cout << targetPractice(100.0, velocityVector[0], velocityVector[1]);
	/*

	srand(static_cast<unsigned int>(time(nullptr))); // seeding randoms
	playTargetPractice();
	*/
	keep_window_open();
}

//------------------------------------------------------------------------------
