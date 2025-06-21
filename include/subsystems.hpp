#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;
// Your motors, sensors, etc. should go here.  Below are examples
inline pros::Motor motor_intake(-11, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
inline pros::Motor motor_lift(-12, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);
inline pros::Rotation lift_encoder(13);

inline void set_lift(int input) {
  motor_lift.move(input);
}

inline ez::PID liftPID{15, 0, 0, 0, "LiftPID"};
//inline ez::PID liftPID{3.8, 0, 15, 0, "LiftPID"};
//inline ez::PID liftPID{1.8, 0, 15, 0, "LiftPID"};
//inline ez::PID liftPID{1.11, 0, 0.9, 0, "LiftPID"};

inline void lift_wait() {
  while (liftPID.exit_condition({motor_lift}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}
inline bool lift_toggled = false;

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

