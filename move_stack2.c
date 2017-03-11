
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
