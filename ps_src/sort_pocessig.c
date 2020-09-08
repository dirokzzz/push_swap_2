#include "checker.h"

void save_index(t_tab *tab, int *a, int *b, int *c)
{ 
    *a = tab->head_a->index;
    *b = tab->head_a->next->index;
    *c = tab->head_a->next->next->index;
}

void num_sort3(t_tab *tab)
{
while (tab->head_a->index != 1)
    {
        if (tab->head_a->index == tab->bottom + 1)
        {  
            tab->bottom += 1;
            tab->head_a = ft_r_stack(tab->head_a, "ra");  
        }
        else
            ft_push_b(tab);
    }
}

void from_b_to_a(t_tab *tab)
{
    while (tab->head_b->index)
    {
        if(tab->head_b->index == tab->top - 1)
         {
            ft_push_a(tab);
            tab->top -= 1;
         }
        if(tab->head_b->index == tab->bottom + 1)
        {
            ft_push_a(tab);
            tab->bottom += 1;
            tab->head_a = ft_r_stack(tab->head_a, "ra");
        }
        if(tab->head_b->index &&(tab->head_b->index != tab->top - 1 && tab->head_b->index != tab->bottom + 1))
            tab->head_b = ft_rr_stack(tab->head_b, "rrb");
    }
}

void num_sort(t_tab *tab)
{
    int middle;
    int flag;

    flag = 1;
    middle = tab->size / 2;
    while (flag <= tab->size)
    {
        if(tab->head_a->index <= middle)
            ft_push_b(tab);
        else
            tab->head_a = ft_r_stack(tab->head_a, "ra");
        flag++;  
    }
    from_b_to_a(tab);
    while (tab->head_a->index == tab->bottom + 1)
    {
        tab->bottom += 1;
        tab->head_a = ft_r_stack(tab->head_a, "ra");
    }
    tab->top = tab->size + 1;
    num_sort3(tab);
    from_b_to_a(tab);
    num_sort3(tab);
}

void three_num_sort(t_tab *tab)
{
    int a;
    int b;
    int c;

    save_index(tab, &a, &b, &c);
    if((a > b && a < c) || (b > c && b < a)\
    || (c < b && c > a))
    {
        ft_s_elem(tab->head_a, "sa");
        save_index(tab, &a , &b, &c);
    }
    if (a < b && a > c)
        tab->head_a = ft_rr_stack(tab->head_a, "rra");
    if (c > b && a > c)
        tab->head_a = ft_r_stack(tab->head_a, "ra");
}

void sort_processing(t_tab *tab)
{
    if (tab->size == 3)
        three_num_sort(tab);
    if (tab->size > 5)
        num_sort(tab);
}