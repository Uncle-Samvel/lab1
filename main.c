#include <stdio.h>

#include "menu.h"
#include "tests.h"

int main() {
    //system("chcp 65001");
    //test();
    int err, n, len = 0;

    myVector *v = NULL;
    myVector **arr = (myVector **) malloc(sizeof(myVector *));
    do {
        printMenu();
        err = scanf("%d", &n);
        if (err <= 0 || n > 7 || n < 1) {
            printf("Неправильно введено число, повторите попытку: ");
            if (err <= 0) scanf("%s");
            continue;
        }
        if (n == 7) break;

        switch (n) {
            case 1: v = getVector(); break;
            case 2: writeVector(&arr, &len, &v); break;
            case 3: operationWithVector(arr, len, &v); break;
            case 4: printArrVector(&arr, len); break;
            case 5: removeArr(&arr, &len); break;
            case 6: tests(); break;
            default: break;
        }
    } while (1);

    for (int i = 0; i < len; i++) {
        arr[i]->remove(arr[i]);
    }
    free(arr);
    if (v != NULL)
        v->remove(v);

    return 0;
}
