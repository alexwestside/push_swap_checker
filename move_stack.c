
#include "push_swap_checker.h"

void ft_swap(t_stack **head)
{
    t_stack *list;
    t_stack *tail;

    list = *head;
    tail = *head;

    tail = list->next;
    list = tail->next ? tail->next : tail;
    (*head)->prev = tail;
    tail->prev = NULL;
    (*head)->next = tail->next ? list :NULL;
    tail->next = *head;
    list->prev = *head;
    *head = tail;
}

void ft_sswap(t_stack **a, t_stack **b)
{
    ft_swap(a);
    ft_swap(b);
}

void ft_rotate(t_stack **head)
{
    t_stack *list;
    t_stack *tail;

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

void ft_rrotate(t_stack **a, t_stack **b)
{
    ft_rotate(a);
    ft_rotate(b);
}

void ft_rev_rotate(t_stack **head)
{
    t_stack *list;
    t_stack *tail;

    list = *head;
    while(list->next)
        list = list->next;
    tail = list->prev;
    tail->next = NULL;
    list->prev = NULL;
    list->next = *head;
    (*head)->prev = list;
    (*head) = list;
}

void ft_rrev_rotate(t_stack **a, t_stack **b)
{
    ft_rev_rotate(a);
    ft_rev_rotate(b);
}

void ft_push(t_stack **a, t_stack **b)
{
    t_stack *list;
    t_stack *tail;

    if (!*b)
    {
        list = *a;
        *b = *a;
        list = list->next;
        *a = list;
        list->prev = NULL;
        (*b)->next = NULL;
        (*b)->prev = NULL;
    }
    else
    {
        list = *a;
        tail = *b;
        tail->prev = *a;
        tail = tail->prev;
        list = list->next;
        *a = list;
        tail->next = *b;
        *b = tail;
        list->prev = NULL;
        tail->prev = NULL;
    }
}