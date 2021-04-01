// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

/**
 * This is a demo program showing how to use Mecanum control with the
 * MecanumDrive class.
 */
void Robot2498::RobotInit()
{
  // Invert the left side motors. You may need to change or remove this to
  // match your robot.

  // TODO: Verify which motors are inverted on the robot
  frontLeft_.SetInverted(true);
  rearLeft_.SetInverted(true);
}

void Robot2498::TeleopPeriodic()
{
  /* Use the joystick X axis for lateral movement, Y axis for forward
     * movement, and Z axis for rotation.
     */
  double gyroAngle = pigeonIMU_.GetAbsoluteCompassHeading();
  robotDrive_.DriveCartesian(throttle_.GetY(), stick_.GetY(), stick_.GetZ(), gyroAngle);
  
}