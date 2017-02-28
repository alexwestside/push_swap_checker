
#include "push_swap_checker.h"

void ft_std_input(t_stack **a, t_stack **b, char *s)
{
    if (*s == 's')
    {
        s++;
        ft_swap_sa_sb_ss(a, b, s);
    }
    else if (*s == 'p')
    {
        s++;
        ft_push_pa_pb(a, b, s);
    }
    else if (*s == 'r')
    {
        s++;
        if (*s == 'r')
        {
            s++;
            ft_rrotat_rrra_rrb_rrr(a, b, s);
        }
        else
            ft_swap_ra_rb_rr(a, b, s);
    }
    ft_print_stack(a, b);
}

void ft_swap_sa_sb_ss(t_stack **a, t_stack **b, char *s)
{
    *s == 'a' ? ft_swap(a) : 0;
    *s == 'b' ? ft_swap(b) : 0;
    s++;
    *s == 's' ? ft_sswap(a, b) : 0;
}

void ft_push_pa_pb(t_stack **a, t_stack **b, char *s)
{
    *s == 'a' ? ft_push_a(a, b) : 0;
    *s == 'b' ? ft_push_b(a, b) : 0;
}

void ft_swap_ra_rb_rr(t_stack **a, t_stack **b, char *s)
{
    *s == 'a' ? ft_rotate(a) : 0;
    *s == 'b' ? ft_rotate(b) : 0;
    s++;
    *s == 'r' ? ft_rrotate(a, b) : 0;
}

void ft_rrotat_rrra_rrb_rrr(t_stack **a, t_stack **b, char *s)
{
    *s == 'a' ? ft_rev_rotate(a) : 0;
    *s == 'b' ? ft_rev_rotate(b) : 0;
    s++;
    *s == 'r' ? ft_rrev_rotate(a, b) : 0;
}