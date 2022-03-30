NAME    = push_swap
BNS		= checker
CC      = gcc  
CFLAGS  = -Wall -Wextra -Werror


HEAD    = push_swap.h \
		
OBJS    = push_swap.o push_swap_utils.o tables.o  ft_algo.o algo.o Error.o \
			instruction_third_part.o instructions_first_part.o instructions_second_part.o \
			ft_split.o get_next_line.o get_next_line_utils.o libft.o check_isdigit_error.o
OBJSB   = checker.o push_swap_utils.o tables.o  ft_algo.o algo.o Error.o \
			instruction_third_part.o instructions_first_part.o instructions_second_part.o \
			ft_split.o get_next_line.o get_next_line_utils.o libft.o check_isdigit_error.o
	
all: $(NAME) $(HEAD)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BNS) $(HEAD)

$(BNS) : $(OBJSB)
		$(CC) $(CFLAGS) $(OBJSB) -o $(BNS)
		
$(OBJS): $(HEAD)

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
		rm -f $(NAME)$(BNS)

re: fclean all
