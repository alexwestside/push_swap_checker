
#include "push_swap_checker.h"

void ft_std_input(t_stack **a, t_stack **b, char *s)
{
    if (!ft_isalpha(*s) && *s)
        ft_error();
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
            ft_rotate_ra_rb_rr(a, b, s);
    }
    //ft_print_stack(a, b);
}

void ft_swap_sa_sb_ss(t_stack **a, t_stack **b, char *s)
{
    if (*s == 'a')
        ft_swap(a, 0);
    else if (*s == 'b')
        ft_swap(b, 1);
    //s++
    else /*(*s == 's')*/
        ft_sswap(a, b);
}

void ft_push_pa_pb(t_stack **a, t_stack **b, char *s)
{
    if (*s == 'a')
        ft_push(b, a, 0);
    else if (*s == 'b')
        ft_push(a, b, 1);
}

void ft_rotate_ra_rb_rr(t_stack **a, t_stack **b, char *s)
{
    if (*s == 'a')
        ft_rotate(a, 0);
    else if (*s == 'b')
        ft_rotate(b, 1);
    //s++;
    else /*(*s == 'r')*/
        ft_rrotate(a, b);
}

void ft_rrotat_rrra_rrb_rrr(t_stack **a, t_stack **b, char *s)
{
    if (*s == 'a')
        ft_rev_rotate(a, 0);
    else if (*s == 'b')
        ft_rev_rotate(b, 1);
    //s++;
    else /*(*s == 'r')*/
        ft_rrev_rotate(a, b);
}