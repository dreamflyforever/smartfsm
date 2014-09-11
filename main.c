/*
 * It's a Use-Case of YSJ_FSM, by Shanjin Yang.
 * Email: sjyangv0@gmail.com
 *
 */

#include "ysj_fsm.h"

#define state1 1
#define state2 2
#define state3 3


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
    state_tran(10);
}

void func_default(void *arg)
{
    printf("default\n");
    state_tran(1);
}

FSM user_app[3] = {
    {state1, one, "name_one"},
    {state2, two, "name_two"},
    {state3, three, "name_three"},
 };

int main()
{
    SET_STATE_DEFAULT_FUNC(func_default);
    
    state_init(user_app[0].state, user_app[0].func, user_app[0].name);
    state_add(user_app[1].state, user_app[1].func, user_app[1].name);
    state_add(user_app[2].state, user_app[2].func, user_app[2].name);
    //state_remove(user_app[2].state);
    fsm_while(fsm_obj);
    return 0;
}
