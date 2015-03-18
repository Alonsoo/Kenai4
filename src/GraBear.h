/*
 * GraBear.h
 *
 *  Created on: 02/02/2015
 *      Author: Alonso
 */

#ifndef KENAI3_SRC_GRABEAR_H_
#define KENAI3_SRC_GRABEAR_H_
#include "WPILib.h"

class GraBear {
public:
	Joystick stick;
	CANTalon grabear1, grabear2, opener;
	DigitalInput closeLimit;
	DigitalInput openLimit;
	Servo gadget;
	int control;
	int gadgetControl;
	int btnControl;
	double div;
	int openControl;
	bool controlChange;
	double p1;
	double p2;

	GraBear(int pwm1, int pwm2, int pwm3, int stickChan=0);

	void Set(double power1, double power2);
	void Grab();
	void OpenClose();
	void Gadget();

	virtual ~GraBear();
};

#endif /* KENAI3_SRC_GRABEAR_H_ */
