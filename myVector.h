//
// Created by Grisha on 19.02.2021.
//
#pragma once

#include "stdMath.h"
#include "stdlib.h"

typedef struct myVector {
    struct operation* operation;

    void *x, *y, *z;

    size_t element_size;
    size_t myVectorSize;

    struct myVector* (*add) (struct myVector *v1, struct myVector *v2);
    void* (*scalarMult) (struct myVector *v1, struct myVector *v2);
    struct myVector* (*mult) (struct myVector *v1, struct myVector *v2);

    int (*isSame) (struct myVector *v1,  struct myVector *v2);

    void (*print)(struct myVector *v);
    void (*remove)(struct myVector *v);
} myVector;

myVector *newVector(void *x, void *y, void *z, size_t element_size, const struct operation *op);
int checkType(struct myVector *v1, struct myVector *v2);

myVector *vectorAdd(myVector *v1, myVector *v2);
void *vectorScalarMult(myVector *v1, myVector *v2);
myVector *vectorMult(myVector *v1, myVector *v2);

int vectorIsSame(myVector *v1, myVector *v2);

void printVector(myVector *v);
void removeMyVector(myVector *);