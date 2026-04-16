#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Servo/IController.h"

namespace PiSubmarine::Servo
{
    class IControllerMock : public IController
    {
    public:
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), SetTargetAngle, (PiSubmarine::Radians angle), (override));
        MOCK_METHOD(PiSubmarine::Radians, GetTargetAngle, (), (const, override));
        MOCK_METHOD(PiSubmarine::AngularSector, GetAllowedTargetAngleSector, (), (const, override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), SetEnabled, (bool isEnabled), (override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<bool>), IsEnabled, (), (const, override));
    };
}
