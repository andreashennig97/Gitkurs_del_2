#pragma once
#include "std_lib_facilities.h"

double acclY();

double velY(double time, double initVelocityY);

double posX(double initPositionX, double initVelocityX, double time);

double posY(double initPositionY, double initVelocityY, double time);

void printTime(double time);

double flightTime(double initVelocityY);

double getUserInputTheta();

double getUserInputAbsoluteVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);

double getVelocityY(double theta, double absVelocity);

vector<double> getVelocityVector(double theta, double absVelocity);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);

void playTargetPractice();
