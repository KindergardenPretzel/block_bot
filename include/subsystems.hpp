#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// intake
inline pros::Motor motor_intake(-10, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
inline pros::ADIDigitalOut loader (1, LOW);
inline pros::ADIDigitalOut descoringMech (2, LOW);
inline pros::ADIDigitalOut flipper (3, LOW);

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

inline void loader_toggle()
{
  static bool load_toggle = false;
  if(!load_toggle){
   loader.set_value(HIGH);
   
   load_toggle = true;
  }
  else{
    loader.set_value(LOW);
    load_toggle = false;
  }
}

inline void flipper_toggle()
{
  static bool flip_toggle = false;
  if(!flip_toggle){
   flipper.set_value(HIGH);
   
   flip_toggle = true;
  }
  else{
    flipper.set_value(LOW);
    flip_toggle = false;
  }
}

// Lift Subsytem
inline pros::Motor motor_lift(-12, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);
inline pros::Rotation lift_encoder(13);

inline void set_lift(int input) {
  motor_lift.move(input);
}

inline ez::PID liftPID{9, 0.2, 0, 6, "LiftPID"};

inline void lift_wait() {
  while (liftPID.exit_condition({motor_lift}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}
inline bool lift_toggled = false;

inline void descore_on()
{
   descoringMech.set_value(HIGH);
   liftPID.target_set(68);
   lift_toggled = true;
}