SRCS_DIR = srcs/
SRCS = buffer buffer_op
SRCS_NAME = $(SRCS:%=$(SRCS_DIR)%.c)
OBJS_NAME = $(SRCS_NAME:%.c=%.o)
LIB_DIR = ../lib/
LIB_NAME = libbuffer
HEADERS = buffer.h
HEADERS_DIR = includes/
LIB_HEADERS = $(HEADERS:%=$(LIB_DIR)$(HEADERS_DIR)%.h%)
TEST = test
COMP = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(LIB_DIR)$(LIB_NAME).a

$(SRCS_DIR)%.o : $(SRCS_DIR)%.c
	$(COMP) $(CFLAGS) -I$(HEADERS_DIR) -c $(SRCS_DIR)$*.c -o $(SRCS_DIR)$*.o

$(LIB_DIR)$(LIB_NAME).a: $(OBJS_NAME)
	ar -rc $(LIB_DIR)$(LIB_NAME).a $?
	ranlib $(LIB_DIR)$(LIB_NAME).a

clean :
	rm -f $(OBJS_NAME)

fclean : clean
	rm -f $(LIB_DIR)$(LIB_NAME).a

re : fclean all

.PHONY : all clean fclean
