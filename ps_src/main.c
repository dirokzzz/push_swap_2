#include "checker.h"

void ft_error(int e)
{
    if(e == 1)
        write(1, "Error1\n", 6);
    if(e == 2)
        write(1, "Error2\n", 6);
    if(e == 3)
        write(1, "Error3\n", 6);
    if(e == 4)
        write(1, "Error4\n", 6);
    if(e == 3)
        write(1, "Error5\n", 6);
    exit(0);
}

void print_int_tab(int *tab, int size)
{
    int i;

    i = 0;
    while(i < size)
    {
        ft_printf("%d\n", tab[i]);
        i++;
    }
}

t_stack *new_elem(t_stack *stack, int elem)
{
    t_stack *new;
    if (!(new = malloc(sizeof(t_stack))))
        exit(0);
    stack->next = new;
    new->elem = elem;
    if (new->elem < 0)
        ft_error(5);
    new->next = NULL;
    return (new);
}

t_stack *init_stack_b(t_stack *stack)
{
    if(!(stack = malloc(sizeof(t_stack))))
        exit(0);
    stack->index = 0;
    stack->elem = 0;
    stack->next = NULL;
    return(stack);
}

void check_arg(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while(i < ac)
    {
        j = 0;
         while(av[i][j])
         {
            if((av[i][j] < 48 || av[i][j] > 57) && av[i][j] != ' ')
                ft_error(1);
            j++;
         }
         i++;
    }
}

void check_dubble(t_stack *a)
{
    t_stack *head;
    t_stack *current;
    int elem;
    int index;

    head = a;
    current = a;
    while(current->index)
    {
        elem = current->elem;
        index = current->index;
        while(a->next->index)
        {
            if((elem == a->elem && index != a->index) || a->elem > 2147483647)
                ft_error(2);
            a = a->next;
        }
        a = head;
        current = current->next;
    }
}

void sort_int_tab(int *tab, int size)
{
    int i;

    i = 1;
    while (i < size)
    {
        if(tab[i] < tab[i - 1])
        {
            ft_swap_int(&tab[i], &tab[i - 1]);
            i = 0;
        }
        i++;
    }
}

t_stack *index_init(t_stack *a, t_tab *tab)
{
    t_stack *head;
    int i;

    head = a;
    i = 0;
    sort_int_tab(tab->tab, tab->size);
    while (i < tab->size && a->next)
    {
        if(tab->tab[i] == a->elem)
        {
            a->index = i + 1;
            i = -1;
            a = a->next;
        }
        i++;        
    }
    return(head);
}

t_stack *init_stack_a(t_stack *stack, char **av, int ac, t_tab *tab)
{
    int x;
    t_stack *head;

    x = 0;
    tab->size = size_of_tab(ac, av);
    tab->tab = parse_args(ac, av);
    if (!(stack = malloc(sizeof(t_stack))))
        exit(0);
    head = stack;
    stack->elem = tab->tab[x++];
    stack->index = x;
    stack->next = NULL;
    while (x < tab->size)
    {
        stack = new_elem(stack, tab->tab[x++]);
        stack->index = x;
    }
    stack = new_elem(stack, 0);
    stack->index = 0;
    check_dubble(head);
    head = index_init(head, tab);
    return(head);
}

void print_stacks(t_stack *a, t_stack *b)
{
    int flag;

    while(a->index || b->index)
    {
        flag = 0;
        if(a->index)
        {
            flag = 1;
            ft_printf("%d ", a->elem);
            if(a->next)
                a = a->next;
        }
        if(b->index)
        {
            if(!flag)
            {
                flag = 1;
                ft_printf("3%d", b->elem);
            }
            else
                ft_printf("%d", b->elem);
            if(b->next)
                b = b->next;
        }
        if(flag)
            ft_printf("\n");
    }
    ft_printf("_ _\na b\n");
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    t_tab   *tab;
    
    if(!(tab = malloc(sizeof(t_tab))))
        exit(0);
    a = NULL;
    b = NULL;
    if (ac >= 2)
    {
        tab->head_a = init_stack_a(a, av, ac, tab);
        tab->head_b = init_stack_b(b);
        print_stacks(tab->head_a, tab->head_b);
        sort_processing(tab);
        print_stacks(tab->head_a, tab->head_b);
    }
    free(tab);
}