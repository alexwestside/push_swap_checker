
#include "push_swap_checker.h"

void    ft_swap(t_stack **head, int id, t_flags *f)
{
    t_stack *list;
    t_stack *tail;

    if (*head)
    {
        if ((*head)->next)
        {
            list = *head;
            //tail = *head;
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

void    ft_sswap(t_stack **a, t_stack **b, t_flags *f)
{
    ft_swap(a, -1, f);
    ft_swap(b, -1, f);
    f->status_oper_mode ? ft_printf("%s\n", "ss") : 0;
    f->count_op++;
}

void    ft_rotate(t_stack **head, int id, t_flags *f)
{
    t_stack *list;
    t_stack *tail;

    if (*head)
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

void    ft_rrotate(t_stack **a, t_stack **b, t_flags *f)
{
    ft_rotate(a, -1, f);
    ft_rotate(b, -1, f);
    f->status_oper_mode ? ft_printf("%s\n", "rr") : 0;
}

void    ft_rev_rotate(t_stack **head, int id, t_flags *f)
{
    t_stack *list;
    t_stack *tail;

    if (*head)
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

void    ft_rrev_rotate(t_stack **a, t_stack **b, t_flags *f)
{
    ft_rev_rotate(a, -1, f);
    ft_rev_rotate(b, -1, f);
    f->status_oper_mode ? ft_printf("%s\n", "rrr") : 0;
    f->count_op++;
}

void    ft_push(t_stack **a, t_stack **b, int id, t_flags *f)
{
    t_stack *list;
    t_stack *tail;

    if (!*b)
    {
        list = *a;
        *b = *a;
        list =  list->next ? list->next : NULL;
        *a = list;
        list ? list->prev = NULL : 0;
        (*b)->next = NULL;
        (*b)->prev = NULL;
    }
    else if (*a)
    {
        list = *a;
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
    f->status_oper_mode ? ft_printf("%s\n", !id ? "pa" : "pb") : 0;
    f->count_op++;
}