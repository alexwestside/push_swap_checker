
#include "push_swap_checker.h"

void	ft_swap(t_stack **head, int id, t_flags *f)
{
	t_stack	*list;
	t_stack	*tail;

	if (*head)
	{
		if ((*head)->next)
		{
			list = *head;
			tail = list->next;
			list = tail->next ? tail->next : tail;
			(*head)->prev = tail;
			tail->prev = NULL;
			(*head)->next = tail->next ? list : NULL;
			tail->next = *head;
			list->prev = *head;
			*head = tail;
		}
	}
	if (id != -1 && f->status_oper_mode)
		ft_printf("%s\n", !id ? "sa" : "sb");
	if (id != -1 && f->number_oper_mode)
		f->count_op++;
}

void	ft_rotate(t_stack **head, int id, t_flags *f)
{
	t_stack	*list;
	t_stack	*tail;

	if (*head && (*head)->next)
	{
		list = *head;
		while (list->next)
			list = list->next;
		tail = (*head)->next;
		list->next = (*head);
		(*head)->prev = list;
		tail->prev = NULL;
		(*head)->next = NULL;
		(*head) = tail;
	}
	if (id != -1 && f->status_oper_mode)
		ft_printf("%s\n", !id ? "ra" : "rb");
	if (id != -1 && f->number_oper_mode)
		f->count_op++;
}

void	ft_rev_rotate(t_stack **head, int id, t_flags *f)
{
	t_stack	*list;
	t_stack	*tail;

	if (*head && (*head)->next)
	{
		list = *head;
		while (list->next)
			list = list->next;
		tail = list->prev;
		tail->next = NULL;
		list->prev = NULL;
		list->next = *head;
		(*head)->prev = list;
		(*head) = list;
	}
	if (id != -1 && f->status_oper_mode)
		ft_printf("%s\n", !id ? "rra" : "rrb");
	if (id != -1 && f->number_oper_mode)
		f->count_op++;
}

void	ft_push(t_stack **a, t_stack **b, int id, t_flags *f)
{
	t_stack	*list;
	t_stack	*tail;

	list = *a;
	if (!*b)
	{
		*b = *a;
		list = list->next ? list->next : NULL;
		*a = list;
		list ? list->prev = NULL : 0;
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
	else if (*a)
	{
		tail = *b;
		tail->prev = *a;
		tail = tail->prev;
		list = list->next ? list->next : NULL;
		*a = list;
		tail->next = *b;
		*b = tail;
		list ? list->prev = NULL : 0;
		tail->prev = NULL;
	}
	if (f->status_oper_mode)
	{
		ft_printf("%s\n", !id ? "pa" : "pb");
		f->count_op++;
	}
}

int ft_check_size(t_stack *head)
{
	t_stack *list;

	list = head;
	return (list ? 1 : 0);
}
