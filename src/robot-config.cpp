#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXCode device constructors
motor fLeftMotor = motor(PORT11, ratio6_1, true);
motor mLeftMotor = motor(PORT12, ratio6_1, true);
motor bLeftMotor = motor(PORT13, ratio6_1, true);
motor fRightMotor = motor(PORT1, ratio6_1, false);
motor mRightMotor = motor(PORT2, ratio6_1, false);
motor bRightMotor = motor(PORT6, ratio6_1, false);

inertial iner = inertial(PORT10);

rotation leftRot = rotation(PORT4, true);
rotation rearRot = rotation(PORT3, false);

controller Controller1 = controller(primary);

motor flywheel = motor(PORT5, ratio36_1, true);
motor intake = motor(PORT20, ratio6_1, true);

digital_out leftWing = digital_out(Brain.ThreeWirePort.E);
digital_out rightWing = digital_out(Brain.ThreeWirePort.G);
digital_out intakePist = digital_out(Brain.ThreeWirePort.H);
digital_out AWPShoot = digital_out(Brain.ThreeWirePort.A);
 
bool leftWingToggle = false;
bool rightWingToggle = false;
bool intakePistToggle = false;
bool AWPShootToggle = false;
 
void ButtonL2_Callback()
{
  leftWingToggle = !(leftWingToggle);
  leftWing.set(leftWingToggle);
  printf("activated callback \n left wing toggle: %d \n", leftWingToggle);
}
void ButtonR2_Callback()
{
  rightWingToggle = !(rightWingToggle);
  rightWing.set(rightWingToggle);
  printf("activated callback \n right wing toggle: %d \n", rightWingToggle);
}
void ButtonX_Callback()
{
  intakePistToggle = !(intakePistToggle);
  intakePist.set(intakePistToggle);
  printf("activated callback \n intake piston toggle: %d \n", intakePistToggle);
}

void ButtonA_Callback(){
  AWPShootToggle = !(AWPShootToggle);
  AWPShoot.set(AWPShootToggle);
  printf("activated callback \n AWP shoot toggle: %d \n", AWPShootToggle);
}


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
