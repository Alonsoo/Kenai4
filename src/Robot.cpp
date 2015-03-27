#include "WPILib.h"
#include "Arm.h"
#include "GraBear.h"
#include "Drive.h"

class Robot: public SampleRobot
{
	SmartDashboard *sd;
	Joystick stick;
//	Talon FrontRight, BackRight, FrontLeft, BackLeft;
//	CANTalon GraBear1, GraBear2, Opener;
	Arm arm;
	GraBear grabear;
	Drive drive;

public:
	Robot() :
		sd(),           //?????????????????
		stick(0),
		arm(2, 5, 0, 1),
		grabear(1, 4, 3, 1),
		drive(1, 3, 0, 2, 0)
	{
	}

	void RobotInit(){
//		CameraServer::GetInstance()->SetQuality(50);
//	//the camera name (ex "cam0") can be found through the roborio web interface
//		CameraServer::GetInstance()->StartAutomaticCapture("cam0");
	}

	void Autonomous()
	{

			//arm.MoveToPosition(false);

			drive.Set(-0.5,-0.5,-0.5,-0.5);
			Wait(1.3);
			drive.Set(0,0,0,0);

			//Mas Autonomos!


	}


	void OperatorControl()
	{
		//double power;
		//SendableChooser *chooser;
		arm.position=0;
		arm.actPot=arm.GetPot();
		drive.pDiv=1;
		CameraServer::GetInstance()->SetQuality(50);
		//the camera name (ex "cam0") can be found through the roborio web interface
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");

		while (IsOperatorControl() && IsEnabled())
		{
			//power= (1-stick2.GetThrottle()/2) + (1-(1-stick2.GetThrottle()/2))/10;

//			chooser->AddDefault("auto1", new Arm(1,2,3));
//			chooser->AddObject("auto2", new GraBear(4,5,6));
			//sd->PutData("autonomous", chooser);
			sd->PutNumber("Power", arm.armPower);
			sd->PutNumber("Error", arm.error);
			sd->PutNumber("tError", arm.sumError);
			sd->PutNumber("Position", arm.position);
			sd->PutNumber("div", drive.pDiv);
//			sd->PutNumber("I", arm.I);
			sd->PutNumber("Angle", arm.GetAngle());
			sd->PutNumber("Pot", arm.GetPot());
			sd->PutBoolean("Manual", arm.MoveManualy());
//			sd->PutNumber("control", grabear.control);
//			sd->PutNumber("Button Control", grabear.btnControl);
//			sd->PutNumber("POV", stick.GetPOV());
//			sd->PutData("cLimit", &grabear.closeLimit);
//			sd->PutData("olimit", &grabear.openLimit);
//			sd->PutNumber("open Control", grabear.openControl);
			sd->PutNumber("Y",drive.Y);
//			sd->PutNumber("Gadget", grabear.gadgetControl);
			sd->PutNumber("p1",grabear.p1);
			sd->PutNumber("p2",grabear.p2);
			sd->PutNumber("maxSpeed", arm.maxSpeed);
			sd->PutNumber("pid",drive.pid.Get());
//			SmartDashboard::PutNumber("DB/Slider 0", arm.GetAngle());
//			SmartDashboard::PutNumber("DB/Slider 1", arm.maxSpeed);
//			arm.maxSpeed=SmartDashboard::GetNumber("DB/Slider 2");
//			grabear.div=SmartDashboard::GetNumber("DB/Slider 2");


			arm.MoveToPosition();
			arm.MoveManualy();

			grabear.Grab();
			grabear.OpenClose();
//			grabear.Gadget();

			drive.MecanumDrive();
			drive.Precision();

			if(arm.GetAngle()>20){
				grabear.gadgetControl=1;
			}
			else{
				grabear.gadgetControl=0;
			}

			Wait(0.005);				// wait for a motor update time
		}
	}

};

START_ROBOT_CLASS(Robot);
