/*
 * It's a part of smartfsm, by Shanjin Yang.
 * Email: sjyangv0@gmail.com
 *
 */
#include <stdlib.h>
#include "list.h"
#include "stdio.h"

#define uint  unsigned int
#define uchar unsigned char

#define ERROR_PRINTF  printf("error: %d\n", __LINE__)

#define STATE_OBJ_MALLOC_AND_INSERT(token, state, func, state_name)  \
	STATE_DIS *state_obj_##token = (STATE_DIS *)malloc(sizeof(STATE_DIS)); \
state_obj_##token->state = state; \
state_obj_##token->name  = state_name; \
state_obj_##token->func  = func;\
list_insert( &(state_obj->node), &(state_obj_##token->node)) 

#define SET_STATE_DEFAULT_FUNC(function)  fsm_default.func = function

typedef  void (*FUNC_PTR)(void *p_arg);

typedef struct fsm_s {
	uint state;  
	FUNC_PTR func;
	uchar *name;
	char message[1024];
} FSM;

typedef struct state_dis_s {
	LIST node;
	uint state;
	FUNC_PTR func;
	uchar *name;
} STATE_DIS;

extern FSM *fsm_obj;
extern FSM  fsm_default;

int state_init(uint state, FUNC_PTR func, uchar *name);

int state_add(uint state, FUNC_PTR func, uchar *name);

uint state_remove(uint state);

uint state_tran(uint state, void *message);

int fsm_init();

void fsm_while(FSM *obj);

int state_default(uint state, FUNC_PTR func, uchar *name);
