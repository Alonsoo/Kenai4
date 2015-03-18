/*
 * Arm.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: Developer
 */

#include <Arm.h>

Arm::Arm(int pwm1, int pwm2, int potChan, int stickChan):
arm1(pwm1),
arm2(pwm2),
stick(stickChan),
pot(potChan, 250)
{
	actPot=pot.Get();
	relPot=0;
	position=0;
//	innerRange=5;
//	outerRange=50;
	P=0.02;
	I=0.00004;
	error=0;
	sumError=0;
	armPower=0;
	aArm=0;
	maxSpeed=0.5;
	btnChange=true;
	// TODO Auto-generated constructor stub
}

void Arm::Set(double power){
	if( (relPot>110 && power/abs(power)>0.0)  ||  (relPot<0 && power/abs(power)<0.0) ){
		arm1.Set(0);
		arm2.Set(0);
	}
	else{
		arm1.Set(-power);
		arm2.Set(power);
	}
}

bool Arm::MoveManualy(){
	if(stick.GetRawButton(5)||stick.GetRawButton(6)){

		Set(((stick.GetRawButton(6)-stick.GetRawButton(5)))*(0.5));

		position = relPot;
		return true;
	}
	else{
		//btnChange=true;
		//Set(0);
		return false;
	}
}


//double Arm::Accelerate(double power, double *a){
//	if(*a<power){
//		*a=*a + 0.01;
//	}
//	else if(*a>power){
//		*a= *a - 0.01;
//	}
//	return *a;
//}

 void Arm::MoveToPosition(bool stickEnabled){

	if((stick.GetRawButton(1)||stick.GetRawButton(2)||stick.GetRawButton(3)||stick.GetRawButton(4))  &&  stickEnabled){
		position=NewPosition();
		if(position==60){
			position=80;
		}
		sumError=0;
	}
	if(stick.GetRawButton(8)){
		actPot=pot.Get();
		position=0;
		sumError=0;
	}
	relPot=pot.Get()-actPot;
	error=position-relPot;
//	if(abs(error)<3){
//		error=0;
//	}
	sumError=sumError+error;
//	armPower=(abs(error)<outerRange)   ?   (   (abs(error)<innerRange) ?  0  :   (error*(1/outerRange))  )  :1*error/abs(error);
	armPower=P*error;
	if(armPower>maxSpeed){
		armPower=maxSpeed;
	}
	if(armPower<-maxSpeed){
		armPower=-maxSpeed;
	}

	if(!MoveManualy()){
		Set(armPower);
	}
}

int Arm::NewPosition (int btn){
		if(btn>4){
			return position;
		}
		if(stick.GetRawButton(btn)){
			return (btn-1)*30;
		}else{
			return NewPosition(btn+1);
		}
	}

double Arm::GetAngle(){
		return relPot;
	}

double Arm::GetPot(){
	return pot.Get();
}

Arm::~Arm() {
	// TODO Auto-generated destructor stub
}

