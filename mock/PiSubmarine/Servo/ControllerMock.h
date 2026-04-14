#pragma once

#include <expected>

#include <gmock/gmock.h>

#include "PiSubmarine/Servo/IController.h"

namespace PiSubmarine::Servo
{
    class ControllerMock : public IController
    {
    public:
        MOCK_METHOD((std::expected<void, Error>), SetTargetAngle, (PiSubmarine::Radians angle), (override));
        MOCK_METHOD(PiSubmarine::Radians, GetTargetAngle, (), (const, override));
        MOCK_METHOD(PiSubmarine::AngularSector, GetAllowedTargetAngleSector, (), (const, override));
    };
}
