/*
 * Drive.h
 *
 *  Created on: 03/02/2015
 *      Author: Alonso
 */

#ifndef KENAI3_SRC_DRIVE_H_
#define KENAI3_SRC_DRIVE_H_
#include "WPILib.h"

class Drive {
public:
	Talon frontRight;
	Talon frontLeft;
	Talon backRight;
	Talon backLeft;
	Servo servo;
	Joystick stick;
	Gyro gyro;
	PIDController pid;
	double Y;
	double X;
	double gX;
	double X2;
	double heading;
	double gyroError;
	int deadzone;
	int pDiv;
	bool PChange;
	int control;


	Drive(int pwm1, int pwm2, int pwm3, int pwm4, int stickChan=0);
	void Set(double pfr, double pfl, double pbr, double pbl);
	double Accelerate(double power, double *a);
	void MecanumDrive();
	void Precision();
	void Paraguas();
	virtual ~Drive();
};

#endif /* KENAI3_SRC_DRIVE_H_ */
