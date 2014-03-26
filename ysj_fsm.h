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

typedef  void (*FUNC_PTR)(void *p_arg);
typedef struct fsm_s{
    uint state;
    uchar *name;
    FUNC_PTR func;
}FSM;


typedef struct state_dis_s{
    LIST node;
    uint state;
    FUNC_PTR func;
    uchar *name;
}STATE_DIS;


void state_init( uint state, FUNC_PTR func, uchar *name );

void state_add( uint state, FUNC_PTR func, uchar *name );

void state_remove( uint state );

void state_tran( uint state );

void fsm_init();

void fsm_while(FSM *obj);





