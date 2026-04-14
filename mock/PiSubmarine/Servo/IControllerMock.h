#pragma once

#include <expected>

#include <gmock/gmock.h>

#include "PiSubmarine/Servo/IController.h"

namespace PiSubmarine::Servo
{
    class IControllerMock : public IController
    {
    public:
        MOCK_METHOD((std::expected<void, Error>), SetTargetAngle, (PiSubmarine::Radians angle), (override));
        MOCK_METHOD(PiSubmarine::Radians, GetTargetAngle, (), (const, override));
        MOCK_METHOD(PiSubmarine::AngularSector, GetAllowedTargetAngleSector, (), (const, override));
        MOCK_METHOD((std::expected<void, Error>), SetEnabled, (bool isEnabled), (override));
        MOCK_METHOD(bool, IsEnabled, (), (const, override));
    };
}
