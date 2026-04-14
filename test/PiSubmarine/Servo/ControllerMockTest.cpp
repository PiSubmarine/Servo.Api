#include <expected>

#include <gtest/gtest.h>

#include "PiSubmarine/Servo/ControllerMock.h"

namespace PiSubmarine::Servo
{
    TEST(ControllerMockTest, SetTargetAngleReturnsConfiguredSuccess)
    {
        ControllerMock controllerMock;
        constexpr auto targetAngle = PiSubmarine::Radians(1.0);

        EXPECT_CALL(controllerMock, SetTargetAngle(targetAngle))
            .WillOnce(testing::Return(std::expected<void, Error>{}));

        const auto result = controllerMock.SetTargetAngle(targetAngle);

        EXPECT_TRUE(result.has_value());
    }
}
