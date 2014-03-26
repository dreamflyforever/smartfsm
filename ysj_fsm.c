#include "ysj_fsm.h"

FSM *fsm_obj;
STATE_DIS *state_obj;
STATE_DIS *state_obj_copy;


void fsm_init()
{
    state_obj = (STATE_DIS *)malloc(sizeof(STATE_DIS));

    fsm_obj   = (FSM *)malloc(sizeof(FSM));
}

void state_init( uint state, FUNC_PTR func, uchar *name )
{
    fsm_init();

    if ( (state_obj == NULL) || ( fsm_obj == NULL)) 
        ERROR_PRINTF;

    fsm_obj->state = state;
    fsm_obj->func = func;
    fsm_obj->name = name;

    state_obj->state = state;
    state_obj->func  = func;  
    state_obj->name  = name;

    state_obj_copy = state_obj;
    list_init( &(state_obj->node) );

}

void state_add( uint state, FUNC_PTR func, uchar *name )
{
    uint token = (uint)(int *)name;

    STATE_OBJ_MALLOC_AND_INSERT(token, state, func, name);    

    state_obj = (&(state_obj->node))->next;
}

void state_remove( uint state )
{
    STATE_DIS *tmp = state_obj;
    while(!is_list_empty(&(tmp->node)))  
    {
        if ( tmp->state == state )
        {
            list_delete(&(tmp->node));
            return 0;
        }

        tmp = (&(tmp->node))->next;
    }   
}

void state_tran( uint state )
{
    STATE_DIS *tmp = state_obj_copy;    

    while( !is_list_empty(&(tmp->node)) )  
    {
        if ( tmp->state == state )
        {
            fsm_obj->func = tmp->func;
            fsm_obj->name     = tmp->name; 
            fsm_obj->state    = state;
            return 0; 
        }

        tmp = (&(tmp->node))->next;
    }    
    
    if ( tmp->state == state )
    {
            fsm_obj->name     = tmp->name; 
            fsm_obj->state    = state;

            fsm_obj->func = tmp->func; 
            return 0; 
    }
    
    printf("state is no found\n");
}


void fsm_while(FSM *obj)
{
    while(1){
        printf("state name = %s\n", obj->name);
        obj->func(NULL);
    }
}

