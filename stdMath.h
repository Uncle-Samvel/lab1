//
// Created by Grisha on 18.02.2021.
//
#pragma once

#include "complexNum.h"
#include "stdio.h"

struct operation {
    char *type;
    void* (*add) (void *, void *, void *);
    void* (*sub) (void *, void *, void *);
    void* (*mult)(void *, void *, void *);
    int (*isSame) (void *, void *);
    void (*print)(void *);
};


#define DeclarateStdMath(TYPE) \
                                 \
void* TYPE##Add(void *num1, void *num2, void *res); \
                                 \
void* TYPE##Sub(void *num1, void *num2, void *res); \
                                 \
void* TYPE##Mult(void *num1, void *num2, void *res); \
                                 \


#define DeclarateOperation(TYPE) \
                                 \
const struct operation TYPE##Operation;\

#define DeclarateMyPrint(TYPE) \
 \
void TYPE##Print(void *num);   \


#define DeclarateAll(TYPE) \
DeclarateOperation(TYPE)   \
DeclarateStdMath(TYPE)     \
DeclarateMyPrint(TYPE)     \

DeclarateAll(int)
DeclarateAll(float)
DeclarateAll(double)

DeclarateOperation(complex)