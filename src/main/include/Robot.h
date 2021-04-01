#pragma once
#include "Constants.h"
#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/drive/MecanumDrive.h>
#include <rev/CANSparkMax.h>
#include <ctre/phoenix/sensors/PigeonIMU.h>

class Robot2498 : public frc::TimedRobot
{
public:
    // override is used to override the TimedRobot classes' virtual function
    void RobotInit() override;
    void TeleopPeriodic() override;

private:
    // Intializes all the spark max motor controllers
    // using the values in Constants.h
    rev::CANSparkMax frontLeft_{kFrontLeftChannel, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax rearLeft_{kRearLeftChannel, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax frontRight_{kFrontRightChannel, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax rearRight_{kRearRightChannel, rev::CANSparkMax::MotorType::kBrushless};

    // Initializing the Mecanum Drive Class
    frc::MecanumDrive robotDrive_{frontLeft_, rearLeft_, frontRight_, rearRight_};

    // Intializing Joysticks
    frc::Joystick stick_{kJoystickStickChannel};
    frc::Joystick throttle_{kJoystickThrottleChannel};

    // Initializing Pigeon Sensor
    ctre::phoenix::sensors::PigeonIMU pigeonIMU_{kPigeonIMUChannel};
};

#ifndef RUNNING_FRC_TESTS
int main()
{
    return frc::StartRobot<Robot2498>();
}
#endif
