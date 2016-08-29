/*
 * It's a Use-Case to smartfsm, write by Shanjin Yang.
 * Email: sjyangv0@gmail.com
 *
 */

#include "fsm.h"

#define state1 1
#define state2 2
#define state3 3


void one(void *arg)
{
	char *message = (char *)arg;
	if (message != NULL)
		printf("one: %s\n", message);
	state_tran(2, "two message");
}

void two(void *arg)
{
	char *message = (char *)arg;
	if (message != NULL)
		printf("two: %s\n", message);
	state_tran(3, "three message");
}

void three(void *arg)
{
	char *message = (char *)arg;
	if (message != NULL)
		printf("three: %s\n", message);
	state_tran(10, "ten message");
}

void func_default(void *arg)
{
	char *message = (char *)arg;
	if (message != NULL)
		printf("default: %s\n", message);
	state_tran(1, "default message");
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
