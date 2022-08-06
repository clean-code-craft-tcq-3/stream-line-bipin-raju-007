#include "stdio.h"
#include "stdbool.h"

void readDataFromConsole(int* batteryCharge, int* batteryTemperature);
bool checkAvgWithinRange(float *movingAvg, float limit);
float calculateSimpleMovingAverage(int *sensorparameter);
void printRxDataAndAvgToConsole(int *RxData, float SMA);
bool receiveAndProcessSensorData(int* batteryCharge, int* batteryTemperature);
