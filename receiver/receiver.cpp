#include "receiver.h"


int FindMAXValueWithCurrentSample(int OldMaxValue, int CurrentSample)
{
    return (OldMaxValue>=CurrentSample) ? OldMaxValue: CurrentSample;
}

int FindMinValueWithCurrentSample(int OldMaxValue, int CurrentSample)
{
    return (OldMaxValue<=CurrentSample) ? OldMaxValue: CurrentSample;
}

float findMovingAvgOfLastFiveSamples(int *dataSample, int sampleIndex)
{
    int loopCntr;
    int Sum=0;
    float Avg=0.0;
    if(sampleIndex<5)
    {
        for(loopCntr=0;loopCntr<=sampleIndex;loopCntr++)
        {
            
            Sum = Sum+dataSample[loopCntr];
            
        }
        Avg = Sum/(float)(sampleIndex+1);
    }
    else
    {
        Sum = dataSample[sampleIndex]+dataSample[sampleIndex-1]+dataSample[sampleIndex-2]+dataSample[sampleIndex-3]+dataSample[sampleIndex-4];
        Avg= (float)Sum/5;
    }
    return Avg;
}


bool printStatisticOnConsole(batteryParameters SOC,batteryParameters Temperature)
{
    bool retVal;
    cout<<"Maximum SOC:"<<SOC.MaxValue<<",Minimum SOC:"<<SOC.MinValue<<",Simple moving average of SOC:"<<SOC.MovingAVg<<"\n";
    cout<<"Maximum Temperature:"<<Temperature.MaxValue<<",Minimum Temperature:"<<Temperature.MinValue<<",Simple moving average of Temperature:"<<Temperature.MovingAVg<<"\n";
     retVal= true;
    return retVal;
}






/*
#define STREAM_LENGTH 50

void getSingleStreamOfValues(int dataStream[])
{
    int idx;
    scanf("%*s", &dataStream); // Skip parameter string at beginning of stream
    for (idx = 0; idx < STREAM_LENGTH; idx++)
    {
        scanf("%i", &dataStream[idx]);
    }
}


int main()
{
  int temperatureDataStream[STREAM_LENGTH];
   int temperatureDataStream1[STREAM_LENGTH];
  int i;
  getSingleStreamOfValues(&temperatureDataStream[0]);
   getSingleStreamOfValues(&temperatureDataStream1[0]);
  for(i=0;i<STREAM_LENGTH;i++)
  {
    printf("%d ",temperatureDataStream[i] );
  }
 for(i=0;i<STREAM_LENGTH;i++)
  {
    printf("%d ",temperatureDataStream1[i] );
  }
 
  return 0;
}
*/
