#ifndef CHECKER_H
# define CHECKER_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
    int          elem;
    int               index;
    struct s_stack    *next;
}             t_stack;

typedef struct s_rule
{
    int     sa;
    int     sb;
    int     ss;
    int     pa;
    int     pb;
    int     ra;
    int     rb;
    int     rr;
    int     rra;
    int     rrb;
    int     rrr;
}              t_rule;

void ft_error(int e);
void print_stacks(t_stack *stack_a, t_stack *stack_b);
void get_rule_check(t_stack *a, t_stack *b);
int     size_of_tab(int ac, char **av);
void    check_arg(int ac, char **av);
int     *parse_args(int ac, char **av);
void    ft_s_elem(t_stack *a);
void    ft_ss(t_stack *stack_a, t_stack *stack_b);
t_stack *del_elem(t_stack *stack);
t_stack *add_elem(t_stack *src, t_stack *dst);
void    ft_push_a(t_stack **a, t_stack **b);
t_stack *ft_push_b(t_stack **a, t_stack **b);
t_stack *ft_r_stack(t_stack *a);
t_stack *ft_rr_stack(t_stack *a);
void    ft_rrr(t_stack **a, t_stack **b);
void    ft_rr(t_stack **a, t_stack **b);

#endif