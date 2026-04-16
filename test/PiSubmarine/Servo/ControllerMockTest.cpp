#include <gtest/gtest.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Servo/IControllerMock.h"

namespace PiSubmarine::Servo
{
    TEST(ControllerMockTest, SetTargetAngleReturnsConfiguredSuccess)
    {
        IControllerMock controllerMock;
        constexpr auto targetAngle = PiSubmarine::Radians(1.0);

        EXPECT_CALL(controllerMock, SetTargetAngle(targetAngle))
            .WillOnce(testing::Return(PiSubmarine::Error::Api::Result<void>{}));

        const auto result = controllerMock.SetTargetAngle(targetAngle);

        EXPECT_TRUE(result.has_value());
    }

    TEST(ControllerMockTest, SetEnabledReturnsConfiguredSuccess)
    {
        IControllerMock controllerMock;

        EXPECT_CALL(controllerMock, SetEnabled(false))
            .WillOnce(testing::Return(PiSubmarine::Error::Api::Result<void>{}));

        const auto result = controllerMock.SetEnabled(false);

        EXPECT_TRUE(result.has_value());
    }

    TEST(ControllerMockTest, GetTargetAngleMayStillReturnLastTargetWhileDisabled)
    {
        IControllerMock controllerMock;
        constexpr auto lastTargetAngle = PiSubmarine::Radians(1.0);

        EXPECT_CALL(controllerMock, IsEnabled())
            .WillOnce(testing::Return(PiSubmarine::Error::Api::Result<bool>(false)));
        EXPECT_CALL(controllerMock, GetTargetAngle())
            .WillOnce(testing::Return(lastTargetAngle));

        const auto isEnabled = controllerMock.IsEnabled();
        ASSERT_TRUE(isEnabled.has_value());
        EXPECT_FALSE(isEnabled.value());
        EXPECT_EQ(controllerMock.GetTargetAngle(), lastTargetAngle);
    }
}
