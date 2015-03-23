/*
 * GraBear.cpp
 *
 *  Created on: 02/02/2015
 *      Author: Alonso
 */

#include <GraBear.h>

GraBear::GraBear(int pwm1, int pwm2, int pwm3, int stickChan):
stick(stickChan),
grabear1(pwm1),
grabear2(pwm2),
opener(pwm3),
closeLimit(1),
openLimit(2),
gadget(4)
{
	control=0;
	gadgetControl=0;
	btnControl=false;
	div=1;
	openControl=0;
	controlChange=true;
	p1=0;
	p2=0;
	// TODO Auto-generated constructor stub
}

void GraBear::Set(double power1, double power2){
	grabear1.Set(power1+power2);
	grabear2.Set(-power1+power2);
}

void GraBear::Grab(){
	if(stick.GetRawAxis(2)!=0.0||stick.GetRawAxis(3)!=0.0){
		p1=( (stick.GetRawAxis(2)!=0.0)?1:0 ) - ( (stick.GetRawAxis(3)!=0.0)?1:0 );
	}
	else{
		p1= ( (stick.GetPOV()==0)?1:0 ) - ( (stick.GetPOV()==180)?1:0 );
	}


	p2= ( (stick.GetPOV()==90)?1:0 ) - ( (stick.GetPOV()==270)?1:0 );
	//Set(   (stick.GetRawAxis(2)-stick.GetRawAxis(3))/1.5   );
	Set(p1,p2);
}

void GraBear::OpenClose(){
//	switch(control){
//		case 0: if(stick.GetRawButton(8)){
//			if(controlChange){
//					controlChange=false;
//					control=1;
//			}
//				}
//				else if(!closeLimit.Get()){
//						//opener.Set(1);
//					openControl=1;
//					controlChange=true;
//				}
//				else{
//					opener.Set(0);
//					openControl=0;
//					controlChange=true;
//				}
//				break;
//		case 1: if(stick.GetRawButton(8)){
//			if(controlChange){
//					control=0;
//					controlChange=false;
//			}
//				}
//				else if(!openLimit.Get()){
//						//opener.Set(-1);
//						openControl=0;
//						controlChange=true;
//				}
//				else{
//						opener.Set(0);
//						openControl=0;
//						controlChange=true;
//				}
//				break;
//	}
	opener.Set((stick.GetRawButton(7)/*-stick.GetRawButton(8))*/));
}

void GraBear::Gadget(){
	switch(gadgetControl){
	case 0:
		gadget.SetAngle(150.0);
		break;
	case 1:
		gadget.SetAngle(0.0);
		break;
	}
}

GraBear::~GraBear() {
	// TODO Auto-generated destructor stub
}

