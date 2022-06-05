//
// Created by Grisha on 18.02.2021.
//

#include "complexNum.h"

complex *newComplex(const float realPart, const float complexPart) {
    complex *res = (complex*) malloc(sizeof(complex));
    res->realPart = realPart;
    res->complexPart = complexPart;
    res->size = sizeof(complex);
    return res;
}


void* complexAdd(void *num1, void *num2, void *res) {
    complex *n1 = num1;
    complex *n2 = num2;
    complex *n3 = newComplex(n1->realPart + n2->realPart, n1->complexPart + n2->complexPart);
    memcpy(res, n3, sizeof(complex));
    free(n3);
    return res;
}

void* complexSub(void *num1, void *num2, void *res) {
    complex *n1 = num1;
    complex *n2 = num2;
    complex *n3 = newComplex(n1->realPart - n2->realPart, n1->complexPart - n2->complexPart);
    memcpy(res, n3, sizeof(complex));
    free(n3);
    return res;
}

void* complexMult(void *num1, void *num2, void *res) {
    complex *n1 = num1;
    complex *n2 = num2;
    complex *n3 = newComplex(n1->realPart * n2->realPart - n1->complexPart * n2->complexPart,
                             n1->realPart * n2->complexPart + n1->complexPart * n2->realPart);
    memcpy(res, n3, sizeof(complex));

    free(n3);
    return res;
}

void complexPrint(void *num) {
    complex *n = num;
    if (n->realPart != 0 && n->complexPart == 0)
        printf("%f ", n->realPart);

    if (n->complexPart != 0)
        if (n->realPart != 0) {
            if (n->complexPart > 0)
                printf("+ ");
            else
                printf("- ");
        }
        if (n->complexPart > 0 || n->realPart == 0)
            printf("%fi", n->complexPart);
        else
            printf("%fi", -n->complexPart);
}

int complexIsSame(void *num1, void *num2) {
    complex *n1 = num1;
    complex *n2 = num2;
    return (n1->realPart == n2->realPart && n1->complexPart == n2->complexPart);
}