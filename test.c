#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
    int          elem;
    int               index;
    struct s_stack    *next;
}             t_stack;

t_stack *new_list(t_stack *a, int i)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	a->next = new;
	new->elem = i;
	new->next = NULL;
	return(new);
}

int main()
{
	t_stack *a;
	t_stack *head;

	int i = 0;
	a = malloc(sizeof(t_stack));
	head = a;
	a->elem = i++;
	while(i < 5)
	{
		a = new_list(a, i);
		i++;
	}
	
	while(head->next)
	{
		printf("elem=%d\n", head->elem);
		head = head->next;
	}
}