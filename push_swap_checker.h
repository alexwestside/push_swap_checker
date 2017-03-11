
#ifndef PUSH_SWAP_CHECKER_PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_PUSH_SWAP_CHECKER_H
# define MIN_INT -2147483648
# define MAX_INT 2147483647

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define END   "\x1B[0m"

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct		s_flags
{
	int				status_oper_mode	: 1;
	int				color_mode			: 1;
	int				number_oper_mode	: 1;
	int				starr_end_mode		: 1;
	int				enable_all_flags	: 1;
	int				disable_all_flags	: 1;
	int				count_op;
}					t_flags;

typedef struct		s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack				*ft_check_and_fill(char **av, t_stack *a, t_flags *f);
void				ft_val_check(char **av, t_flags *f);
int					ft_fill_flags(char s, t_flags *f);
int					ft_fast_check(char s);
t_stack				*ft_fill_stack(int val, t_stack *a);
long long int		ft_atoi_push_swap(char *s);
void				ft_check_dublicates(int val, t_stack *a);
void				ft_error_chk(void);
void				ft_usage_chk(char *av);
void				ft_exit_success_chk(t_stack *a, t_stack *b, t_flags *f);
int					ft_if_is_sorted(t_stack *a, t_flags *f);
void				ft_print_stack(t_stack **a, t_stack **b, t_flags *f);
void				ft_answer(t_stack **a, t_stack **b, t_flags *f);
void				ft_std_input(t_stack **a, t_stack **b, char *s, t_flags *f);
void				ft_swap(t_stack **head, int id, t_flags *f);
void				ft_sswap(t_stack **a, t_stack **b, t_flags *f);
void				ft_rotate(t_stack **head, int id, t_flags *f);
void				ft_rrotate(t_stack **a, t_stack **b, t_flags *f);
void				ft_rev_rotate(t_stack **head, int id, t_flags *f);
void				ft_rrev_rotate(t_stack **a, t_stack **b, t_flags *f);
void				ft_push(t_stack **a, t_stack **b, int id, t_flags *f);
void				ft_swap_sa_sb_ss(t_stack **a, t_stack **b, char *s, t_flags *f);
void				ft_push_pa_pb(t_stack **a, t_stack **b, char *s, t_flags *f);
void				ft_rotate_ra_rb_rr(t_stack **a, t_stack **b, char *s, t_flags *f);
void				ft_rrotat_rrra_rrb_rrr(t_stack **a, t_stack **b, char *s, t_flags *f);
void				ft_flag_enable(t_flags *f);

#endif
