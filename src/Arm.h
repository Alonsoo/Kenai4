/*
 * Arm.h
 *
 *  Created on: Jan 30, 2015
 *      Author: Developer
 */

#ifndef KENAI_SRC_ARM_H_
#define KENAI_SRC_ARM_H_
#include "WPILib.h"

class Arm{
public:
	CANTalon arm1;
	CANTalon arm2;
	Joystick stick;
	AnalogPotentiometer pot;
	double actPot;
	double relPot;
	int position;
//	int innerRange;
//	int outerRange;
	double P;
	double I;
	int error;
	int sumError;
	double armPower;
	double aArm;
	double maxSpeed;
	bool btnChange;
	int position_values[4];

	Arm(int pwm1, int pwm2, int potChan, int stickChan=0);

	void Set (double power);
	bool MoveManualy();
	double Accelerate(double power, double *a);
	void MoveToPosition(bool stickEnabled=true);
	int NewPosition(int btn=1);
	double GetAngle();
	double GetPot();

	virtual ~Arm();
};

#endif /* KENAI_SRC_ARM_H_ */
