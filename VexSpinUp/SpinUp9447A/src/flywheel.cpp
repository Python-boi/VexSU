#include "flywheel.hpp"
#include "motors.hpp"

sate = false;

void flywheelVoltage(int speed1){
    speed1 = speed1*20;
    flywheel.move_voltage(speed1);
}
void toggleFlywheel(){
  if(flywheelstate == true){
    flywheelVoltage(600);
  }
  else{
    flywheel.move_brake();
  }
  flyWheelState = !flyWheelState;
}
void flywheelOpcontrol(){
  if(master.get_digital_new_press(CONTROLLER_DIGITAL_R1) && !lastPress){
		toggleFlywheel(!flyWheelState);
	   }
	   lastPress = master.get_digital_new_press(CONTROLLER_DIGITAL_R1);

   if(master.get_digital_new_press(CONTROLLER_DIGITAL_L1)){
    loader.set_value(!state);
    state = true;
    delay(10);
    loaader.set_value(!state)
    state = false;
    delay(10);
   }
}