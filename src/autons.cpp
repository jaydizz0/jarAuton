#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
  flywheel.setBrake(coast);
}

void soloAWP() {
  //shoot preload
  /*AWPShoot.set(true);
  wait(200, msec);
  AWPShoot.set(false);*/

  //get matchload out
  chassis.turn_to_angle(65, 8, 1, 500, 1000);
  chassis.drive_distance(14, 65, 12, 12, 1, 750, 750);
  leftWing.set(true);
  wait(300, msec);
  chassis.turn_to_angle(10, 8, 1, 500, 1000);
  leftWing.set(false);

  //move to line up with middle triball
  intakePist.set(true);
  intake.spin(fwd, 12000, volt);
  chassis.turn_to_angle(150, 8, 1, 500, 1000);
  chassis.drive_distance(30, 150, 12, 12, 1, 1000, 750);
  chassis.drive_distance(15, 140, 12, 12, 1, 1000, 750);
  wait(210, msec);
  leftWing.set(true);
  rightWing.set(true);

  //push triballs over barrier
  chassis.turn_to_angle(213, 8, 1, 500, 1000);
  intake.spin(reverse, 12000, volt);
  intakePist.set(false);
  chassis.drive_distance(18, 213, 12, 12, 1, 750, 750);
  leftWing.set(false);

  //go touch elevation var
  chassis.right_swing_to_angle(145, 8, 1, 500, 1000, .3, .001, 2, 15);
  chassis.drive_distance(-65, 145, 12, 12, 1, 1500, 1500);
  chassis.turn_to_angle(38, 8, 1, 500, 1000);
  chassis.drive_distance(-34, 38, 12, 12, 1, 1000, 1000);
  //put flywheel piston up
}

void solo_AWP_short() {
  //shoot preload
  /*AWPShoot.set(true);
  wait(200, msec);
  AWPShoot.set(false);*/

  //get matchload out
  chassis.turn_to_angle(65, 8, 1, 500, 1000);
  chassis.drive_distance(14, 65, 12, 12, 1, 750, 750);
  leftWing.set(true);
  wait(300, msec);
  chassis.turn_to_angle(10, 8, 1, 500, 1000);
  leftWing.set(false);

  chassis.turn_to_angle(65, 8, 1, 500, 1000);
  chassis.drive_distance(-13, 65, 12, 12, 1, 750, 750);

  //touch elevation bar
  chassis.drive_distance(-29, 38, 12, 12, 1, 1000, 1000);
  //put flywheel piston up
}

void skills() {
  //get to shooting angle
  chassis.turn_to_angle(-45, 8, 1, 500, 1000);
  chassis.drive_distance(-11, 30, 4, 4, 1, 1000, 1000);

  // flywheel.spin(fwd, 12000, volt);
  // wait(35, sec);
  // flywheel.stop();

  //go to middle
  chassis.drive_distance(55, 45, 12, 12, 1, 1500, 1500);
  rightWing.set(true);
  leftWing.set(true);
  chassis.turn_to_angle(0, 8, 1, 500, 1000);
  //chassis.drive_distance(10, 0, 12, 12, 1, 500, 500);

  //go over barrier
  chassis.drive_distance(-5, 0, 12, 12, 1, 500, 500);
  chassis.drive_distance(90, 0, 12, 12, 1, 2500, 3000);

  ////push in from right side
  rightWing.set(false);
  leftWing.set(false);
  chassis.drive_distance(-34, 0, 12, 12, 1, 1000, 1000);
  chassis.turn_to_angle(-90, 8, 1, 500, 1000);
  chassis.drive_distance(-34, -90, 12, 12, 1, 1000, 1000);
  chassis.set_heading(0);
  chassis.turn_to_angle(45, 8, 1, 500, 1000);
  rightWing.set(true);
  leftWing.set(true);
  chassis.drive_distance(40, 45, 12, 12, 1, 1000, 1000);
  chassis.turn_to_angle(90, 8, 1, 500, 1000);

  //push in from left side
  rightWing.set(false);
  leftWing.set(false);
  chassis.drive_distance(-29, 90, 12, 12, 1, 1000, 1000);
  chassis.turn_to_angle(180, 8, 1, 500, 1000);
  chassis.drive_distance(-28, 180, 12, 12, 1, 1000, 1000);
  chassis.set_heading(0);
  chassis.turn_to_angle(-55, 8, 1, 500, 750);
  rightWing.set(true);
  leftWing.set(true);
  chassis.drive_distance(35, -55, 12, 12, 1, 1000, 1000);
  rightWing.set(false);
  leftWing.set(false);

  //push on left side side
  chassis.drive_distance(-13, -55, 12, 12, 1, 1000, 750);
  chassis.turn_to_angle(-180, 8, 1, 500, 1000);
  chassis.drive_distance(13, -180, 12, 12, 1, 1000, 1000);
  chassis.set_heading(0);
  rightWing.set(true);
  chassis.left_swing_to_angle(150, 8, 1, 500, 1000, .3, .001, 2, 15);
  chassis.drive_distance(30, 160, 12, 12, 1, 1000, 1000);
  chassis.drive_distance(-15, 160, 12, 12, 1, 1000, 1000);
}

void right_side_six() {
  rightWing.set(true);
  intakePist.set(true);
  rightWing.set(false);
  wait(250, msec);
  intake.setVelocity(400, rpm);
  intake.spin(fwd);

  // score first 2 balls (3 secs)
  chassis.drive_distance(65, 1, 12, 12, 1, 1000, 1250); // intake first ball
  chassis.turn_to_angle(125, 8, 1, 500, 600); // turn to goal
  intakePist.set(false);
  intake.spin(reverse);
  leftWing.set(true);
  rightWing.set(true);
  chassis.drive_distance(32, 125, 12, 12, 1, 750, 750); // score both
  leftWing.set(false);
  rightWing.set(false);

  // move other triball next to matchload bar (4 secs)
  chassis.set_heading(0.0);
  chassis.turn_to_angle(148, 8, 1, 500, 600);
  intakePist.set(true);
  intake.spin(fwd);
  chassis.drive_distance(44, 150, 12, 12, 1, 1000, 1000);
  chassis.turn_to_angle(25, 8, 1, 500, 700);
  intake.spin(reverse, 12000, volt);
  intakePist.set(false);
  chassis.drive_distance(40, 30, 12, 12, 1, 1000, 1000);

  // grab ball under elevation bar (3 secs)
  intakePist.set(true);
  intake.spin(fwd);
  chassis.turn_to_angle(115, 8, 1, 500, 550);
  chassis.drive_distance(16, 135, 12, 12, 1, 500, 500);
  chassis.drive_distance(38, 180, 12, 12, 1, 750, 750);
  wait(210, msec);

  // push balls into goal (5 secs)
  chassis.drive_distance(-37, 175, 12, 12, 1, 750, 750);
  chassis.turn_to_angle(122, 8, 1, 500, 600);
  leftWing.set(true);
  chassis.drive_distance(-16, 122, 12, 12, 1, 750, 500);
  chassis.turn_to_angle(80, 8, 1, 500, 750);
  wait(200, msec);
  leftWing.set(false);
  wait(450, msec);
  intakePist.set(false);
  chassis.turn_to_angle(-60, 8, 1, 500, 750);
  intake.spin(reverse);
  chassis.drive_distance(22, -60, 12, 12, 1, 500, 400);
  chassis.drive_distance(-10, -15, 12, 12, 1, 500, 400);
  chassis.drive_distance(45, -70, 12, 12, 1, 500, 950);
  chassis.drive_distance(-25, -65, 12, 12, 1, 500, 400);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}