

#ifndef LIST_H
#define LIST_H

#define INLINE static
//创建的是双链表
typedef struct LIST {
	struct LIST	*next;
	struct LIST	*previous;
} LIST;


#define list_entry(node, type, member)    ((type *)((U8 *)(node) - (U32)(&((type *)0)->member))) //模仿linux



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
}


INLINE void list_delete(LIST *element)
{

	element->previous->next = element->next;
	element->next->previous = element->previous;
	
}


#endif

