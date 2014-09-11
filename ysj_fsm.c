/*
 * It's a part of YSJ_FSM, by Shanjin Yang.
 * Email: sjyangv0@gmail.com
 *
 */

#include "ysj_fsm.h"

FSM *fsm_obj;
STATE_DIS *state_obj;
STATE_DIS *state_obj_copy;

FSM fsm_default = 
{
    0, NULL, "state_default",
};


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
    /*Just make a symbol for state name*/
    uint token = (uint)*name;

    STATE_OBJ_MALLOC_AND_INSERT(token, state, func, name);    

    state_obj = (STATE_DIS *)(&(state_obj->node))->next;
}

uint state_remove( uint state )
{
    STATE_DIS *tmp = state_obj_copy;
    while(!is_list_empty(&(tmp->node)))  
    {
        if ( tmp->state == state )
        {
            list_delete(&(tmp->node));
            tmp->state = 10000;
            tmp->func  = NULL;
            tmp->name  = "";
            return 0;
        }

        tmp = (STATE_DIS *)(&(tmp->node))->next;
    }   
    
    if ( tmp->state == state )
    {
        list_delete(&(tmp->node)); 
        
        tmp->state = 10000;
        tmp->func  = NULL;
        tmp->name  = "";

        return 0;
    }
    printf("State no fund\n");
}

uint state_tran( uint state )
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

        tmp = (STATE_DIS *)(&(tmp->node))->next;
    }    
    
    if ( tmp->state == state )
    {
            fsm_obj->name     = tmp->name; 
            fsm_obj->state    = state;

            fsm_obj->func = tmp->func; 
            return 0; 
    }
    state_default(fsm_default.state, fsm_default.func, fsm_default.name);
    
    printf("state is no found, and fsm will transfer to default, It is name: %s\n", fsm_obj->name);
}


void fsm_while(FSM *obj)
{
    while(1){
        printf("state name = %s\n", obj->name);
        obj->func(NULL);
    }
}

void state_default(uint state, FUNC_PTR func, uchar *name)
{
    fsm_obj->state = state;
    fsm_obj->func  = func;
    fsm_obj->name  = name;
}


