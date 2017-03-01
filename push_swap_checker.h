
#ifndef PUSH_SWAP_CHECKER_PUSH_SWAP_CHECKER_H
#define PUSH_SWAP_CHECKER_PUSH_SWAP_CHECKER_H

#include "ft_printf/ft_printf.h"
#include "gnl/get_next_line.h"

#define MIN_INT -2147483648
#define MAX_INT 2147483647

#define SA swap stack a
#define SB swap stack b


typedef struct 	s_flags
{
    int status_oper_mode 	: 1;	// -v
    int color_mode 			: 1;	// -c
    int number_oper_mode 	: 1;	// -o
    int starr_end_mode 		: 1;	// -i
    int enable_all_flags 	: 1;	// -a
    int disable_all_flags 	: 1;	// -s
    uintmax_t count_op		: 1;	// count operation

}				t_flags;

typedef struct 		s_stack
{
    int 			val;
    //struct s_stack	*start;
    //struct s_stack	*end;
    struct s_stack 	*next;
    struct s_stack	*prev;
}					t_stack;

t_stack *ft_check_and_fill(char **av, t_stack *a);
void  ft_val_check(char **av);
t_stack *ft_fill_stack(int val, t_stack *a);
long long int ft_atoi_push_swap(char *s);
void ft_check_dublicates(int val, t_stack *a);
void ft_error_chk(void);
void ft_usage_chk(char *av);
void ft_exit_success_chk(t_stack *a, t_stack *b);
int ft_if_is_sorted(t_stack *a);
void ft_print_stack(t_stack **a, t_stack **b);
void ft_answer(t_stack **a, t_stack **b);
void ft_std_input(t_stack **a, t_stack **b, char *s);
void ft_swap(t_stack **head);
void ft_sswap(t_stack **a, t_stack **b);
void ft_rotate(t_stack **head);
void ft_rrotate(t_stack **a, t_stack **b);
void ft_rev_rotate(t_stack **head);
void ft_rrev_rotate(t_stack **a, t_stack **b);
void ft_push(t_stack **a, t_stack **b);
//void ft_push_a(t_stack **a, t_stack **b);
void ft_swap_sa_sb_ss(t_stack **a, t_stack **b, char *s);
void ft_push_pa_pb(t_stack **a, t_stack **b, char *s);
void ft_swap_ra_rb_rr(t_stack **a, t_stack **b, char *s);
void ft_rrotat_rrra_rrb_rrr(t_stack **a, t_stack **b, char *s);
void ft_error(void);

#endif //PUSH_SWAP_CHECKER_PUSH_SWAP_CHECKER_H
