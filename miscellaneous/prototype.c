#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerTwo,   sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerThree,   sensorLineFollower)
#pragma config(Sensor, dgtl1,  bumpSwitchTwo,     sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,  sensorTouch)
#pragma config(Sensor, dgtl3,  bumpSwitchThree, sensorTouch)
#pragma config(Sensor, dgtl10, red,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, yellow,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, green,          sensorLEDtoVCC)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void LED();
//void Safety();

// READING 1300 WHITE PAPER

/* first color floor is white, second is blue, and third is black */
task main() {
	while (1 == 1) {
		clearTimer(T1);
		LED();
		//Safety();

		/* first floor */
		if (SensorValue(lineFollower) > 2950 && SensorValue(lineFollower) < 3100 && SensorValue(bumpSwitchThree) == 1) {
			startMotor(rightMotor, 127);
			/* untilLight(3100, lineFollower);
			stopMotor(rightMotor); */
		}
		if (SensorValue(lineFollower) > 2950 && SensorValue(lineFollower) < 3100 && SensorValue(bumpSwitch) == 1) {
			startMotor(rightMotor, 127);
			/* untilLight(3100, lineFollower);
			stopMotor(rightMotor); */
		}
		if (SensorValue(lineFollower) > 2950 && SensorValue(lineFollower) < 3100 && SensorValue(bumpSwitchTwo) == 1) {
			stopMotor(rightMotor);
		}

		/* second floor
		if (SensorValue(lineFollower) > 2950 && SensorValue(lineFollower) < 3100 && SensorValue(bumpSwitchThree) == 1) {
		startMotor(rightMotor, 127);
		untilLight(3100, lineFollower);
		stopMotor(rightMotor);
		}
		if (SensorValue(lineFollower) > 2950 && SensorValue(lineFollower) < 3100 && SensorValue(bumpSwitch) == 1) {
		stopMotor(rightMotor);
		}
		if (SensorValue(lineFollower) > 2950 && SensorValue(lineFollower) < 3100 && SensorValue(bumpSwitchTwo) == 1) {
		startMotor(rightMotor, 127);
		untilLight(2900, lineFollower);
		stopMotor(rightMotor);
		} */

		/* third floor
		if (SensorValue(lineFollower) == 2900 && SensorValue(bumpSwitchThree) == 1) {
		startMotor(rightMotor, 127);
		untilLight(3100, lineFollower);
		stopMotor(rightMotor);
		}
		if (SensorValue(lineFollower) == 2900 && SensorValue(bumpSwitch) == 1) {
		stopMotor(rightMotor);
		}
		if (SensorValue(lineFollower) == 2900 && SensorValue(bumpSwitchTwo) == 1) {
		startMotor(rightMotor, 127);
		untilLight(3100, lineFollower);
		stopMotor(rightMotor);
		} */
	}
}

void LED() {
	if (SensorValue(bumpSwitchThree) == 1) {
		turnLEDOff(yellow);
		//turnLEDOff(yellow2);
		//turnLEDOff(yellow3);
		turnLEDOff(green);
		//turnLEDOff(green2);
		//turnLEDOff(green3);
		turnLEDOn(red);
		//turnLEDOn(red2);
		//turnLEDOn(red3);
		untilLight(2900, lineFollower);
		turnLEDOff(red);
		//turnLEDOff(red2);
		//turnLEDOff(red3);
	}
	if (SensorValue(bumpSwitch) == 1) {
		turnLEDOff(red);
		//turnLEDOff(red2);
		//turnLEDOff(red3);
		turnLEDOff(yellow);
		//turnLEDOff(yellow2);
		//turnLEDOff(yellow3);
		turnLEDOn(green);
		//turnLEDOn(green2);
		//turnLEDOn(green3);
		untilLight(2900, lineFollower);
		turnLEDOff(green);
		//turnLEDOn(green2);
		//turnLEDOn(green3);
	}
	if (SensorValue(bumpSwitchTwo) == 1) {
		turnLEDOff(green);
		//turnLEDOff(green2);
		//turnLEDOff(green3);
		turnLEDOff(red);
		//turnLEDOff(red2);
		//turnLEDOff(red3);
		turnLEDOn(yellow);
		//turnLEDOn(yellow2);
		//turnLEDOn(yellow3);
		untilLight(2900, lineFollower);
		turnLEDOff(yellow);
		//turnLEDOff(yellow2);
		//turnLEDOff(yellow3);
	}

}

/* void Safety() { // return to first floor
	if(time1[T1] == 30000) {
		untilLight(3100, lineFollower);
		stopMotor(rightMotor);
	}
} */
