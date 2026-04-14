#pragma once

#include <expected>

#include "PiSubmarine/AngularSector.h"
#include "PiSubmarine/Radians.h"
#include "PiSubmarine/Servo/Error.h"

namespace PiSubmarine::Servo
{
    class IController
    {
    public:
        virtual ~IController() = default;

        [[nodiscard]] virtual std::expected<void, Error> SetTargetAngle(Radians angle) = 0;
        [[nodiscard]] virtual Radians GetTargetAngle() const = 0;
        [[nodiscard]] virtual AngularSector GetAllowedTargetAngleSector() const = 0;
        [[nodiscard]] virtual std::expected<void, Error> SetEnabled(bool isEnabled) = 0;
        [[nodiscard]] virtual bool IsEnabled() const = 0;
    };
}
