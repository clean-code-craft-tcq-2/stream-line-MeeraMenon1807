#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "../test/catch.hpp"
#include "receiver.h"

TEST_CASE(" Find the maximum value with latest streaming data")
{
   int OldMaxValue = 23;
   int CurrentSample = 34;
   REQUIRE(FindMAXValueWithCurrentSample(OldMaxValue,CurrentSample) == 34);
     
   OldMaxValue = 34;
   CurrentSample = 12;
   REQUIRE(FindMAXValueWithCurrentSample(OldMaxValue,CurrentSample) == 34);
}
 
TEST_CASE("Find the minimum value with latest streaming data")
{
    int OldMinValue = 23;
    int CurrentSample = 34;
   REQUIRE(FindMinValueWithCurrentSample(OldMinValue,CurrentSample) == 23);
  
  OldMinValue = 34;
  CurrentSample = 12;
  REQUIRE(FindMinValueWithCurrentSample(OldMinValue,CurrentSample) == 12);
}

TEST_CASE("Find Moving average with latest streaming data")
{
  int TemperatureDatastream[10] = {1,2,3,4,5,6,7,8,9,10};
  float expectedMovingAvg[10] = {1.0,1.5,2.0,2.5,3.0,4.0,5.0,6.0,7.0,8.0};
  float simplemovingAvg;
  int sampleIndex;
  for(sampleIndex =0;sampleIndex<10;sampleIndex++)
   {
       simplemovingAvg = findMovingAvgOfLastFiveSamples(TemperatureDatastream, sampleIndex);
       REQUIRE(simplemovingAvg == expectedMovingAvg[sampleIndex]);
   }
   
}


TEST_CASE("Test printStatisticOnConsole")
{
  struct batteryParameters DummyStateOFCharge, DummyTemperature;
  std::cout<<"***************************test case data************************** \n";
   REQUIRE(printStatisticOnConsole(DummyStateOFCharge,DummyTemperature) == true);
}

TEST_CASE("Get streaming data and compute statistics")
{
   int SOCDatastream[NUMBEROFSAMPLE];
   int TemperatureDatastream[NUMBEROFSAMPLE];
   
   std::cout<<"***************************Actual statdata************************** \n";
   REQUIRE(ReadStreamingDataAndComputeStatistics(SOCDatastream,TemperatureDatastream)== true);
   for(int index=0;index<NUMBEROFSAMPLE;index++)
   {
   std::cout<<"***************************Test case data************************** \n";
   std::cout<<TemperatureDatastream[index]<<"  "<<SOCDatastream[index]<<"\n";  
   REQUIRE(SOCDatastream[index]>=MIN_SOC  && SOCDatastream[index]<=MAX_SOC);
   REQUIRE(TemperatureDatastream[index]>=MIN_TEMPERATURE  && TemperatureDatastream[index] <= MAX_TEMPERATURE);
   }
}
