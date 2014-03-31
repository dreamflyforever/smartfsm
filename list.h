

#ifndef LIST_H
#define LIST_H

#define INLINE static

typedef struct LIST {
	struct LIST	*next;
	struct LIST	*previous;
} LIST;


#define list_entry(node, type, member)    ((type *)((U8 *)(node) - (U32)(&((type *)0)->member))) 



INLINE void list_init(LIST *list_head)
{
	list_head->next = list_head;
	list_head->previous = list_head;
}
  

INLINE unsigned char is_list_empty(LIST *list)
{

    return (list->next == list);	
	
}


INLINE void list_insert(LIST *head, LIST *element)
{
    element->previous=  head;
    element->next =element;
    head->next = element;
    
#if 0
    element->next = head->next;
    element->previous = head;

    head->next->previous = element;
    head->next           = element;
#endif
}


INLINE int list_delete(LIST *element)
{
    if (is_list_empty(element))
    {
        element->previous->next = element->previous;
        return 0;
    }
	element->previous->next = element->next;
	element->next->previous = element->previous;
	
}


#endif

