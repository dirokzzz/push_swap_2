#include "checker.h"

t_stack *add_elem(t_stack *src, t_stack *dst)
{
    t_stack *new;

    if (src->index == 0)
        return (dst);
    if (!(new = malloc(sizeof(t_stack))))
        exit(0);
    new->next = dst;
    new->elem = src->elem;
    new->index = src->index;
    return(new);
}

t_stack *del_elem(t_stack *stack)
{
    t_stack *tmp;

    if(stack->index == 0)
        return (stack);
    tmp = stack;
    stack = stack->next;
    free(tmp);
    return (stack);
}

int check_array(t_tab *tab)
{
	int ok;
    t_stack *a;

    a = tab->head_a;
	ok = 1;
	while(a->next->index)
	{
		if(a->elem > a->next->elem)
			ok = 0;
		a = a->next;
	}
	if(tab->head_b->index)
		ok = 0;
	if(ok)
		return (1);
	return (0);
}