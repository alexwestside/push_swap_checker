
#include "push_swap_checker.h"

void ft_usage_chk(char *av)
{
    ft_printf("usage: %s\n", av);
    ft_printf("use number >= -2147483648 and <= 2147483647\n");
    ft_printf("\t -v fot [status operation mode]\n");
    ft_printf("\t -c fot [color mode]\n");
    ft_printf("\t -o for [number operation mode]\n");
    ft_printf("\t -i for [start and end mode]\n");
    ft_printf("\t -a for [enable all mode]\n");
    ft_printf("\t -s for [disable all mode]\n");
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

void ft_exit_success_chk(t_stack *a, t_stack *b)
{
    if (!a->next)
    {
        ft_printf("Stack with ONE elemend is alredy ordered!!!\n");
        ft_print_stack(&a, &b);
        ft_printf("OK\n");
        exit(EXIT_SUCCESS);
    }
    if (!ft_if_is_sorted(a))
    {
        ft_printf("Stack is alredy ordered!!!\n");
        ft_print_stack(&a, &b);
        ft_printf("OK\n");
        exit(EXIT_SUCCESS);
    }
}

int ft_if_is_sorted(t_stack *a)
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

void ft_print_stack(t_stack **a, t_stack **b)
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

void ft_answer(t_stack **a, t_stack **b)
{
    if (!(*a))
        ft_printf("KO\n Stack is AMPTY!!!");
    else if(!(*a)->next)
        ft_printf("Stack is alredy ordered!!!\n");
    else
        !ft_if_is_sorted(*a) ? ft_printf("OK\n") : ft_printf("KO\n");
    ft_print_stack(a, b);
    //exit(EXIT_SUCCESS);
}