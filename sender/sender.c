#include "sender.h"

int getRandomIntegerInRange(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

int *setArrayWithValuesInRange(int lower, int upper, int arraySize, int *arr)
{
    srand(time(0));
    for (int i = 0; i < arraySize; i++)
    {
        arr[i] = getRandomIntegerInRange(lower, upper);
    }
    return arr;
}

void printToConsole(char *fieldName, int *values, int size)
{
    printf("%s: ", fieldName);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", values[i]);
    }
    printf("\n");
}

void generateAndPrintDataToConsole()
{
    int *temperatureArray = (int *)malloc(DATA_SIZE * sizeof(int));
    setArrayWithValuesInRange(MIN_TEMPERATURE, MAX_TEMPERATURE, DATA_SIZE, temperatureArray);

    int *socArray = (int *)malloc(DATA_SIZE * sizeof(int));
    setArrayWithValuesInRange(MIN_SOC, MAX_SOC, DATA_SIZE, socArray);

    printToConsole((char *)"temperature", temperatureArray, DATA_SIZE);
    printToConsole((char *)"soc", socArray, DATA_SIZE);

    free(temperatureArray);
    free(socArray);
}


