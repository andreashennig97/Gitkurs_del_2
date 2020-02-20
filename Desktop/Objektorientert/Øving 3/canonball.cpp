
#include "canonball.h"
#include "std_lib_facilities.h"

double acclY(){
    return -9.81;
}

double velY(double time, double initVelocityY){
    return (initVelocityY + time*acclY());
}

double posX(double initPositionX, double initVelocityX, double time){
    return (initPositionX + initVelocityX*time);
}

double posY(double initPositionY, double initVelocityY, double time){
    return (initPositionY + velY(time, initVelocityY)*time + acclY()*time*time*0.5);
}

void printTime(double time){
	int timer = time/3600;
	int temp = time-(3600*timer);
	int minutter = temp/60;
	temp -= minutter*60;
	int sekunder = temp;
	std::cout << timer << " tango, " << minutter << " mike, " << sekunder << " sierra.\n";
}

double flightTime(double initVelocityY){
    return (-2*initVelocityY/acclY());
}

double getUserInputTheta(){
	double theta;
	std::cout << "Skriv inn vinkel: ";
	std::cin >> theta;
	return theta;
}

double getUserInputAbsoluteVelocity(){
	double velocity;
	std::cout << "Skriv inn absolutt fart: ";
	std::cin >> velocity;
	return velocity;
}

double degToRad(double deg){
	return (deg*atan(1.0)*4/180);
}

double getVelocityX(double theta, double absVelocity){
	return (absVelocity*cos(theta));
}

double getVelocityY(double theta, double absVelocity){
	return (absVelocity*sin(theta));
}


vector<double> getVelocityVector(double theta, double absVelocity){
	vector<double> velocityVector;
	velocityVector.push_back(getVelocityX(theta, absVelocity));
	velocityVector.push_back(getVelocityY(theta, absVelocity));
	return velocityVector;
}


double getDistanceTraveled(double velocityX, double velocityY){
	return (velocityX*flightTime(velocityY));
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
	return (abs(getDistanceTraveled(velocityX, velocityY)-distanceToTarget));
}
