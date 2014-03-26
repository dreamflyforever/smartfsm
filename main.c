
#include "ysj_fsm.h"

extern FSM *fsm_obj;

void one(void *arg)
{
    printf("one\n");
    state_tran(2);
}

void two(void *arg)
{
    printf("two\n");
    state_tran(3);
}

void three(void *arg)
{
    printf("three\n");
    state_tran(1);
}

void main()
{
    state_init(1, one, "name_one");
    state_add(2, two, "name_two");
    state_add(3, three, "name_three");
    //state_remove(3);
    fsm_while(fsm_obj);
    return 0;
}
