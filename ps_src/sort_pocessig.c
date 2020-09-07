#include "checker.h"

void save_index(t_tab *tab, int *a, int *b, int *c)
{ 
    *a = tab->head_a->index;
    *b = tab->head_a->next->index;
    *c = tab->head_a->next->next->index;
}

void num_sort(t_tab *tab)
{
    int middle;
    int flag;

    flag = 1;
    middle = tab->size / 2;
    while (flag <= middle)
    {
        if(tab->head_a->index <= middle)
        {
            ft_push_b(tab);
            flag++;
        }
        else
            tab->head_a = ft_r_stack(tab->head_a, "ra");  
    }
    middle /= 2;
    while (tab->head_b->index)
    {
        if(tab->head_b->index <= middle)
            tab->head_b = ft_r_stack(tab->head_b, "rb");
        if(tab->head_b->index > middle)
            ft_push_a(tab);
        getchar();
        print_stacks(tab->head_a, tab->head_b);

    }

}
/*
t_stack *five_num_sort(t_stack *a, t_stack *b)
{
    t_stack *head;
    int flag;

    flag = 2;
    head = a;
    while (flag)
    {
        if(a->index < 3)
        {
            b = add_elem(a, b);
		    a = del_elem(a);
            ft_printf("pb\n");
            flag--;
        }
    }
    return;
}*/

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