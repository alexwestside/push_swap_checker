
#include "push_swap_checker.h"

void    ft_usage_chk(char *av)
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

void    ft_error_chk(void)
{
    ft_printf("Error\n");
    exit(EXIT_FAILURE);
}

void    ft_exit_success_chk(t_stack *a, t_stack *b, t_flags *f)
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

void    ft_print_stack(t_stack **a, t_stack **b, t_flags *f)
{
    t_stack *list1;
    t_stack *list2;

    list1 = *a;
    list2 = *b;
    ft_printf("----------------   ----------------\n");
    ft_printf("| STACK: [ A ] |   | STACK: [ B ] |\n");
    ft_printf("----------------   ----------------\n");
    while (list1 || list2)
    {
        if (list1)
        {
            ft_printf("|%8d%7|", list1->val);
            list1 = list1->next;
        }
        else
            ft_printf("|%15|");
        ft_printf("   ");
        if (list2)
        {
            ft_printf("|%8d%7|", list2->val);
            list2 = list2->next;
        }
        else
            ft_printf("|%15|");
        ft_printf("\n");
    }
    ft_printf("----------------   ----------------");
    ft_printf("\n");
}

void    ft_answer(t_stack **a, t_stack **b, t_flags *f)
{
    if (!(*a))
        ft_printf("KO\n Stack is AMPTY!!!\n");
    else if (!(*a)->next)
        ft_printf("Stack is alredy ordered!!!\n");
    else
        !ft_if_is_sorted(*a, f) ? ft_printf("OK\n") : ft_printf("KO\n");
    f->starr_end_mode ? ft_print_stack(a, b, f) : 0;
    f->number_oper_mode ? ft_printf("%d\n", f->count_op) : 0;
    f->status_oper_mode ? ft_print_stack(a, b, f) : 0;
    exit(EXIT_SUCCESS);
}