#include "checker.h"

void ft_push_b(t_tab *tab)
{
    tab->head_b = add_elem(tab->head_a, tab->head_b);
    tab->head_a = del_elem(tab->head_a);
    ft_printf("pb\n");
}

void ft_push_a(t_tab *tab)
{
    tab->head_a = add_elem(tab->head_b, tab->head_a);
    tab->head_b = del_elem(tab->head_b);
    ft_printf("pa\n");
}

void ft_ss(t_tab *tab)
{
    ft_s_elem(tab->head_a, "");
    ft_s_elem(tab->head_b, "");
    ft_printf("ss\n");
}

void ft_s_elem(t_stack *a, char *s)
{
    if(a->next->index != 0)
    {
        ft_swap_int(&a->elem, &a->next->elem);
        ft_swap_int(&a->index, &a->next->index);
        if (!ft_strcmp("sb", s))
            ft_printf("sb\n");
        if (!ft_strcmp("sa", s))
            ft_printf("sa\n");
    }
}

t_stack *ft_r_stack(t_stack *a, char *s)
{
    t_stack *current;
    t_stack *first;
    t_stack *last;

    if (!a->next->index)
        return (a);
    first = a;
    a = a->next;
    current = a;
    while(current->next->next)
        current = current->next;
    last = current;
    first->next = current->next;
    last->next = first;
    if (!ft_strcmp("rb", s))
        ft_printf("rb\n");
    if (!ft_strcmp("ra", s))
        ft_printf("ra\n");
    return(a); 
}

t_stack *ft_rr_stack(t_stack *a, char *s)
{
    t_stack *first;
    t_stack *last;

    if (!a->next->index)
        return (a);
    first = a;
    while(a->next->next->index)
        a = a->next;
    last = a->next;
    a->next = a->next->next;
    last->next = first;
    if (!ft_strcmp(s, "rrb"))
        ft_printf("rrb\n");
    else if (!ft_strcmp(s, "rra"))
        ft_printf("rra\n");
    return(last);
}

void ft_rrr(t_tab *tab, char *s)
{
    tab->head_a = ft_rr_stack(tab->head_a, s);
    tab->head_b = ft_rr_stack(tab->head_b, s);
}

void ft_rr(t_tab *tab, char *s)
{
    tab->head_a = ft_r_stack(tab->head_a, s);
    tab->head_b = ft_r_stack(tab->head_b, s);
    if (ft_strcmp("rr", s))
        ft_printf("rr\n");
}