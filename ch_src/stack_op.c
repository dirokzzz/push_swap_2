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