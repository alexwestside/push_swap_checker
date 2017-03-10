
#include "push_swap_checker.h"

void ft_error(void)
{
    ft_printf("Error\n");
    exit(EXIT_FAILURE);
}

void ft_usage_chk(char *av)
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

long long int ft_atoi_push_swap(char *s)
{
    long long int res;
    int sign;

    res = 0;
    sign = 0;
    if (!*s)
        ft_error_chk();
    if (*s == '-' || *s == '+')
    {
        sign = *s =='-' ? -1 : 1;
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

void ft_check_dublicates(int val, t_stack *a)
{
    t_stack *list;

    list = a;
    while (list)
    {
        if (val == list->val)
            ft_error_chk();
        list = list->next;
    }
}

void ft_error_chk(void)
{
    ft_printf("Error\n");
    exit(EXIT_FAILURE);
}

void ft_exit_success_chk(t_stack *a, t_stack *b, t_flags *f)
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

int ft_if_is_sorted(t_stack *a, t_flags *f)
{
    t_stack *list;
    int val;

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

void ft_print_stack(t_stack **a, t_stack **b, t_flags *f)
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

void ft_answer(t_stack **a, t_stack **b, t_flags *f)
{
    if (!(*a))
        ft_printf("KO\n Stack is AMPTY!!!\n");
    else if(!(*a)->next)
        ft_printf("Stack is alredy ordered!!!\n");
    else
        !ft_if_is_sorted(*a, f) ? ft_printf("OK\n") : ft_printf("KO\n");
    f->starr_end_mode ? ft_print_stack(a, b, f) : 0;
    exit(EXIT_SUCCESS);
}

int ft_fill_flags(char s, t_flags *f)
{
    if (s == 'v' || s == 'c' || s == 'n' || s == 'i' || s == 'e' || s == 'd')
    {
        s == 'v' ? f->status_oper_mode = 1 : 0;
        s == 'c' ? f->color_mode = 1 : 0;
        s == 'n' ? f->number_oper_mode = 1 : 0;
        s == 'i' ? f->starr_end_mode = 1 : 0;
        s == 'e' ? f->enable_all_flags = 1 : 0;
        s == 'd' ? f->disable_all_flags = 1 : 0;
        return (1);
    }
    return (0);
}

int ft_fast_check(char s)
{
    if (s == 'v' || s == 'c' || s == 'n' || s == 'i' || s == 'e' || s == 'd')
        return (1);
    return (0);
}