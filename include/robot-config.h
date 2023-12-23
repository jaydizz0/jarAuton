using namespace vex;

extern brain Brain;
extern controller Controller1;

extern motor fLeftMotor;
extern motor fRightMotor;
extern motor mLeftMotor;
extern motor mRightMotor;
extern motor bLeftMotor;
extern motor bRightMotor;

extern inertial iner;
extern rotation leftRot;
extern rotation rearRot;

extern motor flywheel;
extern motor intake;

extern digital_out leftWing;
extern digital_out rightWing;
extern digital_out intakePist;
extern digital_out AWPShoot;

extern bool leftWingToggle;
extern bool rightWingToggle;
extern bool intakePistToggle;
extern bool AWPShootToggle;

extern void ButtonL2_Callback();
extern void ButtonR2_Callback();
extern void ButtonX_Callback();
extern void ButtonA_Callback();
// VEXcode devices

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
