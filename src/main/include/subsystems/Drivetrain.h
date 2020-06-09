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

	rev::CANSparkMax m_motor1WheelEncoder{m_motor1Wheel};
	rev::CANSparkMax m_motor1SpinEncoder {m_motor1Spin};
	rev::CANSparkMax m_motor2WheelEncoder{m_motor2Wheel};
	rev::CANSparkMax m_motor2SpinEncoder {m_motor2Spin};
	rev::CANSparkMax m_motor3WheelEncoder{m_motor3Wheel};
	rev::CANSparkMax m_motor3SpinEncoder {m_motor3Spin};
public:
};

