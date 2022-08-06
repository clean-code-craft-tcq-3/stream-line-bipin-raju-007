#include "Receiver.h"

void readDataFromConsole(int* batteryCharge, int* batteryTemperature)
{
  for(int index = 0; index < 50; index++)
  {
    scanf("%d, %d",&batteryCharge[index], &batteryTemperature[index]);
  }
}

bool checkAvgWithinRange(float *movingAvg, float limit)
{
    if(movingAvg < limit)
    {
      return true;
    }
  return false;
}

float calculateSimpleMovingAverage(int *sensorparameter)
{
  float SMAvalue = 0.0;
  float total = 0.0;
  for(int index = (readings_count-5); index < readings_count; index++)
  {
    total += sensorparameter[index];
  }
  SMAvalue = total/5.0; 
  return SMAvalue;
}

void printRxDataAndAvgToConsole(int *RxData, float SMA)
{
  printf("Data received from sender\n");
  for(int index = 0; index < 50; index++)
  {
    printf("%d\n",RxData[index]);
  }
  printf("SimpleMovingAverage of last 5 values: %f\n",SMA);  
}

bool receiveAndProcessSensorData(int* batteryCharge, int* batteryTemperature)
{
  float movingAvgBatChr, movingAvgBatTemp;
  readDataFromConsole(batteryCharge,batteryTemperature);
  movingAvgBatChr = calculateSimpleMovingAverage(batteryCharge);
  movingAvgBatTemp = calculateSimpleMovingAverage(batteryTemperature);
  printRxDataAndAvgToConsole(batteryCharge, movingAvgBatChr);
  printRxDataAndAvgToConsole(batteryTemperature, movingAvgBatTemp);
  isChargeInRange = checkAvgWithinRange(movingAvgBatChr, chargeLimit);
  isTempInRange = checkAvgWithinRange(movingAvgBatTemp, tempLimit);
  if(isChargeInRange && isTempInRange)
  {
    return true;
  }
  return false;
}
