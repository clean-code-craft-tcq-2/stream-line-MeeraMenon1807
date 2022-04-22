#include "receiver.h"


void getStreamingData(int *dataSample)
{
    int sampleIndex;
    char fieldname[20];
    scanf("%s", fieldname); 
    for (sampleIndex = 0; sampleIndex < NUMBEROFSAMPLE; sampleIndex++)
    {
        scanf("%i", &dataSample[sampleIndex]);
    }
 
}


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
    std::cout<<"Maximum SOC:"<<SOC.MaxValue<<",Minimum SOC:"<<SOC.MinValue<<",Simple moving average of SOC:"<<SOC.MovingAVg<<"\n";
    std::cout<<"Maximum Temperature:"<<Temperature.MaxValue<<",Minimum Temperature:"<<Temperature.MinValue<<",Simple moving average of Temperature:"<<Temperature.MovingAVg<<"\n";
     retVal= true;
    return retVal;
}


bool ReadStreamingDataAndComputeStatistics(int *SOCDatastream, int *TemperatureDatastream )
{
    int sampleIndex;
    bool retVal;
    struct batteryParameters StateOFCharge, Temperature;
    //Read data from console at once. could not find a way to read it line by line. SOC data is available only after reading all temperarure data
    
    getStreamingData(TemperatureDatastream);
    getStreamingData(SOCDatastream);
    
    
     for(sampleIndex=0;sampleIndex<NUMBEROFSAMPLE;sampleIndex++)
  {
    StateOFCharge.MaxValue = FindMAXValueWithCurrentSample(StateOFCharge.MaxValue,SOCDatastream[sampleIndex] );
    Temperature.MaxValue = FindMAXValueWithCurrentSample(Temperature.MaxValue,TemperatureDatastream[sampleIndex] );
    StateOFCharge.MinValue = FindMinValueWithCurrentSample(StateOFCharge.MinValue,SOCDatastream[sampleIndex] );
    Temperature.MinValue = FindMinValueWithCurrentSample(Temperature.MinValue,TemperatureDatastream[sampleIndex] );
    StateOFCharge.MovingAVg = findMovingAvgOfLastFiveSamples(SOCDatastream,sampleIndex);
    Temperature.MovingAVg = findMovingAvgOfLastFiveSamples(TemperatureDatastream,sampleIndex);
     retVal = printStatisticOnConsole(StateOFCharge,Temperature); 
  }
  
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
