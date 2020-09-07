#include "checker.h"

void rule_accept_a(t_stack **a, t_stack **b, t_rule *rule)
{
	if(rule->rb)
		*b = ft_r_stack(*b);
	if (rule->rr)
	{
		*a = ft_r_stack(*a);
		*b = ft_r_stack(*b);
	}
	if (rule->rra)
		*a = ft_rr_stack(*a);
	if(rule->rrb)
		*b = ft_rr_stack(*b);
	if (rule->rrr)
	{
		*a = ft_rr_stack(*a);
		*b = ft_rr_stack(*b);
	}
}

void rule_accept_b(t_stack **a, t_stack **b, t_rule *rule)
{
	if(rule->pa)
	{
		*a = add_elem(*b, *a);
		*b = del_elem(*b);
	}
	if(rule->pb)
	{
		*b = add_elem(*a, *b);
		*a = del_elem(*a);
	}
	if (rule->sa)
		ft_s_elem(*a);
	if (rule->sb)
		ft_s_elem(*b);
	if (rule->ss)
		ft_ss(*a, *b);
	if (rule->ra)
		*a = ft_r_stack(*a);
}

void rule_parse(char *line, t_rule *rule)
{
	if(!ft_strcmp(line, "sa"))
		rule->sa = 1;
	else if(!ft_strcmp(line, "sb"))
		rule->sb = 1;
	else if(!ft_strcmp(line, "ss"))
		rule->ss = 1;
	else if(!ft_strcmp(line, "pa"))
		rule->pa = 1;
	else if(!ft_strcmp(line, "pb"))
		rule->pb = 1;
	else if(!ft_strcmp(line, "ra"))
		rule->ra = 1;
	else if(!ft_strcmp(line, "rb"))
		rule->rb = 1;
	else if(!ft_strcmp(line, "rrb"))
		rule->rrb = 1;
	else if(!ft_strcmp(line, "rrr"))
		rule->rrr = 1;
	else if(!ft_strcmp(line, "rr"))
		rule->rr = 1;
	else if(!ft_strcmp(line, "rra"))
		rule->rra = 1;
	else
		ft_error(4);
}

void b_zero_rule(t_rule *rule)
{
	rule->sa = 0;
	rule->sb = 0;
	rule->ss = 0;
	rule->pa = 0;
	rule->pb = 0;
	rule->ra = 0;
	rule->rb = 0;
	rule->rr = 0;
	rule->rra = 0;
	rule->rrb = 0;
	rule->rrr = 0;
}

void check_array(t_stack *a, t_stack *b)
{
	int ok;

	ok = 1;
	while(a->next->index)
	{
		if(a->elem > a->next->elem)
			ok = 0;
		a = a->next;
	}
	if(b->index)
		ok = 0;
	if(ok)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void get_rule_check(t_stack *a, t_stack *b)
{
	char	*line;
	int		flag;
	t_rule	*rule;

	if(!(rule = malloc(sizeof(t_rule))))
		exit(0);
	flag = 1;
	while(flag)
	{
		b_zero_rule(rule);
		flag = get_next_line(0, &line);
		if(!flag)
			break;
		rule_parse(line, rule);
		free(line);
		rule_accept_a(&a, &b, rule);
		rule_accept_b(&a, &b, rule);
	}
	print_stacks(a, b);
	check_array(a, b);
	free(rule);
}