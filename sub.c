
#include "push_swap_checker.h"

long long int	ft_atoi_push_swap(char *s)
{
	long long int	res;
	int				sign;

	res = 0;
	sign = 0;
	if (!*s)
		ft_error_chk();
	if (*s == '-' || *s == '+')
	{
		sign = *s == '-' ? -1 : 1;
		s++;
	}
	while (*s)
		res = res * 10 + *(s++) - 48;
	res = sign < 0 ? res * sign : res;
	if (res > MAX_INT || res < MIN_INT)
	{
		ft_error_chk();
		return (0);
	}
	else
		return (res);
}

int				ft_if_is_sorted(t_stack *a, t_flags *f)
{
	(void)f;
	t_stack	*list;
	int		val;

	list = a;
	if (list)
	{
		val = list->val;
		while (list)
		{
			if (val > list->val)
				return (1);
			val = list->val;
			list = list->next;
		}
		return (0);
	}
	return (1);
}

int				ft_fast_check(char s)
{
	if (s == 'v' || s == 'c' || s == 'n' || s == 'i' || s == 'e' || s == 'd')
		return (1);
	return (0);
}

void			ft_flag_enable(t_flags *f)
{
	f->status_oper_mode = 1;
	f->number_oper_mode = 1;
	f->color_mode = 1;
	f->starr_end_mode = 1;
}

void			ft_check_dublicates(int val, t_stack *a)
{
	t_stack	*list;

	list = a;
	while (list)
	{
		if (val == list->val)
			ft_error_chk();
		list = list->next;
	}
}