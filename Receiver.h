#include "stdio.h"
#include "stdbool.h"

void readDataFromConsole(int* batteryCharge, int* batteryTemperature);
void maxAndMinValue(int *sensorparameter, int *max, int *min);
bool checkAvgWithinRange(float movingAvg, float limit);
float calculateSimpleMovingAverage(int *sensorparameter);
void printRxDataAndAvgToConsole(int *RxData, float SMA, int maxVal, int minVal);
bool receiveAndProcessSensorData(int* batteryCharge, int* batteryTemperature, float chargeLimit, float tempLimit);
