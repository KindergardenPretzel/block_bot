#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// intake
inline pros::Motor motor_intake(-20, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);

inline void intake_spin(int speed)
{
  static bool intake_toggle = false;
  if(!intake_toggle){
   motor_intake.move(speed);
   intake_toggle = true;
  }
  else{
    motor_intake.move(0);
    intake_toggle = false;
  }
}

// Lift Subsytem
inline pros::Motor motor_lift(-12, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);
inline pros::Rotation lift_encoder(13);

inline void set_lift(int input) {
  motor_lift.move(input);
}

inline ez::PID liftPID{8, 0.2, 0, 4, "LiftPID"};

inline void lift_wait() {
  while (liftPID.exit_condition({motor_lift}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}
inline bool lift_toggled = false;


