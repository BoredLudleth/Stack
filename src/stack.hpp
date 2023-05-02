#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>

typedef float type;
#define TYPE_SPECIFIER "%f"
#define CANARY_VALUE 58

#define DEFAULT_STACK_LENGTH 10
#define POISON 0xBAD

#define DBG printf("FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__);

#define ASSERT(stack) if (stackCheck(stack)) { \
                        exit(0);               \
                      }

struct stack 
{
    type* data;                     // значение
    int   filled;                       // указывает на первый свободный
    int   lengthStack;
    int   error;
    int   canary_1;
    int   canary_2;
};


enum commands
{
    STACKPUSH  = 0,
    STACKPOP   = 1
};

enum Errors
{
    NO_ERRORS               = 0,
    ERR_STACK_IS_LITTLE     = 1,
    ERR_NULL_DATA           = 2,
    ERR_CANERY_CHANGED      = 4,
    ERR_SIZE_OUT_LEFTRANGE  = 8,
};



void stackCtor (struct stack* stack);

void stackDtor (struct stack* stack);

void stackDump (struct stack* stack);

void stackPush (struct stack* stack, type value);

type stackPop (struct stack* p_stack);

int stackCheck (struct stack* stack);

void stackResizeUp (struct stack* stack);

void stackResizeDown (struct stack* stack);
