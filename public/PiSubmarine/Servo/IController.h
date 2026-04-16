#pragma once

#include "PiSubmarine/AngularSector.h"
#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Radians.h"

namespace PiSubmarine::Servo
{
    class IController
    {
    public:
        virtual ~IController() = default;

        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> SetTargetAngle(Radians angle) = 0;
        [[nodiscard]] virtual Radians GetTargetAngle() const = 0;
        [[nodiscard]] virtual AngularSector GetAllowedTargetAngleSector() const = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> SetEnabled(bool isEnabled) = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<bool> IsEnabled() const = 0;
    };
}
