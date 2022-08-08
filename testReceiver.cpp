#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "Receiver.h"

TEST_CASE("Test to check whether sensor data parameters are in Range") 
{
  int batteryCharge[50] = {0};
  int batteryTemperature[50] = {0};
  float chargeLimit = 99.0, tempLimit = 50.0;
  bool isParametersInRange;
  isParametersInRange = receiveAndProcessSensorData(&batteryCharge[0],&batteryTemperature[0], chargeLimit, tempLimit);
  REQUIRE(isParametersInRange == 1);
}
