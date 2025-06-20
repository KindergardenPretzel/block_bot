#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;
// Your motors, sensors, etc. should go here.  Below are examples
inline pros::Motor motor_intake(-11, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
inline pros::Motor motor_lift(12, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);
inline pros::Rotation lift_encoder(13);

void set_lift(int input) {
  motor_lift.move(input);
}

inline ez::PID liftPID{0.45, 0, 0, 0, "Lift"};
// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');