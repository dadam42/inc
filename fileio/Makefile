SRCS = fileo.c filei.c
SRCSDIR = srcs/
HEADERSDIR = includes/

COMP = gcc
CFLAG = -Wall -Wextra
SRCSFP = $(SRCS:%=$(SRCSDIR)%)
OBJSFP = $(SRCSFP:%.c=%.o)
LIBDIR = lib/
LIBFP = $(SRCS:%.c=$(LIBDIR)lib%.a)


all : $(LIBFP)

install : all clean

$(SRCSDIR)%.o : $(SRCSDIR)%.c
	$(COMP) $(CFLAGS) -I$(HEADERSDIR) -c $(SRCSDIR)$*.c -o $(SRCSDIR)$*.o


$(LIBDIR)lib%.a : $(SRCSDIR)%.o $(HEADERSDIR)%.h
	ar -rf  $(LIBDIR)lib$*.a $(SRCSDIR)$*.o
	ranlib $(LIBDIR)lib$*.a
	cp $(HEADERSDIR)$*.h $(LIBDIR)includes/$*.h

clean : 
	rm -f $(OBJSFP)

fclean : clean
	rm -f $(LIBFP)

.PHONY : all clean fclean install

