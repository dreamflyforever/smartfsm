/*
 * It's a Use-Case to smartfsm, write by Shanjin Yang.
 * Email: sjyangv0@gmail.com
 *
 */

#include "fsm.h"

#define wakeup_state 1
#define asr_state 2
#define tts_state 3
#define comm_state 4
#define sock_state 5


void wakeup_state_func(void *arg)
{
	char *message = (char *)arg;
	if (message != NULL)
		printf("%s: %s\n", __func__, message);
	state_tran(asr_state, "wakeup end message");
}

void asr_state_func(void *arg)
{
	char *message = (char *)arg;
	if (message != NULL)
		printf("%s: %s\n", __func__, message);
	state_tran(tts_state, "asr end message");
}

void tts_state_func(void *arg)
{
	char *message = (char *)arg;
	if (message != NULL)
		printf("%s: %s\n", __func__, message);
	state_tran(wakeup_state, NULL);
}

void comm_state_func(void *arg)
{
	char *message = (char *)arg;
	if (message != NULL)
		printf("%s: %s\n", __func__, message);
	state_tran(10, "ten message");
}

void sock_state_func(void *arg)
{
	char *message = (char *)arg;
	if (message != NULL)
		printf("%s: %s\n", __func__, message);
	state_tran(10, "ten message");
}

void func_default(void *arg)
{
	char *message = (char *)arg;
	if (message != NULL)
		printf("default: %s\n", message);
	state_tran(wakeup_state, "default message");
}

FSM user_app[5] = {
	{wakeup_state, wakeup_state_func, "name_one"},
	{asr_state, asr_state_func, "name_two"},
	{tts_state, tts_state_func, "name_three"},
	{comm_state, comm_state_func, "name_three"},
	{sock_state, sock_state_func, "name_three"},
};

int main()
{
	SET_STATE_DEFAULT_FUNC(func_default);

	state_init(user_app[0].state, user_app[0].func, user_app[0].name);
	state_add(user_app[1].state, user_app[1].func, user_app[1].name);
	state_add(user_app[2].state, user_app[2].func, user_app[2].name);
	fsm_while(fsm_obj);
	return 0;
}
