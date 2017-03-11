
#include "push_swap_checker.h"

void	ft_sswap(t_stack **a, t_stack **b, t_flags *f)
{
	ft_swap(a, -1, f);
	ft_swap(b, -1, f);
	f->status_oper_mode ? ft_printf("%s\n", "ss") : 0;
	f->count_op++;
}

void	ft_rrotate(t_stack **a, t_stack **b, t_flags *f)
{
	ft_rotate(a, -1, f);
	ft_rotate(b, -1, f);
	f->status_oper_mode ? ft_printf("%s\n", "rr") : 0;
}

void	ft_rrev_rotate(t_stack **a, t_stack **b, t_flags *f)
{
	ft_rev_rotate(a, -1, f);
	ft_rev_rotate(b, -1, f);
	f->status_oper_mode ? ft_printf("%s\n", "rrr") : 0;
	f->count_op++;
}

int ft_check_move(char *s)
{
	if (!ft_strcmp(s, "sa"))
		return (0);
	else if (!ft_strcmp(s, "sb"))
		return (0);
	else if (!ft_strcmp(s, "ra"))
		return (0);
	else if (!ft_strcmp(s, "rb"))
		return (0);
	else if (!ft_strcmp(s, "pa"))
		return (0);
	else if (!ft_strcmp(s, "pb"))
		return (0);
	else if (!ft_strcmp(s, "rra"))
		return (0);
	else if (!ft_strcmp(s, "rrb"))
		return (0);
	else if (!ft_strcmp(s, "ss"))
		return (0);
	else if (!ft_strcmp(s, "rr"))
		return (0);
	else if (!ft_strcmp(s, "rrr"))
		return (0);
	return (1);
}

t_stack *ft_end(t_stack *head)
{
	t_stack *list;

	list = head;
	while (list->next)
		list = list->next;
	return (list);
}
