#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MIN_TEMPERATURE = 0;
const int MAX_TEMPERATURE = 45;
const int MIN_SOC = 20;
const int MAX_SOC = 80;
const int DATA_SIZE = 50;

int getRandomIntegerInRange(int lower, int upper);

int *setArrayWithValuesInRange(int lower, int upper, int arraySize, int *arr);

void printToConsole(char *fieldName, int *values, int size);

void generateAndPrintDataToConsole();
