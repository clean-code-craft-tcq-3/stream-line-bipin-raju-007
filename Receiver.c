#include "Receiver.h"

void readDataFromConsole(int* batteryCharge, int* batteryTemperature)
{
  for(int index = 0; index < 50; index++)
  {
    scanf("%d, %d\n",&batteryCharge[index], &batteryTemperature[index]);
  }
}

bool checkAvgWithinRange(float movingAvg, float limit)
{
    if(movingAvg < limit)
    {
      return true;
    }
  return false;
}

void maxAndMinValue(int *sensorparameter, int *max, int *min)
{
  for(int index = 0; index < 50; index++)
  {
    if(sensorparameter[index] > *max)
    {
      *max = sensorparameter[index];
    }
    if(sensorparameter[index] < *min)
    {
      *min = sensorparameter[index];
    }
  }
}

float calculateSimpleMovingAverage(int *sensorparameter)
{
  float SMAvalue = 0.0;
  float total = 0.0;
  for(int index = 45; index < 50; index++)
  {
    total += sensorparameter[index];
  }
  SMAvalue = total/5.0; 
  return SMAvalue;
}

void printRxDataAndAvgToConsole(int *RxData, float SMA, int maxVal, int minVal, sensorParam Value)
{
    if(BATCHARGE == sensorParam)
    {
        printf("Battery charge received from sender\n");
    }
    else
    {
        printf("Battery Temperature received from sender\n");
    }
    for(int index = 0; index < 50; index++)
    {
        printf("%d\n",RxData[index]);
    }
  printf("Max Value : %d\n",maxVal);  
  printf("Min Value: %d\n",minVal);  
  printf("SimpleMovingAverage of last 5 values: %f\n",SMA);  
}

bool receiveAndProcessSensorData(int* batteryCharge, int* batteryTemperature, float chargeLimit, float tempLimit)
{
  float movingAvgBatChr, movingAvgBatTemp;
  bool isChargeInRange, isTempInRange;
  readDataFromConsole(batteryCharge,batteryTemperature);
  int maxBatChrgVal = batteryCharge[0], minBatChrgVal = batteryCharge[0];
  int maxBatTempVal = batteryTemperature[0], minBatTempVal = batteryTemperature[0];
  maxAndMinValue(batteryCharge, &maxBatChrgVal, &minBatChrgVal);
  maxAndMinValue(batteryTemperature, &maxBatTempVal, &maxBatTempVal);
  movingAvgBatChr = calculateSimpleMovingAverage(batteryCharge);
  movingAvgBatTemp = calculateSimpleMovingAverage(batteryTemperature);
  printRxDataAndAvgToConsole(batteryCharge, movingAvgBatChr, maxBatChrgVal, minBatChrgVal, BATCHARGE);
  printRxDataAndAvgToConsole(batteryTemperature, movingAvgBatTemp, maxBatTempVal, minBatTempVal, BATTEMP);
  isChargeInRange = checkAvgWithinRange(movingAvgBatChr, chargeLimit);
  isTempInRange = checkAvgWithinRange(movingAvgBatTemp, tempLimit);
  if(isChargeInRange && isTempInRange)
  {
    return true;
  }
  return false;
}



  
