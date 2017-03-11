
#include "push_swap_checker.h"

void	ft_usage_chk(char *av)
{
	ft_printf("usage: %s\n", av);
	ft_printf("use integer >= -2147483648 and <= 2147483647\n");
	ft_printf("use next flags:\n");
	ft_printf("\t -v fot [status operation mode]\n");
	ft_printf("\t -c fot [color mode]\n");
	ft_printf("\t -n for [number operation mode]\n");
	ft_printf("\t -i for [start and end mode]\n");
	ft_printf("\t -e for [enable all mode]\n");
	ft_printf("\t -d for [disable all mode]\n");
	exit(EXIT_FAILURE);
}

void	ft_error_chk(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_exit_success_chk(t_stack *a, t_stack *b, t_flags *f)
{
	if (!a->next)
	{
		ft_printf("Stack with ONE elemend is alredy ordered!!!\n");
		f->starr_end_mode ? ft_print_stack(&a, &b, f) : 0;
		ft_printf("OK\n");
		exit(EXIT_SUCCESS);
	}
	if (!ft_if_is_sorted(a, f))
	{
		ft_printf("Stack is alredy ordered!!!\n");
		f->starr_end_mode ? ft_print_stack(&a, &b, f) : 0;
		ft_printf("OK\n");
		exit(EXIT_SUCCESS);
	}
}

void	ft_print_stack(t_stack **a, t_stack **b, t_flags *f)
{
	t_stack *list1;
	t_stack *list2;
	char	*s;

	s = f->color_mode ? RED : END;
	list1 = *a;
	list2 = *b;
	ft_printf("%s----------------   ----------------%s\n", s, END);
	ft_printf("%s| STACK: [ A ] |   | STACK: [ B ] |\n", s, END);
	ft_printf("%s----------------   ----------------\n", s, END);
	while (list1 || list2)
	{
		list1 ? ft_printf("%s|%8d%7|   %s", s, list1->val, END) : 0;
		if (list1)
			list1 = list1->next;
		else
			ft_printf("%s|%15|   %s", s, END);
		list2 ? ft_printf("%s|%8d%7|\n", s, list2->val, END) : 0;
		if (list2)
			list2 = list2->next;
		else
			ft_printf("%s|%15|%s\n", s, END);
	}
	ft_printf("%s----------------   ----------------%s\n", s, END);
}

void	ft_answer(t_stack **a, t_stack **b, t_flags *f)
{
	if (!(*a))
		ft_printf("KO\n Stack is AMPTY!!!\n");
	else if (!(*a)->next)
		ft_printf("Stack is alredy ordered!!!\n");
	else
		!ft_if_is_sorted(*a, f) ? ft_printf("OK\n") : ft_printf("KO\n");
	if (f->starr_end_mode && !f->status_oper_mode)
		ft_print_stack(a, b, f);
	f->number_oper_mode ? ft_printf("%d\n", f->count_op) : 0;
	f->status_oper_mode ? ft_print_stack(a, b, f) : 0;
	exit(EXIT_SUCCESS);
}
