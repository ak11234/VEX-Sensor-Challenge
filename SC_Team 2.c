#pragma config(Sensor, in1,    line1,          sensorLineFollower)
#pragma config(Sensor, in2,    line2,          sensorLineFollower)
#pragma config(Sensor, in3,    line3,          sensorLineFollower)
#pragma config(Sensor, dgtl1,  sonic,          sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  limit,          sensorTouch)
#pragma config(Sensor, dgtl4,  leftencode,     sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  rightencode,    sensorQuadEncoder)
#pragma config(Motor,  port1,           leftmotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           topjaw,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           scooptilt,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightmotor,    tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*The forwardfortime function makes to robot move forwards
at a specified speed for a specified time. */
void forwardfortime (int speed, int time) {
	motor[leftmotor] = speed;
	motor[rightmotor] = speed;
	wait1Msec(time);
	motor[leftmotor] = 0;
	motor[rightmotor] = 0;
}
/*The setmotorspeed function simply sets the speed of both
motors at once. Saving space and time. (For the coder)*/
void setmotorspeed (int speed) {
	motor[leftmotor] = speed;
	motor[rightmotor] = speed;
}
/*This function does a zero point turn based on speed,
time (optional), and direction.
True = Clockwise turn. False = Counterclockwise turn.
If the time paramater is -1, the motor will not be stopped
when the function ends, meaning they must be stopped later. */
void zeropointturn (int speed, int time, bool direction) {
  if (direction == true) {
    motor[leftmotor] = speed;
    motor[rightmotor] = -1 * speed;
    if (time > 0) {
      wait1Msec(time);
      setmotorspeed(0);
    }
  }
  if (direction == false) {
    motor[leftmotor] = -1 * speed;
    motor[rightmotor] = speed;
    if (time > 0) {
      wait1Msec(time);
      setmotorspeed(0);
    }
  }
}
void gotobin () {
  int y1;
  int y2;
  int y3;

}
/* This function automatically does a u-turn.
True = right turn, False = left turn */
void uturn (bool direction) {
	if (direction == true) {
		SensorValue(leftencode) = 0;
		SensorValue(rightencode) = 0;
		while (SensorValue(leftencode) > -160) {
			motor[leftmotor] = 127;
			motor[rightmotor] = -127;
		}
		setmotorspeed(127);
		wait1Msec(500);
		if (direction == false) {
			SensorValue(leftencode) = 0;
			SensorValue(rightencode) = 0;
			while (SensorValue(leftencode) < 160) {
				motor[leftmotor] = -127;
				motor[rightmotor] = 127;
			}
			setmotorspeed(0);
		}
	}
}
void dump () {
	motor[scooptilt] = 30;
	wait1Msec(750);
	motor[scooptilt] = 0;
	motor[topjaw] = -30;
	wait1Msec(1000);
	motor[topjaw] = 0;
	wait1Msec(3500);
	motor[topjaw] = 30;
	motor[scooptilt] = -30;
	wait1Msec(1000);
	motor[topjaw] = 0;
	motor[scooptilt] = 0;
}

	//Beginning the autonomous operation of the robot.
	task main() {
		SensorValue(rightencode) = 0;
		SensorValue(leftencode) = 0;
		int zigzagcount = 0;
		while (zigzagcount > 2) {
			while (SensorValue(sonic) > 10) {
				setmotorspeed(100);
			}
			setmotorspeed(0);
			uturn(false);
			while (SensorValue(sonic) > 10) {
				setmotorspeed(100);
			}
			uturn(true);
			zigzagcount=zigzagcount + 1;
		}
		gotobin();
	}
