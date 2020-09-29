#include "checker.h"

t_stack *ft_push_b(t_stack **a, t_stack **b)
{
    *b = add_elem(*a, *b);
    *a = del_elem(*a);
    return (*a);
}

void ft_push_a(t_stack **a, t_stack **b)
{
    *a = add_elem(*b, *a);
    *b = del_elem(*b);
}

void ft_ss(t_stack *a, t_stack *b)
{
    ft_s_elem(a);
    ft_s_elem(b);
}

void ft_s_elem(t_stack *a)
{
    if(a->next->index != 0)
    {
        ft_swap_int(&a->elem, &a->next->elem);
        ft_swap_int(&a->index, &a->next->index);
    }
}

t_stack *ft_r_stack(t_stack *a)
{
    t_stack *current;
    t_stack *first;
    t_stack *last;

    if (!a->index)
        return (a);
    else if(!a->next->index)
        return (a);
    first = a;
    a = a->next;
    current = a;
    while (current->next->next)
        current = current->next;
    last = current;
    first->next = current->next;
    last->next = first;
    return (a); 
}

t_stack *ft_rr_stack(t_stack *a)
{
    t_stack *first;
    t_stack *last;

    if (!a->index)
        return (a);
    else if(!a->next->index)
        return (a);
    first = a;
    while (a->next->next->index)
        a = a->next;
    last = a->next;
    a->next = a->next->next;
    last->next = first;
    return (last);
}

void ft_rrr(t_stack **a, t_stack **b)
{
    *a = ft_rr_stack(*a);
    *b = ft_rr_stack(*b);
}

void ft_rr(t_stack **a, t_stack **b)
{
    *a = ft_r_stack(*a);
    *b = ft_r_stack(*b);
}