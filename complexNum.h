//
// Created by Grisha on 18.02.2021.
//
#pragma once

#include "stdlib.h"
#include "string.h"
#include "stdio.h"

typedef struct complex {
    float realPart;
    float complexPart;

    size_t size;
} complex;

complex *newComplex(float realPart, float complexPart);

void* complexAdd(void *num1, void *num2, void *res);
void* complexSub(void *num1, void *num2, void *res);
void* complexMult(void *num1, void *num2, void *res);

void complexPrint(void *num);
int complexIsSame(void *num1, void *num2);