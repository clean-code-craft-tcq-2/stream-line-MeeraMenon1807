#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
  for(i=0;i<49;i++)
  {
    printf("%d ",temperatureDataStream[i] );
  }
 for(i=0;i<49;i++)
  {
    printf("%d ",temperatureDataStream1[i] );
  }
 
  return 0;
}
