#pragma once

#include <rev/CANSparkMax.h>

class Drivetrain
{
private:
	rev::CANSparkMax m_motor1Wheel{0, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
	rev::CANSparkMax m_motor1Spin {1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
	rev::CANSparkMax m_motor2Wheel{2, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
	rev::CANSparkMax m_motor2Spin {3, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
	rev::CANSparkMax m_motor3Wheel{4, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
	rev::CANSparkMax m_motor3Spin {5, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
public:
};

