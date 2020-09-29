#ifndef CHECKER_H
# define CHECKER_H

#include "../libft/includes/ft_printf.h"
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

typedef struct s_tab
{
    int *tab;
    int size;
    t_stack *head_a;
    t_stack *head_b;
    t_stack *tail_a;
    t_stack *tail_b;
    int bottom;
    int top;
}               t_tab;

int     check_array(t_tab *tab);
void    sort_processing(t_tab *tab);
void    ft_error(int e);
void    print_stacks(t_stack *stack_a, t_stack *stack_b);
void    get_rule_check(t_stack *a, t_stack *b);
int     size_of_tab(int ac, char **av);
void    check_arg(int ac, char **av);
int     *parse_args(int ac, char **av);
void    ft_s_elem(t_stack *a, char *s);
void    ft_ss(t_tab *tab);
t_stack *del_elem(t_stack *stack);
t_stack *add_elem(t_stack *src, t_stack *dst);
void    ft_push_a(t_tab *tab);
void    ft_push_b(t_tab *tab);
t_stack *ft_r_stack(t_stack *a, char *s);
t_stack *ft_rr_stack(t_stack *a, char *s);
void    ft_rrr(t_tab *tab, char *s);
void    ft_rr(t_tab *tab, char *s);

#endif