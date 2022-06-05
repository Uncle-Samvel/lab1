//
// Created by Grisha on 20.02.2021.
//

#include "menu.h"

int getInt(int *n, int down, int up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err, num;

    do {
        err = scanf("%d", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Неворно! Повторите попытку!\n::");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

double getDouble(double *n, double down, double up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err;
    double num;

    do {
        err = scanf("%lf", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Неворно! Повторите попытку!\n::");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

float getFloat(float *n, float down, float up) {
    int k = (down == 0 && up == 0) ? 0 : 1;
    int err;
    float num;

    do {
        err = scanf("%f", &num);
        if (err < 0) {
            exit(0);
        }
        if ((num < down || num > up) && k) {
            err = 0;
            printf("Неворно! Повторите попытку!\n::");
        }
    } while (err <= 0);

    if (n != NULL)
        *n = num;

    return num;
}

complex *getComplex() {
    printf("Введите действительную часть числа: ");
    float a = getFloat(NULL, 0, 0);
    printf("Введите мнимую часть числа: ");
    float b = getFloat(NULL, 0, 0);
    complex *res = newComplex(a, b);
    return res;
}

myVector *createIntVector() {
    printf("Введите координату х: ");
    int x = getInt(NULL, 0, 0);
    printf("Введите координату y: ");
    int y = getInt(NULL, 0, 0);
    printf("Введите координату z: ");
    int z = getInt(NULL, 0, 0);

    myVector *res = newVector(malloc(sizeof(int)), malloc(sizeof(int)),
                              malloc(sizeof(int)), sizeof(int), &intOperation);

    memcpy(res->x, &x, sizeof(int));
    memcpy(res->y, &y, sizeof(int));
    memcpy(res->z, &z, sizeof(int));

    return res;
}

myVector *createFloatVector() {
    printf("Введите координату х: ");
    float x = getFloat(NULL, 0, 0);
    printf("Введите координату y: ");
    float y = getFloat(NULL, 0, 0);
    printf("Введите координату z: ");
    float z = getFloat(NULL, 0, 0);

    myVector *res = newVector(malloc(sizeof(float)), malloc(sizeof(float)),
                              malloc(sizeof(float)), sizeof(float), &floatOperation);

    memcpy(res->x, &x, sizeof(float));
    memcpy(res->y, &y, sizeof(float));
    memcpy(res->z, &z, sizeof(float));

    return res;
}

myVector *createDoubleVector() {
    printf("Введите координату х: ");
    double x = getDouble(NULL, 0, 0);
    printf("Введите координату y: ");
    double y = getDouble(NULL, 0, 0);
    printf("Введите координату z: ");
    double z = getDouble(NULL, 0, 0);
    printf("Double: %lf, %lf, %lf\n", x, y, z);

    myVector *res = newVector(malloc(sizeof(double)), malloc(sizeof(double)),
                              malloc(sizeof(double)), sizeof(double), &doubleOperation);

    memcpy(res->x, &x, sizeof(double));
    memcpy(res->y, &y, sizeof(double));
    memcpy(res->z, &z, sizeof(double));

    return res;
}

myVector *createComplexVector() {
    printf("Ввод координаты х: ");
    complex *x = getComplex();
    printf("Введите координату y: ");
    complex *y = getComplex();
    printf("Введите координату z: ");
    complex *z = getComplex();

    myVector *res = newVector(malloc(sizeof(complex)), malloc(sizeof(complex)),
                              malloc(sizeof(complex)), sizeof(complex), &complexOperation);

    memcpy(res->x, x, sizeof(complex));
    memcpy(res->y, y, sizeof(complex));
    memcpy(res->z, z, sizeof(complex));

    free(x);
    free(y);
    free(z);

    return res;
}

myVector *getVector() {
    int n;
    printf("Введите следующее число для выбора типа вектора:\n "
           "\t1: вектор int \n"
           "\t2: вектор float\n"
           "\t3: вектор double\n"
           "\t4: вектор complex\n:");

    getInt(&n, 1, 4);
    myVector *res;

    switch (n) {
        case 1: res = createIntVector(); break;
        case 2: res = createFloatVector(); break;
        case 3: res = createDoubleVector(); break;
        case 4: res = createComplexVector(); break;
        default: res = NULL; break;
    }

    if (n >= 1 && n <= 4 && res == NULL) {
        printf("Не удалось создать вектор!\n");
    }

    return res;
}

void printMenu() {
    printf("Программа имеет следующие возможности, для выбора введите следующую цифру:\n"
           "\t1: Для ввода вектора\n"
           "\t2: Для записи вектора в память\n"
           "\t3: Для выполнения над векторами операций\n"
           "\t4: Для вывода вектора в консоль\n"
           "\t5: Для удаления вектора из памяти\n"
           "\t6: Для проверки векторов\n"
           "\t7: Для выхода из программы\n"
           "Введите число: ");
}

void addToArray(myVector ***arr, int *len, int ind, myVector **vec) {
    (*len)++;
    if (*len == 1) {
        *arr = (myVector**) malloc(sizeof(myVector *));
        (*arr)[0] = *vec;
        *vec = NULL;
        return;
    }

    myVector **arrNew = (myVector**) malloc((*len) * sizeof(myVector *));
    for (int i = 0, j = 0; i < *len; i++) {
        if (i == ind || (i == j && i == *len - 1)) arrNew[i] = *vec;
        else {
            arrNew[i] = (*arr)[j];
            j++;
        }
    }

    free(*arr);
    *arr = arrNew;
    *vec = NULL;
}

void replaceInArray(myVector ***arr, int *len, int ind, myVector **vec) {
    (*arr)[ind]->remove((*arr)[ind]);
    (*arr)[ind] = *vec;
    *vec = NULL;
}

int checkInd(int len) {
    int n = -2;

    do {
        getInt(&n, 0, 0);
        if (n < 0) {
            printf("Индекс не может быть отрицательным! Повторите попытку или введите -1 для выхода: ");
        }
    } while (n < -1);

    return n;
}

void writeVector(myVector ***arr, int *len, myVector **vec) {
    if (vec == NULL) {
        printf("Пустой вектор!\n");
        return;
    }

    printf("Введите индекс, по которому записать вектор в массив или введите -1 для выхода (%d элементов в массиве): ", *len);
    int n = checkInd(*len);
    if (n == -1) return;

    if (n >= *len) {
        if (n == *len) {
            addToArray(arr, len, *len, vec);
            return;
        }
        printf("Индекс превышает колличество элементов в массиве. Записать его в конец массива? (1 - да, 0 - выбор другого индекса, -1 - выход");
        getInt(&n, -1, 1);

        switch (n) {
            default: break;
            case 0: writeVector(arr, len, vec); break;
            case 1: addToArray(arr, len, *len, vec); break;
        }
        return;
    }
    printf("Заменить %d элемент или вставить я его место? (1 - для замены): ", n);
    if (getInt(NULL, 0, 0) == 1) {
        replaceInArray(arr, len, n, vec);
    }
    else {
        addToArray(arr, len, n, vec);
    }
}

void removeInArray(myVector*** arr, int *len, int ind) {
    (*len)--;
    if (*len == 0) {
        (*arr)[0]->remove((*arr)[ind]);
        free(*arr);
        return;
    }
    myVector **newArr = (myVector **) malloc((*len) * sizeof(myVector*));
    for (int i = 0, j = 0; i < *len + 1; i++) {
        if (i == ind) continue;
        newArr[i] = (*arr)[j];
        j++;
    }
    (*arr)[ind]->remove((*arr)[ind]);
    free(*arr);
    *arr = newArr;
}

void removeArr(myVector ***arr, int *len) {
    if (*arr == NULL) {
        printf("Пустой массив!\n");
        return;
    }
    printf("Введите индекс элемента, который необходимо удалить или введите -1 для выхода: (%d элементов в массиве): ", *len);
    int n = checkInd(*len);
    if (n == -1) return;

    if (n >= *len) {
        printf("Индекс превышает колличество элементов в массиве. Удалить последний элемент массива? (1 - да, 0 - выбор другого индекса, -1 - выход");
        getInt(&n, -1, 1);
        switch (n) {
            default: break;
            case 0: removeArr(arr, len); break;
            case 1: removeInArray(arr, len, n); break;
        }
        return;
    }
    removeInArray(arr, len, n);
}

void printArrVector(myVector ***arr, int len) {
    printf("Введите индекс элемента, который необходимо вывести или введите -1 для выхода (%d элементов в массиве): ", len);
    int n = checkInd(len);
    if (n == -1) return;

    if (n >= len) {
        printf("Индекс превышает длину массива, вывести последний элемент? (1 - да, 0 - выбрать другой, -1 - выход): ");
        n = getInt(NULL, -1, 1);
        switch (n) {
            default: break;
            case 0: printArrVector(arr, len); break;
            case 1: printf("%d элемент: ", len-1); myVector *v = (*arr)[len-1]; v->print(v); break;
        }
        return;
    }
    myVector *v = (*arr)[n];
    printf("%d вектор: ", n);
    v->print(v);
}

void operationWithVector(myVector **arr, int len, myVector **res) {
    printf("Введите индекс первого элемента, выступающего в операции или введите -1 для выхода (%d элементов в массиве): ", len);
    int n1 = checkInd(len);
    if (n1 == -1) return;

    if (n1 >= len) {
        printf("Индекс превышает длину массива, использовать последний элемент? (1 - да, 0 - выход): ");
        int n = getInt(NULL, 0, 1);
        if (n == 0) return;
        n1 = len - 1;
    }
    printf("Введите индекс второго элемента, выступающего в операции или введите -1 для выхода (%d элементов в массиве): ", len);

    int n2 = checkInd(len);
    if (n2 == -1) return;

    if (n2 >= len) {
        printf("Индекс превышает длину массива, использовать последний элемент? (1 - да, 0 - выход): ");
        int n = getInt(NULL, 0, 1);
        if (n == 0) return;
        n2 = len - 1;
    }

    myVector *v1 = arr[n1];
    myVector *v2 = arr[n2];

    if (checkType(v1, v2)) {
        printf("Ошибка! Вектора имеют разный тип данных!\n");
        return;
    }

    printf("Введите код операции: 1 - сумма векторов, 2 - скалярное произведение векторов, 3 - векторное произведение векторов: ");
    int n = getInt(NULL, 1, 3);

    if (*res != NULL) (*res)->remove(*res);
    //printf("%d %d %d", *(int*)(v1->x), *(int*)(v1->y), *(int*)(v1->z));
    void *scalar;
    switch (n) {
        default: break;
        case 1: *res = v1->add(v1, v2); break;
        case 2: scalar = v1->scalarMult(v1, v2); break;
        case 3: *res = v1->mult(v1, v2); break;
    }

    if (*res == NULL) {
        printf("Произошла ошибка во время выполнения операции!\n");
        return;
    }

    if (n != 2) return;

    printf("Результат скалярного умножения: тип: %s; значение: ", v1->operation->type);
    v1->operation->print(scalar);
    free(scalar);
    printf("\n");
}