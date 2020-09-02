#include "checker.h"

void ft_error(int e)
{
    if(e == 1)
        write(1, "Error1\n", 6);
    if(e == 2)
        write(1, "Error2\n", 6);
    if(e == 3)
        write(1, "Error3\n", 6);
    exit(0);
}

void print_int_tab(int *tab, int size)
{
    int i;

    i = 0;
    while(i < size)
    {
        printf("%d\n", tab[i]);
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
        ft_error(1);
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

void check_duble(t_stack *a)
{
    t_stack *head;
    t_stack *current;
    int elem;
    int index;

    head = a;
    current = a;
    while(current)
    {
        elem = current->elem;
        index = current->index;
        while(a->next)
        {
            a = a->next;
            if((elem == a->elem && current->index != a->index) || a->elem > 2147483647)
                ft_error(2);
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
    while (i <= tab->size)
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
    stack->next = NULL;
    while (x < tab->size)
    {
        stack->index = 1;
        stack = new_elem(stack, tab->tab[x++]);
    }
    stack = new_elem(stack, 0);
    stack->index = 0;
    head = index_init(head, tab);
    print_int_tab(tab->tab, tab->size);
    check_duble(head);

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
            printf("%d %d", a->elem, a->index);
            if(a->next)
                a = a->next;
        }
        if(b->index)
        {
            if(!flag)
            {
                flag = 1;
                printf("3%d", b->elem);
            }
            else
                printf("%d", b->elem);
            if(b->next)
                b = b->next;
        }
        if(flag)
            printf("\n");
        }
    printf("_ _\na b\n");
}
int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_tab   *tab;
    
    if(!(tab = malloc(sizeof(t_tab))))
        exit(0);
    stack_a = NULL;
    stack_b = NULL;
    if (ac >= 2)
    {
        stack_a = init_stack_a(stack_a, av, ac, tab);
        stack_b = init_stack_b(stack_b);
    }
    print_stacks(stack_a, stack_b);
}