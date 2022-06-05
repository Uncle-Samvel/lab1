//
// Created by Grisha on 26.02.2021.
//

#include "tests.h"


void tests() {
    srand(0);
    int testCount = 10000000;
    intTest(testCount);
    floatTest(testCount);
    doubleTest(testCount);
    complexTest(testCount);
}

int testCheckVec(void *x, void *y, void *z, myVector *v) {
    myVector *res = newVector(x, y, z, v->element_size, v->operation);
    int k = v->isSame(v, res);
    free(res);
    return k;
}

float fRand() {
    return (float)(rand() + 1./rand());
}

double dRand() {
    return (double)(rand() + 1./rand());
}

complex compRand() {
    complex comp = {fRand(), fRand(), sizeof(complex)};
    return comp;
}

void intTest(int testCount) {
    printf("Проверка целочисленных векторов...\n");
    //TODO вручную написать 3-4 примера рассчётов векторов
    printf("Проверка на случайных числах...\n");
    int i;
    for (i = 0; i < testCount; i++) {
        int x1 = rand(), y1 = rand(), z1 = rand(),
            x2 = rand(), y2 = rand(), z2 = rand(),
            x, y, z;
        int k;

        myVector *v1 = newVector(&x1, &y1, &z1, sizeof(int), &intOperation);
        myVector *v2 = newVector(&x2, &y2, &z2, sizeof(int), &intOperation);
        
        myVector *vAdd = v1->add(v1, v2);
        int *vScalar = (int*) v1->scalarMult(v1, v2);
        myVector *vMult = v1->mult(v1, v2);

        x = x1 + x2, y = y1 + y2, z = z1 + z2;
        k = testCheckVec(&x, &y, &z, vAdd);

        x = x1 * x2, y = y1 * y2, z = z1 * z2;
        k = k && (*vScalar == x + y + z);

        x = y1 * z2 - y2 * z1, y = z1 * x2 - z2 * x1, z = x1 * y2 - x2 * y1;
        k = k && testCheckVec(&x, &y, &z, vMult);

        if (!k) break;

        free(v1);
        free(v2);
        free(vScalar);
        vAdd->remove(vAdd);
        vMult->remove(vMult);
    }
    printf("Проверка на %d случайных числах ", testCount);
    if (i == testCount) {
        printf("пройдена!\n");
    }
    else {
        printf("не пройдена!\n");
    }
    printf("\n");
}

void floatTest(int testCount) {
    printf("Проверка вещетвенных векторов одинарной точности...\n");
    //TODO вручную написать 3-4 примера рассчётов векторов
    printf("Проверка на случайных числах...\n");
    int i;
    for (i = 0; i < testCount; i++) {
        float x1 = fRand(), y1 = fRand(), z1 = fRand(),
              x2 = fRand(), y2 = fRand(), z2 = fRand(),
              x, y, z;
        int k;

        myVector *v1 = newVector(&x1, &y1, &z1, sizeof(float), &floatOperation);
        myVector *v2 = newVector(&x2, &y2, &z2, sizeof(float), &floatOperation);

        myVector *vAdd = v1->add(v1, v2);
        float *vScalar = (float*) v1->scalarMult(v1, v2);
        myVector *vMult = v1->mult(v1, v2);

        x = x1 + x2, y = y1 + y2, z = z1 + z2;
        k = testCheckVec(&x, &y, &z, vAdd);

        x = x1 * x2, y = y1 * y2, z = z1 * z2;
        k = k && (*vScalar == x + y + z);

        x = y1 * z2 - y2 * z1, y = z1 * x2 - z2 * x1, z = x1 * y2 - x2 * y1;
        k = k && testCheckVec(&x, &y, &z, vMult);

        if (!k) break;

        free(v1);
        free(v2);
        free(vScalar);
        vAdd->remove(vAdd);
        vMult->remove(vMult);
    }
    printf("Проверка на %d случайных числах ", testCount);
    if (i == testCount) {
        printf("пройдена!\n");
    }
    else {
        printf("не пройдена!\n");
    }
    printf("\n");
}

void doubleTest(int testCount) {
    printf("Проверка вещетвенных векторов двойной точности...\n");
    //TODO вручную написать 3-4 примера рассчётов векторов
    printf("Проверка на случайных числах...\n");
    int i;
    for (i = 0; i < testCount; i++) {
        double x1 = dRand(), y1 = dRand(), z1 = dRand(),
                x2 = dRand(), y2 = dRand(), z2 = dRand(),
                x, y, z;
        int k;

        myVector *v1 = newVector(&x1, &y1, &z1, sizeof(double), &doubleOperation);
        myVector *v2 = newVector(&x2, &y2, &z2, sizeof(double), &doubleOperation);

        myVector *vAdd = v1->add(v1, v2);
        double *vScalar = (double*) v1->scalarMult(v1, v2);
        myVector *vMult = v1->mult(v1, v2);

        x = x1 + x2, y = y1 + y2, z = z1 + z2;
        k = testCheckVec(&x, &y, &z, vAdd);

        x = x1 * x2, y = y1 * y2, z = z1 * z2;
        k = k && (*vScalar == x + y + z);

        x = y1 * z2 - y2 * z1, y = z1 * x2 - z2 * x1, z = x1 * y2 - x2 * y1;
        k = k && testCheckVec(&x, &y, &z, vMult);

        if (!k) break;

        free(v1);
        free(v2);
        free(vScalar);
        vAdd->remove(vAdd);
        vMult->remove(vMult);
    }
    printf("Проверка на %d случайных числах ", testCount);
    if (i == testCount) {
        printf("пройдена!\n");
    }
    else {
        printf("не пройдена!\n");
    }
    printf("\n");
}

void complexTest(int testCount) {
    printf("Проверка комплексных векторов...\n");
    //TODO вручную написать 3-4 примера рассчётов векторов
    printf("Проверка на случайных числах...\n");
    int i;
    for (i = 0; i < testCount; i++) {
        complex x1 = compRand(), y1 = compRand(), z1 = compRand(),
                x2 = compRand(), y2 = compRand(), z2 = compRand(),
                x, y, z, fake1, fake2;
        int k;
        struct operation op = complexOperation;
        myVector *v1 = newVector(&x1, &y1, &z1, sizeof(double), &op);
        myVector *v2 = newVector(&x2, &y2, &z2, sizeof(double), &op);

        myVector *vAdd = v1->add(v1, v2);
        complex *vScalar = (complex*) v1->scalarMult(v1, v2);
        myVector *vMult = v1->mult(v1, v2);

        op.add(&x1, &x2, &x), op.add(&y1, &y2, &y), op.add(&z1, &z2, &z);
        k = testCheckVec(&x, &y, &z, vAdd);

        op.mult(&x1, &x2, &x), op.mult(&y1, &y2, &y), op.mult(&z1, &z2, &z);
        k = k && op.isSame(vScalar, op.add(op.add(&x, &y, &fake1), &z, &fake2));

        //x = y1 * z2 - y2 * z1, y = z1 * x2 - z2 * x1, z = x1 * y2 - x2 * y1;
        op.sub(op.mult(&y1, &z2, &fake1), op.mult(&y2, &z1, &fake2), &x);
        op.sub(op.mult(&z1, &x2, &fake1), op.mult(&z2, &x1, &fake2), &y);
        op.sub(op.mult(&x1, &y2, &fake1), op.mult(&x2, &y1, &fake2), &z);

        k = k && testCheckVec(&x, &y, &z, vMult);

        if (!k) break;

        free(v1);
        free(v2);
        free(vScalar);
        vAdd->remove(vAdd);
        vMult->remove(vMult);
    }
    printf("Проверка на %d случайных числах ", testCount);
    if (i == testCount) {
        printf("пройдена!\n");
    }
    else {
        printf("не пройдена!\n");
    }
    printf("\n");
}