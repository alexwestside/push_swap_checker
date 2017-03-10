
#include "push_swap_checker.h"

void    ft_std_input(t_stack **a, t_stack **b, char *s, t_flags *f)
{
    if (!ft_isalpha(*s) && *s)
        ft_error_chk();
    else if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb") || !ft_strcmp(s, "ss"))
        ft_swap_sa_sb_ss(a, b, s, f);
    else if (!ft_strcmp(s, "pa") || !ft_strcmp(s, "pb"))
        ft_push_pa_pb(a, b, s, f);
    else if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rb") || !ft_strcmp(s, "rr"))
        ft_rotate_ra_rb_rr(a, b, s, f);
    else if (!ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb") || !ft_strcmp(s, "rrr"))
        ft_rrotat_rrra_rrb_rrr(a, b, s, f);
    f->status_oper_mode ? ft_print_stack(a, b, f) : 0;
}

void    ft_swap_sa_sb_ss(t_stack **a, t_stack **b, char *s, t_flags *f)
{
    if (!ft_strcmp(s, "sa"))
        ft_swap(a, 0, f);
    else if (!ft_strcmp(s, "sb"))
        ft_swap(b, 1, f);
    else if (!ft_strcmp(s, "ss"))
        ft_sswap(a, b, f);
}

void    ft_push_pa_pb(t_stack **a, t_stack **b, char *s, t_flags *f)
{
    if (!ft_strcmp(s, "pa"))
        ft_push(b, a, 0, f);
    else if (!ft_strcmp(s, "pb"))
        ft_push(a, b, 1, f);
}

void    ft_rotate_ra_rb_rr(t_stack **a, t_stack **b, char *s, t_flags *f)
{
    if (!ft_strcmp(s, "ra"))
        ft_rotate(a, 0, f);
    else if (!ft_strcmp(s, "rb"))
        ft_rotate(b, 1, f);
    else if (!ft_strcmp(s, "rr"))
        ft_rrotate(a, b, f);
}

void    ft_rrotat_rrra_rrb_rrr(t_stack **a, t_stack **b, char *s, t_flags *f)
{
    if (!ft_strcmp(s, "rra"))
        ft_rev_rotate(a, 0, f);
    else if (!ft_strcmp(s, "rrb"))
        ft_rev_rotate(b, 1, f);
    else if (!ft_strcmp(s, "rrr"))
        ft_rrev_rotate(a, b, f);
}