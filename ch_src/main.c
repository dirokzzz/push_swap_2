#include "checker.h"

void ft_error(int e)
{
    if(e)
        ft_printf("Error\n");
    exit(0);
}

t_stack *new_elem(t_stack *stack, int elem)
{
    t_stack *new;
    if (!(new = malloc(sizeof(t_stack))))
        exit(0);
    stack->next = new;
    new->elem = elem;
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
    while(current->next)
    {
        elem = current->elem;
        index = current->index;
        while(a->next)
        {
            if((elem == a->elem && current->index != a->index))
                ft_error(2);
            a = a->next;
        }
        a = head;
        current = current->next;
    }
}

t_stack *init_stack_a(t_stack *stack, char **av, int ac)
{
    int x;
    t_stack *head;
    int *tab;
    int size;

    x = 0;
    size = size_of_tab(ac, av);
    tab = parse_args(ac, av);
    if (!(stack = malloc(sizeof(t_stack))))
        exit(0);
    head = stack;
    stack->elem = tab[x++];
    stack->index = x;
    stack->next = NULL;
    while (x < size)
    {
        stack = new_elem(stack, tab[x++]);
        stack->index = x;
    }
    stack = new_elem(stack, 0);
    stack->index = 0;
    check_dubble(head);
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
    t_stack *stack_a;
    t_stack *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    if (ac >= 2)
    {
        stack_a = init_stack_a(stack_a, av, ac);
        stack_b = init_stack_b(stack_b);
        get_rule_check(stack_a, stack_b);
    }
    
}