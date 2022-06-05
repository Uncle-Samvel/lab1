//
// Created by Grisha on 20.02.2021.
//
#pragma once

#include "myVector.h"

myVector *getVector();

void printMenu();

void writeVector(myVector ***arr, int *len, struct myVector **vec);

void printArrVector(myVector ***arr, int len);

void removeArr(myVector ***arr, int *len);

void operationWithVector(myVector **arr, int len, myVector **res);