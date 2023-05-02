#include "stack.hpp"

int main () {
    struct stack stack = {};

    stackCtor (&stack);
    for (int i = 0; i < 20; i++) {
        stackPush(&stack, (float) i + 1);
    }
    for (int i = 0; i < 15; i++) {
        float a = stackPop (&stack);
        printf ("%f\n", a);
    }
    stackDump (&stack);
    stackDtor (&stack);

    return 0;
}