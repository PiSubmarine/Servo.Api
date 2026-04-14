#pragma once

namespace PiSubmarine::Servo
{
    enum class Error
    {
        TargetAngleOutOfRange,
        HardwareUnavailable,
        CommunicationFailure,
        Timeout
    };
}
