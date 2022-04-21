#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NUMBEROFSAMPLE 50

struct batteryParameters
{
    int MaxValue=0;
    int MinValue =0;
    float MovingAVg=0;
};

int FindMAXValueWithCurrentSample(int OldMaxValue, int CurrentSample);
int FindMinValueWithCurrentSample(int OldMaxValue, int CurrentSample);
float findMovingAvgOfLastFiveSamples(int *dataSample, int sampleIndex);
bool printStatisticOnConsole(batteryParameters SOC,batteryParameters Temperature);
