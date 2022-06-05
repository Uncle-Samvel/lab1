//
// Created by Grisha on 19.02.2021.
//

#include "myVector.h"

myVector *newVector(void *x, void *y, void *z, size_t element_size, const struct operation *op) {
    myVector *res = (myVector*) malloc(sizeof(myVector));
    res->operation = op;

    res->x = x;
    res->y = y;
    res->z = z;

    res->element_size = element_size;
    res->myVectorSize = sizeof(myVector);

    res->add = vectorAdd;
    res->scalarMult = vectorScalarMult;
    res->mult = vectorMult;

    res->isSame = vectorIsSame;

    res->print = printVector;
    res->remove = removeMyVector;

    return res;
}

int checkType(struct myVector *v1, struct myVector *v2) {
    if (v1 == NULL || v2 == NULL) return 1;

    if (v1->myVectorSize != sizeof(myVector) || v2->myVectorSize != sizeof(myVector)) return 1;

    return (v1->element_size != v2->element_size || v1->operation != v2->operation);
}

myVector *vectorAdd(myVector *v1, myVector *v2) {
    if (checkType(v1, v2)) return NULL;

    void *x = malloc(sizeof(v1->element_size));
    void *y = malloc(sizeof(v1->element_size));
    void *z = malloc(sizeof(v1->element_size));

    v1->operation->add(v1->x, v2->x, x);
    v1->operation->add(v1->y, v2->y, y);
    v1->operation->add(v1->z, v2->z, z);

    return newVector(x, y, z, v1->element_size, v1->operation);
}

void *vectorScalarMult(myVector *v1, myVector *v2) {
    if (checkType(v1, v2)) return NULL;

    void *x = malloc(sizeof(v1->element_size));
    void *y = malloc(sizeof(v1->element_size));
    void *z = malloc(sizeof(v1->element_size));

    v1->operation->mult(v1->x, v2->x, x);
    v1->operation->mult(v1->y, v2->y, y);
    v1->operation->mult(v1->z, v2->z, z);

    void *sum1 = malloc(sizeof(v1->element_size));
    void *sum  = malloc(sizeof(v1->element_size));

    v1->operation->add(x, y, sum1);
    v1->operation->add(sum1, z, sum);

    free(x);
    free(y);
    free(z);
    free(sum1);

    return sum;
}

myVector *vectorMult(myVector *v1, myVector *v2) {
    if (checkType(v1, v2)) return NULL;

    void *x = malloc(sizeof(v1->element_size)), *y = malloc(sizeof(v1->element_size)), *z = malloc(sizeof(v1->element_size)),
         *k1 = malloc(sizeof(v1->element_size)), *k2 = malloc(sizeof(v1->element_size));

    struct operation *op = v1->operation;

    op->sub(op->mult(v1->y, v2->z, k1), op->mult(v1->z, v2->y, k2), x);
    op->sub(op->mult(v1->z, v2->x, k1), op->mult(v1->x, v2->z, k2), y);
    op->sub(op->mult(v1->x, v2->y, k1), op->mult(v1->y, v2->x, k2), z);

    free(k1);
    free(k2);

    return newVector(x, y, z, v1->element_size, op);
}

int vectorIsSame(myVector *v1, myVector *v2) {
    if (checkType(v1, v2)) return 0;
    return (v1->operation->isSame(v1->x, v2->x) &&
            v1->operation->isSame(v1->y, v2->y) &&
            v1->operation->isSame(v1->z, v2->z));
}

void printVector(myVector *v) {
    if (v == NULL) {
        printf("Пустой вектор!");
        return;
    }
    printf("Тип вектора: %s", v->operation->type);

    printf("; элемент х: ");
    v->operation->print(v->x);
    printf("; элемент y: ");
    v->operation->print(v->y);
    printf("; элемент z: ");
    v->operation->print(v->z);
    printf("\n");
}

void removeMyVector(myVector *v) {
    free(v->x);
    free(v->y);
    free(v->z);

    free(v);
}