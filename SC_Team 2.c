#pragma config(Sensor, dgtl1,  sonic,          sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  limit,          sensorTouch)
#pragma config(Motor,  port1,           leftmotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port10,          rightmotor,    tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void forwardfortime (int speed, int time) {
  motor[leftmotor] = speed;
  motor[rightmotor] = speed;
  wait1Msec(time);
  motor[leftmotor] = 0;
  motor[rightmotor] = 0;
}
void motorsset (int speed) {
  motor[leftmotor] = speed;
  motor[rightmotor] = speed;
}

task main() {
  while (true) {
    /* code */
  }
}
