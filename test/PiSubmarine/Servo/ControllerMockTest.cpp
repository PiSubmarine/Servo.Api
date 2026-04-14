#include <expected>

#include <gtest/gtest.h>

#include "PiSubmarine/Servo/IControllerMock.h"

namespace PiSubmarine::Servo
{
    TEST(ControllerMockTest, SetTargetAngleReturnsConfiguredSuccess)
    {
        IControllerMock controllerMock;
        constexpr auto targetAngle = PiSubmarine::Radians(1.0);

        EXPECT_CALL(controllerMock, SetTargetAngle(targetAngle))
            .WillOnce(testing::Return(std::expected<void, Error>{}));

        const auto result = controllerMock.SetTargetAngle(targetAngle);

        EXPECT_TRUE(result.has_value());
    }

    TEST(ControllerMockTest, SetEnabledReturnsConfiguredSuccess)
    {
        IControllerMock controllerMock;

        EXPECT_CALL(controllerMock, SetEnabled(false))
            .WillOnce(testing::Return(std::expected<void, Error>{}));

        const auto result = controllerMock.SetEnabled(false);

        EXPECT_TRUE(result.has_value());
    }

    TEST(ControllerMockTest, GetTargetAngleMayStillReturnLastTargetWhileDisabled)
    {
        IControllerMock controllerMock;
        constexpr auto lastTargetAngle = PiSubmarine::Radians(1.0);

        EXPECT_CALL(controllerMock, IsEnabled())
            .WillOnce(testing::Return(false));
        EXPECT_CALL(controllerMock, GetTargetAngle())
            .WillOnce(testing::Return(lastTargetAngle));

        EXPECT_FALSE(controllerMock.IsEnabled());
        EXPECT_EQ(controllerMock.GetTargetAngle(), lastTargetAngle);
    }
}
