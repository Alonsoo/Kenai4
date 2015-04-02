/*
 * Drive.cpp
 *
 *  Created on: 03/02/2015
 *      Author: Alonso
 */
/*
#include <Drive.h>

Drive::Drive(int pwm1, int pwm2, int pwm3, int pwm4, int stickChan):
frontRight(pwm1),
frontLeft(pwm2),
backRight(pwm3),
backLeft(pwm4),
stick(stickChan),
gyro(2),
pid(1, 0.01, 0.0, &gyro, NULL)
{
	Y=0;
	X=0;
	X2=0;
	deadzone=20;
	pDiv=1;
	PChange=true;
	// TODO Auto-generated constructor stub
}

void Drive::Set(double pfr, double pfl, double pbr, double pbl){
	frontRight.Set(pfr);
	frontLeft.Set(-pfl);
	backRight.Set(pbr);
	backLeft.Set(-pbl);
}


void Drive::MecanumDrive(){
//	if(stick.GetPOV()==0||stick.GetPOV()==45||stick.GetPOV()==315){
//		Y=0.7;
//	}
//	else if(stick.GetPOV()==135||stick.GetPOV()==180||stick.GetPOV()==225){
//		Y=-0.7;
//	}
/*	else*/ /*if(abs(stick.GetY()*100)<deadzone){
		Y=0;
	}
	else{
		Y=-stick.GetY()*0.7;
	}

//	if(stick.GetPOV()==45||stick.GetPOV()==90||stick.GetPOV()==135){
//		X=-0.7;
//	}
//	else if(stick.GetPOV()==225||stick.GetPOV()==270||stick.GetPOV()==315){
//		X=0.7;
//	}
/*	else*/ /*if(abs(stick.GetX()*100)<deadzone){
		X=0;
	}
	else{
		X=-stick.GetX()*0.7;
	}

	if(abs(stick.GetRawAxis(4)*100)<deadzone){
		X2=X*0.3;
	}
	else{
		X2=(-stick.GetRawAxis(4)*0.7)+X*0.3;
	}



	Set( (Y+X+X2), (Y-X-X2), (Y-X+X2), (Y+X-X2) );
}


void Drive::Precision(){
	if(stick.GetRawButton(8)){
		if(PChange){
			PChange=false;
			pDiv=-pDiv+3.5;
		}
	}
	else{
		PChange=true;
	}
}


void Drive::Paraguas(){
	if(stick.GetRawButton(5)){
		servo.Set(250);
	}
	else if(stick.GetRawButton(6)){
		servo.Set(0);
	}
}


Drive::~Drive() {
	// TODO Auto-generated destructor stub
}
*/
