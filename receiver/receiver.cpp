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
    
    StateOFCharge.MaxValue = SOCDatastream[0];
    StateOFCharge.MinValue = SOCDatastream[0];
    Temperature.MaxValue = TemperatureDatastream[0];
    Temperature.MinValue = TemperatureDatastream[0];
    
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




